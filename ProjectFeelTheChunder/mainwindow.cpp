#include "mainwindow.h"
#include "shape.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
    ui->menuStack->setCurrentWidget(ui->start_page);
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

void MainWindow::on_start_add_button_clicked()
{
    ui->menuStack->addWidget(ui->add_page);
    ui->menuStack->setCurrentWidget(ui->add_page);
    QComboBox * shapeTypeCombo   = new QComboBox(ui->shapeType_box);
    QComboBox * penColorCombo    = new QComboBox(ui->pen_color_box);
    QComboBox * penStyleCombo    = new QComboBox(ui->pen_style_box);
    QComboBox * penCapStyleCombo = new QComboBox(ui->pen_cap_style_box);
    QSpinBox  * penWidthCombo    = new QSpinBox(ui->spinBox_setPenWidth);
    QComboBox * penJtStyleCombo  = new QComboBox(ui->pen_join_style_box);
    QComboBox * brushColorCombo  = new QComboBox(ui->brush_color_box);
    QComboBox * brushStyleCombo  = new QComboBox(ui->brush_style_box);
    QListView * shapeList       = new QListView(shapeTypeCombo);
    QListView * penColorList    = new QListView(penColorCombo);
    QListView * penStyleList    = new QListView(penStyleCombo);
    QListView * penCapStyleList = new QListView(penCapStyleCombo);
    QListView * penJtStyleList  = new QListView(penJtStyleCombo);
    QListView * brushColorLisr  = new QListView(brushColorCombo);
    QListView * brushStyleList  = new QListView(brushStyleCombo);
   /* shapeList->setStyleSheet("QListView::item {                              \
                                 border-bottom: 5px solid white; margin:3px; }  \
                                 QListView::item:selected {                     \
                                 border-bottom: 5px solid black; margin:3px;    \
                                 color: black;                                  \
                                }                                               \
                                ");*/
   // shapeTypeCombo = comboTrickShapes(ui->shapeType_box);

    shapeTypeCombo->setView(shapeList);
    shapeTypeCombo->show();

    ui->comboBox->addItem("oofda");
   // comboTrickColors(ui->pen_color_box);
//    penColorCombo->setView(ui->pen_color_box);
//    penColorCombo->show();
    ui->pen_color_box->show();

    penStyleCombo = comboTrickPenStyles(penStyleCombo);
    penStyleCombo->setView(penStyleList);
    penStyleCombo->show();

    penCapStyleCombo = comboTrickPenCapStyles(penCapStyleCombo);
    penCapStyleCombo->setView(penCapStyleList);
    penCapStyleCombo->show();

    penJtStyleCombo = comboTrickPenJoinStyles(penJtStyleCombo);
    penJtStyleCombo->setView(penJtStyleList);
    penJtStyleCombo->show();

    brushStyleCombo = comboTrickBushStyle(brushStyleCombo);
    brushStyleCombo->setView(brushColorLisr);
    brushStyleCombo->show();

    comboTrickColors(brushColorCombo);
    brushColorCombo->setView(brushStyleList);
    brushColorCombo->show();



}

void MainWindow::on_start_edit_button_clicked()
{
    ui->menuStack->setCurrentWidget(ui->edit_page);
}

void MainWindow::setShapeNonsense(Shape* shape, Shape::ShapeType type, int id, Qt::GlobalColor pc, int pw, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::GlobalColor bc, Qt::BrushStyle bs)
{
    shape->setShape(type);
    shape->setBrush(bc,bs);
    shape->setPen(pc, pw, ps, pcs, pjs);
    shape->setID(id);
}

void MainWindow::comboTrickColors(QComboBox *combo)
{
    combo->addItem("white");
    combo->addItem("black");
    combo->addItem("red");
    combo->addItem("green");
    combo->addItem("blue");
    combo->addItem("cyan");
    combo->addItem("magenta");
    combo->addItem("yellow");
    combo->addItem("gray");
}

QComboBox * MainWindow::comboTrickShapes(QComboBox *combo)
{
    combo->addItem("Line");
    combo->addItem("Polyline");
    combo->addItem("Polygon");
    combo->addItem("Rectangle");
    combo->addItem("Ellipse");
    combo->addItem("Text");
    return combo;
}

QComboBox * MainWindow::comboTrickPenStyles(QComboBox *combo)
{
    combo->addItem("Solid Line");
    combo->addItem("Dash Line");
    combo->addItem("Dot Line");
    combo->addItem("Dash Dot Line");
    combo->addItem("Dash Dot Dot Line");
    combo->addItem("No Pen");
    return combo;
}

QComboBox * MainWindow::comboTrickPenCapStyles(QComboBox *combo)
{
    combo->addItem("Square Cap");
    combo->addItem("Flat Cap");
    combo->addItem("Round Cap");
    return combo;
}

QComboBox * MainWindow::comboTrickPenJoinStyles(QComboBox *combo)
{
    combo->addItem("Miter Join");
    combo->addItem("Bevel Join");
    combo->addItem("Round Join");
    return combo;
}

QComboBox * MainWindow::comboTrickBushStyle(QComboBox *combo)
{
    combo->addItem("Solid Pattern");
    combo->addItem("Vertical Pattern");
    combo->addItem("Horizontal Pattern");
    combo->addItem("No Brush");
    return combo;
}

void MainWindow::getShapeType()
{
    switch(ui->shapeType_box->currentIndex())
    {
        case 0: The_shapeType = Shape::ShapeType::Line; break;
        case 1: The_shapeType = Shape::ShapeType::Polyline; break;
        case 2: The_shapeType = Shape::ShapeType::Polygon; break;
        case 3: The_shapeType = Shape::ShapeType::Rectangle; break;
        case 4: The_shapeType = Shape::ShapeType::Ellipse; break;
        case 5: The_shapeType = Shape::ShapeType::Text; break;
        default: The_shapeType = Shape::ShapeType::Rectangle;
    }
}

void MainWindow::getPenColor()
{
    switch(ui->pen_color_box->currentIndex())
    {
    case 0: {The_penColor = Qt::white;
        break;}
    case 1: {The_penColor = Qt::black;
        break;}
    case 2: {The_penColor = Qt::red;
        break;}
    case 3: {The_penColor = Qt::green;
        break;}
    case 4: {The_penColor = Qt::blue;
        break;}
    case 5: {The_penColor = Qt::cyan;
        break;}
    case 6: {The_penColor = Qt::magenta;
        break;}
    case 7: {The_penColor = Qt::yellow;
        break;}
    case 8: {The_penColor = Qt::gray;
        break;}
    default: {The_penColor = Qt:: blue;}
    }
}

void MainWindow::getPenWidth()
{
    The_penWidth = ui->spinBox_setPenWidth->value();
}

void MainWindow::getPenStyle()
{
    switch(ui->pen_style_box->currentIndex())
    {
    case 0: {The_penStyle = Qt::SolidLine;
        break;}
    case 1: {The_penStyle = Qt::DashLine;
        break;}
    case 2: {The_penStyle = Qt::DotLine;
        break;}
    case 3: {The_penStyle = Qt::DashDotLine;
        break;}
    case 4: {The_penStyle = Qt::DashDotDotLine;
        break;}
    case 5: {The_penStyle = Qt::NoPen;
        break;}
    default: {The_penStyle = Qt::SolidLine;}
    }
}

void MainWindow::getPenCapStyle()
{
    switch (ui->pen_cap_style_box->currentIndex())
    {
    case 0: {The_penCap = Qt::SquareCap;
        break;}
    case 1: {The_penCap = Qt::FlatCap;
        break;}
    case 2: {The_penCap = Qt::RoundCap;
        break;}
    default: {The_penCap = Qt::SquareCap;}
    }
}

void MainWindow::getPenJoinStyle()
{
    switch(ui->pen_join_style_box->currentIndex())
    {
    case 0: {The_penJoinStyle = Qt::BevelJoin;
        break;}
    case 1: {The_penJoinStyle = Qt::MiterJoin;
        break;}
    case 2: {The_penJoinStyle = Qt::RoundJoin;
        break;}
    default: {The_penJoinStyle = Qt::BevelJoin;}
    }
}

void MainWindow::getBrushColor()
{
    switch(ui->brush_color_box->currentIndex())
    {
    case 0: {The_brushColor = Qt::blue;
        break;}
    case 1: {The_brushColor = Qt::red;
        break;}
    case 2: {The_brushColor = Qt::green;
        break;}
    case 3: {The_brushColor = Qt::yellow;
        break;}
    case 4: {The_brushColor = Qt::black;
        break;}
    case 5: {The_brushColor = Qt::white;
        break;}
    case 6: {The_brushColor = Qt::cyan;
        break;}
    case 7: {The_brushColor = Qt::magenta;
        break;}
    case 8: {The_brushColor = Qt::gray;
        break;}
    default: {The_brushColor = Qt::blue;}
    }
}

void MainWindow::getBrushStyle()
{
    switch (ui->brush_style_box->currentIndex())
    {
    case 0: {The_brushStyle = Qt::NoBrush;
        break;}
    case 1: {The_brushStyle = Qt::SolidPattern;
        break;}
    case 2: {The_brushStyle = Qt::HorPattern;
        break;}
    case 3: {The_brushStyle = Qt::VerPattern;
        break;}
    default: {The_brushStyle = Qt::NoBrush;}
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


bool MainWindow::on_build_it_final_button_clicked()
{
    debugPrintShapeInfo();
    addify = true;
    return true;
}

bool MainWindow::on_cancel_add_shape_final_clicked()
{
    ui->menuStack->setCurrentWidget(ui->start_page);
    addify = false;
    return true;
}

void MainWindow::debugPrintShapeInfo()
{
    qDebug() << "Shape: " << STstringAR[int(The_shapeType)];
    qDebug() << CstringAR[int(The_penColor)];
    qDebug() << PSstringAR[int(The_penStyle)];
    qDebug() << PCSstringAR[int(The_penCap)];
    qDebug() << PJSstringAR[int(The_penJoinStyle)];
    qDebug() << CstringAR[int(The_brushColor)];
    qDebug() << BSstringAR[int(The_brushStyle)];
}

void MainWindow::on_build_it_button_clicked()
{
    ui->menuStack->addWidget(ui->add_final_page);
    ui->menuStack->setCurrentWidget(ui->add_final_page);

    getShapeType();
    getPenColor();
    getPenStyle();
    getPenCapStyle();
    getPenWidth();
    getPenJoinStyle();
    getBrushColor();
    getBrushStyle();

    debugPrintShapeInfo();

    switch(The_shapeType)
    {
        case Shape::ShapeType::Line:
        {
        qDebug() << "case line";
        } break;
        case Shape::ShapeType::Polygon:
        {
            qDebug() << "case Polygon";
        } break;
        case Shape::ShapeType::Polyline:
        {
            ui->add_stack->addWidget(ui->add_polyline_page);
            ui->add_stack->setCurrentWidget(ui->add_polyline_page);

            int numVerts           = ui->spinBox_polyline_numverts->value();
            Polyline * thingymabob = new Polyline(ui->target, ui->target->getSize());
            setShapeNonsense(thingymabob, The_shapeType, ui->target->getSize(), The_penColor, The_penWidth, The_penStyle, The_penCap, The_penJoinStyle, The_brushColor, The_brushStyle);
            debugPrintShapeInfo();
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

            qDebug() << "pollyline added";

        } break;
        case Shape::ShapeType::Text:
        {
        qDebug() << "case text";
        } break;
        case Shape::ShapeType::Rectangle:
        {
        qDebug() << "case rectangle";
        } break;
        case Shape::ShapeType::Ellipse:
        {
            qDebug() << "case ellipse";
        } break;
        default: {}
    }



   // ui->menuStack->setCurrentWidget(ui->start_page);
}

void MainWindow::on_cancel_button_clicked()
{
    addify = false;
    ui->menuStack->setCurrentWidget(ui->start_page);
}

void MainWindow::on_cancel_button_5_clicked()
{
    ui->menuStack->setCurrentWidget(ui->start_page);
}

void MainWindow::on_cancel_button_6_clicked()
{
    ui->menuStack->setCurrentWidget(ui->start_page);
}

void MainWindow::on_start_delete_button_clicked()
{
    ui->menuStack->setCurrentWidget(ui->delete_page);
}
