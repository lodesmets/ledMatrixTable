#ifndef APPLICATIONBASE_H
#define APPLICATIONBASE_H

#include <QObject>
#include <QTimer>
#include "ws2811.h"
#include <QHash>
#include <QVector>
#include <QString>
#include "settings"

enum directionEnum {NONE,LEFT,RIGHT,UP,DOWN,UPLEFT,UPRIGHT,DOWNLEFT,DOWNRIGHT};

struct scrollText
{
    int x;
    int y;
    int length;
    int height;
    ws2811_led_t color;
    directionEnum direction;
    QString text;
};

class applicationBase : public QObject
{
    Q_OBJECT
public:
    applicationBase(QObject *parent,ws2811_led_t *ledMatrix);
    ~applicationBase();
    void start();
    void stop();
    virtual void inputReceived(QStringList input) = 0;

private:
    QTimer *timer;
    QList<scrollText *> scrollingText;
    QHash<QChar,QVector<QVector<bool>>> fontSmall;
    QHash<QChar,QVector<QVector<bool>>> fontBig;
    void createSmallFont();
    void createBigFont();


protected:
    uchar fps;
    ws2811_led_t *matrix;
    void drawRectangle(uchar x1, uchar y1, uchar x2, uchar y2, ws2811_led_t color);
    void clear();
    void stopShowingText();
    int textShowing();
    void drawText(int x1, int y1, QString text, ws2811_led_t color, bool small=false);
    void drawChar(int x1, int y1, QChar text, ws2811_led_t color, bool small=false);
    void addText(int x1, int y1, QString text, ws2811_led_t color, directionEnum direction=NONE, bool small=false);

signals:

private slots:
    virtual void tick() = 0;


protected slots:
    void move();
};

#endif // APPLICATIONBASE_H
