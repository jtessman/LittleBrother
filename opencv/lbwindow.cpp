#include "lbwindow.h"
#include "feed.h"
#include <pthread.h>
#include <iostream>

void * pthread_iterate(void *pack)
{
  //feed points to the feed object that we want to put an infinite cycle on.
  Feed *feed = (Feed *) pack;

  feed->set_hw();

  while(1)
  {
    feed->refresh();
    feed->show();
  }

  std::cout << "Does the loop finish?" << std::endl;
  return NULL;
}


LBwindow::LBwindow()
{
  set_title("Little Brother");
  // number of initial cameras
  numcams = 1;


  image_logo.set("../Logo.png");
  image_bg.set("../screen.jpg");

  // labels on all buttons
  b_fullscreen.set_label("Fullscreen");
  b_record.set_label("Record");
  b_quit.set_label("Quit");
  b_cameranumber.set_label("Number of cameras: ");


  set_border_width(30);

  image_logo.show();
  main_box.pack_start(image_logo);
  main_box.pack_start(feed);
  main_box.pack_start(button_box);

  add(main_box);

  full = false;

  this->configure_buttons();
  main_box.show();
  button_box.show();
  feed.show();

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

void LBwindow::iterate()
{
  feed.set_hw();

  pthread_create(&thread, NULL, pthread_iterate, &feed);
}

void LBwindow::on_numcams_clicked()
{
  pthread_join(thread, NULL);
}

void LBwindow::on_record_clicked()
{
  iterate();
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

    b_record.signal_clicked().
    connect(sigc::mem_fun(*this, &LBwindow::on_record_clicked));
    button_box.pack_start(b_record);
    b_record.show();

    b_cameranumber.signal_clicked().
    connect(sigc::mem_fun(*this, &LBwindow::on_numcams_clicked));
    button_box.pack_start(b_cameranumber);
    b_cameranumber.show();

    b_quit.signal_clicked().
    connect(sigc::mem_fun(*this, &LBwindow::on_quit_clicked));
    button_box.pack_start(b_quit);
    b_quit.show();
}
