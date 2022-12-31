#ifndef TWISTFORTEST_H
#define TWISTFORTEST_H

#include <QObject>
#include "stdafx.h"
#include <string>
#include <stdio.h>
#include "ros.h"
#include <geometry_msgs/Twist.h>
#include <windows.h>
#include <QMetaType>
#include <QVariant>
#include <QThread>
#include <QMutex>

//#ifndef twistDATA
struct TwistDATA
{
    double lineX;
    double lineY;
    double lineZ;
    double AngX;
    double angY;
    double angZ;
};
Q_DECLARE_METATYPE(TwistDATA);
//#define TwistDATA
//#endif

class TwistForTest : public QObject
{
    Q_OBJECT

public:
    explicit TwistForTest(QObject *parent = nullptr);
    void stopThread();
    void continueThread();

signals:
    void TwistDataOut(QVariant);

public slots:
    void startTwist(int );
private:
    QMutex pause;



};

#endif // TWISTFORTEST_H
