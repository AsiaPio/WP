#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class FactoryInterface
{
public:
	FactoryInterface();
	virtual bool addItem(std::string nazwa);
	virtual bool deleteItem(int index);
	virtual std::vector<std::string> listItems();
	virtual bool sortItems();
	virtual void reset();
	virtual std::string getName(int index);
	~FactoryInterface();
};

