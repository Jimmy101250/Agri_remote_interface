#include "receivemessage.h"
#include <QDebug>
//存数据的结构体
Struct_Gpgga_Msg outGpggaMsg;
QVariant variantGpgga;
Struct_NDAH_Msg outNDAHMsg;
QVariant variantNDAH;
novatel_gps_msgs::NovatelPosition novPositionMsg;
novatel_gps_msgs::Gpgga gpggaMsg;
novatel_gps_msgs::NovatelDualAntennaHeading novDuaAntHeadingMsg;

//NovatelPosition回调函数
void cmd_position_callback(const novatel_gps_msgs::NovatelPosition &bestpos)
{
   //qDebug("经纬度：%.10f, %.10f,%.10f,高度：%.10f", gpgga.lat, gpgga.lon,gpgga.alt);
   //qDebug()<<"position lat"<<bestpos.lat;
   //qDebug()<<"position lon"<<bestpos.lon;
   outGpggaMsg.lat = bestpos.lat;
   outGpggaMsg.lon = bestpos.lon;
   variantGpgga.setValue(outGpggaMsg);
   novPositionMsg = bestpos;
}

 //Gpgga回调函数
 void cmd_gpgga_callback(const novatel_gps_msgs::Gpgga &gpgga)
{
    //qDebug("经纬度：%.10f, %.10f,%.10f,高度：%.10f", gpgga.lat, gpgga.lon,gpgga.alt);

    outGpggaMsg.alt = gpgga.alt;
    variantGpgga.setValue(outGpggaMsg);
    gpggaMsg = gpgga;
}
//NovatelDualAntennaHeading回调函数
 void cmd_NDAH_callback(const novatel_gps_msgs::NovatelDualAntennaHeading &dual_antenna_heading)
{
    //float head = dual_antenna_heading.heading;
    //qDebug() <<"heading:"<< dual_antenna_heading.heading<<" " <<"pitch:"<< dual_antenna_heading.pitch<<endl;
    outNDAHMsg.heading = dual_antenna_heading.heading;
    outNDAHMsg.pitch = dual_antenna_heading.pitch;
    variantNDAH.setValue(outNDAHMsg);
    novDuaAntHeadingMsg = dual_antenna_heading;
}

ReceiveMessage::ReceiveMessage(QObject *parent) : QObject(parent)
{
    qDebug()<<"receive message";
}
//从Ros接收数据
//槽函数从主函数接收农机车IP地址
void ReceiveMessage::receiveFromRos(QString str,int mutex)
{
    ros::NodeHandle nh;
    QString ipString = str;
    qDebug()<<str;
    char* ros_master;
    //将string转化为char*
    QByteArray tempStrtoChars = ipString.toLatin1();
    ros_master = tempStrtoChars.data();
    printf("正在连接 %s\n", ros_master);
    nh.initNode(ros_master);
    //订阅NovalPosition
    ros::Subscriber <novatel_gps_msgs::NovatelPosition >
            posSubPosition("bestpos", &cmd_position_callback);
    nh.subscribe(posSubPosition);
    //订阅Gpgga

    ros::Subscriber <novatel_gps_msgs::Gpgga >
            posSubGpgga("gpgga", &cmd_gpgga_callback);
    nh.subscribe(posSubGpgga);

    //订阅NovatelDualAntennaHeading
    ros::Subscriber <novatel_gps_msgs::NovatelDualAntennaHeading >
            posSubNDAH("dual_antenna_heading", &cmd_NDAH_callback);
    nh.subscribe(posSubNDAH);

    qDebug()<<"等待接收消息";
    qDebug()<<"转发cmd_vel_winpc消息";

    ros::Publisher cmd_vel_pub_NovPosition("cmd_vel_winpc_0", &novPositionMsg);
    ros::Publisher cmd_vel_pub_Gpgga("cmd_vel_winpc_1", &gpggaMsg);
    ros::Publisher cmd_vel_pub_NDAH("cmd_vel_winpc_2", &novDuaAntHeadingMsg);
    nh.advertise(cmd_vel_pub_NovPosition);
    nh.advertise(cmd_vel_pub_Gpgga);
    nh.advertise(cmd_vel_pub_NDAH);

    while (1)
    {
//        qDebug()<<"mutex"<<mutex;
//        if(mutex == 0)
//        {
//            break;
//        }
        cmd_vel_pub_NovPosition.publish(&novPositionMsg);
        cmd_vel_pub_Gpgga.publish(&gpggaMsg);
        cmd_vel_pub_NDAH.publish(&novDuaAntHeadingMsg);
        emit sendNDAHToMainWindow(variantNDAH);
        emit sendGpggaToMainWindow(variantGpgga);
        nh.spinOnce();
        Sleep(10);
    }
    qDebug("rece5ve All done!\n");
}
