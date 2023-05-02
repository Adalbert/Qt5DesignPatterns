
#include <QTime>
#include "myrunnable.h"

MyRunnable::MyRunnable()
{
   qInfo() << "MyRunnable: " << QThread::currentThread();
}

void MyRunnable::run()
{
   for(int i = 0; i < 10; i++) {
      // sim long activity
      int ms = QRandomGenerator::global()->bounded(0, 500);
      qInfo() << QTime::currentTime() << QThread::currentThread() << " sleep: " << ms;
      QThread::currentThread()->msleep(ms);

      qInfo() << QTime::currentTime() << " ##";
      m_pointer->addCount();
   }
}

QSharedPointer<MyClass> MyRunnable::pointer() const
{
   return m_pointer;

}

void MyRunnable::setPointer(const QSharedPointer<MyClass> &pointer)
{
   m_pointer = pointer;
}
