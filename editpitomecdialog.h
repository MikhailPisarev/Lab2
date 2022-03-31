#ifndef EDITPITOMECDIALOG_H
#define EDITPITOMECDIALOG_H

#endif // EDITPITOMECDIALOG_H*/
#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "pitomec.h"

class EditPitomecDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editName;
    QLineEdit* editAge;
    QLineEdit* editBreed;
    QLineEdit* editFIO;


public:
    EditPitomecDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString age() const;
    QString breed() const;
    QString fio() const;


    void SetUpDialog(QString id, QString name, QString age, QString breed, QString fio);
};

#endif // INPUTDIALOG_H

