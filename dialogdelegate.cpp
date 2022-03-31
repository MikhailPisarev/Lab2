#include "dialogdelegate.h"
#include "QtWidgets"
#include "editpitomecdialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;

}


bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditPitomecDialog* editDialog = new EditPitomecDialog(dparentWidget);

        QString ID = model->data(model->index(index.row(),0,index)).toString();
        QString Name = model->data(model->index(index.row(),1,index)).toString();
        QString Age = model->data(model->index(index.row(),2,index)).toString();
        QString Breed = model->data(model->index(index.row(),3,index)).toString();
        QString FIO = model->data(model->index(index.row(),4,index)).toString();

        editDialog->SetUpDialog(ID, Name, Age, Breed, FIO);

        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->id());
            model->setData(model->index(index.row(),1,index),editDialog->name());
            model->setData(model->index(index.row(),2,index),editDialog->age());
            model->setData(model->index(index.row(),3,index),editDialog->breed());
            model->setData(model->index(index.row(),4,index),editDialog->fio());


            editDialog->deleteLater();
        }
    }
    return false;

}

QWidget *DialogDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
