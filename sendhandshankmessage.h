#ifndef SENDHANDSHANKMESSAGE_H
#define SENDHANDSHANKMESSAGE_H

#include <QObject>
#include "stdafx.h"
#include <string>
#include <stdio.h>
#include "ros.h"
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <windows.h>
#include <QVariant>

//游戏手柄
//struct GamePad_Number
//{
//    double upAndDown;
//    double leftAndRight;
//    int buttonY;
//    int buttonX;
//};
//Q_DECLARE_METATYPE(GamePad_Number);
//GamePad_Number gamepadNum;

class SendHandShankMessage : public QObject
{
    Q_OBJECT
public:
    explicit SendHandShankMessage(QObject *parent = nullptr);

    void setUpDownValue(double a);
    void setLeftRightValue(double b);
    void setButtonXValue(int a);
    void setButtonYValue(int b);

    double getUpDownValue();
    double getLeftRightValue();
    int getButtonXValue();
    int getButtonYValue();

signals:

public slots:
    void sendMessagesToRos(QString );
    //void receiveGamepadValueFromMain(QVariant);

protected:

private:
    //GamePad_Number gamepadValue;
    double upAndDown;
    double leftAndRight;
    int buttonY;
    int buttonX;
};
#endif // SENDHANDSHANKMESSAGE_H
