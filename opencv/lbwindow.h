#ifndef LBWINDOW_H
#define LBWINDOW_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include "feed.h"
#include <pthread.h>


class LBwindow : public Gtk::Window
{
public:
  LBwindow();
  virtual ~LBwindow();

protected:
  virtual void on_fullscreen_clicked();
  virtual void on_quit_clicked();
  virtual void on_record_clicked();
  virtual void on_numcams_clicked();
  virtual void iterate();
  virtual void configure_buttons();
  Gtk::HBox button_box;
  Gtk::VBox main_box;
  Gtk::Image image_bg, image_logo;
  Gtk::Button b_fullscreen, b_cameranumber, b_record, b_quit;
  Feed feed;
  bool full;
  int numcams;

};

#endif
