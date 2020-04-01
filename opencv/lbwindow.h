#ifndef LBWINDOW_H
#define LBWINDOW_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/separator.h>
#include "feed.h"


class LBwindow : public Gtk::Window
{
public:
  LBwindow();
  virtual ~LBwindow();

protected:
  virtual void on_fullscreen_clicked();
  virtual void on_quit_clicked();
  virtual void on_numcams_clicked();
  virtual void configure_buttons();
  virtual void configure_feed();
  Gtk::HBox button_box, feeds_1_and_2, feeds_3_and_4;
  Gtk::VBox main_box;
  Gtk::Image image_logo;
  Gtk::Button b_fullscreen, b_cameranumber, b_quit;
  Gtk::HSeparator s_feed_middle, s_buttons;
  Gtk::VSeparator s_feed_top, s_feed_bottom;
  //Although we have 4 feed objects, they're only taking up
  //cpu power when the user decides they want more than one camera
  //running.
  Feed feeds[4];
  bool full; //fullscreen
  int numcams;

};

#endif
