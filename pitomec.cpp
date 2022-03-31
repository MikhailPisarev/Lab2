#include "pitomec.h"

Pitomec::Pitomec(QString ID, QString Name, QString Age, QString Breed, QString FIO, QObject *parent): QObject(parent)
{
    id = ID;
    name = Name;
    age = Age;
    breed = Breed;
    fio = FIO;

}

void Pitomec::SetID(QString ID)
{
    id = ID;
}
void Pitomec::SetName(QString Name)
{
    name = Name;
}
void Pitomec::SetAge(QString Age)
{
    age = Age;
}
void Pitomec::SetBreed(QString Breed)
{
    breed = Breed;
}
void Pitomec::SetFIO(QString FIO)
{
   fio = FIO;
}

QString Pitomec::ID()
{
    return id;
}
QString Pitomec::Name()
{
    return name;
}
QString Pitomec::Age()
{
    return age;
}
QString Pitomec::Breed()
{
    return breed;
}
QString Pitomec::FIO()
{
    return fio;
}

 Pitomec::~Pitomec()
{
}
