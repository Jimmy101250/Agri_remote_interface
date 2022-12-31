#include "mapcontroller.h"
#include "ui_mapcontroller.h"

MapController::MapController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapController)
{
    ui->setupUi(this);
}

MapController::~MapController()
{
    delete ui;
}
