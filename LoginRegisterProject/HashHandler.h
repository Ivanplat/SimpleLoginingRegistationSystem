#pragma once
#include <string>
#include <botan/hash.h>
#include <botan/hex.h>

class HashHandler
{
public:
	explicit HashHandler() noexcept = default;
	virtual ~HashHandler() noexcept = default;
public:
	std::string HashString(const std::string& val) const noexcept;
};

