/**
* lbwindow.cpp
*
* Jacob "Kobi" Tessman
*
* last modified: 4/1/2020
*
* The cpp file for the LBwindow object.
*/

#include "lbwindow.h"
#include "feed.h"
#include <iostream>
#include <gtkmm/main.h>
#include <gdkmm/pixmap.h>
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/filechooser.h>
#include <gtkmm/filechooserwidget.h>
#include <gtkmm/entry.h>

/**
* LBwindow
*
* input: none
*
* output: LBwindow object
*
* The constructor function for the LBwindow object.
*/
LBwindow::LBwindow()
{
  set_title("Little Brother");
  // number of initial cameras
  numcams = 1;

  image_logo.set("../Logo.png");
  modify_bg_pixmap(Gtk::STATE_NORMAL, "../screen.jpg");

  // labels on all buttons
  b_fullscreen.set_label("Fullscreen");
  b_quit.set_label("Quit");
  b_choose_folder.set_label("/home/kobi/Desktop/MotionVideos/"); //default on startup
  b_cameranumber.set_label("Number of cameras: 1");
  email_entry.set_text("kobi.tessman@gmail.com"); //default on startup


  set_border_width(30);

  image_logo.show();
  main_box.pack_start(image_logo);
  this->configure_feed();
  main_box.pack_start(button_box_top);
  main_box.pack_start(button_box_bottom);

  add(main_box);
  full = false;

  this->configure_buttons();
  main_box.show();
  button_box_top.show();
  button_box_bottom.show();

}

/**
* ~LBwindow
*
* input: none
*
* output: none
*
* The destructor for the LBwindow object.
*/
LBwindow::~LBwindow()
{

}

/**
* on_fullscreen_clicked
*
* input: none
*
* output: none
*
* The function that is signalled whenever a user pushes the "Fullscreen" button.
* Switches the bool, then calls the GTK function accordingly.
*/
void LBwindow::on_fullscreen_clicked()
{
  if(full == false)
  {
    this->fullscreen();
    full = true;
  }
  else
  {
    this->unfullscreen();
    full = false;
  }
}

/**
* on_numcams_clicked
*
* input: none
*
* output: none
*
* The function that is signalled whenever the user clicks the "Number of
* Cameras" button. Does all of the necessary work that happens when we hide all
* of the other feeds or add one more feed, including making sure that no non-
* active feeds take up any cpu power by disconnecting them.
*/
void LBwindow::on_numcams_clicked()
{
    if(numcams < 4)
    {
      feeds[numcams].show();
      numcams++;
    }

    else
    {
      for(int i = 1; i < 4; i++)
      {
        feeds[i].disconnect();
        feeds[i].hide();
      }

      numcams = 1;
    }

    if(numcams == 1)
    {
      s_feed_top.hide();
      s_feed_bottom.hide();
      s_feed_middle.hide();
    }
    else if(numcams == 2)
    {
      s_feed_top.show();
    }
    else if(numcams == 3)
    {
      s_feed_middle.show();
    }
    else
    {
      s_feed_bottom.show();
    }

    std::string h = "Number of cameras: " + std::to_string(numcams);
    b_cameranumber.set_label(h);
}

/**
* on_quit_clicked
*
* input: none
* output: none
*
* A function that is signalled whenever the user clicks the "Quit" button. Not
* truly needed, but whenever the user clicks the "x" button in the top right
* corner, it displays a "core dumped" error that can be misleading.
*/
void LBwindow::on_quit_clicked()
{
  exit(0);
}

/**
* on_choose_email_clicked()
*
* input: none
*
* output: none
*
* The function that gets signalled when the user presses "enter" on the email
* entry on the lbwindow. Iterates through all of the feeds and changes the
* default email. Has no error checking, maybe a future feature.
*/
void LBwindow::on_choose_email_clicked()
{
  std::string new_email = email_entry.get_text();
  std::cout << "Changed the email address to " << new_email << std::endl;

  for(int i = 0; i < 4; i++)
  {
    feeds[i].feed_change_email(new_email);
  }

}

/**
* on_choose_folder_clicked
*
* input: none
*
* output: none
*
* When the folder button is clicked, a window pops up and allows the user to
* pick a new folder for the saved videos and pictures. It has built in error
* chekcing. Iterates through all of the feeds and changes the emails, and
* rebrands the button to have the folder name.
*/
void LBwindow::on_choose_folder_clicked()
{
  Gtk::FileChooserDialog dialog("Please choose a folder",
  Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
  dialog.set_transient_for(*this);
  //Add response buttons the the dialog:
  dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("Select", Gtk::RESPONSE_OK);
  int result = dialog.run();
  //Handle the response:
  switch(result)
  {
      case(Gtk::RESPONSE_OK):
      {
        std::cout << "Select clicked." << std::endl;
        std::cout << "Folder selected: " << dialog.get_filename()
        << std::endl;

        std::string new_folder_name = dialog.get_filename() + "/";

        for(int i = 0; i < 4; i++)
        {
          feeds[i].feed_change_folder(new_folder_name);
        }
        b_choose_folder.set_label(new_folder_name);

        break;
      }
      case(Gtk::RESPONSE_CANCEL):
      {
        std::cout << "Cancel clicked." << std::endl;
        break;
      }
      default:
      {
        std::cout << "Unexpected button clicked." << std::endl;
        break;
      }
  }

}
/**
* configure_buttons
*
* input: none
*
* output: none
*
* The function that is called once within the object's constructor, in order to
* make the constructor function smaller. Sets up all of the buttons in the
* LBwindow.
*/
void LBwindow::configure_buttons()
{
    //configure all buttons
    b_fullscreen.signal_clicked().
    connect(sigc::mem_fun(*this, &LBwindow::on_fullscreen_clicked));
    button_box_top.pack_start(b_fullscreen);
    b_fullscreen.show();

    b_cameranumber.signal_clicked().
    connect(sigc::mem_fun(*this, &LBwindow::on_numcams_clicked));
    button_box_top.pack_start(b_cameranumber);
    b_cameranumber.show();

    b_choose_folder.signal_clicked().
    connect(sigc::mem_fun(*this, &LBwindow::on_choose_folder_clicked));
    button_box_bottom.pack_start(b_choose_folder);
    b_choose_folder.show();

    email_entry.signal_activate().
    connect(sigc::mem_fun(*this, &LBwindow::on_choose_email_clicked));
    button_box_bottom.pack_start(email_entry);
    email_entry.show();

    b_quit.signal_clicked().
    connect(sigc::mem_fun(*this, &LBwindow::on_quit_clicked));
    button_box_top.pack_start(b_quit);
    b_quit.show();
}

/**
* configure_feed
*
* input: none
*
* output: none
*
* Another function that is called only once within the object's constructor.
* Sets up all of the Feed objects.
*/
void LBwindow::configure_feed()
{
   //Configure the feeds in the
   for(int i = 0; i < 4; i++)
   {
     feeds[i].set_device_id(i);
   }

   feeds_1_and_2.pack_start(feeds[0]);
   feeds_1_and_2.pack_start(s_feed_top);
   feeds_1_and_2.pack_start(feeds[1]);
   feeds_3_and_4.pack_start(feeds[2]);
   feeds_3_and_4.pack_start(s_feed_bottom);
   feeds_3_and_4.pack_start(feeds[3]);

   main_box.pack_start(feeds_1_and_2);
   main_box.pack_start(s_feed_middle);
   main_box.pack_start(feeds_3_and_4);

   feeds_1_and_2.show();
   feeds_3_and_4.show();
   main_box.pack_start(s_buttons);
   s_buttons.show();

   //Display the first one as default
   feeds[0].show();
}
