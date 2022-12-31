#include "twistfortest.h"
#include <QtDebug>
geometry_msgs::Twist twist_msg;
TwistDATA data;
QVariant varient;

 void cmd_vel_angular_callback(const geometry_msgs::Twist & cmd_vel)
{
    //qDebug("接收ros cmd_vel %f, %f, %f, %f, %f, %f\n",
    //cmd_vel.linear.x, cmd_vel.linear.y, cmd_vel.linear.z,
    //cmd_vel.angular.x, cmd_vel.angular.y, cmd_vel.angular.z);
    data.AngX = cmd_vel.angular.x;
    data.angY = cmd_vel.angular.y;
    data.angZ = cmd_vel.angular.z;
    data.lineX = cmd_vel.linear.x;
    data.lineY = cmd_vel.linear.y;
    data.lineZ = cmd_vel.linear.z;
    //qDebug()<<data.AngX<<data.angY<<data.angZ<<"vv"<<data.lineX<<data.lineY<<data.lineZ;
    varient.setValue(data);

    twist_msg = cmd_vel;

}
TwistForTest::TwistForTest(QObject *parent) : QObject(parent)
{

}
void TwistForTest::startTwist(int hello)
{
    qDebug()<<"get in startTwist";
    ros::NodeHandle nh;

    QString ipString = "192.168.1.200";
    char* ros_master;
    //将string转化为char*
    QByteArray tempStrtoChars = ipString.toLatin1();
    ros_master = tempStrtoChars.data();

    qDebug("正在连接 %s\n", ros_master);
    nh.initNode(ros_master);

    ros::Subscriber < geometry_msgs::Twist >
            poseSub("cmd_vel", &cmd_vel_angular_callback);
    nh.subscribe(poseSub);
    qDebug("等待接受消息\n");

    qDebug("转发cmd_vel_winpc消息 \n");
    ros::Publisher cmd_vel_pub("cmd_vel_winpc", &twist_msg);
    nh.advertise(cmd_vel_pub);
    int i = 0;
    while (1)
    {
        if(hello == 0)
        {
            break;
        }
        pause.lock();
        i++;
        qDebug()<<"while"<<i;

        cmd_vel_pub.publish(&twist_msg);
        emit TwistDataOut(varient);
        nh.spinOnce();
        Sleep(100);

        pause.unlock();

        if(QThread::currentThread()->isInterruptionRequested())
        {
            qDebug()<<"isInterruptionRequested";
            break;
        }
    }
    qDebug("All done!\n");
}
void TwistForTest::stopThread()
{
    pause.lock();
}
void TwistForTest::continueThread()
{
    pause.unlock();
}

