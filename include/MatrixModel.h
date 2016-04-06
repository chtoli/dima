#ifndef MATRIXMODEL_H
#define MATRIXMODEL_H
#include "matrix.h"
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>
#include <QObject>
#include <QDebug>


template<typename T>
class MatrixModel : public QAbstractTableModel {
public:
    MatrixModel(dima::matrix<T> m)
        : m_rows(m.get_rows()), m_columns(m.get_columns()), m(m) {
        std::cout << "Matrix has " << m_rows << " rows and " << m_columns
                  << " columns with data " << std::endl << m << std::endl;
    }
		
    int rowCount(const QModelIndex& parent = QModelIndex()) const;

    int columnCount(const QModelIndex& parent = QModelIndex()) const;
	
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	
private:
	int m_rows;
	int m_columns;
	dima::matrix<T> m;
};



template<typename T>
int MatrixModel<T>::rowCount(const QModelIndex& parent) const {
    return m_rows;
}

template<typename T>
int MatrixModel<T>::columnCount(const QModelIndex& /* parent */) const {
    return m_columns;
}

template<typename T>
QVariant MatrixModel<T>::data(const QModelIndex& index, int role) const {
    std::cout << "data method called";
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();
    //return the data to which the index points
    return QString::number(m(index.row(), index.column()));
}


#endif //MATRIXMODEL_H
