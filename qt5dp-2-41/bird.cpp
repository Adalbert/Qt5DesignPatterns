
#include "bird.h"

Bird::Bird(QObject *parent)
    : QObject{parent}
{

}

void Bird::test()
{

}


void Bird::fly()
{
    qInfo() << this << "Flying";
}


void Bird::land()
{
    qInfo() << this << "land";
}
