#include "mainwindow.h"
#include "shape.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QListView>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
    QMovie *movie = new QMovie(":/pix/heckyeah.gif");
    QLabel *processLabel = new QLabel(ui->KANYE);
    processLabel->setMovie(movie);
    movie->start();

    QMediaPlayer * playa = new QMediaPlayer();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_add_shape_button_3_clicked()
{
    ui->menuStack->addWidget(ui->add_page);
    QComboBox * shapeTypeCombo   = new QComboBox(ui->shapeType_box);
    QComboBox * penColorCombo    = new QComboBox(ui->pen_color_box);
    QComboBox * penStyleCombo    = new QComboBox(ui->pen_style_box);
    QComboBox * penCapStyleCombo = new QComboBox(ui->pen_cap_style_box);
    QSpinBox  * penWidthCombo    = new QSpinBox(ui->spinBox_setPenWidth);
    QComboBox * penJtStyleCombo  = new QComboBox(ui->pen_join_style_box);
    QComboBox * brushColorCombo  = new QComboBox(ui->brush_color_box);
    QComboBox * brushStyleCombo  = new QComboBox(ui->brush_style_box);
    QListView * colorList       = new QListView(shapeTypeCombo);
    QListView * penColorList    = new QListView(penColorCombo);
    QListView * penStyleList    = new QListView(penStyleCombo);
    QListView * penCapStyleList = new QListView(penCapStyleCombo);
    QListView * penJtStyleList  = new QListView(penJtStyleCombo);
    QListView * brushColorLisr  = new QListView(brushColorCombo);
    QListView * brushStyleList  = new QListView(brushStyleCombo);
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
    Shape::ShapeType shape    = getShapeType();
    Qt::GlobalColor  penColor = getPenColor();
    Qt::PenStyle     penStyle = getPenStyle();
    Qt::PenCapStyle  penCapStyle = getPenCapStyle();
    int penWidth                 = getPenWidth();
    Qt::PenJoinStyle penJtStyle = getPenJoinStyle();
    Qt::GlobalColor  brushColor = getBrushColor();
    Qt::BrushStyle   brushStyle = getBrushStyle();


    switch(shape)
    {
        case Shape::ShapeType::Line:
        {


        } break;
        case Shape::ShapeType::Polygon:
        {

        } break;
        case Shape::ShapeType::Polyline:
        {
            ui->add_stack->addWidget(ui->add_polyline_page);
            ui->menuStack->setCurrentWidget(ui->add_page);
            ui->add_stack->setCurrentWidget(ui->add_polyline_page);

            while(!on_build_it_final_button_clicked() && !on_cancel_add_shape_final_clicked())
            {} // waiter

            if(addify)
            {
                int numVerts = ui->spinBox_polyline_numverts->value();
                Polyline * thingymabob = new Polyline(ui->target, ui->target->getSize());
                setShapeNonsense(thingymabob, Shape::ShapeType::Polyline, ui->target->getSize(), penColor, penWidth, penStyle, penCapStyle, penJtStyle, brushColor, brushStyle);
                thingymabob->addNumPoints(numVerts);

                switch(numVerts)
                {
                case 8:
                {
                    QPoint *pt8 = new QPoint(ui->lineEdit_add_pl_x8->text().toInt(), ui->lineEdit_add_pl_y8->text().toInt());
                    thingymabob->addPoint(*pt8);
                }
                case 7:
                {
                    QPoint *pt7 = new QPoint(ui->lineEdit_add_pl_x7->text().toInt(), ui->lineEdit_add_pl_y7->text().toInt());
                    thingymabob->addPoint(*pt7);
                }
                case 6:
                {
                    QPoint *pt6 = new QPoint(ui->lineEdit_add_pl_x6->text().toInt(), ui->lineEdit_add_pl_y6->text().toInt());
                    thingymabob->addPoint(*pt6);
                }
                case 5:
                {
                    QPoint *pt5 = new QPoint(ui->lineEdit_add_pl_x5->text().toInt(), ui->lineEdit_add_pl_y5->text().toInt());
                    thingymabob->addPoint(*pt5);
                }
                case 4:
                {
                    QPoint *pt4 = new QPoint(ui->lineEdit_add_pl_x4->text().toInt(), ui->lineEdit_add_pl_y4->text().toInt());
                    thingymabob->addPoint(*pt4);
                }
                case 3:
                {
                    QPoint *pt3 = new QPoint(ui->lineEdit_add_pl_x3->text().toInt(), ui->lineEdit_add_pl_y3->text().toInt());
                    thingymabob->addPoint(*pt3);
                }
                case 2:
                {
                    QPoint *pt2 = new QPoint(ui->lineEdit_add_pl_x2->text().toInt(), ui->lineEdit_add_pl_y2->text().toInt());
                    thingymabob->addPoint(*pt2);
                }
                }//end switch
                QPoint *pt1 = new QPoint(ui->lineEdit_add_pl_x1->text().toInt(), ui->lineEdit_add_pl_y1->text().toInt());
                thingymabob->addPoint(*pt1);
                ui->target->addShape(thingymabob);
            }
            else
            {
                ui->menuStack->setCurrentWidget(ui->start_page);
            }
            qDebug() << "pollyline added";

        } break;
        case Shape::ShapeType::Text:
        {

        } break;
        case Shape::ShapeType::Rectangle:
        {

        } break;
        case Shape::ShapeType::Ellipse:
        {

        } break;
        default: {}
    }

}

void MainWindow::setShapeNonsense(Shape* shape, Shape::ShapeType type, int id, Qt::GlobalColor pc, int pw, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::GlobalColor bc, Qt::BrushStyle bs)
{
    shape->setShape(type);
    shape->setBrush(bc,bs);
    shape->setPen(pc, pw, ps, pcs, pjs);
    shape->setID(id);
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
    default: {return Qt::blue;}
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

void MainWindow::on_start_add_button_clicked()
{
    ui->menuStack->setCurrentWidget(ui->add_page);

}

bool MainWindow::on_build_it_final_button_clicked()
{
    addify = true;
    return true;
}

bool MainWindow::on_cancel_add_shape_final_clicked()
{
    addify = false;
    return true;
}
