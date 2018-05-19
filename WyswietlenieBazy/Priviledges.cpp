#include "Priviledges.h"


Priviledges::Priviledges()
{
}

bool Priviledges::addItem(std::string nazwa)
{
	items.push_back(nazwa);
	return true;
}

bool Priviledges::deleteItem(int index)
{
	items.erase(items.begin() + index - 1);
	return true;
}

std::vector<std::string> Priviledges::listItems()
{
	return items;
}

bool Priviledges::sortItems()
{
	std::sort(items.begin(), items.end());
	return true;
}

std::string Priviledges::getName(int index)
{
	std::string temp = items[index - 1];
	return temp;
}

void Priviledges::reset()
{
	items.clear();
}


Priviledges::~Priviledges()
{
}


