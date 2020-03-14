#include "feed.h"
#include <iostream>

Feed::Feed() : cap(0)
{
    this->set("../nocamera.png");
    height = 700;
    width = 800;
}

//We actually need to free some things if the user needs less cameras than
//currently in the app
Feed::~Feed()
{

}

void Feed::refresh()
{
    std::cout << "This" << std::endl;
    cap.read(frame);
    cvtColor(frame, frame, cv::COLOR_BGR2RGB);
    auto img = Gdk::Pixbuf::create_from_data(frame.data,
                      Gdk::COLORSPACE_RGB,
                      frame.channels() == 4,
                      8,
                      width,
                      height,
                      (int) frame.step);
    cv::waitKey(1);
    this->set(img);

}

void Feed::set_hw()
{
  //take in one frame and base the heigth and width off of it.
  //makes it so we don't have to do this on every iteration of
  //refresh();/
  cap.read(frame);
  height = frame.rows;
  width = frame.cols;


}
