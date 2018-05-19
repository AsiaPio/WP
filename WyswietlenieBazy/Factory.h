#pragma once
#include <FactoryInterface.h>
#include <Users.h>
#include <Priviledges.h>
#include <Products.h>
class Factory
{
public:
	Factory();
	~Factory();

	static FactoryInterface *create(std::string nazwa);
};

