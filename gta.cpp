#include "gta.h"
#include "ui_gta.h"

gta::gta(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gta)
{
    ui->setupUi(this);
}

gta::~gta()
{
    delete ui;
}
