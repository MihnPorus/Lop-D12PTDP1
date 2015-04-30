#pragma once
#include "ReadFile.h"
#include "InPut.h"
#include "WriteFile.h"
#include "Search.h"
class Manager
{
private:
	list<ThiSinh> *thisinh;
public:
	Manager();
	~Manager();
	bool DangNhap();
	void DangKy();
	void Menu1();
	void Menu2();
	void TimKiem();

};

