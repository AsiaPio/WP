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
#include <QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_WyswietlenieBazy
{
public:
    QPushButton *butAdd;
	QPushButton *butDel;

	QPushButton *butUsers;
	QPushButton *butPriviledges;
	QPushButton *butProducts;
	QPushButton *butGet;
	QPushButton *butSort;
	QPushButton *butConfirm;
	QPushButton *butCancel;
	QPushButton *butMem;
	QPushButton *butRevMem;

	QTextEdit *textbox;
	QTextEdit *text;

    QListWidget *listBox;

    void setupUi(QWidget *WyswietlenieBazy)
    {
        if (WyswietlenieBazy->objectName().isEmpty())
            WyswietlenieBazy->setObjectName(QStringLiteral("WyswietlenieBazy"));
        WyswietlenieBazy->resize(722, 504);
        butAdd = new QPushButton(WyswietlenieBazy);
        butAdd->setObjectName(QStringLiteral("butAdd"));
        butAdd->setGeometry(QRect(530, 100, 75, 23));

		butDel = new QPushButton(WyswietlenieBazy);
        butDel->setObjectName(QStringLiteral("butDel"));				
        butDel->setGeometry(QRect(530, 125, 75, 23));

		butUsers = new QPushButton(WyswietlenieBazy);
		butUsers->setObjectName(QStringLiteral("butUsers"));
		butUsers->setGeometry(QRect(530, 25, 75, 23));

		butPriviledges = new QPushButton(WyswietlenieBazy);
		butPriviledges->setObjectName(QStringLiteral("butPriviledges"));
		butPriviledges->setGeometry(QRect(530, 50, 75, 23));

		butProducts = new QPushButton(WyswietlenieBazy);
		butProducts->setObjectName(QStringLiteral("butProducts"));
		butProducts->setGeometry(QRect(530, 75, 75, 23));

		butGet = new QPushButton(WyswietlenieBazy);
		butGet->setObjectName(QStringLiteral("butGet"));
		butGet->setGeometry(QRect(530, 150, 75, 23));

		butSort = new QPushButton(WyswietlenieBazy);
		butSort->setObjectName(QStringLiteral("butSort"));
		butSort->setGeometry(QRect(530, 175, 75, 23));

		butConfirm = new QPushButton(WyswietlenieBazy);
		butConfirm->setObjectName(QStringLiteral("butConfirm"));
		butConfirm->setGeometry(QRect(530, 275, 75, 23));

		butCancel = new QPushButton(WyswietlenieBazy);
		butCancel->setObjectName(QStringLiteral("butCancel"));
		butCancel->setGeometry(QRect(530, 300, 75, 23));

		textbox = new QTextEdit(WyswietlenieBazy);
		textbox->setObjectName(QStringLiteral("textbox"));
		textbox->setGeometry(QRect(530, 250, 75, 23));

		text = new QTextEdit(WyswietlenieBazy);
		text->setObjectName(QStringLiteral("text"));
		text->setGeometry(QRect(530, 225, 75, 23));

        listBox = new QListWidget(WyswietlenieBazy);
        new QListWidgetItem(listBox);
        listBox->setObjectName(QStringLiteral("listBox"));
        listBox->setGeometry(QRect(60, 25, 450, 400));

		butMem = new QPushButton(WyswietlenieBazy);
		butMem->setObjectName(QStringLiteral("butMem"));
		butMem->setGeometry(QRect(60, 450, 75, 23));

		butRevMem = new QPushButton(WyswietlenieBazy);
		butRevMem->setObjectName(QStringLiteral("butRevMem"));
		butRevMem->setGeometry(QRect(150, 450, 75, 23));

        retranslateUi(WyswietlenieBazy);

        QMetaObject::connectSlotsByName(WyswietlenieBazy);
    } // setupUi

    void retranslateUi(QWidget *WyswietlenieBazy)
    {
        WyswietlenieBazy->setWindowTitle(QApplication::translate("WyswietlenieBazy", "WyswietlenieBazy", nullptr));
        butAdd->setText(QApplication::translate("WyswietlenieBazy", "Add", nullptr));
		butDel->setText(QApplication::translate("WyswietlenieBazy", "Delete", nullptr));
		butUsers->setText(QApplication::translate("WyswietlenieBazy", "Users", nullptr));
		butPriviledges->setText(QApplication::translate("WyswietlenieBazy", "Priviledges", nullptr));
		butProducts->setText(QApplication::translate("WyswietlenieBazy", "Products", nullptr));
		butGet->setText(QApplication::translate("WyswietlenieBazy", "Get", nullptr));
		butSort->setText(QApplication::translate("WyswietlenieBazy", "Sort", nullptr));
		butConfirm->setText(QApplication::translate("WyswietlenieBazy", "Confirm", nullptr));
		butCancel->setText(QApplication::translate("WyswietlenieBazy", "Cancel", nullptr));
		butMem->setText(QApplication::translate("WyswietlenieBazy", "Save state", nullptr));
		butRevMem->setText(QApplication::translate("WyswietlenieBazy", "Revert", nullptr));

		text->setReadOnly(1);
		text->setVisible(0);
		textbox->setVisible(0);
		butConfirm->setVisible(0);
		butCancel->setVisible(0);
    } // retranslateUi

};

namespace Ui {
    class WyswietlenieBazy: public Ui_WyswietlenieBazy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WYSWIETLENIEBAZY_H
