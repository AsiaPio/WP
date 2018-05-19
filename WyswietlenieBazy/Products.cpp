#include "Products.h"
#include <iostream>


Products::Products()
{
}

bool Products::addItem(std::string nazwa)
{
	items.push_back(nazwa);
	return true;
}

bool Products::deleteItem(int index)
{
	items.erase(items.begin() + index - 1);
	return true;
}

std::vector<std::string> Products::listItems()
{
	return items;
}

bool Products::sortItems()
{
	std::sort(items.begin(), items.end());
	return true;
}

void Products::reset()
{
	items.clear();
}

std::string Products::getName(int index)
{
	std::string temp = items[index - 1];
	return temp;
}



Products::~Products()
{
}
