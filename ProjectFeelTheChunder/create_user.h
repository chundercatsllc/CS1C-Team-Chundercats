#ifndef CREATE_USER_H
#define CREATE_USER_H

#include <QWidget>

namespace Ui {
class create_user;
}

class create_user : public QWidget
{
    Q_OBJECT

public:
    explicit create_user(QWidget *parent = nullptr);
    ~create_user();

private slots:
    void on_new_user_pushButton_clicked();

private:
    Ui::create_user *ui;
};

#endif // CREATE_USER_H
