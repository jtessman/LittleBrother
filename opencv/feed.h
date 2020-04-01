#ifndef FEED_H
#define FEED_H

#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <gtkmm/alignment.h>
#include <gtkmm/button.h>
#include <queue>

class Feed : public Gtk::VBox
{

public:
  Feed();
  virtual ~Feed();
  void set_hw(int h, int w);
  void connect();
  void disconnect();
  bool refresh(void);
  void set_buttons();
  void set_device_id(int i);

private:
  Gtk::Alignment recording_align;
  Gtk::Image cur_frame;
  Gtk::Image recording;
  Gtk::Button detect, forget;
  Gtk::HBox feed_buttons;
  bool connected;
  bool catching_frames;
  int width, height, cam_ID, frames_caught;
  std::queue<cv::Mat> pastframes;
  cv::Mat frame, empty_mat;
  cv::Mat resized;
  cv::VideoCapture cap;
  sigc::connection signal;

};


#endif
