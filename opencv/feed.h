#ifndef FEED_H
#define FEED_H

#include <gtkmm/image.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Feed : public Gtk::Image
{

public:
  Feed();
  virtual ~Feed();
  void set_hw();
  void refresh();
private:
  int width;
  int height;
  cv::Mat frame;
  cv::VideoCapture cap;

};


#endif
