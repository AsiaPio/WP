#pragma once
#include "FactoryInterface.h"
class Users :
	public FactoryInterface
{
public:
	Users();
	bool addItem(std::string nazwa);
	bool deleteItem(int index);
	std::vector<std::string> listItems();
	bool sortItems();
	void reset();
	std::string getName(int index);
	~Users();
private:
	std::vector<std::string> items;
};

