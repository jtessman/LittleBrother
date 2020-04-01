#include "feed.h"
#include <iostream>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <cairomm/context.h>

Feed::Feed()
{
    recording_align.add(recording);
    this->add(recording_align);
    recording_align.set(Gtk::ALIGN_RIGHT, Gtk::ALIGN_CENTER, 0.0, 0.0);
    recording.set("../record-OFF.png");
    this->add(cur_frame);
    cur_frame.set("../noCamera.png");
    recording_align.show();
    recording.show();
    cur_frame.show();
    connected = false;
    cam_ID = 0;
    width = 500;
    height = 380;
    this->set_buttons();
}

//We actually need to free some things if the user needs less cameras than
//currently in the app
Feed::~Feed()
{

}


bool Feed::refresh(void)
{
    cap.read(frame);
    //do that in a function
    //cap.open(deviceID + apiID);
    if(!frame.empty())
    {
      //Code to convert a cv::Mat object to a Gtk::Image from geeksforgeeks.
      cv::resize(frame, resized, cv::Size(width, height), 0, 0, cv::INTER_LINEAR);
      cvtColor(resized, resized, cv::COLOR_BGR2RGB);
      auto img = Gdk::Pixbuf::create_from_data(resized.data,
                        Gdk::COLORSPACE_RGB,
                        resized.channels() == 4,
                        8,
                        width,
                        height,
                        (int)resized.step);
      cur_frame.set(img);
      cv::waitKey();
      return true;
    }
    else
    {
      this->disconnect();
    }

}


void Feed::disconnect()
{
  if(connected)
  {
    cap.release();
    connected = false;
    cur_frame.set("../noCamera.png");
    signal.disconnect();
  }
}

void Feed::connect()
{
  int api_ID = cv::CAP_ANY;
  cap.open(cam_ID);
  if(!connected && cap.isOpened())
  {
    connected = true;
    signal = Glib::signal_timeout().connect(
    sigc::mem_fun(*this, &Feed::refresh), 5);
  }
  else
  {
    std::cout << "Could not open /dev/video/" << cam_ID << std::endl;
  }
}


void Feed::set_buttons()
{
  detect.set_label("Detect");
  forget.set_label("Forget");
  forget.signal_clicked().
  connect(sigc::mem_fun(*this, &Feed::disconnect));
  detect.signal_clicked().
  connect(sigc::mem_fun(*this, &Feed::connect));
  feed_buttons.add(forget);
  feed_buttons.add(detect);
  feed_buttons.pack_start(detect);
  feed_buttons.pack_start(forget);
  this->pack_start(feed_buttons);
  detect.show();
  forget.show();
  feed_buttons.show();
}

void Feed::set_hw(int h, int w)
{
  //take in one frame and base the heigth and width off of it.
  //makes it so we don't have to do this on every iteration.
  height = h;
  width = w;

}

void Feed::set_device_id(int i)
{
  cam_ID = i;
}
