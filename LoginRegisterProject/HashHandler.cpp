#include "HashHandler.h"

std::string HashHandler::HashString(const std::string& val) const noexcept
{
    auto hash = Botan::HashFunction::create("SHA-256");
    hash->update(val);
   
    return Botan::hex_encode(hash->final());
}
