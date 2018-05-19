#include "wyswietleniebazy.h"
#include "ui_wyswietleniebazy.h"
#include <mysql.h>
#include <iostream>
#include <string>
#include <Factory.h>
#include "Memento.h"

Factory* fabryka = new Factory;
FactoryInterface* Users = fabryka->create("users");
FactoryInterface* Products = fabryka->create("products");
FactoryInterface* Priviledges = fabryka->create("priviledges");
FactoryInterface* handle = NULL;
FactoryInterface* handletemp = NULL;

std::string cosads;
bool addb;
bool memex=0;

Originator* MUsers;
Originator* MProducts;;
Originator* MPriviledges;

WyswietlenieBazy::WyswietlenieBazy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WyswietlenieBazy)
{
    ui->setupUi(this);
}

WyswietlenieBazy::~WyswietlenieBazy()
{
    delete ui;
}

void WyswietlenieBazy::on_butUsers_clicked()
{
	ui->listBox->clear();

	handle = Users;
	std::vector<std::string> temporary = handle->listItems();
	for (int i = 0; i < temporary.size(); i++)
	{
		QString temp = QString::fromStdString(temporary[i]);
		ui->listBox->addItem(temp);
	}
}

void WyswietlenieBazy::on_butPriviledges_clicked()
{
	ui->listBox->clear();

	handle = Priviledges;
	std::vector<std::string> temporary = handle->listItems();
	for (int i = 0; i < temporary.size(); i++)
	{
		QString temp = QString::fromStdString(temporary[i]);
		ui->listBox->addItem(temp);
	}
}


void WyswietlenieBazy::on_butProducts_clicked()
{
	ui->listBox->clear();

	handle = Products;
	std::vector<std::string> temporary = handle->listItems();
	for (int i = 0; i < temporary.size(); i++)
	{
		QString temp = QString::fromStdString(temporary[i]);
		ui->listBox->addItem(temp);
	}
}


void WyswietlenieBazy::on_butAdd_clicked()
{
	addb = 1;
	ui->butConfirm->setVisible(1);
	ui->text->setText(QApplication::translate("WyswietlenieBazy", "Give name:", nullptr));
	ui->text->setVisible(1);
	ui->textbox->setVisible(1);
	ui->butCancel->setVisible(1);
}

void WyswietlenieBazy::on_butDel_clicked()
{
	addb = 0;
	ui->butConfirm->setVisible(1);
	ui->text->setText(QApplication::translate("WyswietlenieBazy", "Give index:", nullptr));
	ui->text->setVisible(1);
	ui->textbox->setVisible(1);
	ui->butCancel->setVisible(1);
}

void WyswietlenieBazy::on_butGet_clicked()
{
	MYSQL mysql;

	mysql_init(&mysql);
	mysql_real_connect(&mysql, "127.0.0.1", "root", "", "uzytkownicy", 0, NULL, 0);

	MYSQL_RES *idZapytania;
	MYSQL_ROW  wiersz;

	mysql_select_db(&mysql, "users");
	mysql_query(&mysql, "SELECT name FROM users");
	idZapytania = mysql_store_result(&mysql);
	
	handle = Users;
	handle->reset();

	while ((wiersz = mysql_fetch_row(idZapytania)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idZapytania); i++)
		{
			handle->addItem(wiersz[i]);
		}
	
	}
	
	mysql_close(&mysql);

	MYSQL mysql1;

	mysql_init(&mysql1);
	mysql_real_connect(&mysql1, "127.0.0.1", "root", "", "uzytkownicy", 0, NULL, 0);

	MYSQL_RES *idZapytania1;
	MYSQL_ROW  wiersz1;

	mysql_select_db(&mysql1, "privileges");
	mysql_query(&mysql1, "SELECT status FROM privileges");
	idZapytania1 = mysql_store_result(&mysql1);
	
	handle = Priviledges;
	handle->reset();

	while ((wiersz1 = mysql_fetch_row(idZapytania1)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idZapytania1); i++)
		{
			handle->addItem(wiersz1[i]);
		}

	}

	mysql_close(&mysql1);

	MYSQL mysql2;

	mysql_init(&mysql2);
	mysql_real_connect(&mysql2, "127.0.0.1", "root", "", "uzytkownicy", 0, NULL, 0);

	MYSQL_RES *idZapytania2;
	MYSQL_ROW  wiersz2;

	mysql_select_db(&mysql2, "items");
	mysql_query(&mysql2, "SELECT name FROM items");
	idZapytania2 = mysql_store_result(&mysql2);

	handle = Products;
	handle->reset();

	while ((wiersz2 = mysql_fetch_row(idZapytania2)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idZapytania2); i++)
		{
			handle->addItem(wiersz2[i]);
		}

	}

	mysql_close(&mysql2);
}

void WyswietlenieBazy::on_butConfirm_clicked()
{
	QString temp;
	temp = ui->textbox->toPlainText();
	std::string temp1;
	temp1 = temp.toStdString();
	if (addb == 1)
	{
		handle->addItem(temp1);

		ui->listBox->clear();
		std::vector<std::string> temporary = handle->listItems();
		for (int i = 0; i < temporary.size(); i++)
		{
			QString temp = QString::fromStdString(temporary[i]);
			ui->listBox->addItem(temp);
		}

		MYSQL mysql;

		mysql_init(&mysql);
		mysql_real_connect(&mysql, "127.0.0.1", "root", "", "uzytkownicy", 0, NULL, 0);

		std::string temp2;
		if (handle == Users)
		{
			mysql_select_db(&mysql, "users");
			temp2 = "INSERT INTO users (name) VALUES ('" + temp1 + "')";
		}

		if (handle == Priviledges)
		{
			mysql_select_db(&mysql, "privileges");
			temp2 = "INSERT INTO privileges (status) VALUES ('" + temp1 + "')";
		}

		if (handle == Products)
		{
			mysql_select_db(&mysql, "items");
			temp2 = "INSERT INTO items (name) VALUES ('" + temp1 + "')";
		}

		mysql_query(&mysql, temp2.c_str());
		mysql_close(&mysql);
	}

	if (addb == 0)
	{
		int temp2;
		temp2 = std::atoi(temp1.c_str());
		std::string temp3;
		std::string temp4;
		temp3 = handle->getName(temp2);
		handle->deleteItem(temp2);

		MYSQL mysql;

		mysql_init(&mysql);
		mysql_real_connect(&mysql, "127.0.0.1", "root", "", "uzytkownicy", 0, NULL, 0);

		if (handle == Users)
		{
			mysql_select_db(&mysql, "users");
			temp4 = "DELETE FROM users WHERE name ='" + temp3 + "'";
		}

		if (handle == Priviledges)
		{
			mysql_select_db(&mysql, "privileges");
			temp4 = "DELETE FROM privileges WHERE status ='" + temp3 + "'";
		}

		if (handle == Products)
		{
			mysql_select_db(&mysql, "items");
			temp4 = "DELETE FROM items WHERE name ='" + temp3 + "'";
		}
		

		mysql_query(&mysql, temp4.c_str());

		mysql_close(&mysql);
	}
	
	ui->listBox->clear();
	std::vector<std::string> temporary = handle->listItems();
	for (int i = 0; i < temporary.size(); i++)
	{
		QString temp = QString::fromStdString(temporary[i]);
		ui->listBox->addItem(temp);
	}
}

void WyswietlenieBazy::on_butCancel_clicked()
{
	ui->butConfirm->setVisible(0);
	ui->textbox->setText(QApplication::translate("WyswietlenieBazy", "", nullptr));
	ui->text->setVisible(0);
	ui->textbox->setVisible(0);
	ui->butCancel->setVisible(0);
}

void WyswietlenieBazy::on_butSort_clicked()
{	
	ui->listBox->clear();
	handle->sortItems();
	std::vector<std::string> temporary = handle->listItems();
	for (int i = 0; i < temporary.size(); i++)
	{
		QString temp = QString::fromStdString(temporary[i]);
		ui->listBox->addItem(temp);
	}
}

void WyswietlenieBazy::on_butMem_clicked()
{
	handletemp = handle;
	
	if (memex = 0)
	{
		std::vector<std::string> temp3;
		handle = Users;
		temp3 = handle->listItems();
		MUsers = new Originator(temp3);
		handle = Products;
		temp3 = handle->listItems();
		MProducts = new Originator(temp3);
		handle = Priviledges;
		temp3 = handle->listItems();
		MPriviledges = new Originator(temp3);
		memex = 1;
	}
	
	handle = Users;
	std::vector<std::string> mleko;
	mleko = handle->listItems();
	MUsers->SetState(mleko);
	handle = Products;
	mleko = handle->listItems();
	MProducts->SetState(mleko);
	handle = Priviledges;
	mleko = handle->listItems();
	MPriviledges->SetState(mleko);
	
	handle = handletemp;
}


void WyswietlenieBazy::on_butRevMem_clicked()
{
	handletemp = handle;
	MYSQL mysql;

	mysql_init(&mysql);
	mysql_real_connect(&mysql, "127.0.0.1", "root", "", "uzytkownicy", 0, NULL, 0);

	handle = Users;
	handle->reset();

	std::vector<std::string> temp = MUsers->GetState();
	std::string temp2;

	for (int i = 0; i < temp.size(); i++)
	{
		handle->addItem(temp[i]);

		/*mysql_query(&mysql, temp2.c_str());

		mysql_select_db(&mysql, "users");
		temp2 = "INSERT INTO users (name) VALUES ('" + temp2 + "')";
		mysql_query(&mysql, temp2.c_str());*/								//TODO
	}

	handle = Products;
	handle->reset();

	temp = MProducts->GetState();

	for (int i = 0; i < temp.size(); i++)
	{
		handle->addItem(temp[i]);

		/*mysql_query(&mysql, temp2.c_str());

		mysql_select_db(&mysql, "users");
		temp2 = "INSERT INTO users (name) VALUES ('" + temp2 + "')";
		mysql_query(&mysql, temp2.c_str());*/								//TODO
	}

	handle = Priviledges;
	handle->reset();

	temp = MPriviledges->GetState();

	for (int i = 0; i < temp.size(); i++)
	{
		handle->addItem(temp[i]);

		/*mysql_query(&mysql, temp2.c_str());

		mysql_select_db(&mysql, "users");
		temp2 = "INSERT INTO users (name) VALUES ('" + temp2 + "')";
		mysql_query(&mysql, temp2.c_str());*/								//TODO
	}

	ui->listBox->clear();
	std::vector<std::string> temporary = handle->listItems();
	for (int i = 0; i < temporary.size(); i++)
	{
		QString temp = QString::fromStdString(temporary[i]);
		ui->listBox->addItem(temp);
	}

	mysql_close(&mysql);
	handle = handletemp;
}