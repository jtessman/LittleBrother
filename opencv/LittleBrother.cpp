#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.

if (!stream1.isOpened()) { //check if video device has been initialised
cout << "cannot open camera";
}

cv::namedWindow("cam", WINDOW_NORMAL);
cv::resizeWindow("cam", 900, 600);

//unconditional loop
while (true) 
{
    Mat cameraFrame;
    stream1.read(cameraFrame);
    cv::imshow("cam", cameraFrame);
    cv::waitKey(1);
}

	return 0;
}

