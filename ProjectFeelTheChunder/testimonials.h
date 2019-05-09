#ifndef TESTIMONIALS_H
#define TESTIMONIALS_H

#include <QDialog>
#include <QMovie>
#include <QMediaPlayer>

namespace Ui {
class Testimonials;
}

class Testimonials : public QDialog
{
    Q_OBJECT

public:
    explicit Testimonials(QWidget *parent = nullptr);
    ~Testimonials();

private:
    Ui::Testimonials *ui;
};

#endif // TESTIMONIALS_H
