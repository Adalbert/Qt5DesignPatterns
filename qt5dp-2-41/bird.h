
#ifndef BIRD_H
#define BIRD_H


#include <QObject>
#include <QDebug>
#include "interfaces/iFlying.h"

class Bird : public QObject, public iFlying
{
    Q_OBJECT
public:
    explicit Bird(QObject *parent = nullptr);

    void test();

signals:


    // iFlying interface
public:
    void fly();
    void land();
};

#endif // BIRD_H
