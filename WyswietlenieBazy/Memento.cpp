#include "Memento.h"
#include <iostream>

Memento::Memento(std::vector<std::string>& state)
{
	this->_stateM = state;
}

Memento::~Memento()
{}

std::vector<std::string> Memento::GetState()
{
	return this->_stateM;
}

void Memento::SetState(std::vector<std::string>& state)
{
	this->_stateM = state;
}

Originator::Originator()
{}

Originator::Originator(std::vector<std::string>& state)
{
	this->_state = state;
}

Originator::~Originator()
{}

std::vector<std::string> Originator::GetState()
{
	return this->_state;
}

void Originator::show()
{
	//std::cout << this->_state << std::endl;
}

void Originator::SetState(std::vector<std::string>& state)
{
	this->_state = state;
}

Memento* Originator::CreateMemento()
{
	return new Memento(this->_state);
}

void Originator::RestoreToMemento(Memento* pMemento)
{
	this->_state = pMemento->GetState();
}

Caretaker::Caretaker()
{}

Caretaker::~Caretaker()
{}

Memento* Caretaker::GetMemento()
{
	return this->_memento;
}

void Caretaker::SetMemento(Memento* pMemento)
{
	this->_memento = pMemento;
}