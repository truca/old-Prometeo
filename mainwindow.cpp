#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QFile>
#include <QScrollBar>
#include <QKeyEvent>
#include <stdio.h>
#include "plot.h"

#include <QWebFrame>

void MainWindow::keyPressEvent(QKeyEvent* event)
{
//    qWarning("keyPressEvent %s", event->text().toAscii().data());
    if(event->key() == Qt::Key_V) {
        on_boton_view_clicked();
    } else if(event->key() == Qt::Key_G) {
        on_boton_ruta_clicked();
    } else if(event->key() == Qt::Key_R) {
        on_reset_button_clicked();
    } else if(event->key() == Qt::Key_H) {
        on_boton_home_clicked();
    } else if(event->key() == Qt::Key_F) {
        static bool isFullScreen;
        if(isFullScreen)
            showFullScreen();
        else
            showNormal();
        isFullScreen = !isFullScreen;
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    rcv = new PortListener();
    rcv->selectPortName(this); // preguntando a usuario por puerta serial

    //QGMaps
    WaypointMode=false;
    HomeMode=false;
    ViewMode=false;
    firstUAVPos=false;

    ui->setupUi(this);
    showFullScreen();
//    setFocusPolicy(Qt::StrongFocus);

    ui->widgetPlot->addVariable(Qt::red);

    ui->widgetPlot->addVariable(Qt::blue);
    //fileB("blue.csv");
    //fileB.open(QIODevice::WriteOnly | QIODevice::Text);
    t = new QTimer();
    connect(t,SIGNAL(timeout()), this, SLOT(timeout()));
    //ui->pushButtonGo->setStyleSheet("background-color: rgb(0, 255, 0);");
    log=false;


    rcv->start();
//    connect(ui->pushButton_armarDesarmarMotores, SIGNAL(clicked()), rcv, SLOT(SendArmarDesarmarMotores()));
    connect(ui->pushButton_despegar, SIGNAL(clicked()),             rcv, SLOT(SendDespegar()));
    connect(ui->pushButton_aterrizar, SIGNAL(clicked()),            rcv, SLOT(SendAterrizar()));
    connect(ui->pushButton_gotoHome, SIGNAL(clicked()),             rcv, SLOT(SendGotoHome()));
    connect(rcv, SIGNAL(newParamValue(enum Tipo_Param, float)), this, SLOT(newParamValue(enum Tipo_Param, float)));
    connect(rcv,SIGNAL(console(QString)), this, SLOT(insertTextConsola(QString)));

    connect(rcv, SIGNAL(newGPS(double,double)), ui->webView, SLOT(addPosition(double,double)));
    connect(rcv, SIGNAL(newAltura(double)), this, SLOT(newAltura(double)));
    connect(rcv, SIGNAL(newYaw(double)), this, SLOT(newYaw(double)));

    timerSetYawToHome_valueChanged.setSingleShot(true);
    connect(&timerSetYawToHome_valueChanged, SIGNAL(timeout()), this, SLOT(dialYaw_valueChanged_timeout()));

    connect(ui->webView, SIGNAL(setGoto(double,double)), this, SLOT(setGoto(double,double)));
    connect(ui->webView, SIGNAL(setView(double,double)), this, SLOT(setView(double,double)));
    connect(ui->webView, SIGNAL(setHome(double,double)), this, SLOT(setHome(double,double)));


    connect(&timerSetAltura, SIGNAL(timeout()), this, SLOT(timerSetAltura_timeout()));
}

void MainWindow::newParamValue(enum Tipo_Param tipo, float value) {
    switch(tipo) {
      case TIPO_PARAM_ALTURA_P:
        ui->doubleSpinBox_altura_P->setValue(value);
        break;
      case TIPO_PARAM_ALTURA_D:
        ui->doubleSpinBox_altura_D->setValue(value);
        break;
      case TIPO_PARAM_XY_P:
        ui->doubleSpinBox_XY_P->setValue(value);
        break;
      case TIPO_PARAM_XY_D:
        ui->doubleSpinBox_XY_D->setValue(value);
        break;
      case TIPO_PARAM_YAW_P:
        ui->doubleSpinBox_yaw_P->setValue(value);
        break;
      case TIPO_PARAM_YAW_D:
        ui->doubleSpinBox_yaw_D->setValue(value);
        break;
      case TIPO_PARAM_BATERIA:
        ui->progressBar_bateria->setValue((int)value);
        break;
      case TIPO_PARAM_ALTURA:
        {
        QList<double> data;
        data.append(value);
        data.append(0);
        ui->widgetPlot->newData(data);
        break;
        }
    }
}

void MainWindow::insertTextConsola(QString string) {
    ui->textBrowser_consola->insertPlainText(string);
    QScrollBar *sb = ui->textBrowser_consola->verticalScrollBar();
    sb->setValue(sb->maximum());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    static double t=0;
    QList<double> data;
    float time=t;
    float redValue=5*cos(t);
    float blueValue=sin(t);
    data.append(redValue);
    data.append(blueValue);
    if(log){
        QFile fileR("red.csv");
        fileR.open(QIODevice::Append | QIODevice::Text);
        fileR.write(QString::number(time).toLocal8Bit().data());
        fileR.write(";");
        fileR.write(QString::number(redValue).toLocal8Bit().data());
        fileR.write("\n");
        fileR.close();

        QFile fileB("blue.csv");
        fileB.open(QIODevice::Append | QIODevice::Text);
        fileB.write(QString::number(time).toLocal8Bit().data());
        fileB.write(";");
        fileB.write(QString::number(blueValue).toLocal8Bit().data());
        fileB.write("\n");
        fileB.close();
        //fileB.write(QString::number(time)+";"+QString::number(blueValue)+"\n");
    }
    ui->widgetPlot->newData(data);
    t += 0.1;
}

void MainWindow::on_Startlog_clicked()
{
    if(ui->Startlog->text() == "Start log") {
        log=true;
        ui->Startlog->setText("Stop");
        //ui->Startlog->setStyleSheet("background-color: rgb(0, 255, 0);");
    } else {
        log=false;
        ui->Startlog->setText("Start log");
        //ui->Startlog->setStyleSheet("background-color: rgb(255, 0, 0);");
    }
}

void MainWindow::on_boton_ruta_clicked(){
    ui->webView->page()->mainFrame()->evaluateJavaScript("swapWaypointMode();");
    if(HomeMode){
        swapHomeUI();
        ui->webView->page()->mainFrame()->evaluateJavaScript("swapHomeMode();");
    }
    if(ViewMode){
        swapViewUI();
        ui->webView->page()->mainFrame()->evaluateJavaScript("swapViewMode();");
    }
    swapWaypointUI();
}

void MainWindow::on_boton_home_clicked(){
    ui->webView->page()->mainFrame()->evaluateJavaScript("swapHomeMode();");
    if(WaypointMode){
        swapWaypointUI();
        ui->webView->page()->mainFrame()->evaluateJavaScript("swapWaypointMode();");
    }
    if(ViewMode){
        swapViewUI();
        ui->webView->page()->mainFrame()->evaluateJavaScript("swapViewMode();");
    }
    swapHomeUI();
}

void MainWindow::swapWaypointUI(){
    if(!WaypointMode){
        WaypointMode=true;
        ui->boton_ruta->setChecked(true);
    }
    else{
        WaypointMode=false;
        ui->boton_ruta->setChecked(false);
    }
}

void MainWindow::swapViewUI(){
    if(!ViewMode){
        ViewMode=true;
        ui->boton_view->setChecked(true);
    }
    else{
        ViewMode=false;
        ui->boton_view->setChecked(false);
    }
}

void MainWindow::swapHomeUI(){
    if(!HomeMode){
        HomeMode=true;
        ui->boton_home->setChecked(true);
    }
    else{
        HomeMode=false;
        ui->boton_home->setChecked(false);
    }
}

void MainWindow::on_reset_button_clicked() {
    qWarning("limpiando ruta");
    ui->webView->page()->mainFrame()->evaluateJavaScript("deleteTrayectory();");
}


void MainWindow::on_pushButton_armarDesarmarMotores_clicked()
{ // doble click
    static QTime time;
    static int flag=1;
    static int flag_par=0;
    if(flag) {
        time.start();
        flag=0;
        flag_par=0;
        return;
    }
    if(time.restart() < 1000) {
        if((flag_par++%2) == 0) {
          rcv->SendArmarDesarmarMotores();
        }
    } else {
        flag_par = 0;
    }
}

void MainWindow::on_dialYaw_sliderPressed()
{
    //ui->checkBoxYawToHome->setCheckState(Qt::Unchecked);
}

void MainWindow::on_boton_view_clicked()
{
    ui->webView->page()->mainFrame()->evaluateJavaScript("swapViewMode();");
    if(WaypointMode){
        swapWaypointUI();
        ui->webView->page()->mainFrame()->evaluateJavaScript("swapWaypointMode();");
    }
    if(HomeMode){
        swapHomeUI();
        ui->webView->page()->mainFrame()->evaluateJavaScript("swapHomeMode();");
    }
    swapViewUI();
}

void MainWindow::addWaypoint(float lat, float lng) { // ir a punto gps
}

void MainWindow::setGoto(double lat, double lng) {
    rcv->SendGoto(lat, lng);
}

void MainWindow::setHome(double lat, double lng) { // home
    rcv->SendHome(lat, lng);
}

void MainWindow::setView(double lat, double lng) { // yaw
    rcv->SendView(lat, lng);
}



void MainWindow::on_dialYaw_valueChanged(int value)
{
    timerSetYawToHome_valueChanged.stop();
    timerSetYawToHome_valueChanged.start(200);
    dialyaw = (float)value*M_2PI/360;
}

void MainWindow::dialYaw_valueChanged_timeout()
{
    rcv->SendSetRPYT(0, 0, dialyaw, 0);
}

void MainWindow::newAltura(double altura) {
    ui->label_altura->setText(QString::number(altura, 'f', 1));
}

void MainWindow::newYaw(double yaw) {
    ui->label_yaw->setText(QString::number(yaw, 'f', 1));
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 3) {
        emit quit();
    }
}

void MainWindow::on_verticalSlider_altura_sliderReleased()
{
    ui->verticalSlider_altura->setValue(0);
    timerSetAltura.stop();
}

void MainWindow::on_verticalSlider_altura_sliderPressed()
{
    ui->doubleSpinBox_altura->setValue( ui->label_altura->text().toFloat() );
    timerSetAltura.start(100);
}

void MainWindow::timerSetAltura_timeout() {
     ui->doubleSpinBox_altura->setValue( ui->doubleSpinBox_altura->value() + (float)ui->verticalSlider_altura->value() / 100.0 );

     rcv->SendParam(TIPO_PARAM_ALTURA_REF, ui->doubleSpinBox_altura->value());
}

void MainWindow::on_pushButton_read_params_clicked()
{
    rcv->SendRequestParam(TIPO_PARAM_ALTURA_P);
    rcv->SendRequestParam(TIPO_PARAM_ALTURA_D);
    rcv->SendRequestParam(TIPO_PARAM_XY_P);
    rcv->SendRequestParam(TIPO_PARAM_XY_D);
    rcv->SendRequestParam(TIPO_PARAM_YAW_P);
    rcv->SendRequestParam(TIPO_PARAM_YAW_D);
    rcv->SendRequestParam(TIPO_PARAM_YAW_REF);
    rcv->SendRequestParam(TIPO_PARAM_COMPASS_OFFSET_0);
    rcv->SendRequestParam(TIPO_PARAM_COMPASS_OFFSET_1);
    rcv->SendRequestParam(TIPO_PARAM_COMPASS_OFFSET_2);
}

void MainWindow::on_doubleSpinBox_altura_P_valueChanged(double arg1)
{
    rcv->SendParam(TIPO_PARAM_ALTURA_P, (float)arg1);
}

void MainWindow::on_doubleSpinBox_altura_D_valueChanged(double arg1)
{
    rcv->SendParam(TIPO_PARAM_ALTURA_D, (float)arg1);
}

void MainWindow::on_doubleSpinBox_yaw_P_valueChanged(double arg1)
{
    rcv->SendParam(TIPO_PARAM_YAW_P, (float)arg1);
}

void MainWindow::on_doubleSpinBox_yaw_D_valueChanged(double arg1)
{
    rcv->SendParam(TIPO_PARAM_YAW_D, (float)arg1);
}

void MainWindow::on_doubleSpinBox_XY_P_valueChanged(double arg1)
{
    rcv->SendParam(TIPO_PARAM_XY_P, (float)arg1);
}

void MainWindow::on_doubleSpinBox_XY_D_valueChanged(double arg1)
{
    rcv->SendParam(TIPO_PARAM_XY_D, (float)arg1);
}

void MainWindow::on_doubleSpinBox_altura_valueChanged(double arg1)
{
    rcv->SendParam(TIPO_PARAM_ALTURA, (float)arg1);
}

void MainWindow::on_pushButton_casa_clicked()
{
    rcv->SendGotoHome();
}
