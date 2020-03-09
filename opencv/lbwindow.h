#ifndef LBWINDOW_H
#define LBWINDOW_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class LBwindow : public Gtk::Window
{
public:
  LBwindow();
  virtual  ~LBwindow();

protected:
  virtual void on_button_clicked();
  Gtk::Button m_button;

};

#endif
