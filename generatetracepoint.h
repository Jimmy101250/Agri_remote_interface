#ifndef GENERATETRACEPOINT_H
#define GENERATETRACEPOINT_H
#define PI 3.141592653

#include <QObject>
#include "math.h"

using namespace std;

class GenerateTracepoint : public QObject
{
    Q_OBJECT

public:
    explicit GenerateTracepoint(QObject *parent = nullptr);

    double min4num(double a, double b, double c, double d);
    double cal4coord(double coordi0, double coordi1, double coordi2, double L, double W, double l1, double l2);
    void blh2xy(double x, double y, double z, int *gps_X, int *gps_Y);


    int caculate();

    void showPoint();

    double getX1();
    void setX1(double );
    double getY1();
    void setY1(double );
    double getX2();
    void setX2(double );
    double getY2();
    void setY2(double );
    double getX3();
    void setX3(double );
    double getY3();
    void setY3(double );
    double getX4();
    void setX4(double );
    double getY4();
    void setY4(double );

    void setD1(double );
    double getD1();
    void setD2(double );
    double getD2();
    void setD3(double );
    double getD3();
    void setD4(double );
    double getD4();
    void setD(double );
    double getD();
    void setMODEL(int );
    int getMODEL();
signals:

public slots:
    void getFileName(QString fileName);

private:

    int MODEL = 3;

    double X1;//
    double Y1;//起始点附近点1坐标

    double X2;//
    double Y2;//起始点对应长边点2坐标

    double X3;//
    double Y3;//点2对应短边点3坐标

    double X4;//
    double Y4;//点4坐标，保证构成平行四边形


    double XX1, YY1, XX2, YY2, XX3, YY3, XX4, YY4;//距离四个点最近的四个特征坐标点
    double featurePoint_x[200], featurePoint_y[200];
    double orderedFeaturePoint_x[200], orderedFeaturePoint_y[200];
    double tracePoint_x[50000], tracePoint_y[50000];
    int xy_tracePoint_x[50000], xy_tracePoint_y[50000];
    int index[100];
    int Index = 0;

    double d1;//左边距
    double d2;//右边距

    double d3;//顶间距
    double d4;//底间距
    double d10, d20, d30, d40;

    double d;//路线间距
    double d0;//计算特征点用，保证路线满足路线间距等于d，d0 >= d
    //int d00;//保证作物行为整数行间距最大值
    double dp = 30;//每30cm一个路径点

    double L, W;//田长，宽
    double L0, W0;//田有效作业长，宽
    int intervalNum;//作业行间隔数

    double theta;

    QString strFileName;
    QByteArray tempStrtoChars;
    //qDebug()<<str;

    char* charFileName ;
};

#endif // GENERATETRACEPOINT_H
