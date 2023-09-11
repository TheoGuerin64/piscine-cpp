#include <string>
#include <iostream>

#include "Harl.hpp"

Harl::Harl(void)
{
	_levels[0].name = "debug";
	_levels[0].ptr = &Harl::debug;
	_levels[1].name = "info";
	_levels[1].ptr = &Harl::info;
	_levels[2].name = "warning";
	_levels[2].ptr = &Harl::warning;
	_levels[3].name = "error";
	_levels[3].ptr = &Harl::error;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (_levels[i].name == level)
		{
			(this->*_levels[i].ptr)();
			return;
		}
	}
	std::cout << "???" << std::endl;
}
