#include "mainwindow.h"
#include "shape.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QListView>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //setWindowIcon(QIcon(":/pix/icon.png"));

    //AwesomeVector<Shape *> shapeMagazine;
	ui->setupUi(this);
    QMovie *movie = new QMovie(":/pix/heckyeah.gif");
    QLabel *processLabel = new QLabel(ui->KANYE);
    processLabel->setMovie(movie);
    movie->start();

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_KANYE_linkActivated(const QString &link)
{
    QMovie *movie        = new QMovie(":/pix/heckyeah.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();
}

void MainWindow::on_add_shape_button_3_clicked()
{
    ui->menuStack->addWidget(ui->add_page);
    QComboBox * shapeTypeCombo = new QComboBox(ui->shapeType_box);
    QListView * colorList = new QListView(shapeTypeCombo);
    shapeTypeCombo->addItem("white");
    shapeTypeCombo->addItem("black");
    shapeTypeCombo->addItem("red");
    shapeTypeCombo->addItem("green");
    shapeTypeCombo->addItem("blue");
    shapeTypeCombo->addItem("cyan");
    shapeTypeCombo->addItem("magenta");
    shapeTypeCombo->addItem("yellow");
    shapeTypeCombo->addItem("gray");

    shapeTypeCombo->setView(colorList);

    Shape::ShapeType shape = getShapeType();

}

Shape::ShapeType MainWindow::getShapeType()
{
    switch(ui->shapeType_box->currentIndex())
    {
        case 0: return Shape::ShapeType::Polygon; break;
        case 1: return Shape::ShapeType::Polyline; break;
        case 2: return Shape::ShapeType::Line; break;
        case 3: return Shape::ShapeType::Ellipse; break;
        case 4: return Shape::ShapeType::Rectangle; break;
        case 5: return Shape::ShapeType::Text; break;
        default: return Shape::ShapeType::Rectangle;
    }
}

Qt::GlobalColor MainWindow::getPenColor()
{
    switch(ui->pen_color_box->currentIndex())
    {
    case 0: {return Qt::white;
        break;}
    case 1: {return Qt::black;
        break;}
    case 2: {return Qt::red;
        break;}
    case 3: {return Qt::green;
        break;}
    case 4: {return Qt::blue;
        break;}
    case 5: {return Qt::cyan;
        break;}
    case 6: {return Qt::magenta;
        break;}
    case 7: {return Qt::yellow;
        break;}
    case 8: {return Qt::gray;
        break;}
    default: {return Qt:: blue;}
    }
}

int MainWindow::getPenWidth()
{
    return ui->spinBox_setPenWidth->value();
}

Qt::PenStyle MainWindow::getPenStyle()
{
    switch(ui->pen_style_box->currentIndex())
    {
    case 0: {return Qt::SolidLine;
        break;}
    case 1: {return Qt::DashLine;
        break;}
    case 2: {return Qt::DotLine;
        break;}
    case 3: {return Qt::DashDotLine;
        break;}
    case 4: {return Qt::DashDotDotLine;
        break;}
    case 5: {return Qt::NoPen;
        break;}
    default: {return Qt::SolidLine;}
    }
}

Qt::PenCapStyle MainWindow::getPenCapStyle()
{
    switch (ui->pen_cap_style_box->currentIndex())
    {
    case 0: {return Qt::SquareCap;
        break;}
    case 1: {return Qt::FlatCap;
        break;}
    case 2: {return Qt::RoundCap;
        break;}
    default: {return Qt::SquareCap;}
    }
}

Qt::PenJoinStyle MainWindow::getPenJoinStyle()
{
    switch(ui->pen_join_style_box->currentIndex())
    {
    case 0: {return Qt::BevelJoin;
        break;}
    case 1: {return Qt::MiterJoin;
        break;}
    case 2: {return Qt::RoundJoin;
        break;}
    default: {return Qt::BevelJoin;}
    }
}

Qt::GlobalColor MainWindow::getBrushColor()
{
    switch(ui->brush_color_box->currentIndex())
    {
    case 0: {return Qt::blue;
        break;}
    case 1: {return Qt::red;
        break;}
    case 2: {return Qt::green;
        break;}
    case 3: {return Qt::yellow;
        break;}
    case 4: {return Qt::black;
        break;}
    case 5: {return Qt::white;
        break;}
    case 6: {return Qt::cyan;
        break;}
    case 7: {return Qt::magenta;
        break;}
    case 8: {return Qt::gray;
        break;}
    default: {return Qt:: blue;}
    }
}

Qt::BrushStyle MainWindow::getBrushStyle()
{
    switch (ui->brush_style_box->currentIndex())
    {
    case 0: {return Qt::NoBrush;
        break;}
    case 1: {return Qt::SolidPattern;
        break;}
    case 2: {return Qt::HorPattern;
        break;}
    case 3: {return Qt::VerPattern;
        break;}
    default: {return Qt::NoBrush;}
    }
}

/*
Qt::AlignmentFlag MainWindow::getAlign()
{
    switch(ui->alignment_box->currentIndex())
    {
    case 0: {return Qt::AlignLeft;
        break;}
    case 1: {return Qt::AlignCenter;
        break;}
    case 2: {return Qt::AlignRight;
        break;}
    case 3: {return Qt::AlignTop;
        break;}
    case 4: {return Qt::AlignBottom;
        break;}
    default: {return Qt::AlignLeft;}
    }
}

Qt::GlobalColor MainWindow::getTextColor()
{
    switch(ui->text_color_box->currentIndex())
    {
    case 0: {return Qt::blue;
        break;}
    case 1: {return Qt::red;
        break;}
    case 2: {return Qt::green;
        break;}
    case 3: {return Qt::yellow;
        break;}
    case 4: {return Qt::black;
        break;}
    case 5: {return Qt::white;
        break;}
    case 6: {return Qt::cyan;
        break;}
    case 7: {return Qt::magenta;
        break;}
    case 8: {return Qt::gray;
        break;}
    default: {return Qt:: blue;}
    }
}

QFont::Weight MainWindow::getTextWeight()
{
    switch(ui->font_weight_box->currentIndex())
    {
    case 0: {return QFont::Thin;
        break;}
    case 1: {return QFont::Light;
        break;}
    case 2: {return QFont::Normal;
        break;}
    case 3: {return QFont::Bold;
        break;}
    default: {return QFont::Normal;}
    }
}

QFont::Style MainWindow::getTextStyle()
{
    switch(ui->font_style_box->currentIndex())
    {
    case 0: {return QFont::StyleNormal;
        break;}
    case 1: {return QFont::StyleItalic;
        break;}
    case 2: {return QFont::StyleOblique;
        break;}
    default: {return QFont::StyleNormal;}
    }
}

QString MainWindow::getFontFamily()
{
    switch(ui->font_family_box->currentIndex())
    {
    case 0: {return "Comic Sans MS";
        break;}
    case 1: {return "Courier";
        break;}
    case 2: {return "Helvetica";
        break;}
    case 3: {return "Times";
        break;}
    default: {return "Times";}
    }
}
*/
