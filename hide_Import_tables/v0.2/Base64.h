#pragma once
// Base64.h
#ifndef __BASE64_H__
#define __BASE64_H__

#include <string>
using std::string;

class CBase64
{
public:
	static bool Encode(const string& strIn, string& strOut);
	static bool Decode(const string& strIn, string& strOut, bool fCheckInputValid = false);
};

#endif