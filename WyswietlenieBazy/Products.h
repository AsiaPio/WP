#pragma once
#include <iostream>
#include <vector>
#include "FactoryInterface.h"
class Products :
	public FactoryInterface
{
public:
	Products();
	bool addItem(std::string nazwa);
	bool deleteItem(int index);
	std::vector<std::string> listItems();
	bool sortItems();
	void reset();
	std::string getName(int index);
	~Products();
private:
	std::vector<std::string> items;
};

