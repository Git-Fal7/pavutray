#include <QDebug>
#include <QMessageBox>
#include <QCoreApplication>
#include <QProcess>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , trayIcon(new QSystemTrayIcon(this))
{

  // App icon
  this->trayIcon->setIcon(QIcon::fromTheme("audio-volume-high"));

  // Displaying the tray icon
  this->trayIcon->show();     // Note: without explicitly calling show(), QSystemTrayIcon::activated signal will never be emitted!

  // Interaction
  connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::iconActivated);
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason_)
{
  switch (reason_) {
  case QSystemTrayIcon::Trigger:
    QProcess::startDetached("pavucontrol-qt");
    break;
  default:
    ;
  }
}
