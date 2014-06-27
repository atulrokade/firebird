#ifndef CREATEENVIRONMENTDIALOG_H
#define CREATEENVIRONMENTDIALOG_H

#include <QDialog>

namespace Ui {
class createEnvironmentDialog;
}

class createEnvironmentDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit createEnvironmentDialog(QWidget *parent = 0);
    ~createEnvironmentDialog();
    
private:
    Ui::createEnvironmentDialog *ui;
};

#endif // CREATEENVIRONMENTDIALOG_H
