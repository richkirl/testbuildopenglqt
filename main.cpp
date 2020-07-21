#include <QApplication>
#include <QGLWidget>
#include <iostream>
#include "trkbd.hpp"
using namespace std;
int main(int argc, char *argv[])
{
  QApplication a(argc,argv);
  cout<<"Hello World"<<endl;
  trkbd *w = new trkbd;
  w->show();
  w->resize(800,600);
  return a.exec();
  delete w;
  return 0;
}
