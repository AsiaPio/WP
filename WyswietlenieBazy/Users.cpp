#include "Users.h"


Users::Users()
{
}

bool Users::addItem(std::string nazwa)
{
	items.push_back(nazwa);
	return true;
}

bool Users::deleteItem(int index)
{
	items.erase(items.begin() + index - 1);
	return true;
}

std::vector<std::string> Users::listItems()
{
	return items;
}

bool Users::sortItems()
{
	std::sort(items.begin(), items.end());
	return true;
}

void Users::reset()
{
	items.clear();
}

std::string Users::getName(int index)
{
	std::string temp = items[index - 1];
	return temp;
}

Users::~Users()
{
}

