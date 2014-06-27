#include "createenvironmentdialog.h"
#include "ui_createenvironmentdialog.h"

createEnvironmentDialog::createEnvironmentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createEnvironmentDialog)
{
    ui->setupUi(this);
}

createEnvironmentDialog::~createEnvironmentDialog()
{
    delete ui;
}
