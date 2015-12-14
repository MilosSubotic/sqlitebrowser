#include "ColoringDelegate.h"

#include <QFileInfo>

ColoringDelegate::ColoringDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{

}

void ColoringDelegate::initStyleOption(QStyleOptionViewItem *option,
                            const QModelIndex &index) const
{
    QStyledItemDelegate::initStyleOption(option, index);

    QString columnName = index.model()->headerData(index.column(), Qt::Horizontal, Qt::DisplayRole).toString();
    if(columnName == "File")
    {
        QString fileName = index.data().toString();
        QFileInfo fi(rootDir, fileName);
        if(!fi.isFile())
        {
            QStyleOptionViewItemV4 *optionV4 = qstyleoption_cast<QStyleOptionViewItemV4*>(option);
            optionV4->backgroundBrush = QBrush(Qt::red);
        }
    }
}
