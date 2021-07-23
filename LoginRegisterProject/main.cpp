#include <iostream>
#include "boost/algorithm/string.hpp"
#include "LoginHandler.h"

// I  made for my resume
// Author: Ivan Platonov
// Email: Ivanplateam@gmail.com
// Project description: simple register/login system on C++ 17 standart


int main()
{
	LoginHandler lh;
	int choose;
	std::string login;
	std::string password;
	std::cout << "Register or loggin? (0/1)" << std::endl;
	std::cin >> choose;
	std::cout << "Login: "; std::cin >> login;
	std::cout << "Password: "; std::cin >> password;

	switch (choose)
	{
	case 0: lh.RegisterUser(login, password); break;
	case 1: lh.LoginUser(login, password); break;
	}
}