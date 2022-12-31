#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <QWidget>
#include <QWebEngineView>
#include <QtWebChannel>

namespace Ui {
class MapController;
}

class MapController : public QWidget
{
    Q_OBJECT

public:
    explicit MapController(QWidget *parent = nullptr);
    ~MapController();


public slots:
    void getCoordinates(double ,double );

signals:
    void sendCoordinates(double,double);

private slots:
    void on_send_clicked();

private:
Ui::MapController *ui;
    QWebEngineView *mapView;
    QWebChannel *channel;


};

#endif // MAPCONTROLLER_H
