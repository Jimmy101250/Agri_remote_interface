#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMovie>
#include <QTimer>
#include <QFile>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    logGps[0] = 1.0009999999;
    logGps[1] = 2.0009999999;

    //-----一些初始化操作
    resetCoor(myCoordinates);//先重置一下4个标记物坐标
    ui->widget->setStyleSheet("background-color:black;");//可写可不写
    QString str1 =QStringLiteral("手柄已连接");
    QString str2 = QString(QStringLiteral("手柄未连接"));;
    QFont font1( "Microsoft YaHei",14,75);
    QFont font2( "Microsoft YaHei",10,55);
    ui->labelGamepadState->setFont(font1);
    //ui->labelGamepadControl->setFont(font1);
//    ui->labelGamepadX->setFont(font2);
//    ui->labelGamepadY->setFont(font2);
//    ui->labelGamepadX_2->setFont(font2);
//    ui->labelGamepadY_2->setFont(font2);

    //手柄未连接图片
    QImage imageGameP_Dis;
    imageGameP_Dis.load("./Pictures/GamepadDisconnected");
    QPainter painter(&imageGameP_Dis);
    QImage resultImg_G_P_Dis = imageGameP_Dis.scaled(ui->labelGamepadState->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);

    //手柄连接图片
    QImage imageGameP_Con;
    imageGameP_Con.load("./Pictures/GamepadConnected");
    QPainter painter_1(&imageGameP_Con);
    QImage resultImg_G_P_Con = imageGameP_Con.scaled(ui->labelGamepadState->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //Gif
    QSize size(ui->labelGifLocal->size());
    QMovie *movie = new QMovie("./Pictures/gifMapLocal.gif");
    ui->labelGifLocal->setMovie(movie);
    movie->setScaledSize(size);
    movie->start();

    QImage imageGameNUST;
    imageGameNUST.load("./Pictures/MapIcon.png");
    QPainter painter_2(&imageGameNUST);
    QImage resultImg_NUST = imageGameNUST.scaled(ui->buttonPosToNUST->width(),ui->buttonPosToNUST->width(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->buttonPosToNUST->setIcon(QPixmap::fromImage(resultImg_NUST));
    ui->buttonPosToNUST->setText(QStringLiteral("NJUST"));

    QImage imageGameWheatField;
    imageGameWheatField.load("./Pictures/MapIcon.png");
    QPainter painter_3(&imageGameWheatField);
    QImage resultImg_WheatField = imageGameWheatField.scaled(ui->buttonPosToNUST->width(),ui->buttonPosToNUST->width(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->buttonPosToWheatField->setIcon(QPixmap::fromImage(resultImg_WheatField));
    ui->buttonPosToWheatField->setText(QStringLiteral("Wheat field"));

    QImage imageGamepadSphere;
    imageGamepadSphere.load("./Pictures/sphere.png");
    QPainter painterGamepadSphere(&imageGamepadSphere);
    QImage resultImg_GamepadSphere = imageGamepadSphere.scaled(ui->labelPicGpShpere->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->labelPicGpShpere->setPixmap(QPixmap::fromImage(resultImg_GamepadSphere));

    QImage imageGamepadUp;
    imageGamepadUp.load("./Pictures/up2.png");
    QPainter painterGamepadUp(&imageGamepadUp);
    resultImg_GamepadUp = imageGamepadUp.scaled(ui->labelPicUp->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->labelPicUp->setPixmap(QPixmap::fromImage(resultImg_GamepadUp));

    QImage imageGamepadDown;
    imageGamepadDown.load("./Pictures/down2.png");
    QPainter painterGamepadDown(&imageGamepadDown);
    resultImg_GamepadDown = imageGamepadDown.scaled(ui->labelPicDown->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->labelPicDown->setPixmap(QPixmap::fromImage(resultImg_GamepadDown));

    QImage imageGamepadLeft;
    imageGamepadLeft.load("./Pictures/left2.png");
    QPainter painterGamepadLeft(&imageGamepadLeft);
    resultImg_GamepadLeft = imageGamepadLeft.scaled(ui->labelPicLeft->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->labelPicLeft->setPixmap(QPixmap::fromImage(resultImg_GamepadLeft));

    QImage imageGamepadRight;
    imageGamepadRight.load("./Pictures/right2.png");
    QPainter painterGamepadRight(&imageGamepadRight);
    resultImg_GamepadRight = imageGamepadRight.scaled(ui->labelPicRight->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->labelPicRight->setPixmap(QPixmap::fromImage(resultImg_GamepadRight));

    QImage imageGamepadUp1;
    imageGamepadUp1.load("./Pictures/up1.png");
    QPainter painterGamepadUp1(&imageGamepadUp1);
    resultImg_GamepadUp1 = imageGamepadUp1.scaled(ui->labelPicUp->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //ui->labelPicUp->setPixmap(QPixmap::fromImage(resultImg_GamepadUp1));

    QImage imageGamepadDown1;
    imageGamepadDown1.load("./Pictures/down1.png");
    QPainter painterGamepadDown1(&imageGamepadDown1);
    resultImg_GamepadDown1 = imageGamepadDown1.scaled(ui->labelPicDown->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //ui->labelPicDown->setPixmap(QPixmap::fromImage(resultImg_GamepadDown1));

    QImage imageGamepadLeft1;
    imageGamepadLeft1.load("./Pictures/left1.png");
    QPainter painterGamepadLeft1(&imageGamepadLeft1);
    resultImg_GamepadLeft1 = imageGamepadLeft1.scaled(ui->labelPicLeft->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //ui->labelPicLeft->setPixmap(QPixmap::fromImage(resultImg_GamepadLeft1));

    QImage imageGamepadRight1;
    imageGamepadRight1.load("./Pictures/right1.png");
    QPainter painterGamepadRight1(&imageGamepadRight1);
    resultImg_GamepadRight1 = imageGamepadRight1.scaled(ui->labelPicRight->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //ui->labelPicRight->setPixmap(QPixmap::fromImage(resultImg_GamepadRight1));
    //---------------
    myGamepad = new QGamepad(0,this);

    //先检测手柄是否连接
    if(myGamepad->isConnected() == true)
    {
        //ui->labelGamepadState->setText(str1);
        ui->labelGamepadState->setPixmap(QPixmap::fromImage(resultImg_G_P_Con));
    }
    else
    {
        ui->labelGamepadState->setText(str2);
        ui->labelGamepadState->setPixmap(QPixmap::fromImage(resultImg_G_P_Dis));
    }
    //如果中途连接状态改变
    connect(myGamepad,&QGamepad::connectedChanged,this,[=]()
    {
        if(myGamepad->isConnected() == true)
        {
            //ui->labelGamepadState->setText(str1);
            ui->labelGamepadState->setPixmap(QPixmap::fromImage(resultImg_G_P_Con));
        }
        else
        {
            //ui->labelGamepadState->setText(str2);
            ui->labelGamepadState->setPixmap(QPixmap::fromImage(resultImg_G_P_Dis));
        }
    });
    //手柄按键改变
    connect(myGamepad,&QGamepad::axisRightXChanged,this,[=]()
    {
        double temp1 = 0;
        if(myGamepad->axisRightX() > 0.99)
        {
            temp1 = 1;
        }
        else if(myGamepad->axisRightX() < -0.99)
        {
            temp1 = -1;
        }
        else if(myGamepad->axisRightX() > -0.001 && myGamepad->axisRightX() < 0.001)
        {
            temp1 = 0;
        }
        else
        {
            temp1 = myGamepad->axisRightX();
        }
        sendGamepad->setLeftRightValue(temp1);
        gamepadMsgShowInWindow();

    });
    connect(myGamepad,&QGamepad::axisLeftYChanged,this,[=]()
    {
        double temp = 0;
        if(myGamepad->axisLeftY() > 0.99)
        {
            temp = 1;
        }
        else if(myGamepad->axisLeftY() < -0.99)
        {
            temp = -1;
        }
        else if(myGamepad->axisLeftY() > -0.001 && myGamepad->axisLeftY() < 0.001)
        {
            temp = 0;
        }
        else
        {
            temp = myGamepad->axisLeftY();
        }
        sendGamepad->setUpDownValue(temp);
        gamepadMsgShowInWindow();

    });
    connect(myGamepad,&QGamepad::buttonYChanged,this,[=]
    {
        if(myGamepad->buttonY())
        {
            sendGamepad->setButtonXValue(0);
            sendGamepad->setButtonYValue(1);
            gamepadMsgShowInWindow();
        }
    });
    connect(myGamepad,&QGamepad::buttonXChanged,this,[=]
    {
        if(myGamepad->buttonX())
        {
            sendGamepad->setButtonXValue(1);
            sendGamepad->setButtonYValue(0);
            gamepadMsgShowInWindow();
        }
    });

    //-------------连接至js 使地图通过widget显示出来
    mapView = new QWebEngineView(ui->widget);

    QDir htmlDir("./map/map.html");

    QString str = htmlDir.absolutePath();
    qDebug()<<str;

    channel=new QWebChannel(this);//这句应该放在类的私有部分，便于析构
    channel->registerObject(QString("person"),this);//注册一个通道，成为js下的window.bridge

    mapView->page()->load(QUrl(QString("file:///%0").arg(str)));
    mapView->page()->setWebChannel(channel); //webEngine加载channel功能
    mapView->show();
    //-------------

    //接收数据子线程
    receiveMessage = new ReceiveMessage;
    threadReceive = new QThread(this);
    receiveMessage->moveToThread(threadReceive);
    connect(threadReceive,&QThread::finished,receiveMessage,&ReceiveMessage::deleteLater);
    connect(this,&MainWindow::startReceive,receiveMessage,&ReceiveMessage::receiveFromRos);
    threadReceive->start();
    qDebug()<<receiveMessage->thread();
    qDebug()<<threadReceive->thread();
    qDebug()<<"this"<<this->thread();

    //Twist测试线程
    twistMsg = new TwistForTest;
    threadTwist = new QThread(this);
    twistMsg->moveToThread(threadTwist);
    threadTwist->start();
    qDebug()<<twistMsg->thread();
    qDebug()<<threadTwist->thread();
    connect(threadTwist,&QThread::finished,twistMsg,&TwistForTest::deleteLater);
    connect(this,&MainWindow::startTwist,twistMsg,&TwistForTest::startTwist);

    //显示数据信号-槽（从Twist输出信号至主线程）
    connect(twistMsg,&TwistForTest::TwistDataOut,this,&MainWindow::twistMsgShow);
    //显示数据信号-槽（从Gpgga输出信号至主线程）
    connect(receiveMessage,&ReceiveMessage::sendGpggaToMainWindow,this,&MainWindow::gpggaMsgShow);
    //显示数据信号-槽（从NDAH输出信号至主线程）
    connect(receiveMessage,&ReceiveMessage::sendNDAHToMainWindow,this,&MainWindow::ndahMsgShow);

    //------------发送手柄数据
    sendGamepad = new SendHandShankMessage;
    threadSendHandShank = new QThread(this);
    sendGamepad->moveToThread(threadSendHandShank);
    connect(threadSendHandShank,&QThread::finished,sendGamepad,&SendHandShankMessage::deleteLater);
   // connect(this,&MainWindow::startReceive,sendGamepad,&SendHandShankMessage::sendMessagesToRos);
    threadSendHandShank->start();
    //路径规划
    generateTracepoint = new GenerateTracepoint(this);
    connect(this,&MainWindow::sendFileName,generateTracepoint,&GenerateTracepoint::getFileName);

    //日志记录
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(logFile()));
}

MainWindow::~MainWindow()
{
    qDebug()<<"helloworld";

    threadReceive->requestInterruption();//请求线程中断
    threadReceive->quit();
    threadReceive->wait();

    threadTwist->requestInterruption();//请求线程中断
    threadTwist->quit();
    threadTwist->wait();

    threadSendHandShank->requestInterruption();//请求线程中断
    threadSendHandShank->quit();
    threadSendHandShank->wait();

    channel->deregisterObject(this);

    delete ui;
}
//twist数据开始接收
void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"click pushbutton twist";
    mutex = 1;
    emit startTwist(mutex);
}
//twist数据显示
void MainWindow::twistMsgShow(QVariant varient)
{
    TwistDATA data = varient.value<TwistDATA>();
    //数据显示
    ui->lineEditAngX->setText(QString::number(data.AngX));
    ui->lineEditAngY->setText(QString::number(data.angY));
    ui->lineEditAngZ->setText(QString::number(data.angZ));
    ui->lineEditLinX->setText(QString::number(data.lineX));
    ui->lineEditLinY->setText(QString::number(data.lineY));
    ui->lineEditLinZ->setText(QString::number(data.lineZ));

    //qDebug()<<"测试"<<data.AngX<<data.angY<<data.angZ<<"vv"<<data.lineX<<data.lineY<<data.lineZ;
}
//gpgga数据显示
void MainWindow::gpggaMsgShow(QVariant variant)
{
    Struct_Gpgga_Msg structgpggamsg = variant.value<Struct_Gpgga_Msg>();
    ui->lineEditAlt->setText(QString::number(structgpggamsg.alt,'g',10));
    ui->lineEditLat->setText(QString::number(structgpggamsg.lat,'g',10));
    ui->lineEditLon->setText(QString::number(structgpggamsg.lon,'g',10));
    //qDebug()<<"testgps"<<structgpggamsg.alt<<structgpggamsg.lat<<structgpggamsg.lon;
    logLon = structgpggamsg.lon;
    logLat = structgpggamsg.lat;
    logGps[0] = logLon;
    logGps[1] = logLat;
    sendCoordinates(structgpggamsg.lon,structgpggamsg.lat);
}
//ndah数据显示
void MainWindow::ndahMsgShow(QVariant variant)
{
    Struct_NDAH_Msg structndagmsg = variant.value<Struct_NDAH_Msg>();
    ui->lineEditHeading->setText(QString::number(structndagmsg.heading,'g',10));
    ui->lineEditPitch->setText(QString::number(structndagmsg.pitch,'g',10));
   // qDebug()<<"testNDAH"<<structndagmsg.heading<<structndagmsg.pitch;
}
//接收信息
void MainWindow::on_buttonRecAll_clicked()
{
    QString str = ui->lineEdi_IP->text();

    emit startReceive(str, 1);
}
//从地图获取坐标
void MainWindow::getCoordinates(double lon, double lat)
{
    //int i = 0,j = 0;
    QString strLon = QString::number(lon,'g',10);
    QString strLat = QString::number(lat,'g',10);
    qDebug()<<"receive:::"<<strLon<<" "<<strLat;
    for(int i = 0; i < 4; i++)
    {
            if(myCoordinates[i][0] != 0.0)
                continue;
            else
            {
                myCoordinates[i][0] = lon;
                myCoordinates[i][1] = lat;
                break;
            }
    }
    showCoorDinates();

}

//重置坐标
void MainWindow::resetCoor(double myCoor[4][2])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            myCoor[i][j] = 0.0;
        }
    }
}
void MainWindow::resetPointOrig()
{
    qDebug()<<"Come in resetPointOrig";
    for(int i = 0; i < 4; i++)
    {
        pointOrig[i].x = 0;
        pointOrig[i].y = 0;
    }
}
void MainWindow::on_buttonClearMark_clicked()
{
    tellJsToCleanMark();
    resetCoor(myCoordinates);
    resetPointOrig();
    showCoorDinates();
    //showPointOrig();
}

//高斯投影由经纬度(Unit:DD)反算大地坐标(含带号，Unit:Metres)
void MainWindow::GaussProjCal(double longitude, double latitude)
{

    qDebug()<<"x:"<<longitude<<"y:"<<latitude;
    for(int i = 0; i< 4; i++)
    {
        qDebug()<<"beforeCount"<<pointOrig[i].x<<pointOrig[i].y;
    }
    int ProjNo = 0; int ZoneWide; ////带宽
    double longitude1, latitude1, longitude0, latitude0, X0, Y0, xval, yval;
    double a, f, e2, ee, NN, T, C, A, M, iPI;
    iPI = 0.0174532925199433; ////3.1415926535898/180.0;
    ZoneWide = 6; ////6度带宽
    a = 6378245.0;
    f = 1.0 / 298.3; //54年北京坐标系参数
    ////a=6378140.0; f=1/298.257; //80年西安坐标系参数
    ProjNo = (int)(longitude / ZoneWide);
    longitude0 = ProjNo * ZoneWide + ZoneWide / 2;
    longitude0 = longitude0 * iPI;
    latitude0 = 0;
    longitude1 = longitude * iPI; //经度转换为弧度
    latitude1 = latitude * iPI; //纬度转换为弧度
    e2 = 2 * f - f*f;
    ee = e2*(1.0 - e2);
    NN = a / sqrt(1.0 - e2*sin(latitude1)*sin(latitude1));
    T = tan(latitude1)*tan(latitude1);
    C = ee*cos(latitude1)*cos(latitude1);
    A = (longitude1 - longitude0)*cos(latitude1);

    M = a*((1 - e2 / 4 - 3 * e2*e2 / 64 - 5 * e2*e2*e2 / 256)*latitude1 - (3 * e2 / 8 + 3 * e2*e2 / 32 + 45 * e2*e2*e2 / 1024)*sin(2 * latitude1) + (15 * e2*e2 / 256 + 45 * e2*e2*e2 / 1024)*sin(4 * latitude1) - (35 * e2*e2*e2 / 3072)*sin(6 * latitude1));
    xval = NN*(A + (1 - T + C)*A*A*A / 6 + (5 - 18 * T + T*T + 72 * C - 58 * ee)*A*A*A*A*A / 120);
    yval = M + NN*tan(latitude1)*(A*A / 2 + (5 - T + 9 * C + 4 * C*C)*A*A*A*A / 24 + (61 - 58 * T + T*T + 600 * C - 330 * ee)*A*A*A*A*A*A / 720);
    X0 = 1000000L * (ProjNo + 1) + 500000L;
    Y0 = 0;
    xval = xval + X0;
    yval = yval + Y0;

    int i = 0;
    for(i = 0; i<4; i++)
    {
        if(pointOrig[i].x == 0)
        {
            pointOrig[i].x = int (xval * 100);
            pointOrig[i].y = int (yval * 100);
            qDebug()<<"number:"<<i<<"show in for "<<pointOrig[i].x<<","<<pointOrig[i].y;
            break;
        }
    }
    for(int j = 0;j<4;j++)
    {
        qDebug()<<"afterCount"<<j<<pointOrig[j].x<<pointOrig[j].y;
    }

}

//高斯投影由大地坐标(Unit:Metres)反算经纬度(Unit:DD)
void MainWindow::GaussProjInvCal(int X, int Y)
{
    //qDebug()<<"x:"<<X<<"y:"<<Y;
    int ProjNo; int ZoneWide; ////带宽
    double longitude1, latitude1, longitude0, latitude0, X0, Y0, xval, yval;
    double e1, e2, f, a, ee, NN, T, C, M, D, R, u, fai, iPI;
    iPI = 0.0174532925199433; ////3.1415926535898/180.0;
    a = 6378245.0;
    f = 1.0 / 298.3; //54年北京坐标系参数
    ////a=6378140.0; f=1/298.257; //80年西安坐标系参数
    ZoneWide = 6; ////6度带宽
    X = X / 100;
    Y = Y / 100;
    ProjNo = (int)(X / 1000000L); //查找带号
    longitude0 = (ProjNo - 1) * ZoneWide + ZoneWide / 2;
    longitude0 = longitude0 * iPI; //中央经线
    X0 = ProjNo * 1000000L + 500000L;
    Y0 = 0;
    xval = X - X0;
    yval = Y - Y0; //带内大地坐标
    e2 = 2 * f - f*f;
    e1 = (1.0 - sqrt(1 - e2)) / (1.0 + sqrt(1 - e2));
    ee = e2 / (1 - e2);
    M = yval;
    u = M / (a*(1 - e2 / 4 - 3 * e2*e2 / 64 - 5 * e2*e2*e2 / 256));
    fai = u + (3 * e1 / 2 - 27 * e1*e1*e1 / 32)*sin(2 * u) + (21 * e1*e1 / 16 - 55 * e1*e1*e1*e1 / 32)*sin(4 * u) + (151 * e1*e1*e1 / 96)*sin(6 * u) + (1097 * e1*e1*e1*e1 / 512)*sin(8 * u);
    C = ee*cos(fai)*cos(fai);
    T = tan(fai)*tan(fai);
    NN = a / sqrt(1.0 - e2*sin(fai)*sin(fai));
    R = a*(1 - e2) / sqrt((1 - e2*sin(fai)*sin(fai))*(1 - e2*sin(fai)*sin(fai))*(1 - e2*sin(fai)*sin(fai)));
    D = xval / NN;
    //计算经度(Longitude) 纬度(Latitude)
    longitude1 = longitude0 + (D - (1 + 2 * T + C)*D*D*D / 6 + (5 - 2 * C + 28 * T - 3 * C*C + 8 * ee + 24 * T*T)*D*D*D*D*D / 120) / cos(fai);
    latitude1 = fai - (NN*tan(fai) / R)*(D*D / 2 - (5 + 3 * T + 10 * C - 4 * C*C - 9 * ee)*D*D*D*D / 24+ (61 + 90 * T + 298 * C + 45 * T*T - 256 * ee - 3 * C*C)*D*D*D*D*D*D / 720);
    //转换为度 DD
    double tempLon = longitude1 / iPI;
    double tempLat = latitude1 / iPI;
    //qDebug("%.10lf,%.10lf",tempLon,tempLat);

    for(int i = 0; i < 10000; i++)
    {
        if(lonLatPoint[i][0] == 0)
        {
            lonLatPoint[i][0] = tempLon;
            lonLatPoint[i][1] = tempLat;
            //qDebug("fuck%d %.10lf,%.10lf",i,lonLatPoint[i][0],lonLatPoint[i][1]);
            break;
        }
    }
//    for(int i = 0; i < 10000; i++)
//    {
//        if(lonLatPoint[i][0] != 0)
//        {
//            qDebug("try%d,%.10lf,%.10lf",i,tempLon,tempLat);
//        }
//    }

}

void MainWindow::showCoorDinates()
{
    QString strLon1 = QString::number(myCoordinates[0][0],'g',10);
    QString strLat1 = QString::number(myCoordinates[0][1],'g',10);
    QString strCoo1 = QString(strLon1+","+strLat1);
    ui->coord1->setText(strCoo1);

    QString strLon2 = QString::number(myCoordinates[1][0],'g',10);
    QString strLat2 = QString::number(myCoordinates[1][1],'g',10);
    ui->coord2->setText(strLon2+","+strLat2);

    QString strLon3 = QString::number(myCoordinates[2][0],'g',10);
    QString strLat3 = QString::number(myCoordinates[2][1],'g',10);
    ui->coord3->setText(strLon3+","+strLat3);

    QString strLon4 = QString::number(myCoordinates[3][0],'g',10);
    QString strLat4 = QString::number(myCoordinates[3][1],'g',10);
    ui->coord4->setText(strLon4+","+strLat4);
}
void MainWindow::caculateFromLineEdit()
{
    myCoordinates[0][0] = ui->labelOrig1X->text().toDouble();
    myCoordinates[0][1] = ui->labelOrig1Y->text().toDouble();
    myCoordinates[1][0] = ui->labelOrig2X->text().toDouble();
    myCoordinates[1][1] = ui->labelOrig2Y->text().toDouble();
    myCoordinates[2][0] = ui->labelOrig3X->text().toDouble();
    myCoordinates[2][1] = ui->labelOrig3Y->text().toDouble();
    myCoordinates[3][0] = ui->labelOrig4X->text().toDouble();
    myCoordinates[3][1] = ui->labelOrig4Y->text().toDouble();
//    for(int i = 0; i < 4; i++)
//    {
//        qDebug()<<"caculateFromLineEdit"<<myCoordinates[i][0]<<","<<myCoordinates[i][1];
//        GaussProjCal(myCoordinates[i][0],myCoordinates[i][1]);
//    }
    //showPointOrig();
    g_T_Points();
}
//void MainWindow::showPointOrig()
void MainWindow::g_T_Points()
{
//    QString strOrigx1 = QString::number(pointOrig[0].x);
//    QString strOrigy1 = QString::number(pointOrig[0].y);
//    ui->labelOrig1->setText(strOrigx1+","+strOrigy1);
//    QString strOrigx2 = QString::number(pointOrig[1].x);
//    QString strOrigy2 = QString::number(pointOrig[1].y);
//    ui->labelOrig2->setText(strOrigx2+","+strOrigy2);
//    QString strOrigx3 = QString::number(pointOrig[2].x);
//    QString strOrigy3 = QString::number(pointOrig[2].y);
//    ui->labelOrig3->setText(strOrigx3+","+strOrigy3);
//    QString strOrigx4 = QString::number(pointOrig[3].x);
//    QString strOrigy4 = QString::number(pointOrig[3].y);
//    ui->labelOrig4->setText(strOrigx4+","+strOrigy4);

    generateTracepoint->setX1(myCoordinates[0][0]);
    generateTracepoint->setY1(myCoordinates[0][1]);
    generateTracepoint->setX2(myCoordinates[1][0]);
    generateTracepoint->setY2(myCoordinates[1][1]);
    generateTracepoint->setX3(myCoordinates[2][0]);
    generateTracepoint->setY3(myCoordinates[2][1]);
    double X4 = myCoordinates[0][0] + myCoordinates[2][0] - myCoordinates[1][0];//
    double Y4 = myCoordinates[0][1] + myCoordinates[2][1] - myCoordinates[1][1];//点4坐标，保证构成平行四边形
    generateTracepoint->setX4(X4);
    generateTracepoint->setY4(Y4);
//    generateTracepoint->setX1(118.994545);
//    generateTracepoint->setY1(32.384779);
//    generateTracepoint->setX2(118.995178);
//    generateTracepoint->setY2(32.384961);
//    generateTracepoint->setX3(118.995224);
//    generateTracepoint->setY3(32.385051);
//    double X4 = 118.994545 + 118.995224 - 118.995178;//
//    double Y4 = 32.384779 + 32.385051 - 32.384961;//点4坐标，保证构成平行四边形
//    generateTracepoint->setX4(X4);
//    generateTracepoint->setY4(Y4);
}
//此方法调用高斯投影方法，将gps转换为坐标并调用showPointOrig将坐标显示在界面上，
//现增加getset以实现将坐标中的前3个值传递给路径规划算法。

void MainWindow::on_buttonSure_clicked()
{
    resetPointOrig();
//    for(int i = 0; i < 4; i++)
//    {
//        qDebug()<<"mycoor"<<myCoordinates[i][0]<<","<<myCoordinates[i][1];
//        GaussProjCal(myCoordinates[i][0],myCoordinates[i][1]);

//    }
    //showPointOrig();
    g_T_Points();

    generateTracepoint->showPoint();


}
//重置mapview大小**important
void MainWindow::resizeEvent(QResizeEvent *)
{
    mapView->resize(ui->widget->size());
}

//让地图显示南理工
void MainWindow::on_buttonPosToNUST_clicked()
{
    double a = 118.851192;
    double b = 32.02878014;
    sendCoorNJUST(a,b);
}
//让地图显示麦田
void MainWindow::on_buttonPosToWheatField_clicked()
{
    double a = 118.99525881;
    double b = 32.38409303;
    sendCoorWheatField(a,b);
}

//手柄数据显示在窗口中
void MainWindow::gamepadMsgShowInWindow()
{
    double numberLR = - sendGamepad->getUpDownValue();

    if(numberLR == 0.0 && sendGamepad->getLeftRightValue() == 0.0)
    {
        ui->labelPicUp->setPixmap(QPixmap::fromImage(resultImg_GamepadUp));
        ui->labelPicDown->setPixmap(QPixmap::fromImage(resultImg_GamepadDown));
        ui->labelPicLeft->setPixmap(QPixmap::fromImage(resultImg_GamepadLeft));
        ui->labelPicRight->setPixmap(QPixmap::fromImage(resultImg_GamepadRight));
    }
    if(numberLR > 0 && sendGamepad->getLeftRightValue() > 0)
    {
        ui->labelPicUp->setPixmap(QPixmap::fromImage(resultImg_GamepadUp1));
        ui->labelPicDown->setPixmap(QPixmap::fromImage(resultImg_GamepadDown));
        ui->labelPicLeft->setPixmap(QPixmap::fromImage(resultImg_GamepadLeft));
        ui->labelPicRight->setPixmap(QPixmap::fromImage(resultImg_GamepadRight1));
    }
    if(numberLR > 0 && sendGamepad->getLeftRightValue() < 0)
    {
        ui->labelPicUp->setPixmap(QPixmap::fromImage(resultImg_GamepadUp1));
        ui->labelPicDown->setPixmap(QPixmap::fromImage(resultImg_GamepadDown));
        ui->labelPicLeft->setPixmap(QPixmap::fromImage(resultImg_GamepadLeft1));
        ui->labelPicRight->setPixmap(QPixmap::fromImage(resultImg_GamepadRight));
    }
    if(numberLR < 0 && sendGamepad->getLeftRightValue() < 0)
    {
        ui->labelPicUp->setPixmap(QPixmap::fromImage(resultImg_GamepadUp));
        ui->labelPicDown->setPixmap(QPixmap::fromImage(resultImg_GamepadDown1));
        ui->labelPicLeft->setPixmap(QPixmap::fromImage(resultImg_GamepadLeft1));
        ui->labelPicRight->setPixmap(QPixmap::fromImage(resultImg_GamepadRight));
    }
    if(numberLR < 0 && sendGamepad->getLeftRightValue() > 0)
    {
        ui->labelPicUp->setPixmap(QPixmap::fromImage(resultImg_GamepadUp));
        ui->labelPicDown->setPixmap(QPixmap::fromImage(resultImg_GamepadDown1));
        ui->labelPicLeft->setPixmap(QPixmap::fromImage(resultImg_GamepadLeft));
        ui->labelPicRight->setPixmap(QPixmap::fromImage(resultImg_GamepadRight1));
    }
    if(numberLR == 0.0 && sendGamepad->getLeftRightValue() > 0)
    {
        ui->labelPicUp->setPixmap(QPixmap::fromImage(resultImg_GamepadUp));
        ui->labelPicDown->setPixmap(QPixmap::fromImage(resultImg_GamepadDown));
        ui->labelPicLeft->setPixmap(QPixmap::fromImage(resultImg_GamepadLeft));
        ui->labelPicRight->setPixmap(QPixmap::fromImage(resultImg_GamepadRight1));
    }
    if(numberLR == 0.0 && sendGamepad->getLeftRightValue() < 0)
    {
        ui->labelPicUp->setPixmap(QPixmap::fromImage(resultImg_GamepadUp));
        ui->labelPicDown->setPixmap(QPixmap::fromImage(resultImg_GamepadDown));
        ui->labelPicLeft->setPixmap(QPixmap::fromImage(resultImg_GamepadLeft1));
        ui->labelPicRight->setPixmap(QPixmap::fromImage(resultImg_GamepadRight));
    }
    if(numberLR > 0.0 && sendGamepad->getLeftRightValue() == 0.0)
    {
        ui->labelPicUp->setPixmap(QPixmap::fromImage(resultImg_GamepadUp1));
        ui->labelPicDown->setPixmap(QPixmap::fromImage(resultImg_GamepadDown));
        ui->labelPicLeft->setPixmap(QPixmap::fromImage(resultImg_GamepadLeft));
        ui->labelPicRight->setPixmap(QPixmap::fromImage(resultImg_GamepadRight));
    }
    if(numberLR < 0.0 && sendGamepad->getLeftRightValue() == 0.0)
    {
        ui->labelPicUp->setPixmap(QPixmap::fromImage(resultImg_GamepadUp));
        ui->labelPicDown->setPixmap(QPixmap::fromImage(resultImg_GamepadDown1));
        ui->labelPicLeft->setPixmap(QPixmap::fromImage(resultImg_GamepadLeft));
        ui->labelPicRight->setPixmap(QPixmap::fromImage(resultImg_GamepadRight));
    }
    //2020/0213该段表示移动手柄显示数值
//    if(sendGamepad->getLeftRightValue() > 0)
//    {
//        ui->labelGamepadX->setText(QString::number(sendGamepad->getLeftRightValue(), 'f', 2));
//    }
//    if(numberLR > 0)
//    {
//        ui->labelGamepadY->setText(QString::number(numberLR, 'f', 2));
//    }
//    if(sendGamepad->getLeftRightValue() < 0)
//    {
//        ui->labelGamepadX_2->setText(QString::number(sendGamepad->getLeftRightValue(), 'f', 2));
//    }
//    if(numberLR < 0)
//    {
//        ui->labelGamepadY_2->setText(QString::number(numberLR, 'f', 2));
//    }
//    if(sendGamepad->getLeftRightValue() == 0.0)
//    {
//        ui->labelGamepadX->setText(QString::number(0));
//        ui->labelGamepadX_2->setText(QString::number(0));
//    }
//    if(numberLR == 0.0)
//    {
//        ui->labelGamepadY->setText(QString::number(0));
//        ui->labelGamepadY_2->setText(QString::number(0));
//    }
    if(sendGamepad->getButtonXValue() == 1 && sendGamepad->getButtonYValue() == 0)
    {
        ui->labelGamepadControl->setText(QStringLiteral("Being intervened"));
    }
    else if(sendGamepad->getButtonXValue() == 0 && sendGamepad->getButtonYValue() == 1)
    {
        ui->labelGamepadControl->setText(QStringLiteral("No intervention"));
    }
    //qDebug()<<"X"<<sendGamepad->getButtonXValue()<<"Y"<<sendGamepad->getButtonYValue()<<"lef rit"<<sendGamepad->getLeftRightValue()<<"up down"<<sendGamepad->getUpDownValue();
}

void MainWindow::origToLatLon()
{
    FILE *TracePoint;
    TracePoint = fopen("./gpspoint.txt", "r");
    int tracePointNum = 0;

    while (!feof(TracePoint))
    {
        //qDebug()<<tracePointNum;
        fscanf(TracePoint, "%lf%lf", &tracePoint[tracePointNum][0],&tracePoint[tracePointNum][1]);
        qDebug()<<"infile"<<tracePoint[tracePointNum][0];
        tracePointNum++;
    }

    fclose(TracePoint);
    qDebug()<<"tracepoint"<<tracePointNum;

    pointCount = tracePointNum;
    sendLonLatCounts(pointCount-1);

    for(int i = 0; i < tracePointNum; i++)
    {
        if(tracePoint[i][0] == 0)
        {
            break;
        }
        qDebug()<<i<<" "<<tracePoint[i][0]<<tracePoint[i][1];
    }
}
//绘图
//当坐标点没有遍历完，一直给js发送坐标点
//js每接收到一个坐标点，往polyline的数组里push一个点

void MainWindow::on_buttonDraw_clicked()
{
    qDebug()<<"getIntheDraw";
    origToLatLon();
    int i = 4;
    qDebug()<<tracePoint[i][0];
    while(tracePoint[i][0] != 0)
    {
        qDebug("try%d,%.10lf,%.10lf",i,tracePoint[i][0],tracePoint[i][1]);
        sendLonLats(i,tracePoint[i][0],tracePoint[i][1]);
        i++;
    }
    qDebug()<<"draw end";
}

void MainWindow::on_buttonPathPlan_clicked()
{
    QString str1 = ui->lineEditFileName->text();
    QString str2 = ".txt";
    QString str3 = str1 + str2;
    sendFileName(str3);
    generateTracepoint->setD(ui->marginLine->text().toInt()*0.0000001);
    generateTracepoint->setD1(ui->marginLeft->text().toInt()*0.0000001);
    generateTracepoint->setD2(ui->marginRight->text().toInt()*0.0000001);
    generateTracepoint->setD3(ui->marginUp->text().toInt()*0.0000001);
    generateTracepoint->setD4(ui->marginDown->text().toInt()*0.0000001);
    generateTracepoint->setMODEL(ui->spinBoxModel->value());
    qDebug()<<generateTracepoint->getD()<<generateTracepoint->getD2()
           <<generateTracepoint->getD1()<<generateTracepoint->getD3()
          <<generateTracepoint->getD4()<<generateTracepoint->getMODEL();
    generateTracepoint->caculate();
}

void MainWindow::on_buttonSureFromHand_clicked()
{
    caculateFromLineEdit();
}

void MainWindow::on_buttonCleanLine_clicked()
{
    tellJsToCleanLines();
}

void MainWindow::on_logButton_clicked()
{
    timer->start(2000);
}

void MainWindow::logFile()
{
    QString str1 = ui->lineEditLogFile->text();
    QString str2 = ".txt";
    QString str4 = "./";
    QString str3 = str4 + str1 + str2;

    QByteArray tempStrtoChars = str3.toLatin1();
    charLogFileName = tempStrtoChars.data();

//    FILE * fp1;
//    fp1 = fopen(charLogFileName, "a");
//    fprintf(fp1, "%f\t%f\n",logLon,logLat);

    QDateTime curDateTime=QDateTime::currentDateTime();
    QString str = curDateTime.toString("yyyy-MM-dd hh:mm:ss");
    QByteArray tempStrtoChars2 = str.toLatin1();
    char* charLog = tempStrtoChars2.data();

    QString gpsLogTest = "gps log test";
    char*  ch;
    QByteArray ba = gpsLogTest.toLatin1(); // must
    ch=ba.data();

    LogFile = fopen(charLogFileName, "a");
//    fprintf(LogFile, "%s ",charLog);
    fprintf(LogFile, "%lf ",logGps[0]);
    fprintf(LogFile, "%lf\n",logGps[1]);
    fclose(LogFile);
}

void MainWindow::on_buttonLogPause_clicked()
{
    timer->stop();


}
void MainWindow::readLogFile()
{
    qDebug()<<"ready openfile"<<charDrawLogFileName;;
    FILE *LogFile;
    QByteArray tempStrtoChars = strLogFilename.toLatin1();
    charDrawLogFileName = tempStrtoChars.data();
    LogFile = fopen(charDrawLogFileName, "r");
    qDebug()<<"has been opened "<<charDrawLogFileName;

    int tracePointNum = 0;

    while (!feof(LogFile))
    {
        fscanf(LogFile, "%lf%lf", &logTracePoint[tracePointNum][0],&logTracePoint[tracePointNum][1]);
        qDebug()<<"infile"<<logTracePoint[tracePointNum][0];
        tracePointNum++;
    }

    fclose(LogFile);

    pointCount = tracePointNum;

    //sendLonLatCounts(pointCount-1);

    for(int i = 0; i < tracePointNum; i++)
    {
        if(logTracePoint[i][0] == 0)
        {
            break;
        }
        qDebug()<<i<<" "<<logTracePoint[i][0]<<logTracePoint[i][1];
    }
}
void MainWindow::on_buttonLogDraw_clicked()
{
    qDebug()<<"getIntheDraw";
    readLogFile();
    int i = 4;
    qDebug()<<logTracePoint[i][0];
    while(logTracePoint[i][0] != 0)
    {
        qDebug("try%d,%.10lf,%.10lf",i,logTracePoint[i][0],logTracePoint[i][1]);
        sendLonLatsLog(i,logTracePoint[i][0],logTracePoint[i][1]);
        i++;
    }
    qDebug()<<"draw end";

}

void MainWindow::on_buttonOpenLogFile_clicked()
{
    QString fileFull,filename;
    QFileInfo fileinfo;
    fileFull = QFileDialog::getOpenFileName();
    fileinfo = QFileInfo(fileFull);
    filename = fileinfo.fileName();
    ui->labelLogFilename->setText(filename);

    strLogFilename = filename;

//    QByteArray tempStrtoChars = str1.toLatin1();
//    charDrawLogFileName = tempStrtoChars.data();
    qDebug()<<strLogFilename;
}

void MainWindow::on_buttonCleanLogLine_clicked()
{
    tellJsToCleanLinesLog();
}
