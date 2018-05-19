/********************************************************************************
** Form generated from reading UI file 'wyswietleniebazy.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WYSWIETLENIEBAZY_H
#define UI_WYSWIETLENIEBAZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WyswietlenieBazy
{
public:
    QPushButton *butShowUsers;
    QListWidget *listBox;
    QPushButton *butPriviledges;
    QPushButton *butProducts;
    QPushButton *butAdd;
    QPushButton *butDelete;
    QPushButton *butGet;
    QPushButton *butSort;

    void setupUi(QWidget *WyswietlenieBazy)
    {
        if (WyswietlenieBazy->objectName().isEmpty())
            WyswietlenieBazy->setObjectName(QStringLiteral("WyswietlenieBazy"));
        WyswietlenieBazy->resize(722, 504);
        butShowUsers = new QPushButton(WyswietlenieBazy);
        butShowUsers->setObjectName(QStringLiteral("butShowUsers"));
        butShowUsers->setGeometry(QRect(640, 10, 75, 23));
        listBox = new QListWidget(WyswietlenieBazy);
        listBox->setObjectName(QStringLiteral("listBox"));
        listBox->setGeometry(QRect(15, 11, 611, 461));
        butPriviledges = new QPushButton(WyswietlenieBazy);
        butPriviledges->setObjectName(QStringLiteral("butPriviledges"));
        butPriviledges->setGeometry(QRect(640, 40, 75, 23));
        butProducts = new QPushButton(WyswietlenieBazy);
        butProducts->setObjectName(QStringLiteral("butProducts"));
        butProducts->setGeometry(QRect(640, 70, 75, 23));
        butAdd = new QPushButton(WyswietlenieBazy);
        butAdd->setObjectName(QStringLiteral("butAdd"));
        butAdd->setGeometry(QRect(640, 100, 75, 23));
        butDelete = new QPushButton(WyswietlenieBazy);
        butDelete->setObjectName(QStringLiteral("butDelete"));
        butDelete->setGeometry(QRect(640, 130, 75, 23));
        butGet = new QPushButton(WyswietlenieBazy);
        butGet->setObjectName(QStringLiteral("butGet"));
        butGet->setGeometry(QRect(640, 160, 75, 23));
        butSort = new QPushButton(WyswietlenieBazy);
        butSort->setObjectName(QStringLiteral("butSort"));
        butSort->setGeometry(QRect(640, 190, 75, 23));

        retranslateUi(WyswietlenieBazy);

        QMetaObject::connectSlotsByName(WyswietlenieBazy);
    } // setupUi

    void retranslateUi(QWidget *WyswietlenieBazy)
    {
        WyswietlenieBazy->setWindowTitle(QApplication::translate("WyswietlenieBazy", "WyswietlenieBazy", nullptr));
        butShowUsers->setText(QApplication::translate("WyswietlenieBazy", "Users", nullptr));
        butPriviledges->setText(QApplication::translate("WyswietlenieBazy", "Priviledges", nullptr));
        butProducts->setText(QApplication::translate("WyswietlenieBazy", "Products", nullptr));
        butAdd->setText(QApplication::translate("WyswietlenieBazy", "Add", nullptr));
        butDelete->setText(QApplication::translate("WyswietlenieBazy", "Delete", nullptr));
        butGet->setText(QApplication::translate("WyswietlenieBazy", "Get", nullptr));
        butSort->setText(QApplication::translate("WyswietlenieBazy", "Sort", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WyswietlenieBazy: public Ui_WyswietlenieBazy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WYSWIETLENIEBAZY_H
