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
    ui->menuStack->addWidget(ui->add_final_page);
    ui->menuStack->addWidget(ui->add_page);
    ui->menuStack->addWidget(ui->edit_page);
    ui->menuStack->addWidget(ui->delete_page);
    ui->add_stack->addWidget(ui->add_polyline_page);
    ui->add_stack->addWidget(ui->add_line_page);
    ui->add_stack->addWidget(ui->add_polygon_page);
    ui->add_stack->addWidget(ui->add_text_page);
    ui->add_stack->addWidget(ui->add_rectangle_page);
    ui->add_stack->addWidget(ui->add_ellipse_page);

//    ui->start_add_button->setEnabled(false);
//    ui->start_edit_button->setEnabled(false);
//    ui->start_delete_button->setEnabled(false);

    comboTrickShapes(ui->shapeType_box);
    comboTrickColors(ui->pen_color_box);
    comboTrickPenStyles(ui->pen_style_box);
    comboTrickPenCapStyles(ui->pen_cap_style_box);
    comboTrickPenJoinStyles(ui->pen_join_style_box);
    comboTrickBushStyle(ui->brush_style_box);
    comboTrickColors(ui->brush_color_box);
    comboTrickFlag(ui->text_align_box);
    comboTrickFontFam(ui->text_font_box);
    comboTrickFontWeight(ui->text_weight_box);
    comboTrickColors(ui->text_color_box);
    comboTrickFontStyle(ui->text_style_box);
    comboTrickColors(ui->pen_color_edit_box);
    comboTrickPenStyles(ui->pen_style_edit_box);
    comboTrickPenCapStyles(ui->pen_cap_style_edit_box);
    comboTrickPenJoinStyles(ui->pen_join_style_edit_box);
    comboTrickBushStyle(ui->brush_style_edit_box);
    comboTrickColors(ui->brush_color_edit_box);


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

    ui->menuStack->setCurrentWidget(ui->add_page);

    ui->shapeType_box->show();
    ui->pen_color_box->show();
    ui->pen_style_box->show();
    ui->pen_cap_style_box->show();
    ui->pen_join_style_box->show();
    ui->brush_style_box->show();
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
    combo->addItem("White");
    combo->addItem("Black");
    combo->addItem("Red");
    combo->addItem("Green");
    combo->addItem("Blue");
    combo->addItem("Cyan");
    combo->addItem("Magenta");
    combo->addItem("Yellow");
    combo->addItem("Gray");
}

void MainWindow::comboTrickShapes(QComboBox *combo)
{
    combo->addItem("Line");
    combo->addItem("Polyline");
    combo->addItem("Polygon");
    combo->addItem("Rectangle");
    combo->addItem("Ellipse");
    combo->addItem("Text");
}

void MainWindow::comboTrickPenStyles(QComboBox *combo)
{
    combo->addItem("Solid Line");
    combo->addItem("Dash Line");
    combo->addItem("Dot Line");
    combo->addItem("Dash Dot Line");
    combo->addItem("Dash Dot Dot Line");
    combo->addItem("No Pen");
}

void MainWindow::comboTrickPenCapStyles(QComboBox *combo)
{
    combo->addItem("Square Cap");
    combo->addItem("Flat Cap");
    combo->addItem("Round Cap");
}

void MainWindow::comboTrickPenJoinStyles(QComboBox *combo)
{
    combo->addItem("Miter Join");
    combo->addItem("Bevel Join");
    combo->addItem("Round Join");
}

void MainWindow::comboTrickBushStyle(QComboBox *combo)
{
    combo->addItem("Solid Pattern");
    combo->addItem("Vertical Pattern");
    combo->addItem("Horizontal Pattern");
    combo->addItem("No Brush");
}

void MainWindow::comboTrickFlag(QComboBox *combo)
{
    combo->addItem("Align Left");
    combo->addItem("Align Right");
    combo->addItem("Align H Center");
    combo->addItem("Align Justify");
    combo->addItem("Align Top");
    combo->addItem("Align Bottom");
    combo->addItem("Align V Center");
    combo->addItem("Align Center");
}

void MainWindow::comboTrickFontFam(QComboBox *combo)
{
    combo->addItem("Comic Sans MS");
    combo->addItem("Courier");
    combo->addItem("Helvetica");
    combo->addItem("Times");
}

void MainWindow::comboTrickFontWeight(QComboBox *combo)
{
    combo->addItem("Thin");
    combo->addItem("Light");
    combo->addItem("Normal");
    combo->addItem("Bold");
}

void MainWindow::comboTrickFontStyle(QComboBox *combo)
{
    combo->addItem("Normal");
    combo->addItem("Italic");
    combo->addItem("Oblique");
}

void MainWindow::getShapeType(QComboBox * combo)
{
    switch(combo->currentIndex())
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

void MainWindow::getPenColor(QComboBox * combo)
{
    switch(combo->currentIndex())
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

void MainWindow::getPenWidth(QSpinBox * spinster)
{
    The_penWidth = spinster->value();
}

void MainWindow::getPenStyle(QComboBox * combo)
{
    switch(combo->currentIndex())
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

void MainWindow::getPenCapStyle(QComboBox * combo)
{
    switch (combo->currentIndex())
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

void MainWindow::getPenJoinStyle(QComboBox * combo)
{
    switch(combo->currentIndex())
    {
    case 0: {The_penJoinStyle = Qt::MiterJoin;
        break;}
    case 1: {The_penJoinStyle = Qt::BevelJoin;
        break;}
    case 2: {The_penJoinStyle = Qt::RoundJoin;
        break;}
    default: {The_penJoinStyle = Qt::BevelJoin;}
    }
}

void MainWindow::getBrushColor(QComboBox * combo)
{
    switch(combo->currentIndex())
    {
    case 0: {The_brushColor = Qt::white;
        break;}
    case 1: {The_brushColor = Qt::black;
        break;}
    case 2: {The_brushColor = Qt::red;
        break;}
    case 3: {The_brushColor = Qt::green;
        break;}
    case 4: {The_brushColor = Qt::blue;
        break;}
    case 5: {The_brushColor = Qt::cyan;
        break;}
    case 6: {The_brushColor = Qt::magenta;
        break;}
    case 7: {The_brushColor = Qt::yellow;
        break;}
    case 8: {The_brushColor = Qt::gray;
        break;}
    default: {The_brushColor = Qt::blue;}
    }
}

void MainWindow::getBrushStyle(QComboBox * combo)
{
    switch (combo->currentIndex())
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

Qt::AlignmentFlag MainWindow::getAlign(QComboBox * combo)
{
    switch(combo->currentIndex())
    {
    case 0: {return Qt::AlignLeft;
        break;}
    case 1: {return Qt::AlignRight;
        break;}
    case 2: {return Qt::AlignHCenter;
        break;}
    case 3: {return Qt::AlignJustify;
        break;}
    case 4: {return Qt::AlignTop;
        break;}
    case 5: {return Qt::AlignBottom;
        break;}
    case 6: {return Qt::AlignVCenter;
        break;}
    case 7: {return Qt::AlignTop;
        break;}
    case 8: {return Qt::AlignTop;
        break;}
    default: return Qt::AlignCenter;
    }
}

Qt::GlobalColor MainWindow::getTextColor(QComboBox * combo)
{
    switch(combo->currentIndex())
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

QFont::Weight MainWindow::getTextWeight(QComboBox * combo)
{
    switch(combo->currentIndex())
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

QFont::Style MainWindow::getTextStyle(QComboBox * combo)
{
    switch(combo->currentIndex())
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

QString MainWindow::getFontFamily(QComboBox * combo)
{
   return combo->currentText();
}

void MainWindow::on_build_it_final_button_clicked()
{
    debugPrintShapeInfo();
    switch(The_shapeType)
    {
        case Shape::ShapeType::Line:
        {
            Line * thingymabob = new Line(ui->target, ui->target->getSize());

            int x1 = ui->line_pt1_x_box->text().toInt();
            int y1 = ui->line_pt1_y_box->text().toInt();
            int x2 = ui->line_pt2_x_box->text().toInt();
            int y2 = ui->line_pt2_y_y->text().toInt();

            QPoint * pt1 = new QPoint(x1, y1);
            QPoint * pt2 = new QPoint(x2, y2);
            thingymabob->setPoints(*pt1, *pt2);
            ui->target->addShape(thingymabob);
        } break;
        case Shape::ShapeType::Polygon:
        {
            int numVerts           = ui->spinBox_polyline_numverts->value();
            Polygon * thingymabob = new Polygon(ui->target, ui->target->getSize());
            setShapeNonsense(thingymabob, The_shapeType, ui->target->getSize(), The_penColor, The_penWidth, The_penStyle, The_penCap, The_penJoinStyle, The_brushColor, The_brushStyle);

            thingymabob->setNumVertices(numVerts);

            switch(numVerts)
            {
            case 8:
            {
                QPoint *pt8 = new QPoint(ui->lineEdit_add_pl_x8_2->text().toInt(), ui->lineEdit_add_pl_y8_2->text().toInt());
                thingymabob->addVertex(*pt8);
            }
            case 7:
            {
                QPoint *pt7 = new QPoint(ui->lineEdit_add_pl_x7_2->text().toInt(), ui->lineEdit_add_pl_y7_2->text().toInt());
                thingymabob->addVertex(*pt7);
            }
            case 6:
            {
                QPoint *pt6 = new QPoint(ui->lineEdit_add_pl_x6_2->text().toInt(), ui->lineEdit_add_pl_y6_2->text().toInt());
                thingymabob->addVertex(*pt6);
            }
            case 5:
            {
                QPoint *pt5 = new QPoint(ui->lineEdit_add_pl_x5_2->text().toInt(), ui->lineEdit_add_pl_y5_2->text().toInt());
                thingymabob->addVertex(*pt5);
            }
            case 4:
            {
                QPoint *pt4 = new QPoint(ui->lineEdit_add_pl_x4_2->text().toInt(), ui->lineEdit_add_pl_y4_2->text().toInt());
                thingymabob->addVertex(*pt4);
            }
            case 3:
            {
                QPoint *pt3 = new QPoint(ui->lineEdit_add_pl_x3_2->text().toInt(), ui->lineEdit_add_pl_y3_2->text().toInt());
                thingymabob->addVertex(*pt3);
            }
            }//end switch
            QPoint *pt2 = new QPoint(ui->lineEdit_add_pl_x2_2->text().toInt(), ui->lineEdit_add_pl_y2_2->text().toInt());
            thingymabob->addVertex(*pt2);
            QPoint *pt1 = new QPoint(ui->lineEdit_add_pl_x1_2->text().toInt(), ui->lineEdit_add_pl_y1_2->text().toInt());
            thingymabob->addVertex(*pt1);
            ui->target->addShape(thingymabob);

            qDebug() << "pollygon added";

        } break;
        case Shape::ShapeType::Polyline:
        {
            int numVerts           = ui->spinBox_polyline_numverts->value();
            Polyline * thingymabob = new Polyline(ui->target, ui->target->getSize());
            setShapeNonsense(thingymabob, The_shapeType, ui->target->getSize(), The_penColor, The_penWidth, The_penStyle, The_penCap, The_penJoinStyle, The_brushColor, The_brushStyle);

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
            Text * thingymabob = new Text(ui->target, ui->target->getSize());
            int length = ui->text_length_box->text().toInt();
            int width  = ui->text_width_box->text().toInt();
            QString text = ui->add_text_string_box->text();
            int x = ui->text_x_box->text().toInt();
            int y = ui->text__y_box->text().toInt();
            int size = ui->text_font_size_spinbox->value();
            thingymabob->setDimensions(width, length);
            thingymabob->setLocation(x,y);
            thingymabob->setFlag(getAlign(ui->text_align_box));
            thingymabob->setFont(getFontFamily(ui->text_font_box), getTextStyle(ui->text_style_box), size, getTextWeight(ui->text_weight_box), getTextColor(ui->text_color_box));
            thingymabob->setText(text);
            ui->target->addShape(thingymabob);
        } break;
        case Shape::ShapeType::Rectangle:
        {
            Rectangle * thingymabob = new Rectangle(ui->target, ui->target->getSize());

            int width  = ui->add_rect_width_box->text().toInt();
            int height = ui->add_rect_length_box->text().toInt();

            int x = ui->rect_x_box->text().toInt();
            int y = ui->rect_y_box->text().toInt();

            thingymabob->setAll(width, height, x, y);
            ui->target->addShape(thingymabob);
        } break;
        case Shape::ShapeType::Ellipse:
        {
            Ellipse * thingymabob = new Ellipse(ui->target, ui->target->getSize());

            int width  = ui->add_ellipse_width_box_2->text().toInt();
            int length = ui->add_ellipse_length_box->text().toInt();

            int x = ui->ellipse_x_box->text().toInt();
            int y = ui->ellipse_y_box->text().toInt();

            thingymabob->setDimensions(width, length);
            thingymabob->setLocation(x,y);
            ui->target->addShape(thingymabob);
        } break;
        default: {qDebug() << "Error finding shape type";}
    }

    ui->menuStack->setCurrentWidget(ui->start_page);
}

void MainWindow::on_cancel_add_shape_final_clicked()
{
    ui->menuStack->setCurrentWidget(ui->start_page);
}

void MainWindow::debugPrintShapeInfo()
{
    qDebug() << STstringAR[int(The_shapeType) - 1];
    qDebug() << CstringAR[int(The_penColor) - 1];
    qDebug() << PSstringAR[int(The_penStyle) - 1];
    qDebug() << PCSstringAR[int(The_penCap) - 1];
    qDebug() << PJSstringAR[int(The_penJoinStyle) - 1];
    qDebug() << CstringAR[int(The_brushColor) - 1];
    qDebug() << BSstringAR[int(The_brushStyle) - 1];
}

void MainWindow::on_build_it_button_clicked()
{

    ui->menuStack->setCurrentWidget(ui->add_final_page);

    getShapeType(ui->shapeType_box);
    getPenColor(ui->pen_color_box);
    getPenStyle(ui->pen_style_box);
    getPenCapStyle(ui->pen_cap_style_box);
    getPenWidth(ui->spinBox_setPenWidth);
    getPenJoinStyle(ui->pen_join_style_box);
    getBrushColor(ui->brush_color_box);
    getBrushStyle(ui->brush_style_box);

    debugPrintShapeInfo();

    switch(The_shapeType)
    {
        case Shape::ShapeType::Line:
        {
            ui->add_stack->setCurrentWidget(ui->add_line_page);
        } break;
        case Shape::ShapeType::Polygon:
        {
            ui->add_stack->setCurrentWidget(ui->add_polygon_page);
        } break;
        case Shape::ShapeType::Polyline:
        {
            ui->add_stack->setCurrentWidget(ui->add_polyline_page);
        } break;
        case Shape::ShapeType::Text:
        {
            ui->add_stack->setCurrentWidget(ui->add_text_page);
        } break;
        case Shape::ShapeType::Rectangle:
        {
            ui->add_stack->setCurrentWidget(ui->add_rectangle_page);
        } break;
        case Shape::ShapeType::Ellipse:
        {
            ui->add_stack->setCurrentWidget(ui->add_ellipse_page);
        } break;
        default: {qDebug() << "Error finding shape type";}
    }

}

void MainWindow::on_cancel_button_clicked()
{

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

void MainWindow::on_erase_it_button_clicked()
{
    int id = ui->shape_id_delete_spin->value();
    ui->target->chopShape(id);
}

void MainWindow::on_change_it_button_clicked()
{
    int id = ui->shapeID_edit_spin->value();
    getPenColor(ui->pen_color_edit_box);
    getPenStyle(ui->pen_style_edit_box);
    getPenCapStyle(ui->pen_cap_style_edit_box);
    getPenJoinStyle(ui->pen_join_style_edit_box);
    getPenWidth(ui->pen_width_edit_spin);
    getBrushColor(ui->brush_color_edit_box);
    getBrushStyle(ui->brush_style_edit_box);


}
