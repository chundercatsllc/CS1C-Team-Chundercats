#ifndef LOGIN_H
#define LOGIN_H

#include "dbconnection.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool coolcool{true};
private slots:
    void on_pushButton_login_clicked();

private:

    Ui::Login *ui;
};

#endif // LOGIN_H
