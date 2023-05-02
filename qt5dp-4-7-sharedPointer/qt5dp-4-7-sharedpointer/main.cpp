#include<QCoreApplication>b
#include<QDebug>
#include<QMutexLocker>
#include<QThread>
#include<QThreadPool>
#include<QSharedPointer>
#include "myclass.h"
#include "myrunnable.h"

void test() {

   qInfo() << "******** Entering Test() " << QThreadPool::globalInstance()->maxThreadCount();

   QSharedPointer<MyClass> ptr(new MyClass);

   for(int i = 0; i < QThreadPool::globalInstance()->maxThreadCount(); i++) {

      MyRunnable *runnable = new MyRunnable();
      runnable->setAutoDelete(true);
      runnable->setPointer(ptr);
      QThreadPool::globalInstance()->start(runnable);
   }

   qInfo() << "******** Exiting Test() ";
}


int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);

   test();

   return a.exec();
}
