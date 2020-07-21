// Copyright 2020 <kaje>
#ifndef TRKBD_HPP
#define TRKBD_HPP
#include <QKeyEvent>
#include <QGLWidget>
//#include <filesystem>

class trkbd : public QGLWidget {
  Q_OBJECT
 public :
  const
  static int W = 80;
  const
  static int H = 30;
    struct grid {
      grid
      (char ach = ' ', int alive = 0) : x(0), y(0), ch(ach), live(alive) { }
      int x;
      int y;
      QString ch;
      int live;
    };

  grid scren[trkbd::W][trkbd::H];

  //
  int timerID;
  trkbd();
  ~trkbd();
  void setX(int);
  int X(int);
  void setY(int);
  int Y(int);
  int x1;int y1;
 private :
  void initializeGL() override;
  void resizeGL(int, int) override;
  void paintGL();
  void keyReleaseEvent(QKeyEvent *) override;
    virtual
    void resizeEvent(QResizeEvent *) override;
    virtual
    void timerEvent(QTimerEvent *) override;

 private :
  void _processing();
  void _draw();

 private :
};
#endif  // TRKBD_HPP
