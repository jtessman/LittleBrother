#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <gtkmm/main.h>

#include "lbwindow.h"

using namespace cv;

int main(int argc, char * argv[])
{

	Gtk::Main kit(argc, argv);
	LBwindow * lbwindow = new LBwindow();
	Gtk::Main::run(*lbwindow);

	return 0;
}
