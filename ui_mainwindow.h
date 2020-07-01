/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *lineEdit_Healthy;
    QLabel *label_5;
    QLineEdit *lineEdit_Infected;
    QLineEdit *lineEdit_Recovered;
    QLabel *label_6;
    QLineEdit *lineEdit_Dead;
    QLabel *label_7;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(887, 544);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 501, 501));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(530, 10, 102, 16));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(670, 10, 31, 20));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(670, 40, 31, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(530, 40, 141, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 70, 141, 16));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(670, 70, 31, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(530, 110, 75, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(530, 240, 141, 16));
        lineEdit_Healthy = new QLineEdit(centralWidget);
        lineEdit_Healthy->setObjectName(QString::fromUtf8("lineEdit_Healthy"));
        lineEdit_Healthy->setEnabled(false);
        lineEdit_Healthy->setGeometry(QRect(670, 210, 31, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(530, 210, 121, 16));
        lineEdit_Infected = new QLineEdit(centralWidget);
        lineEdit_Infected->setObjectName(QString::fromUtf8("lineEdit_Infected"));
        lineEdit_Infected->setEnabled(false);
        lineEdit_Infected->setGeometry(QRect(670, 240, 31, 20));
        lineEdit_Recovered = new QLineEdit(centralWidget);
        lineEdit_Recovered->setObjectName(QString::fromUtf8("lineEdit_Recovered"));
        lineEdit_Recovered->setEnabled(false);
        lineEdit_Recovered->setGeometry(QRect(670, 270, 31, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(530, 270, 141, 16));
        lineEdit_Dead = new QLineEdit(centralWidget);
        lineEdit_Dead->setObjectName(QString::fromUtf8("lineEdit_Dead"));
        lineEdit_Dead->setEnabled(false);
        lineEdit_Dead->setGeometry(QRect(670, 300, 31, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(530, 300, 141, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 887, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Epidemic", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\210\320\260\321\200\320\276\320\262: ", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\267\320\260\321\200\320\260\320\266\320\265\320\275\320\275\321\213\321\205:  ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\321\214 \321\201\320\274\320\265\321\200\321\202\320\270:", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\320\272", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\267\320\260\321\200\320\260\320\266\320\265\320\275\320\275\321\213\321\205:  ", nullptr));
        lineEdit_Healthy->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\267\320\264\320\276\321\200\320\276\320\262\321\213\321\205", nullptr));
        lineEdit_Infected->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_Recovered->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\321\213\320\273\320\265\321\207\320\265\320\275\320\275\320\275\321\213\321\205:  ", nullptr));
        lineEdit_Dead->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\274\320\265\321\200\321\202\320\262\321\213\321\205:  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
