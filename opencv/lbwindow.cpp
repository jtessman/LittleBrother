#include "lbwindow.h"
#include <iostream>

LBwindow::LBwindow() : m_button("Hello World")
{
  set_border_width(100);

  m_button.signal_clicked().connect(sigc::mem_fun(*this, &LBwindow::on_button_clicked));

  add(m_button);

  m_button.show();

}

LBwindow::~LBwindow()
{

}

void LBwindow::on_button_clicked()
{
  std::cout << "Hello World!" << std::endl;
}
