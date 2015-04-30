#pragma once
#include "Thisinh.h"
class ReadFile
{
public:
	static bool Read_Login(const string &, string *, string*);
	static void Read_Thisinh(const string &, const string &, list <ThiSinh> *);
};

