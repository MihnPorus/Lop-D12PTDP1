#pragma once
#include "ThiSinh.h"
#include "QuanLy.h"
#include <list>
class WriteFile
{
public:
	void static WriteFile_Quanly(const string&, const string& , QuanLy*);
	void static Write_Thisinh(const string&, const string&, ThiSinh*);
	void static Write_Up_Diem(const string&, list<ThiSinh>*);
};

