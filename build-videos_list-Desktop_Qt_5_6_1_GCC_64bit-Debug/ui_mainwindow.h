/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *show_list;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QTextEdit *DIR;
    QLabel *label;
    QTextEdit *key;
    QLabel *label_2;
    QPushButton *pushButton_7;
    QTextBrowser *searchResult;
    QLabel *label_3;
    QTextEdit *videoNumber;
    QPushButton *pushButton_8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(988, 544);
        MainWindow->setMouseTracking(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 70, 99, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 99, 27));
        show_list = new QTextEdit(centralWidget);
        show_list->setObjectName(QStringLiteral("show_list"));
        show_list->setGeometry(QRect(120, 70, 681, 191));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(820, 70, 99, 27));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(820, 110, 99, 27));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(820, 150, 99, 27));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(820, 220, 141, 41));
        DIR = new QTextEdit(centralWidget);
        DIR->setObjectName(QStringLiteral("DIR"));
        DIR->setGeometry(QRect(120, 10, 681, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 300, 101, 21));
        key = new QTextEdit(centralWidget);
        key->setObjectName(QStringLiteral("key"));
        key->setGeometry(QRect(120, 300, 321, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 360, 91, 21));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(470, 300, 111, 31));
        searchResult = new QTextBrowser(centralWidget);
        searchResult->setObjectName(QStringLiteral("searchResult"));
        searchResult->setGeometry(QRect(120, 360, 681, 111));
        searchResult->setMouseTracking(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(820, 380, 131, 31));
        videoNumber = new QTextEdit(centralWidget);
        videoNumber->setObjectName(QStringLiteral("videoNumber"));
        videoNumber->setGeometry(QRect(810, 420, 61, 31));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(880, 420, 99, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 988, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "List all movie", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Open Dir", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Sort Name", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Sort Size", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Sort Date", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Check same name", 0));
        label->setText(QApplication::translate("MainWindow", "Enter Keyword", 0));
        label_2->setText(QApplication::translate("MainWindow", "Search Result", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Search", 0));
        label_3->setText(QApplication::translate("MainWindow", "Run video number:", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "Run", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
