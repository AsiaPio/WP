#ifndef WYSWIETLENIEBAZY_H
#define WYSWIETLENIEBAZY_H

#include <QWidget>

namespace Ui {
class WyswietlenieBazy;
}

class WyswietlenieBazy : public QWidget
{
    Q_OBJECT

public:
    explicit WyswietlenieBazy(QWidget *parent = 0);
    ~WyswietlenieBazy();

private:
    Ui::WyswietlenieBazy *ui;

private slots:
	void on_butUsers_clicked();
	void on_butPriviledges_clicked();
	void on_butProducts_clicked();
	void on_butAdd_clicked();
	void on_butDel_clicked();
	void on_butGet_clicked();
	void on_butSort_clicked();
	void on_butConfirm_clicked();
	void on_butCancel_clicked();
	void on_butMem_clicked();
	void on_butRevMem_clicked();
};

#endif // WYSWIETLENIEBAZY_H
