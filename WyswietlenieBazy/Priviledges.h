#pragma once
#include "FactoryInterface.h"
class Priviledges :
	public FactoryInterface
{
public:
	Priviledges();
	bool addItem(std::string nazwa);
	bool deleteItem(int index);
	std::vector<std::string> listItems();
	bool sortItems();
	std::string getName(int index);
	void reset();
	~Priviledges();
private:
	std::vector<std::string> items;

};
