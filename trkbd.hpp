// Copyright 2020 <kaje>
#ifndef TRKBD_HPP
#define TRKBD_HPP
#include <QKeyEvent>
#include <QTime>
#include <qt5/QtOpenGL/QGLWidget>

class trkbd : public QGLWidget {
  Q_OBJECT
public:
  const static int W = 80;
  const static int H = 30;
  struct grid {
    grid(char ach = ' ', int alive = 0) : x(0), y(0), ch(ach), live(alive) {}
    int x;
    int y;
    QString ch;
    int live;
  };
  std::list<QString> *p;
  grid scren[trkbd::W][trkbd::H];

  //
  int i = 0;

  int second = 0;
  int timerID;
  int stringelement;
  std::map<int, QString> keytointmap;
  trkbd();
  ~trkbd();
  void setX(int);
  int X(int);
  void setY(int);
  int Y(int);
  int x1 = 0;
  int y1 = 0;

  QTime a;
private slots:
  void updatetime();

private:
  void initializeGL() override;
  void resizeGL(int, int) override;
  void paintGL() override;
  void keyReleaseEvent(QKeyEvent *) override;
  virtual void resizeEvent(QResizeEvent *) override;
  virtual void timerEvent(QTimerEvent *) override;

private:
  void _processing();
  void _draw();

private:
};
#endif // TRKBD_HPP
