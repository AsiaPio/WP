#include "Factory.h"



Factory::Factory()
{
}


Factory::~Factory()
{
}


FactoryInterface * Factory::create(std::string nazwa)
{
	if (nazwa == "users")
	{
		return new Users();
	}
	else if (nazwa == "products")
	{
		return new Products();
	}
	else if (nazwa == "priviledges")
	{
		return new Priviledges();
	}
	else
	{
		return nullptr;
	}
}
