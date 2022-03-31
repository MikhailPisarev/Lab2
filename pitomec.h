#ifndef PITOMEC_H
#define PITOMEC_H
#include "QString"
#include <QObject>

class Pitomec: public QObject
{
    Q_OBJECT

public:
    Pitomec(QString ID, QString Name, QString Age, QString Breed, QString FIO, QObject *parent = nullptr );
    virtual ~Pitomec();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetAge(QString Age);
    void SetBreed(QString Breed);
    void SetFIO(QString FIO);


    QString ID();
    QString Name();
    QString Age();
    QString Breed();
    QString FIO();

private:
    QString id;
    QString name;
    QString age;
    QString breed;
    QString fio;

};
#endif // PITOMEC_H
