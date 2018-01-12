/********************************************************************************
** Form generated from reading UI file 'CameraCalib.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERACALIB_H
#define UI_CAMERACALIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraCalibClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CameraCalibClass)
    {
        if (CameraCalibClass->objectName().isEmpty())
            CameraCalibClass->setObjectName(QStringLiteral("CameraCalibClass"));
        CameraCalibClass->resize(600, 400);
        menuBar = new QMenuBar(CameraCalibClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        CameraCalibClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CameraCalibClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CameraCalibClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CameraCalibClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CameraCalibClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CameraCalibClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CameraCalibClass->setStatusBar(statusBar);

        retranslateUi(CameraCalibClass);

        QMetaObject::connectSlotsByName(CameraCalibClass);
    } // setupUi

    void retranslateUi(QMainWindow *CameraCalibClass)
    {
        CameraCalibClass->setWindowTitle(QApplication::translate("CameraCalibClass", "CameraCalib", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CameraCalibClass: public Ui_CameraCalibClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERACALIB_H
