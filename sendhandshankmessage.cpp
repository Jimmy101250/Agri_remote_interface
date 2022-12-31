#include "sendhandshankmessage.h"
#include <QDebug>


//geometry_msgs::Twist twist_msg_Send;


SendHandShankMessage::SendHandShankMessage(QObject *parent) : QObject(parent)
{
    upAndDown = 0;
    leftAndRight = 0;
    buttonX = 0;
    buttonY = 0;
}
void SendHandShankMessage::setUpDownValue(double a)
{
    upAndDown = a;
}
void SendHandShankMessage::setLeftRightValue(double b)
{
    leftAndRight = b;
}
void SendHandShankMessage::setButtonXValue(int a)
{
    buttonX = a;
}
void SendHandShankMessage::setButtonYValue(int b)
{
    buttonY = b;
}
double SendHandShankMessage::getUpDownValue()
{
    return upAndDown;
}
double SendHandShankMessage::getLeftRightValue()
{
    return leftAndRight;
}
int SendHandShankMessage::getButtonXValue()
{
    return buttonX;
}
int SendHandShankMessage::getButtonYValue()
{
    return buttonY;
}


void SendHandShankMessage::sendMessagesToRos(QString str)
{
    ros::NodeHandle nh1;
    QString ipString = str;
    qDebug()<<"in gamepad"<<str;
    char* ros_master;
    //将string转化为char*
    QByteArray tempStrtoChars = ipString.toLatin1();
    ros_master = tempStrtoChars.data();


    printf("Connecting to server at %s\n", ros_master);
    nh1.initNode(ros_master);


    printf("Advertising cmd_vel message\n");
    geometry_msgs::Twist twist_msg;
    ros::Publisher cmd_vel_pub("cmd_vel", &twist_msg);
    nh1.advertise(cmd_vel_pub);

    printf("Go robot go!\n");
    while (1)
    {
        twist_msg.linear.x = upAndDown;
        twist_msg.linear.y = buttonX;
        twist_msg.linear.z = buttonY;
        twist_msg.angular.x = 0;
        twist_msg.angular.y = 0;
        twist_msg.angular.z = leftAndRight;
        cmd_vel_pub.publish(&twist_msg);

        nh1.spinOnce();
        Sleep(100);
    }

    printf("ga0e*ad All done!\n");

}



