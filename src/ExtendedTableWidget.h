#ifndef EXTENDEDTABLEWIDGET_H
#define EXTENDEDTABLEWIDGET_H

#include <QTableView>
#include "FilterTableHeader.h"
#include <QSet>
#include <QDir>

class ColoringDelegate;

class ExtendedTableWidget : public QTableView
{
    Q_OBJECT

public:
    explicit ExtendedTableWidget(QWidget* parent = 0);

    FilterTableHeader* filterHeader() { return m_tableHeader; }

public:
    QSet<int> selectedCols();
    void setRootDir(const QDir &rootDir);

signals:
    void foreignKeyClicked(const QString& table, const QString& column, const QByteArray& value);

private:
    void copy();
    void paste();
    void erase();
    void selectFile();
    void openFile();
    int numVisibleRows();

private slots:
    void vscrollbarChanged(int value);
    void cellClicked(const QModelIndex& index);

protected:
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void updateGeometries();

    FilterTableHeader* m_tableHeader;
    ColoringDelegate* delegate;
    QDir rootDir;
    QDir lastDir;
};

#endif
