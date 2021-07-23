#pragma once
#include <string>
class LoginHandler
{
public:
	explicit LoginHandler() noexcept = default;
	virtual ~LoginHandler() noexcept = default;
public:
	virtual void RegisterUser(const std::string& username, const std::string& userpassword);
	virtual void LoginUser(const std::string& username, const std::string& userpassword);
};

