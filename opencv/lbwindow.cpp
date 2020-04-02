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
  b_cameranumber.set_label("Number of cameras: 1");


  set_border_width(30);

  image_logo.show();
  main_box.pack_start(image_logo);
  this->configure_feed();
  main_box.pack_start(button_box);

  add(main_box);
  full = false;

  this->configure_buttons();
  main_box.show();
  button_box.show();

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
    button_box.pack_start(b_fullscreen);
    b_fullscreen.show();

    b_cameranumber.signal_clicked().
    connect(sigc::mem_fun(*this, &LBwindow::on_numcams_clicked));
    button_box.pack_start(b_cameranumber);
    b_cameranumber.show();

    b_quit.signal_clicked().
    connect(sigc::mem_fun(*this, &LBwindow::on_quit_clicked));
    button_box.pack_start(b_quit);
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
