#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <gtkmm/main.h>
#include "lbwindow.h"
using namespace cv;

int main(int argc, char * argv[])
{
VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.

if (!stream1.isOpened()) { //check if video device has been initialised
std::cout << "cannot open camera" << std::endl;
}

Gtk::Main kit(argc, argv);
LBwindow * lbwindow = new LBwindow();
Gtk::Main::run(*lbwindow);

cv::namedWindow("cam", WINDOW_NORMAL);
cv::resizeWindow("cam", 900, 600);

//unconditional loop
while (1)
{
    Mat cameraFrame;
    stream1.read(cameraFrame);
    cv::imshow("cam", cameraFrame);
    cv::waitKey(1);
}

	return 0;
}
