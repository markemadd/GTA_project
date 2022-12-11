#include "widgets.h"

Widgets::Widgets(QString l, int w, int index_x, int index_y) {
  QFont font;
  font.setPixelSize(20);
  setDefaultTextColor(Qt::white);
  setFont(font);
  setPos(index_x, index_y);
  count = w;
  label = l;
  setPlainText(label + QString::number(count));
}
void Widgets::setTime(int t) { count = t; }
void Widgets::timers2() {
  count--;
  setPlainText(label + QString::number(count));
}
void Widgets::timers() {
  if (count != 0) {

    count--;
    setPlainText(label + QString::number(count));
  }
}
