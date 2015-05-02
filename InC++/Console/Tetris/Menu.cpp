#include <iostream>
#include <sstream>
#include <string>
#include <stdarg.h> 

#include "Menu.h"
#include "Game.h"


using namespace std;

Menu::Menu()
{

}

Menu::~Menu(void)
{

}

string Menu::getAttribute(int number)
{
	return m_attributes[number];
}

void Menu::addAttributes(int nb_arg, ...)
{
	va_list p_list;  
	va_start(p_list, nb_arg);
	stringstream ss;

	for(int i = 0; i < nb_arg; i++){ 
		m_attributes.push_back(va_arg(p_list, char*));
	}

	va_end(p_list); 
}

void Menu::show()
{
	cout << "######################################################################" << endl;
	cout << "#                                                                    #" << endl;
	cout << "#      Welcome in Tetris ! Revolutionary game ! Gniark Gniark !      #" << endl;
	cout << "#                                By                                  #" << endl;
	cout << "#                       Jacques Adrien HENRI                         #" << endl;
	cout << "#                                                                    #" << endl;
	cout << "######################################################################" << endl;
	cout << endl << "What do you want do ?" << endl;

	for(size_t i = 0; i < m_attributes.size(); i++){
		cout << " - " << m_attributes[i] << endl;
	}

	cout << endl;
}

string Menu::entry()
{
	int count = 3;
	string entry("");

	while (!(find(m_attributes.begin(), m_attributes.end(), entry) != m_attributes.end()) && count >= 0)
	{
		if(!count > 0)
		{
			Game::display("exit");
			exit(0);
		} else {
			--count;
		}

		if(count < 2)
		{
			cout << endl << "Error in your choice." << endl << endl;
		}

		cin >> entry;
		cout << endl;
	}
	
	return entry;
}
