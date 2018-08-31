#ifndef FONTS_H
#define FONTS_H

#include <QHash>
#include <QVector>
#include <QString>


class fonts
{
public:
    fonts();

private:
    QHash<QString,QVector<QVector<bool>>> fontSmall;
    QHash<QString,QVector<QVector<bool>>> fontBig;
};

#endif // FONTS_H
