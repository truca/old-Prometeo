/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 4. Apr 02:04:01 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <mapa.h>
#include "plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    Mapa *webView;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_8;
    QSlider *verticalSlider_altura;
    QDoubleSpinBox *doubleSpinBox_altura;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_8;
    QProgressBar *progressBar_bateria;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_9;
    QDial *dialYaw;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLabel *label_altura;
    QLabel *label_3;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLabel *label_yaw;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_armarDesarmarMotores;
    QPushButton *pushButton_despegar;
    QPushButton *pushButton_aterrizar;
    QPushButton *pushButton_casa;
    QSpacerItem *verticalSpacer;
    QPushButton *boton_ruta;
    QPushButton *boton_view;
    QPushButton *boton_home;
    QPushButton *reset_button;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_gotoHome;
    QPushButton *Startlog;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_read_params;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_XY_P;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_XY_D;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_4;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_yaw_P;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_yaw_D;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_3;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_altura_P;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_altura_D;
    Plot *widgetPlot;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *textBrowser_consola;
    QWidget *tab;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(716, 492);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        webView = new Mapa(centralWidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        verticalLayout = new QVBoxLayout(webView);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(webView);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane { border:0px; }\n"
"QTabWidget::tab-bar { alignment: center; }"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        horizontalLayout_2 = new QHBoxLayout(tab_1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(tab_1);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Grande"));
        widget_5->setFont(font);
        widget_5->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_7 = new QHBoxLayout(widget_5);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        widget_10 = new QWidget(widget_5);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 255);"));
        verticalLayout_7 = new QVBoxLayout(widget_10);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(2, 2, 2, 2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        widget_11 = new QWidget(widget_10);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_8 = new QHBoxLayout(widget_11);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalSlider_altura = new QSlider(widget_11);
        verticalSlider_altura->setObjectName(QString::fromUtf8("verticalSlider_altura"));
        verticalSlider_altura->setMinimum(-100);
        verticalSlider_altura->setMaximum(100);
        verticalSlider_altura->setOrientation(Qt::Vertical);
        verticalSlider_altura->setInvertedControls(false);
        verticalSlider_altura->setTickPosition(QSlider::TicksBothSides);
        verticalSlider_altura->setTickInterval(20);

        horizontalLayout_8->addWidget(verticalSlider_altura);


        verticalLayout_7->addWidget(widget_11);

        doubleSpinBox_altura = new QDoubleSpinBox(widget_10);
        doubleSpinBox_altura->setObjectName(QString::fromUtf8("doubleSpinBox_altura"));
        doubleSpinBox_altura->setDecimals(1);
        doubleSpinBox_altura->setMinimum(-100);
        doubleSpinBox_altura->setMaximum(1000);
        doubleSpinBox_altura->setSingleStep(0.1);

        verticalLayout_7->addWidget(doubleSpinBox_altura);


        horizontalLayout_7->addWidget(widget_10);

        widget_9 = new QWidget(widget_5);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_8 = new QVBoxLayout(widget_9);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        progressBar_bateria = new QProgressBar(widget_9);
        progressBar_bateria->setObjectName(QString::fromUtf8("progressBar_bateria"));
        progressBar_bateria->setMinimumSize(QSize(70, 0));
        progressBar_bateria->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"border: 1px solid black;\n"
"text-align: center;\n"
"padding: 1px;\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"stop: 0 #fff,\n"
"stop: 0.4999 #eee,\n"
"stop: 0.5 #ddd,\n"
"stop: 1 #eee );\n"
"width: 15px;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"stop: 0 #78d,\n"
"stop: 0.4999 #46a,\n"
"stop: 0.5 #45a,\n"
"stop: 1 #238 );\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"border: 1px solid black;\n"
"}"));
        progressBar_bateria->setMaximum(13000);
        progressBar_bateria->setValue(10000);
        progressBar_bateria->setOrientation(Qt::Vertical);
        progressBar_bateria->setInvertedAppearance(false);
        progressBar_bateria->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout_8->addWidget(progressBar_bateria);

        widget_12 = new QWidget(widget_9);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 227);"));
        verticalLayout_9 = new QVBoxLayout(widget_12);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(5, 2, 5, 5);
        dialYaw = new QDial(widget_12);
        dialYaw->setObjectName(QString::fromUtf8("dialYaw"));
        dialYaw->setMinimum(-180);
        dialYaw->setMaximum(180);
        dialYaw->setOrientation(Qt::Horizontal);
        dialYaw->setInvertedAppearance(false);
        dialYaw->setInvertedControls(false);
        dialYaw->setWrapping(true);
        dialYaw->setNotchTarget(15);
        dialYaw->setNotchesVisible(true);

        verticalLayout_9->addWidget(dialYaw);

        widget_7 = new QWidget(widget_12);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(widget_7);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        label_altura = new QLabel(widget_7);
        label_altura->setObjectName(QString::fromUtf8("label_altura"));
        label_altura->setMinimumSize(QSize(30, 0));
        label_altura->setMaximumSize(QSize(30, 16777215));
        label_altura->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_altura);

        label_3 = new QLabel(widget_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);


        verticalLayout_9->addWidget(widget_7);

        widget_8 = new QWidget(widget_12);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_6 = new QHBoxLayout(widget_8);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(widget_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        label_yaw = new QLabel(widget_8);
        label_yaw->setObjectName(QString::fromUtf8("label_yaw"));
        label_yaw->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_yaw);

        label_6 = new QLabel(widget_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);


        verticalLayout_9->addWidget(widget_8);


        verticalLayout_8->addWidget(widget_12);


        horizontalLayout_7->addWidget(widget_9);


        verticalLayout_6->addWidget(widget_5);


        horizontalLayout_4->addWidget(widget_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        horizontalLayout->addWidget(widget_6);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(200, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_armarDesarmarMotores = new QPushButton(widget_3);
        pushButton_armarDesarmarMotores->setObjectName(QString::fromUtf8("pushButton_armarDesarmarMotores"));

        verticalLayout_3->addWidget(pushButton_armarDesarmarMotores);

        pushButton_despegar = new QPushButton(widget_3);
        pushButton_despegar->setObjectName(QString::fromUtf8("pushButton_despegar"));

        verticalLayout_3->addWidget(pushButton_despegar);

        pushButton_aterrizar = new QPushButton(widget_3);
        pushButton_aterrizar->setObjectName(QString::fromUtf8("pushButton_aterrizar"));

        verticalLayout_3->addWidget(pushButton_aterrizar);

        pushButton_casa = new QPushButton(widget_3);
        pushButton_casa->setObjectName(QString::fromUtf8("pushButton_casa"));

        verticalLayout_3->addWidget(pushButton_casa);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        boton_ruta = new QPushButton(widget_3);
        boton_ruta->setObjectName(QString::fromUtf8("boton_ruta"));
        boton_ruta->setAutoFillBackground(false);
        boton_ruta->setStyleSheet(QString::fromUtf8(""));
        boton_ruta->setCheckable(true);
        boton_ruta->setChecked(false);
        boton_ruta->setFlat(false);

        verticalLayout_3->addWidget(boton_ruta);

        boton_view = new QPushButton(widget_3);
        boton_view->setObjectName(QString::fromUtf8("boton_view"));
        boton_view->setCheckable(true);

        verticalLayout_3->addWidget(boton_view);

        boton_home = new QPushButton(widget_3);
        boton_home->setObjectName(QString::fromUtf8("boton_home"));
        boton_home->setEnabled(true);
        boton_home->setCheckable(true);

        verticalLayout_3->addWidget(boton_home);

        reset_button = new QPushButton(widget_3);
        reset_button->setObjectName(QString::fromUtf8("reset_button"));

        verticalLayout_3->addWidget(reset_button);


        horizontalLayout->addWidget(widget_3);


        horizontalLayout_2->addWidget(widget);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        widget_15 = new QWidget(widget_2);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        horizontalLayout_10 = new QHBoxLayout(widget_15);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_gotoHome = new QPushButton(widget_15);
        pushButton_gotoHome->setObjectName(QString::fromUtf8("pushButton_gotoHome"));

        horizontalLayout_10->addWidget(pushButton_gotoHome);

        Startlog = new QPushButton(widget_15);
        Startlog->setObjectName(QString::fromUtf8("Startlog"));

        horizontalLayout_10->addWidget(Startlog);


        verticalLayout_2->addWidget(widget_15);

        widget_13 = new QWidget(widget_2);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        horizontalLayout_9 = new QHBoxLayout(widget_13);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        widget_14 = new QWidget(widget_13);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        widget_14->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 255);"));
        horizontalLayout_11 = new QHBoxLayout(widget_14);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        pushButton_read_params = new QPushButton(widget_14);
        pushButton_read_params->setObjectName(QString::fromUtf8("pushButton_read_params"));

        horizontalLayout_11->addWidget(pushButton_read_params);

        groupBox = new QGroupBox(widget_14);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        doubleSpinBox_XY_P = new QDoubleSpinBox(groupBox);
        doubleSpinBox_XY_P->setObjectName(QString::fromUtf8("doubleSpinBox_XY_P"));
        doubleSpinBox_XY_P->setMaximum(1000);

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_XY_P);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        doubleSpinBox_XY_D = new QDoubleSpinBox(groupBox);
        doubleSpinBox_XY_D->setObjectName(QString::fromUtf8("doubleSpinBox_XY_D"));
        doubleSpinBox_XY_D->setMaximum(1000);

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_XY_D);


        horizontalLayout_11->addWidget(groupBox);

        groupBox_3 = new QGroupBox(widget_14);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        formLayout_4 = new QFormLayout(groupBox_3);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_9);

        doubleSpinBox_yaw_P = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_yaw_P->setObjectName(QString::fromUtf8("doubleSpinBox_yaw_P"));
        doubleSpinBox_yaw_P->setMaximum(1000);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_yaw_P);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_10);

        doubleSpinBox_yaw_D = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_yaw_D->setObjectName(QString::fromUtf8("doubleSpinBox_yaw_D"));
        doubleSpinBox_yaw_D->setMaximum(1000);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_yaw_D);


        horizontalLayout_11->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(widget_14);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_3 = new QFormLayout(groupBox_2);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_7);

        doubleSpinBox_altura_P = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_altura_P->setObjectName(QString::fromUtf8("doubleSpinBox_altura_P"));
        doubleSpinBox_altura_P->setMaximum(1000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_altura_P);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_8);

        doubleSpinBox_altura_D = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_altura_D->setObjectName(QString::fromUtf8("doubleSpinBox_altura_D"));
        doubleSpinBox_altura_D->setMaximum(1000);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_altura_D);


        horizontalLayout_11->addWidget(groupBox_2);


        horizontalLayout_9->addWidget(widget_14);


        verticalLayout_2->addWidget(widget_13);

        widgetPlot = new Plot(widget_2);
        widgetPlot->setObjectName(QString::fromUtf8("widgetPlot"));
        widgetPlot->setMinimumSize(QSize(100, 100));

        verticalLayout_2->addWidget(widgetPlot);


        verticalLayout_5->addWidget(widget_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        textBrowser_consola = new QTextBrowser(tab_3);
        textBrowser_consola->setObjectName(QString::fromUtf8("textBrowser_consola"));

        verticalLayout_4->addWidget(textBrowser_consola);

        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);


        horizontalLayout_3->addWidget(webView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 716, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        progressBar_bateria->setFormat(QApplication::translate("MainWindow", "%vmV", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Altura:", 0, QApplication::UnicodeUTF8));
        label_altura->setText(QApplication::translate("MainWindow", "1000", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "m", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "yaw", 0, QApplication::UnicodeUTF8));
        label_yaw->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\302\272", 0, QApplication::UnicodeUTF8));
        pushButton_armarDesarmarMotores->setText(QApplication::translate("MainWindow", "Motores", 0, QApplication::UnicodeUTF8));
        pushButton_despegar->setText(QApplication::translate("MainWindow", "Despegar", 0, QApplication::UnicodeUTF8));
        pushButton_aterrizar->setText(QApplication::translate("MainWindow", "Aterrizar", 0, QApplication::UnicodeUTF8));
        pushButton_casa->setText(QApplication::translate("MainWindow", "Ir a Casa", 0, QApplication::UnicodeUTF8));
        boton_ruta->setText(QApplication::translate("MainWindow", "Ir a (G)", 0, QApplication::UnicodeUTF8));
        boton_view->setText(QApplication::translate("MainWindow", "Ver (V)", 0, QApplication::UnicodeUTF8));
        boton_home->setText(QApplication::translate("MainWindow", "Casa (H)", 0, QApplication::UnicodeUTF8));
        reset_button->setText(QApplication::translate("MainWindow", "Limpiar (R)", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "Comandos", 0, QApplication::UnicodeUTF8));
        pushButton_gotoHome->setText(QApplication::translate("MainWindow", "Goto Home", 0, QApplication::UnicodeUTF8));
        Startlog->setText(QApplication::translate("MainWindow", "Start log", 0, QApplication::UnicodeUTF8));
        pushButton_read_params->setText(QApplication::translate("MainWindow", "READ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "XY", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "P:", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_XY_P->setPrefix(QString());
        label_5->setText(QApplication::translate("MainWindow", "D:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Yaw", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "P:", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_yaw_P->setPrefix(QString());
        label_10->setText(QApplication::translate("MainWindow", "D:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Altura", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "P:", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_altura_P->setPrefix(QString());
        label_8->setText(QApplication::translate("MainWindow", "D:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Configuracion", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Consola", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
