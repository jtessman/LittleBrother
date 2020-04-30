/**
* feed.h
*
* Jacob "Kobi" Tessman
*
* Last modified 4/1/2020
*
* The header file for the Feed object.
*/

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
  void set_mode();
  void disconnect();
  bool refresh();
  void set_buttons();
  void set_device_id(int i);
  void email_notification(std::string filename, std::string date_and_time);
  void feed_change_email(std::string new_email);
  void feed_change_folder(std::string new_folder);

private:
  bool noise, connected, catching_frames;
  Gtk::Alignment recording_align;
  Gtk::Image cur_frame;
  Gtk::Image recording;
  Gtk::Button b_detect, b_forget;
  Gtk::HBox feed_buttons;
  int width, height, cam_ID, seconds_recording, default_num_gs_frames, frames_caught;
  std::queue<cv::Mat> pastframes;
  cv::Mat frame, empty_mat;
  cv::Mat resized;
  cv::VideoCapture cap;
  sigc::connection signal, email_signal;
  cv::VideoWriter video;
  std::string user_email_address, user_folder;

};


#endif
