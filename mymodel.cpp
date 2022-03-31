#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    Pitomec* std1 = new Pitomec("101","Боня","5","Тибетский мастиф","Писарев М.Р.",this);
    Pitomec* std2 = new Pitomec("102","Када","7","Немецкая овчарка","Кольцова А.Д.",this);
    Pitomec* std3 = new Pitomec("103","Юстас","4","Немецкая овчарка","Кольцова А.Д.",this);
    AddPitomec(std1);
    AddPitomec(std2);
    AddPitomec(std3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return pitomecs.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 5;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Pitomec* std = pitomecs.at(index.row());
        if (index.column() == 0){Value = std->ID();}
        else if (index.column() == 1){Value = std->Name();}
        else if (index.column() == 2){Value = std->Age();}
        else if (index.column() == 3){Value = std->Breed();}
        else if (index.column() == 4){Value = std->FIO();}

        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Имя");
            case 2:
                return QString("Возраст");
            case 3:
                return QString("Порода");
            case 4:
                return QString("ФИО владельца");

            }
        }
    }
    return QVariant();
}


bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        Pitomec* std = pitomecs.at(index.row());
        if (index.column() == 0){std->SetID(value.toString());}
        else if (index.column() == 1){std->SetName(value.toString());}
        else if (index.column() == 2){std->SetAge(value.toString());}
        else if (index.column() == 3){std->SetBreed(value.toString());}
        else if (index.column() == 4){std->SetFIO(value.toString());}

    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}




void MyModel::AddPitomec(Pitomec*pitomec)
{
    beginInsertRows(QModelIndex(),pitomecs.size(),pitomecs.size());
    pitomecs.append(pitomec);
    endInsertRows();
    //emit layoutChanged();
}

void MyModel::DeletePitomec(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    pitomecs.removeAt(row);
    endRemoveRows();
    //emit layoutChanged();
}

