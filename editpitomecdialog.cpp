#include "editpitomecdialog.h"
#include "pitomec.h"
EditPitomecDialog::EditPitomecDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editAge = new QLineEdit();
    editBreed = new QLineEdit();
    editFIO = new QLineEdit();


    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Имя"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Возраст"),3,1);
    mainLayout->addWidget(editAge,3,2);
    mainLayout->addWidget(new QLabel("Порода"),4,1);
    mainLayout->addWidget(editBreed,4,2);
    mainLayout->addWidget(new QLabel("ФИО владельца"),5,1);
    mainLayout->addWidget(editFIO,5,2);



    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,7,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о питомце");


    //Располагаем диалог над основным окном
    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditPitomecDialog::id() const
{
    return editID->text();
}
QString EditPitomecDialog::name() const
{
    return editName->text();
}
QString EditPitomecDialog::age() const
{
    return editAge->text();
}
QString EditPitomecDialog::breed() const
{
    return editBreed->text();
}
QString EditPitomecDialog::fio() const
{
    return editFIO->text();
}


void EditPitomecDialog::SetUpDialog(QString id, QString name, QString age, QString breed, QString fio)
{
    editID->setText(id);
    editName->setText(name);
    editAge->setText(age);
    editBreed->setText(breed);
    editFIO->setText(fio);

}
