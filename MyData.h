#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>
#include <QString>
#include <QStringList>

class MyData : public QObject
{
    Q_OBJECT
public:
    explicit MyData(QObject *parent = 0);
    ~MyData();
    enum Type
    {
        Name,
        Book,
    };
    static MyData* singleton();
    static void resetNameData();
    static void resetBookData();
signals:
    void dataChanged(Type type);
public slots:

public:
    static QStringList m_name;
    static QStringList m_book;
private:
    static MyData *m_instance;
};

#endif // MYDATA_H
