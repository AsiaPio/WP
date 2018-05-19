#include <iostream>
#include <vector>
#include <string>

class Memento
{
private:
	friend class Originator;
	Memento(std::vector<std::string>& state);
	~Memento();
	void SetState( std::vector<std::string>& state);
	std::vector<std::string> GetState();
	std::vector<std::string> _stateM;
};

class Originator
{
public:
	Originator();
	Originator(std::vector<std::string>& state);
	~Originator();
	void RestoreToMemento(Memento* pMemento);
	Memento* CreateMemento();
	void SetState(std::vector<std::string>& state);
	std::vector<std::string> GetState();
	void show();
	std::vector<std::string> _state;
};

class Caretaker
{
public:
	Caretaker();
	~Caretaker();
	void SetMemento(Memento*);
	Memento* GetMemento();
private:
	Memento * _memento;
};