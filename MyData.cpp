#include "MyData.h"
#include <QDebug>

QStringList MyData::m_name = QStringList();
QStringList MyData::m_book = QStringList();
MyData* MyData::m_instance = NULL;

MyData::MyData(QObject *parent) : QObject(parent)
{
}

MyData::~MyData()
{
}

MyData* MyData::singleton()
{
    // 两种方式均可
#if 0
    if (m_instance == NULL)
    {
        m_instance = new MyData();
    }
    return m_instance;
#else
    static MyData myData;
    return &myData;
#endif
}

void MyData::resetNameData()
{
    m_name.clear();
    int cnt = rand() % 20;
    for(int i = 0; i < cnt; i++)
    {
        m_name.append("name_" + QString::number(rand()));
    }
    emit singleton()->dataChanged(Name);
}

void MyData::resetBookData()
{
    m_book.clear();
    int cnt = rand() % 20;
    for(int i = 0; i < cnt; i++)
    {
        m_book.append("book_" + QString::number(rand()));
    }
    emit singleton()->dataChanged(Book);
}
