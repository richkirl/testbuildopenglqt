#include "trkbd.hpp"
#include <GL/gl.h>
#include <QFont>
#include <QTimer>
#include <iostream>
#include <list>
#include <map>
#include <random>
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
  if (trkbd::keytointmap.find(trkbd::stringelement)->second ==
      (int)(apkey->key())) {
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
  trkbd::keytointmap.insert(std::pair<int, QString>(97, Qt::Key_A));
  trkbd::keytointmap.insert(std::pair<int, QString>(98, Qt::Key_B));
  trkbd::keytointmap.insert(std::pair<int, QString>(99, Qt::Key_C));
  trkbd::keytointmap.insert(std::pair<int, QString>(100, Qt::Key_D));
  trkbd::keytointmap.insert(std::pair<int, QString>(101, Qt::Key_E));
  trkbd::keytointmap.insert(std::pair<int, QString>(102, Qt::Key_F));
  trkbd::keytointmap.insert(std::pair<int, QString>(103, Qt::Key_G));
  trkbd::keytointmap.insert(std::pair<int, QString>(104, Qt::Key_H));
  trkbd::keytointmap.insert(std::pair<int, QString>(105, Qt::Key_I));
  trkbd::keytointmap.insert(std::pair<int, QString>(106, Qt::Key_J));
  trkbd::keytointmap.insert(std::pair<int, QString>(107, Qt::Key_K));
  trkbd::keytointmap.insert(std::pair<int, QString>(108, Qt::Key_L));
  trkbd::keytointmap.insert(std::pair<int, QString>(109, Qt::Key_M));
  trkbd::keytointmap.insert(std::pair<int, QString>(110, Qt::Key_N));
  trkbd::keytointmap.insert(std::pair<int, QString>(111, Qt::Key_O));
  trkbd::keytointmap.insert(std::pair<int, QString>(112, Qt::Key_P));
  trkbd::keytointmap.insert(std::pair<int, QString>(113, Qt::Key_Q));
  trkbd::keytointmap.insert(std::pair<int, QString>(114, Qt::Key_R));
  trkbd::keytointmap.insert(std::pair<int, QString>(115, Qt::Key_S));
  trkbd::keytointmap.insert(std::pair<int, QString>(116, Qt::Key_T));
  trkbd::keytointmap.insert(std::pair<int, QString>(117, Qt::Key_U));
  trkbd::keytointmap.insert(std::pair<int, QString>(118, Qt::Key_V));
  trkbd::keytointmap.insert(std::pair<int, QString>(119, Qt::Key_W));
  trkbd::keytointmap.insert(std::pair<int, QString>(120, Qt::Key_X));
  trkbd::keytointmap.insert(std::pair<int, QString>(121, Qt::Key_Y));
  trkbd::keytointmap.insert(std::pair<int, QString>(122, Qt::Key_Z));
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
