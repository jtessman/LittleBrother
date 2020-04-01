#include "lbwindow.h"
#include "feed.h"
#include <iostream>
#include <gtkmm/main.h>
#include <gdkmm/pixmap.h>


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

LBwindow::~LBwindow()
{

}

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

void LBwindow::on_quit_clicked()
{
  //Not really needed, but whenever you quit the program by pressing
  //the "x" in the top right corner, it gives you a "core dumped" error
  //that can be misleading.
  exit(0);
}


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
