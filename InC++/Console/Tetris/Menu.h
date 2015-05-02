#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

class Menu
{
protected:
	std::vector<std::string> m_attributes;

public:
	Menu();
	~Menu(void);

	std::string getAttribute(int number);

	void addAttributes(int nb_arg, ...);
	void show();
	std::string entry();
};

#endif