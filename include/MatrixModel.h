#ifndef MATRIXMODEL_H
#define MATRIXMODEL_H
#include "matrix.h"
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>
#include <QObject>
#include <QDebug>
#include <QString>
#include <rational.h>
#include <QRegExp>
#include <QRegExpValidator>

//for use of to_string to own types
using std::to_string;

template<typename T>
class MatrixModel : public QAbstractTableModel {
public:
    MatrixModel(dima::matrix<T> m)
        : m_rows(m.get_rows()), m_columns(m.get_columns()), m(m) {    }
		
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;

    //! access table data
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

    //! needed to make cells editable
    Qt::ItemFlags flags(const QModelIndex &index) const;

    //! set the given index data to the view's input
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

private:
	int m_rows;
	int m_columns;
	dima::matrix<T> m;
};


template<typename T>
int MatrixModel<T>::rowCount(const QModelIndex& /*parent*/) const {
    return m_rows;
}

template<typename T>
int MatrixModel<T>::columnCount(const QModelIndex& /* parent */) const {
    return m_columns;
}

template<typename T>
QVariant MatrixModel<T>::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();
    //return the data to which the index points
    else if (role == Qt::DisplayRole)
        return QString::fromStdString(to_string(m(index.row(), index.column())));
    else if (role == Qt::EditRole) {
        QString str = QString::fromStdString(to_string(m(index.row(), index.column())));
        return str;
    }
    return QVariant();
}

template<typename T>
Qt::ItemFlags MatrixModel<T>::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    flags |= (Qt::ItemIsEditable
              |Qt::ItemIsSelectable
              |Qt::ItemIsEnabled
              |Qt::ItemIsUserCheckable);
    return flags;
}

template<typename T>
bool MatrixModel<T>::setData(const QModelIndex &index, const QVariant &value, int role) {
    qDebug() << "in setData" << "\n";
    if (!index.isValid() || role != Qt::EditRole || value.toString().isEmpty())
        return false;
    m(index.row(), index.column()) = value.toUInt();
    //emit dataChanged(index, index);
    return true;
}

template<>
bool MatrixModel<dima::rational>::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid() || role != Qt::EditRole || value.toString().isEmpty())
        return false;
    //matches fractions
    QRegExp e("^[+-]?[0-9]+\\/?[0-9]+$");
    QRegExpValidator validator(e);
    QString valueqstr = value.toString();
    int pos = 0;
    if (!validator.validate(valueqstr,pos)) {
        return false;
    }
    std::string valuestr = valueqstr.toStdString();
    dima::rational r;
    r.fromString(valuestr);
    m(index.row(),index.column()) =  r;

    return true;
}

#endif //MATRIXMODEL_H
