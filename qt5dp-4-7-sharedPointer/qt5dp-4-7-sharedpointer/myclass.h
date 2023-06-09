#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QMutex>

class MyClass : public QObject
{
   Q_OBJECT
public:
   explicit MyClass(QObject *parent = nullptr);
   ~MyClass();

   int count() const;
   void addCount();
   QMutex* mutex();

private:
   int m_count;
   QMutex m_mutex;

signals:

};

#endif // MYCLASS_H
