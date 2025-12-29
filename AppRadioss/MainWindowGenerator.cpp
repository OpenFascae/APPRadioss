#include "MainWindowGenerator.h"
#include "GUIFrame/MainWindow.h"
#include <QMainWindow>

MainWindowGenerator::MainWindowGenerator()
{
}

QWidget * MainWindowGenerator::genMainWindow()
{
    return new GUI::MainWindow;
}

bool MainWindowGenerator::showPreSettingPage()
{
#ifndef QT_DEBUG
//     GUI::WorkingDirDlg d;
//     return d.exec() == QDialog::Accepted;
#else
    return true;
#endif // !QT_DEBUG 
    return true;
}

QString MainWindowGenerator::getQssStyle()
{
 //   return QString("://IGA.qss");
	return QString();
}
