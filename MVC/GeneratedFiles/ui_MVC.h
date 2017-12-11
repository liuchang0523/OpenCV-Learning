/********************************************************************************
** Form generated from reading UI file 'MVC.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MVC_H
#define UI_MVC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MVCClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonColor;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSlider *verticalSlider;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QPushButton *pushButtonProcess;
    QPushButton *pushButtonSrc;
    QLabel *labelImg;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MVCClass)
    {
        if (MVCClass->objectName().isEmpty())
            MVCClass->setObjectName(QStringLiteral("MVCClass"));
        MVCClass->resize(657, 495);
        centralWidget = new QWidget(MVCClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButtonOpen = new QPushButton(centralWidget);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));

        verticalLayout->addWidget(pushButtonOpen);

        pushButtonColor = new QPushButton(centralWidget);
        pushButtonColor->setObjectName(QStringLiteral("pushButtonColor"));

        verticalLayout->addWidget(pushButtonColor);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalSlider->sizePolicy().hasHeightForWidth());
        verticalSlider->setSizePolicy(sizePolicy);
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 57 9pt \"Source Code Pro Medium\";"));
        label->setFrameShadow(QFrame::Plain);
        label->setMargin(0);

        verticalLayout->addWidget(label);

        pushButtonProcess = new QPushButton(centralWidget);
        pushButtonProcess->setObjectName(QStringLiteral("pushButtonProcess"));

        verticalLayout->addWidget(pushButtonProcess);

        pushButtonSrc = new QPushButton(centralWidget);
        pushButtonSrc->setObjectName(QStringLiteral("pushButtonSrc"));

        verticalLayout->addWidget(pushButtonSrc);


        horizontalLayout_2->addLayout(verticalLayout);

        labelImg = new QLabel(centralWidget);
        labelImg->setObjectName(QStringLiteral("labelImg"));

        horizontalLayout_2->addWidget(labelImg);

        horizontalLayout_2->setStretch(1, 1);
        MVCClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MVCClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 657, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MVCClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MVCClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MVCClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MVCClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MVCClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());

        retranslateUi(MVCClass);

        QMetaObject::connectSlotsByName(MVCClass);
    } // setupUi

    void retranslateUi(QMainWindow *MVCClass)
    {
        MVCClass->setWindowTitle(QApplication::translate("MVCClass", "MVC", Q_NULLPTR));
        pushButtonOpen->setText(QApplication::translate("MVCClass", "Open Image", Q_NULLPTR));
        pushButtonColor->setText(QApplication::translate("MVCClass", "Select Color", Q_NULLPTR));
        label->setText(QApplication::translate("MVCClass", "<html><head/><body><p>Color</p><p align=\"justify\">Distance</p><p>Threshold:0</p></body></html>", Q_NULLPTR));
        pushButtonProcess->setText(QApplication::translate("MVCClass", "Process", Q_NULLPTR));
        pushButtonSrc->setText(QApplication::translate("MVCClass", "Input Image", Q_NULLPTR));
        labelImg->setText(QString());
        menuFile->setTitle(QApplication::translate("MVCClass", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MVCClass: public Ui_MVCClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MVC_H
