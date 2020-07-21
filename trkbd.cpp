#include "trkbd.hpp"
//#include <QKeyEvent>
#include <QTimer>
#include <map>
#include <random>
#include <iostream>
#include <QFont>
#include <QPainter>
#include <GL/gl.h>
trkbd::trkbd() {
  x1=0;
  y1=0;
  QTimer *tmr = new QTimer(this);
  connect(tmr, SIGNAL(timeout()), this, SLOT(updateGL()));
  tmr->start(33);
  timerID = startTimer(5000);
}
trkbd::~trkbd() {
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
      break;
    }
    case Qt::Key_J: {
      break;
    }
    case Qt::Key_K: {
      break;
    }
    case Qt::Key_L: {
      break;
    }
    case Qt::Key_Z: {
      break;
    }
    case Qt::Key_X: {
      break;
    }
    case Qt::Key_C: {
      break;
    }
    case Qt::Key_V: {
      break;
    }
    case Qt::Key_B: {
      break;
    }
    case Qt::Key_N: {
      break;
    }
    case Qt::Key_M: {
      break;
    }
    case Qt::Key_Escape: {
      close();
    }
  }
}

void trkbd::resizeEvent(QResizeEvent *) {
}
void trkbd::timerEvent(QTimerEvent * e) {
  Q_UNUSED(e)
  // _processing();
  // _draw();
}
void trkbd::_processing() {
  auto aw = trkbd::width();
  auto ah = trkbd::height();

}
void trkbd::_draw() {
  auto aw = trkbd::width();
  auto ah = trkbd::height();
  const int W = aw/20;
  const int H = ah/20;
  grid screen[W][H];
  for(int x=1;x!=W;x++)
      {
        for(int y=1;y!=2;y++)
          {
            screen[x][y].x=x*aw/W;
            // fscreen[x][y].y=y*ah/H;
          }
      }
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  QString s("q");
  static auto font = QFont("xos-4 Terminus:style=Regular", 18);
  for ( int x=1; x< W; ++x ) {
    for ( int y=1; y< 2; ++y ) {
      renderText(x * 20, y * 20, screen[x][y].ch = s, font);
      // std::cout<< i << y << std::endl;
    }
  }
}
void trkbd::setX(int x) {
  x1=x;
}
int trkbd::X( int x ) {
  return x;
}
void trkbd::setY(int y) {
  y1=y;
}
int trkbd::Y( int y ) {
  return y;
}
