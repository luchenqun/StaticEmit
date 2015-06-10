#include "Widget.h"
#include "MyData.h"
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(3000);
    m_timer->start();

    m_listWidgetName = new QListWidget(this);
    m_listWidgetBook = new QListWidget(this);

    m_listWidgetName->addItem("nameInit");
    m_listWidgetBook->addItem("booInit");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_listWidgetName);
    mainLayout->addWidget(m_listWidgetBook);

    this->setLayout(mainLayout);

    connect(m_timer, &QTimer::timeout, this, &Widget::dataRand);
    connect(MyData::singleton(), &MyData::dataChanged, this, &Widget::updateWidget);
}

Widget::~Widget()
{
    delete m_timer;
}

void Widget::dataRand()
{
    (rand() % 2) ? (MyData::resetNameData()) : (MyData::resetBookData());
}

void Widget::updateWidget(MyData::Type type)
{
    switch (type)
    {
    case MyData::Name:
        m_listWidgetName->clear();
        m_listWidgetName->addItems(MyData::m_name);
        break;
    case MyData::Book:
        m_listWidgetBook->clear();
        m_listWidgetBook->addItems(MyData::m_book);
        break;
    default:
        break;
    }
}
