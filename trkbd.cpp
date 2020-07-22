#include "trkbd.hpp"
//#include <QKeyvent>
#include <GL/gl.h>
#include <QFont>
#include <QTimer>
#include <iostream>
#include <list>
#include <random>
#include <vector>
trkbd::trkbd() {
  x1 = 20;
  y1 = 20;
  p = new std::list<QString>(trkbd::width());
  trkbd::p->resize(trkbd::width() / 20);
  std::cout << trkbd::p->size() << std::endl;
  trkbd::a.setHMS(0, 0, 0);
  trkbd::second = 0;
  trkbd::stringelement = 97;
  trkbd::i = 1;
  QTimer *tmr = new QTimer(this);
  connect(tmr, SIGNAL(timeout()), this, SLOT(updateGL()));
  tmr->start(33);
  timerID = startTimer(32);
}
trkbd::~trkbd() {
  // delete trkbd;
}
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
  switch (apkey->key()) {
  case Qt::Key_Q: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_W: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_E: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_R: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() %26+97;
    _draw();
    break;
  }
  case Qt::Key_T: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_Y: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_U: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_I: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_O: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_P: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_A: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_S: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_D: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_F: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_G: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_H: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_J: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_K: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_L: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_Z: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_X: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_C: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_V: {
    trkbd::i = rand() % 32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_B: {
    trkbd::i = rand() %32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_N: {
    trkbd::i = rand() %32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_M: {
    trkbd::i = rand() %32;
    trkbd::stringelement = rand() % 26+97;
    _draw();
    break;
  }
  case Qt::Key_Escape: {
    close();
  }
  }
}
void trkbd::resizeEvent(QResizeEvent *) {}
void trkbd::timerEvent(QTimerEvent *e) {
  Q_UNUSED(e)
  // trkbd::second++;
  // if(trkbd::second==15) trkbd::i=rand()%32;
  // if(trkbd::second==1000)trkbd::second=0;
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
void trkbd::setX(int x) { x1 = x; }
int trkbd::X(int x) { return x; }
void trkbd::setY(int y) { y1 = y; }
int trkbd::Y(int y) { return y; }
void trkbd::updatetime() { trkbd::a = trkbd::a.addSecs(1); }
