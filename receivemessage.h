#ifndef RECEIVEMESSAGE_H
#define RECEIVEMESSAGE_H

#include <QObject>
#include <QVariant>
#include "stdafx.h"
#include <string>
#include <stdio.h>
#include "ros.h"
#include <novatel_gps_msgs/NovatelPosition.h>
#include <novatel_gps_msgs/Gpgga.h>
#include <novatel_gps_msgs/NovatelDualAntennaHeading.h>
#include <windows.h>


struct Struct_Gpgga_Msg
{
    double lat;
    double lon;
    double alt;
};
Q_DECLARE_METATYPE(Struct_Gpgga_Msg);
struct Struct_NDAH_Msg
{
    double heading;
    double pitch;
};
Q_DECLARE_METATYPE(Struct_NDAH_Msg);
class ReceiveMessage : public QObject
{
    Q_OBJECT
public:
    explicit ReceiveMessage(QObject *parent = nullptr);

signals:
    emit void sendGpggaToMainWindow(QVariant);
    emit void sendNDAHToMainWindow(QVariant);

public slots:
    void receiveFromRos(QString ,int );
};

#endif // RECEIVEMESSAGE_H
