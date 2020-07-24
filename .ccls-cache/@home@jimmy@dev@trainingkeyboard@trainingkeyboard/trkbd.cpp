#include "trkbd.hpp"
#include <GL/gl.h>
#include <QDebug>
#include <QFont>
#include <QString>
#include <QTimer>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <sstream>
#include <vector>
trkbd::trkbd() { trkbd::inithisprogram(); }
trkbd::~trkbd() {}
void trkbd::initializeGL() {
  glViewport(0, 0, 800, 600);
  glLoadIdentity();
  glOrtho(0, 800, 0, 600, 0, 1);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glDisable(GL_DEPTH);
  glEnable(GL_MULTISAMPLE);
  glEnable(GL_BLEND);
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_SMOOTH);
}
void trkbd::resizeGL(int aw, int ah) {
  glViewport(0, 0, (GLint)aw, (GLint)ah);
  glLoadIdentity();
  glOrtho(0, aw, ah, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
void trkbd::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  qglClearColor(Qt::black);
  _processing();
  _draw();
}
void trkbd::keyReleaseEvent(QKeyEvent *apkey) {
  if (trkbd::keytointmap.find(trkbd::stringelement)->second == (apkey->key())) {
    trkbd::getrandpelement();
    _draw();
  }
  if (apkey->key() == Qt::Key_Escape) {
    close();
  }
}
void trkbd::resizeEvent(QResizeEvent *) {}
void trkbd::timerEvent(QTimerEvent *e) {
  Q_UNUSED(e)
  updatetime();
}
void trkbd::_processing() {
  trkbd::y1++;
  if (trkbd::y1 == trkbd::height())
    trkbd::y1 = 1;
}
void trkbd::_draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  static auto font = QFont("terminus", 18);
  renderText(trkbd::x1 * trkbd::i, trkbd::y1, (QString)trkbd::stringelement,
             font);
}
void trkbd::getrandpelement() {
  trkbd::i = rand() % 32;
  trkbd::stringelement = rand() % 26 + 97;
}
void trkbd::inithisprogram() {
  x1 = 20;
  y1 = 20;
  trkbd::a.setHMS(0, 0, 0);
  trkbd::second = 0;
  trkbd::stringelement = 97;
  trkbd::i = 1;
  int N = 122;
  std::stringstream ss;
  int o;
  for (int l = 97; l != N; ++l) {
    o = l - 32;
    ss << o;
    trkbd::s.push_back(ss.str().c_str());
    trkbd::keytointmap.insert(std::pair<int, QString>(l, trkbd::s.toInt()));
    trkbd::s.clear();
    ss.str("");
  }
  QTimer *tmr = new QTimer(this);
  connect(tmr, SIGNAL(timeout()), this, SLOT(updateGL()));
  tmr->start(33);
  timerID = startTimer(32);
}
void trkbd::setX(int x) { x1 = x; }
int trkbd::X(int x) { return x; }
void trkbd::setY(int y) { y1 = y; }
int trkbd::Y(int y) { return y; }
void trkbd::updatetime() { trkbd::a = trkbd::a.addSecs(1); }
