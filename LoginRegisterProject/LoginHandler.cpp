#include <fstream>
#include <filesystem>
#include <iostream>
#include "HashHandler.h"
#include "LoginHandler.h"

void LoginHandler::RegisterUser(const std::string& username, const std::string& userpassword)
{
	HashHandler hh;
	if (std::filesystem::is_regular_file(std::filesystem::current_path().string() + "/users/" + username + ".txt"))
	{
		std::cout << "This user is already exist!" << std::endl;
		return;
	}
	if (!std::filesystem::is_directory(std::filesystem::current_path().string() + "/users"))
	{
		std::filesystem::create_directory(std::filesystem::current_path().string() + "/users");
	}
	std::string HashedUserPassword = hh.HashString(userpassword);
	std::ofstream file(std::filesystem::current_path().string() + "/users/" + username + ".txt", std::ios::app);
	if (file)
	{
		file.write(HashedUserPassword.c_str(), HashedUserPassword.size());
		std::cout << "User is succsecsfuly created!" << std::endl;
	}
	else
	{
		std::cout << "Can not create a user!" << std::endl;
	}
}

void LoginHandler::LoginUser(const std::string& username, const std::string& userpassword)
{
	HashHandler hh;
	if (!std::filesystem::is_regular_file(std::filesystem::current_path().string() + "/users/" + username + ".txt"))
	{
		std::cout << "This user does non exist!" << std::endl;
		return;
	}
	std::string HashedUserPassword = hh.HashString(userpassword);
	std::ifstream file(std::filesystem::current_path().string() + "/users/" + username + ".txt", std::ios::in);
	if (file)
	{
		std::string buffer;
		std::getline(file, buffer);
		if (HashedUserPassword != buffer)
		{
			std::cout << "Incorrect password!" << std::endl;
			return;
		}
		std::cout << "Logged in!" << std::endl;
	}
	else
	{
		std::cout << "Wrong username!" << std::endl;
	}
}
