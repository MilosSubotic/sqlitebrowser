#ifndef COLORINGDELEGATE_H
#define COLORINGDELEGATE_H

#include <QStyledItemDelegate>
#include <QDir>

class ColoringDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit ColoringDelegate(QObject *parent = 0);

public:
    void setRootDir(const QDir &rootDir){ this->rootDir = rootDir; }

protected:
    virtual void initStyleOption(QStyleOptionViewItem *option,
                                const QModelIndex &index) const;

private:
    QDir rootDir;

};

#endif
