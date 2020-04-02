/**
* main.cpp
*
* Jacob "Kobi" Tessman
* last modified: 4/1/2020
*
* The main.cpp file for my LittleBrother security camera manager app.
*
*/

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <gtkmm/main.h>
#include "lbwindow.h"


/**
* main
*
* input: none
*
* output: int
*
* Sets the entire program into motion. Calls an instance of a Gtk::Main object,
* then calls an instance of an LBwindow object, and runs it.
*/
int main(int argc, char * argv[])
{

	Gtk::Main kit(argc, argv);
	LBwindow * lbwindow = new LBwindow();
	Gtk::Main::run(*lbwindow);

	return 0;
}
