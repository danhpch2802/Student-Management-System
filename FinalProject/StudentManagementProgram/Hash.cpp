#include "startup.h"
std::string SHA256HashString(std::string aString) {
    std::string digest;
    CryptoPP::SHA256 hash;

    CryptoPP::StringSource foo(aString, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::Base64Encoder(
                new CryptoPP::StringSink(digest), false)));

    return digest;
}


void convertHash(char tempPass[])
{
    string temp(tempPass);
    string hash = SHA256HashString(temp);
    strcpy(tempPass, hash.c_str());
}