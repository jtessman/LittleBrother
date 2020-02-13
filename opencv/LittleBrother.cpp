#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <GL/glut.h>
#include <iostream>

using namespace cv;

int main()
{
    VideoCapture stream1(0);   //default is one camera initially

    if (!stream1.isOpened())
    { //check if video device has been initialised
        std::cout << "cannot open camera" << std::endl;
    }

    //unconditional loop
    while(1)
    {

      if(!stream1.isOpened())
      {
        break;
      }

      Mat cameraFrame;
      stream1.read(cameraFrame);
      const std::string wname = "LittleBrother";
      const cv::String * windowname = new cv::String(wname);


      namedWindow(*windowname, WINDOW_OPENGL);
      imshow(*windowname, cameraFrame);
      resizeWindow(*windowname, 1300, 1000);


      if (waitKey(30) >= 0)
      {
          break;
      }
    }
return 0;
}


//utilize mutexes to tell when a camera is opened or not
//first figure out how in the world opencv intertwines with opengl
