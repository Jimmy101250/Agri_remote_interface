#include "generatetracepoint.h"
#include <QDebug>
void GenerateTracepoint::setX1(double a)
{
    X1 = a;
}
double GenerateTracepoint::getX1()
{
    return X1;
}
void GenerateTracepoint::setY1(double a)
{
    Y1 = a;
}
double GenerateTracepoint::getY1()
{
    return Y1;
}
void GenerateTracepoint::setX2(double a)
{
    X2 = a;
}
double GenerateTracepoint::getX2()
{
    return X2;
}
void GenerateTracepoint::setY2(double a)
{
    Y2 = a;
}
double GenerateTracepoint::getY2()
{
    return Y2;
}
void GenerateTracepoint::setX3(double a)
{
    X3 = a;
}
double GenerateTracepoint::getX3()
{
    return X3;
}
void GenerateTracepoint::setY3(double a)
{
    Y3 = a;
}
double GenerateTracepoint::getY3()
{
    return Y3;
}
void GenerateTracepoint::setX4(double a)
{
    X4 = a;
}
double GenerateTracepoint::getX4()
{
    return X4;
}
void GenerateTracepoint::setY4(double a)
{
    Y4 = a;
}
double GenerateTracepoint::getY4()
{
    return Y4;
}
void GenerateTracepoint::setD1(double a)
{
    d1 = a;
}
double GenerateTracepoint::getD1()
{
    return d1;
}
void GenerateTracepoint::setD2(double a)
{
    d2 = a;
}
double GenerateTracepoint::getD2()
{
    return d2;
}
void GenerateTracepoint::setD3(double a)
{
    d3 = a;
}
double GenerateTracepoint::getD3()
{
    return d3;
}

void GenerateTracepoint::setD4(double a)
{
    d4 = a;
}
double GenerateTracepoint::getD4()
{
    return d4;
}

void GenerateTracepoint::setD(double a)
{
    d = a;
}
double GenerateTracepoint::getD()
{
    return d;
}
void GenerateTracepoint::setMODEL(int a)
{
    MODEL = a;
}
int GenerateTracepoint::getMODEL()
{
    return MODEL;
}
void GenerateTracepoint::getFileName(QString str111)
{
    strFileName = str111;
    tempStrtoChars = strFileName.toLatin1();
    charFileName = tempStrtoChars.data();
}
GenerateTracepoint::GenerateTracepoint(QObject *parent) : QObject(parent)
{

}
double GenerateTracepoint::min4num(double a, double b, double c, double d)
{
    double minnum = a < b ? a : b;
    minnum = minnum < c ? minnum : c;
    minnum = minnum < d ? minnum : d;
    return minnum;
}
double GenerateTracepoint::cal4coord(double coordi0, double coordi1, double coordi2, double L, double W, double l1, double l2)
//coordi0:计算坐标点，coordi1:对应长坐标点，coordi2:对应宽坐标点，L:长，W：宽，l1，l2:对应边界长度
{
    double a = coordi0 - l1 * (coordi0 - coordi1) / L;
    double b = coordi0 - l2 * (coordi0 - coordi2) / W;
    double c = a + b - coordi0;
    return c;
}
void GenerateTracepoint::blh2xy(double x,double y,double z, int *gps_X, int *gps_Y)
{
    int n,L0;
    double X,N54,W54,t,m,a54,e54,e_54;
    double iptr;
    double t_2=0,t_4=0,yita_2=0,yita_4=0;
    double lp=0,lp_2=0;
    double SinL,CosL,CosL_2,SinL_2;
    double SinG,CosG;
    double daa,df,db2p,dl2p,dahm;
    double deltabo,deltalo;
    double w84,n84,m84,a84,e842,f84,f54,dx,dy,dz;
    double lati,logi,hegt;
    double pi=3.1415926535;

    lati = x;
    logi = y;
    hegt = z;

    lati = lati*pi/180;
    logi = logi*pi/180;

    SinL = sin(lati);
    CosL = cos(lati);
    SinG = sin(logi);
    CosG = cos(logi);
    CosL_2 = CosL * CosL;
    SinL_2 = SinL * SinL;

    a84=6378137.0;
    e842=0.00669437999014132;
    f84=1.0/298.257223563;

    a54=6378245.0;
    f54=1.0/298.3;

    dx=-16.0;
    dy=147.0;
    dz=77.0;

    w84=sqrt(1-e842*SinL_2);
    n84=a84/w84;
    m84=a84*(1-e842)/(w84*w84*w84);

    daa=a54-a84;
    df=f54-f84;

    db2p=(-dx*SinL*CosG-dy*SinL*SinG+dz*CosL+(a84*df+f84*daa)*sin(2*lati))/(m84*sin(1/3600.0*pi/180));
    dl2p=(-dx*SinG+dy*CosG)/(n84*CosL*sin(1/3600.0*pi/180));
    dahm=dx*CosL*CosG+dy*CosL*SinG+dz*SinL+(a84*df+f84*daa)*SinL_2-daa;

    deltabo=(db2p/3600.0)*pi/180.0;
    deltalo=(dl2p/3600.0)*pi/180.0;

    logi = logi+deltalo;
    lati = lati+deltabo;
    hegt = hegt+dahm;

    SinL = sin(lati);
    CosL = cos(lati);
    CosL_2 = CosL * CosL;
    SinL_2 = SinL * SinL;

    a54 = 6378245.0;
    e54 = 0.0066934274898192;

    W54=sqrt(1.0-e54*SinL_2);
    N54=a54/W54;
    e_54=0.0067385254147;

    logi=logi*180/pi;
    modf(logi/6.0,&iptr);
    n=(int)iptr+1;
    L0=n*6-3;

    lp = (logi-L0)*pi/180;
    lp_2 = lp*lp;

    m=CosL_2*lp_2;
    yita_2=e_54*CosL_2;
    yita_4 = yita_2 * yita_2;

    t=tan(lati);
    t_2 = t*t;
    t_4 = t_2*t_2;

    double gps_xx,gps_yy;
    X = 111134.8611*lati*180/pi
            -SinL*CosL*( 32005.7799 + 133.9238*SinL_2 + 0.6973*SinL_2*SinL_2+0.0039*SinL_2*SinL_2*SinL_2);

    gps_yy = X + N54*t*m*( 0.5 + 1.0/24.0*( 5.0 - t_2 + 9.0*yita_2 + 4.0*yita_4)*m
                           + 1.0/720.0*( 61.0 - 58.0*t_2 + t_4)*m*m);

    gps_xx = N54*CosL*lp*( 1.0 + 1.0/6.0*( 1-t_2 + yita_2)*m
                           + 1.0/120.0*( 5.0 - 18.0*t_2 + t_4 + 14.0*yita_2-58.0*yita_2*t_2)*m*m);
    gps_xx = gps_xx + 1000000*n+500000;
    gps_xx*=100;
    gps_yy *=100;
    *gps_X = gps_xx;
    *gps_Y = gps_yy;
    return;
}
void GenerateTracepoint::showPoint()
{
    qDebug()<<"X1"<<X1<<"Y1"<<Y1<<"X2"<<X2<<"Y2"<<Y2<<"X3"<<X3<<"Y3"<<Y3;
}
int GenerateTracepoint::caculate()
{
    qDebug()<<charFileName;
    qDebug()<<"X1"<<X1<<"Y1"<<Y1<<"X2"<<X2<<"Y2"<<Y2<<"X3"<<X3<<"Y3"<<Y3<<"d1"<<d1<<"d2"<<d2<<"d3"<<d3<<"d4"<<d4<<"d"<<d;
    double X0 = min4num(X1, X2, X3, X4);
    double Y0 = min4num(Y1, Y2, Y3, Y4);
    X1 = X1 - X0;
    Y1 = Y1 - Y0;
    X2 = X2 - X0;
    Y2 = Y2 - Y0;
    X3 = X3 - X0;
    Y3 = Y3 - Y0;
    X4 = X4 - X0;
    Y4 = Y4 - Y0;
    qDebug("%f\t%f\n%f\t%f\n%f\t%f\n%f\t%f\n", X1, Y1, X2, Y2, X3, Y3, X4, Y4);
    L = sqrt(pow((X2 - X1),2) + pow((Y2 - Y1),2));
    W = sqrt(pow((X2 - X3),2) + pow((Y2 - Y3),2));
    L0 = L - d3 - d4;//作业有效长度
    W0 = W - d1 - d2;//作业有效宽度
    theta = atan2((Y3 - Y2), (X3 - X2)) - atan2((Y1 - Y2), (X1 - X2));//平行四边形内角
    d0 = d / abs(sin(theta));
    d10 = d1 / abs(sin(theta));
    d20 = d2 / abs(sin(theta));
    d30 = d3 / abs(sin(theta));
    d40 = d4 / abs(sin(theta));
    intervalNum = W0 / d0;
    qDebug("chang:%f, kuan:%f, youxiaochang:%f, youxiaokuan:%f\ntheta:%f, d0:%f, hangjiangeshu:%d\n", L, W, L0, W0, theta, d0, intervalNum);
    XX1 = cal4coord(X1, X2, X4, L, W, d30, d10);
    YY1 = cal4coord(Y1, Y2, Y4, L, W, d30, d10);
    XX2 = cal4coord(X2, X1, X3, L, W, d40, d10);
    YY2 = cal4coord(Y2, Y1, Y3, L, W, d40, d10);
    XX3 = cal4coord(X3, X4, X2, L, W, d40, d20);
    YY3 = cal4coord(Y3, Y4, Y2, L, W, d40, d20);
    XX4 = cal4coord(X4, X3, X1, L, W, d30, d20);
    YY4 = cal4coord(Y4, Y3, Y1, L, W, d30, d20);
    qDebug("%f,%f\n%f,%f\n%f,%f\n%f,%f\n", XX1, YY1, XX2, YY2, XX3, YY3, XX4, YY4);
    for (int i = 0; i <= intervalNum; i++)
    {
        featurePoint_x[i] = (XX1 * (intervalNum - i) + XX4 * i) / intervalNum;
        featurePoint_y[i] = (YY1 * (intervalNum - i) + YY4 * i) / intervalNum;
    }
    for (int i = intervalNum + 1; i <= 2 * intervalNum + 1; i++)
    {
        featurePoint_x[i] = (XX2 * (2 * intervalNum + 1 - i) + XX3 * (i - intervalNum - 1)) / intervalNum;
        featurePoint_y[i] = (YY2 * (2 * intervalNum + 1 - i) + YY3 * (i - intervalNum - 1)) / intervalNum;
    }
    for (int i = 0; i <= 2 * intervalNum + 1; i++)
        qDebug("()()() the %d feature point is: %f, %f\n", i, featurePoint_x[i], featurePoint_y[i]);

    if (MODEL == 2)                  //每两行掉头
    {
        switch (intervalNum % 4)
        {
        case 0:
            for (int i = 0; i <= intervalNum + 1; i++)
            {
                if (i % 4 == 0)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[i];
                    orderedFeaturePoint_y[i] = featurePoint_y[i];
                }
                else if (i % 4 == 1)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + i];
                    orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + i];
                }
                else if (i % 4 == 2)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + i + 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + i + 1];
                }
                else if (i % 4 == 3)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[i - 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[i - 1];
                }
            }
            for (int i = intervalNum + 2; i <= 2 * intervalNum + 1; i++)
            {
                if (i % 4 == 0)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[2 * intervalNum - i + 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[2 * intervalNum - i + 1];
                }
                else if (i % 4 == 1)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[3 * intervalNum - i + 3];
                    orderedFeaturePoint_y[i] = featurePoint_y[3 * intervalNum - i + 3];
                }
                else if (i % 4 == 2)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[3 * intervalNum - i + 2];
                    orderedFeaturePoint_y[i] = featurePoint_y[3 * intervalNum - i + 2];
                }
                else if (i % 4 == 3)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[2 * intervalNum - i + 2];
                    orderedFeaturePoint_y[i] = featurePoint_y[2 * intervalNum - i + 2];
                }
            }
            break;
        case 1:
            for (int i = 0; i <= intervalNum; i++)
            {
                if (i % 4 == 0)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[i];
                    orderedFeaturePoint_y[i] = featurePoint_y[i];
                }
                else if (i % 4 == 1)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + i];
                    orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + i];
                }
                else if (i % 4 == 2)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + i + 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + i + 1];
                }
                else if (i % 4 == 3)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[i - 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[i - 1];
                }
            }
            for (int i = intervalNum + 1; i <= 2 * intervalNum + 1; i++)
            {
                if (i % 4 == 0)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[2 * intervalNum - i + 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[2 * intervalNum - i + 1];
                }
                else if (i % 4 == 1)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[3 * intervalNum - i + 3];
                    orderedFeaturePoint_y[i] = featurePoint_y[3 * intervalNum - i + 3];
                }
                else if (i % 4 == 2)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[3 * intervalNum - i + 2];
                    orderedFeaturePoint_y[i] = featurePoint_y[3 * intervalNum - i + 2];
                }
                else if (i % 4 == 3)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[2 * intervalNum - i + 2];
                    orderedFeaturePoint_y[i] = featurePoint_y[2 * intervalNum - i + 2];
                }
            }
            break;
        case 2:
            for (int i = 0; i <= intervalNum + 1; i++)
            {
                if (i % 4 == 0)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[i];
                    orderedFeaturePoint_y[i] = featurePoint_y[i];
                }
                else if (i % 4 == 1)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + i];
                    orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + i];
                }
                else if (i % 4 == 2)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + i + 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + i + 1];
                }
                else if (i % 4 == 3)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[i - 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[i - 1];
                }
            }
            for (int i = intervalNum + 2; i <= 2 * intervalNum + 1; i++)
            {
                if (i % 4 == 0)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[2 * intervalNum - i + 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[2 * intervalNum - i + 1];
                }
                else if (i % 4 == 1)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[3 * intervalNum - i + 3];
                    orderedFeaturePoint_y[i] = featurePoint_y[3 * intervalNum - i + 3];
                }
                else if (i % 4 == 2)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[3 * intervalNum - i + 2];
                    orderedFeaturePoint_y[i] = featurePoint_y[3 * intervalNum - i + 2];
                }
                else if (i % 4 == 3)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[2 * intervalNum - i + 2];
                    orderedFeaturePoint_y[i] = featurePoint_y[2 * intervalNum - i + 2];
                }
            }
            break;
        case 3:
            for (int i = 0; i <= intervalNum; i++)
            {
                if (i % 4 == 0)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[i];
                    orderedFeaturePoint_y[i] = featurePoint_y[i];
                }
                else if (i % 4 == 1)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + i];
                    orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + i];
                }
                else if (i % 4 == 2)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + i + 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + i + 1];
                }
                else if (i % 4 == 3)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[i - 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[i - 1];
                }
            }
            for (int i = intervalNum + 1; i <= 2 * intervalNum + 1; i++)
            {
                if (i % 4 == 0)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[2 * intervalNum - i + 1];
                    orderedFeaturePoint_y[i] = featurePoint_y[2 * intervalNum - i + 1];
                }
                else if (i % 4 == 1)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[3 * intervalNum - i + 3];
                    orderedFeaturePoint_y[i] = featurePoint_y[3 * intervalNum - i + 3];
                }
                else if (i % 4 == 2)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[3 * intervalNum - i + 2];
                    orderedFeaturePoint_y[i] = featurePoint_y[3 * intervalNum - i + 2];
                }
                else if (i % 4 == 3)
                {
                    orderedFeaturePoint_x[i] = featurePoint_x[2 * intervalNum - i + 2];
                    orderedFeaturePoint_y[i] = featurePoint_y[2 * intervalNum - i + 2];
                }
            }
            break;
        }
    }
    else if (MODEL == 1)            //每行掉头
    {
        for (int i = 0; i <= 2 * intervalNum + 1; i++)
        {
            if (i % 4 == 0)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[i / 2];
                orderedFeaturePoint_y[i] = featurePoint_y[i / 2];
            }
            else if (i % 4 == 1)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + (i + 1) / 2];
                orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + (i + 1) / 2];
            }
            else if (i % 4 == 2)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + (i + 2) / 2];
                orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + (i + 2) / 2];
            }
            else if (i % 4 == 3)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[(i - 1) / 2];
                orderedFeaturePoint_y[i] = featurePoint_y[(i - 1) / 2];
            }
        }
    }
    else if (MODEL == 3)        //掉头转弯直径为田块宽的一半
    {
        for (int i = 0; i <= 2 * intervalNum + 1; i++)
        {
            if (i == 0)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[0];
                orderedFeaturePoint_y[i] = featurePoint_y[0];
                index[i] = 0;
            }
            else if (i == 1)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + 1];
                orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + 1];
                index[i] = intervalNum + 1;
            }
            else if (i == 2)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + 1 + (intervalNum - 1) / 2];
                orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + 1 + (intervalNum - 1) / 2];
                index[i] = intervalNum + 1 + (intervalNum - 1) / 2;
            }
            else if (i == 3)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[(intervalNum - 1) / 2];
                orderedFeaturePoint_y[i] = featurePoint_y[(intervalNum - 1) / 2];
                index[i] = (intervalNum - 1) / 2;
            }
            else if (i == 4)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[intervalNum];
                orderedFeaturePoint_y[i] = featurePoint_y[intervalNum];
                index[i] = intervalNum;
            }
            else if (i == 5)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[2 * intervalNum + 1];
                orderedFeaturePoint_y[i] = featurePoint_y[2 * intervalNum + 1];
                index[i] = 2 * intervalNum + 1;
            }
            else if (i == 8)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[1];
                orderedFeaturePoint_y[i] = featurePoint_y[1];
                index[i] = 1;
            }
            else if (i == 9)
            {
                orderedFeaturePoint_x[i] = featurePoint_x[intervalNum + 2];
                orderedFeaturePoint_y[i] = featurePoint_y[intervalNum + 2];
                index[i] = intervalNum + 2;
            }
            else
            {
                orderedFeaturePoint_x[i] = featurePoint_x[index[i - 4] + 1];
                orderedFeaturePoint_y[i] = featurePoint_y[index[i - 4] + 1];
                index[i] = index[i - 4] + 1;
            }
        }
    }

    FILE * fp0;
    fp0 = fopen("./featurepoint.txt", "w+");
    for (int i = 0; i <= 2 * intervalNum + 1; i++)
        fprintf(fp0, "%f\t%f\n", orderedFeaturePoint_x[i] + X0, orderedFeaturePoint_y[i] + Y0);
    fclose(fp0);

    FILE * fp;
    fp = fopen("./gpspoint.txt", "w+");

    FILE * fp1;
    fp1 = fopen(charFileName, "w+");
    ///*
    fprintf(fp, "%f\t%f\n", X1 + X0, Y1 + Y0);
    fprintf(fp, "%f\t%f\n", X2 + X0, Y2 + Y0);
    fprintf(fp, "%f\t%f\n", X3 + X0, Y3 + Y0);
    fprintf(fp, "%f\t%f\n", X4 + X0, Y4 + Y0);
    fprintf(fp, "%f\t%f\n", X1 + X0, Y1 + Y0);
    //*/
    /*	for (int i = 0; i <= 2 * intervalNum; i++)
        {
            double dis = sqrt(pow((orderedFeaturePoint_y[i + 1] - orderedFeaturePoint_y[i]), 2) + pow((orderedFeaturePoint_x[i + 1] - orderedFeaturePoint_x[i]), 2));
            int n = dis / dp;
            for (int j = 0; j <= n; j++)
            {
                tracePoint_x[Index] = (orderedFeaturePoint_x[i] * (n - j) + orderedFeaturePoint_x[i + 1] * j) / n;
                tracePoint_y[Index] = (orderedFeaturePoint_y[i] * (n - j) + orderedFeaturePoint_y[i + 1] * j) / n;
                fprintf(fp, "%d\t%d\n", tracePoint_x[Index] + X0, tracePoint_y[Index] + Y0);
                Index++;
            }
        }
        */
    for (int i = 0; i <= 2 * intervalNum; i++)
    {
        if (i % 2 == 0)
        {
            double dis = sqrt(pow((orderedFeaturePoint_y[i + 1] - orderedFeaturePoint_y[i]), 2) + pow((orderedFeaturePoint_x[i + 1] - orderedFeaturePoint_x[i]), 2));
            //int n = dis / dp;
            for (int j = 0; j <= 300; j++)
            {
                tracePoint_x[Index] = (orderedFeaturePoint_x[i] * (300 - j) + orderedFeaturePoint_x[i + 1] * j) / 300;
                tracePoint_y[Index] = (orderedFeaturePoint_y[i] * (300 - j) + orderedFeaturePoint_y[i + 1] * j) / 300;
                fprintf(fp, "%f\t%f\n", tracePoint_x[Index] + X0, tracePoint_y[Index] + Y0);
                double lati = tracePoint_y[Index] + X0;
                double longi = tracePoint_x[Index] + Y0;
                double height = 0.0;
                int gps_XX, gps_YY;
                blh2xy(longi, lati, height, &gps_XX, &gps_YY);
                xy_tracePoint_x[Index] = gps_XX;
                xy_tracePoint_y[Index] = gps_YY;
                fprintf(fp1, "%d\t%d\n", xy_tracePoint_x[Index], xy_tracePoint_y[Index]);
                Index++;
            }
        }
        else if (i % 2 == 1)
        {
            double circleCentre_x = (orderedFeaturePoint_x[i] + orderedFeaturePoint_x[i + 1]) / 2;
            double circleCentre_y = (orderedFeaturePoint_y[i] + orderedFeaturePoint_y[i + 1]) / 2;
            double dis = sqrt(pow((orderedFeaturePoint_y[i + 1] - orderedFeaturePoint_y[i]), 2) + pow((orderedFeaturePoint_x[i + 1] - orderedFeaturePoint_x[i]), 2));
            double radius = dis / 2;
            double theta_i = atan2((orderedFeaturePoint_y[i] - circleCentre_y), (orderedFeaturePoint_x[i] - circleCentre_x)) * 180 / PI;
            double circle_x1 = circleCentre_x + radius * cos(theta_i * PI / 180 - PI / 2);
            double circle_y1 = circleCentre_y + radius * sin(theta_i * PI / 180 - PI / 2);
            double circle_x2 = circleCentre_x + radius * cos(theta_i * PI / 180 + PI / 2);
            double circle_y2 = circleCentre_y + radius * sin(theta_i * PI / 180 + PI / 2);
            double dis1 = sqrt(pow((circle_y1 - orderedFeaturePoint_y[i - 1]), 2) + pow((circle_x1 - orderedFeaturePoint_x[i - 1]), 2));
            double dis2 = sqrt(pow((circle_y2 - orderedFeaturePoint_y[i - 1]), 2) + pow((circle_x2 - orderedFeaturePoint_x[i - 1]), 2));
            if (dis1 < dis2)
            {
                for (int j = 0; j <= 18; j++)
                {
                    tracePoint_x[Index] = circleCentre_x + radius * cos((theta_i + 10 * j) * PI / 180);
                    tracePoint_y[Index] = circleCentre_y + radius * sin((theta_i + 10 * j) * PI / 180);
                    fprintf(fp, "%f\t%f\n", tracePoint_x[Index] + X0, tracePoint_y[Index] + Y0);
                    double lati = tracePoint_y[Index] + X0;
                    double longi = tracePoint_x[Index] + Y0;
                    double height = 0.0;
                    int gps_XX, gps_YY;
                    blh2xy(longi, lati, height, &gps_XX, &gps_YY);
                    xy_tracePoint_x[Index] = gps_XX;
                    xy_tracePoint_y[Index] = gps_YY;
                    fprintf(fp1, "%d\t%d\n", xy_tracePoint_x[Index], xy_tracePoint_y[Index]);
                    Index++;
                }
            }
            else if (dis1 > dis2)
            {
                for (int j = 0; j <= 18; j++)
                {
                    tracePoint_x[Index] = circleCentre_x + radius * cos((theta_i - 10 * j) * PI / 180);
                    tracePoint_y[Index] = circleCentre_y + radius * sin((theta_i - 10 * j) * PI / 180);
                    fprintf(fp, "%f\t%f\n", tracePoint_x[Index] + X0, tracePoint_y[Index] + Y0);
                    double lati = tracePoint_y[Index] + X0;
                    double longi = tracePoint_x[Index] + Y0;
                    double height = 0.0;
                    int gps_XX, gps_YY;
                    blh2xy(longi, lati, height, &gps_XX, &gps_YY);
                    xy_tracePoint_x[Index] = gps_XX;
                    xy_tracePoint_y[Index] = gps_YY;
                    fprintf(fp1, "%d\t%d\n", xy_tracePoint_x[Index], xy_tracePoint_y[Index]);
                    Index++;
                }
            }
        }
    }
    fclose(fp);
    fclose(fp1);


    return 0;
}

