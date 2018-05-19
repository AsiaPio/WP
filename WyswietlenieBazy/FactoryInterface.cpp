#include "FactoryInterface.h"


FactoryInterface::FactoryInterface()
{
}

bool FactoryInterface::addItem(std::string nazwa)
{
	return false;
}

bool FactoryInterface::deleteItem(int index)
{
	return false;
}

std::vector<std::string> FactoryInterface::listItems()
{
	return std::vector<std::string>();
}

bool FactoryInterface::sortItems()
{
	return true;
}

void FactoryInterface::reset()
{
}

std::string FactoryInterface::getName(int index)
{
	return std::string();
}


FactoryInterface::~FactoryInterface()
{
}
