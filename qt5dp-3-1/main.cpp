#include <QCoreApplication>
#include <QTextStream>
#include <QList>
#include <QString>
#include <QDebug>


bool userIO(QTextStream &stream, QList<QString> &list) {

   QString value = stream.readLine(255);
   qInfo () << "val; " << value;
   if(!value.isEmpty()) return false;

   int id = 0;
   QString name = "";

   QStringList items = value.split(" ");
   qDebug() << "items " << items  << items.length();
   if(items.length() < 2) return false;

   bool ok;
   id = items.at(0).toInt(&ok);
   if(!ok) return false;

   name = items.at(1);

   if(id < list.length()) {
      list.insert(id, name);
   }
   else {
      id = list.length();
      list.append(name);
   }

   qInfo() << id << ", " << name;

   return true;
}


int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);

   QTextStream stream(stdin);
   QList<QString> list;

   while(userIO(stream, list)) {
      qInfo() << "Do it again ..";
   }

   return a.exec();
}
