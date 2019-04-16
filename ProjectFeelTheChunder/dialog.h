#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDialog>
#include <QLabel>
#include <QDebug>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_buttonBox_accepted();


private:
    Ui::Dialog *ui;
    QString username;
    QString password;

};

#endif // DIALOG_H
