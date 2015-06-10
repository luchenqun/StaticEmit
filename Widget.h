#ifndef WIDGET_H
#define WIDGET_H

#include "MyData.h"
#include <QWidget>
#include <QListWidget>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void dataRand();
    void updateWidget(MyData::Type type);
private:
    QTimer *m_timer;
    QListWidget *m_listWidgetName;
    QListWidget *m_listWidgetBook;
};

#endif // WIDGET_H
