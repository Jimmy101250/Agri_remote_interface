#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>
//游戏手柄控制
#include <QGamepad>
#include <QGamepadManager>

//ros控制必要的头文件
#include "stdafx.h"
#include <string>
#include <stdio.h>
#include "ros.h"
#include <windows.h>

#include <novatel_gps_msgs/Gpgga.h>//gps数据格式
#include <novatel_gps_msgs/NovatelDualAntennaHeading.h>//航向角格式

// 进程/网页控制
#include <QThread>
#include <QWebEngineView>
#include <QtWebChannel>

#include <QTimer>

// 接收数据包/twist格式测试/发送手柄数据
#include "receivemessage.h"
#include "twistfortest.h"
#include "sendhandshankmessage.h"

#include "generatetracepoint.h"


//高斯投影坐标系
struct PointOrig
{
    int x = 0;
    int y = 0;
};
Q_DECLARE_METATYPE(PointOrig);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resetCoor(double a[4][2]);//重置标记物坐标
    void resetPointOrig();//重置结构体

    //6度带宽 54年北京坐标系
    void GaussProjCal(double , double );//经纬度---大地坐标
    void GaussProjInvCal(int X, int Y );//大地坐标---经纬度

    PointOrig pointOrig[4];
    //手柄数据显示
    void gamepadMsgShowInWindow();
    //手动输入框的计算按钮
    void caculateFromLineEdit();
    //坐标转经纬度
    void origToLatLon();
    //赋值给generatePoints
    void g_T_Points();

    //记录日志文件
    void readLogFile();

public slots:
    void getCoordinates(double ,double );//从地图获得坐标

signals:
    void tellJsToCleanMark();
    void sendCoordinates(double,double);//给地图发送坐标

    void sendCoorNJUST(double,double);
    void sendCoorWheatField(double,double);

    //----------与ros的数据交互
    void startReceive(QString,int);//接收坐标和航向角数据
    void startTwist(int );
    //void startGamepadTest();

    //传递手柄数据
    void sendGamepadMsgToClass(QVariant);

    //给地图发送坐标用来绘图
    void sendLonLats(int, double, double);
    void sendLonLatCounts(int);
    void tellJsToCleanLines();
    //给路径规划类发送文件名称
    void sendFileName(QString str);
    //给地图发送log坐标来绘图
    void tellJsToCleanLinesLog();
    void sendLonLatsLog(int, double, double);
protected:
    void resizeEvent(QResizeEvent *);//界面大小重置

private slots:

    void showCoorDinates();
    //void showPointOrig();

    //void on_buttonSure_clicked();
    void on_buttonClearMark_clicked();
    //----------与ros的数据交互
    void on_pushButton_clicked();
    void twistMsgShow(QVariant);
    void gpggaMsgShow(QVariant);
    void ndahMsgShow(QVariant);
    void on_buttonRecAll_clicked();//接收全部——gpgga ndah


    //改变地图位置到南理工
    void on_buttonPosToNUST_clicked();
    //改变地图位置到艾津稻田
    void on_buttonPosToWheatField_clicked();

    void on_buttonDraw_clicked();

    void on_buttonPathPlan_clicked();
    
    void on_buttonSureFromHand_clicked();

    void on_buttonSure_clicked();

    void on_buttonCleanLine_clicked();

    void on_logButton_clicked();

    void logFile();

    void on_buttonLogPause_clicked();

    void on_buttonLogDraw_clicked();

    void on_buttonOpenLogFile_clicked();

    void on_buttonCleanLogLine_clicked();



private:
    Ui::MainWindow *ui;

    QWebEngineView *mapView;
    QWebChannel *channel;
    double myCoordinates[4][2];//接收到的标记物坐标
    int dataForPath[4][2];
    //----------与ros的数据交互
    //接收Gpgga和NADH信息
    ReceiveMessage *receiveMessage;
    QThread *threadReceive;
    //twist测试
    TwistForTest *twistMsg;
    QThread *threadTwist;

    //发送手柄数据类-------------------
    SendHandShankMessage *sendGamepad;
    QThread *threadSendHandShank;

    QVariant variantGamepad;
    QGamepad *myGamepad;

    //绘图相关 包括 反转坐标 给地图发送坐标
    double tracePoint[10000][2] = {0};
    double lonLatPoint[10000][2] = {0};
    int pointCount = 0;
    
    int mutex = 0;

    QImage resultImg_GamepadLeft1;
    QImage resultImg_GamepadDown1;
    QImage resultImg_GamepadRight1;
    QImage resultImg_GamepadUp1;
    QImage resultImg_GamepadLeft;
    QImage resultImg_GamepadDown;
    QImage resultImg_GamepadRight;
    QImage resultImg_GamepadUp;

    GenerateTracepoint *generateTracepoint;

    //行驶路线日志
    FILE * LogFile;
    QTimer *timer;
    char* charLogFileName;
    char* charDrawLogFileName;
    QString strLogFilename;
    double logLon,logLat;
    double logTracePoint[10000][2] = {0};

    double logGps[2];


};

#endif // MAINWINDOW_H
