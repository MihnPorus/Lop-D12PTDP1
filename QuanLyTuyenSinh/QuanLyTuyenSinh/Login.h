#pragma once
#include "VaoRaChuan.h"
#include "InPut.h"
class Login: virtual VaoRaChuan
{
public:
	Login();
	virtual ~Login();
	void Nhap() const override;
	void HienThi() const override;
	void Set_password(string *);
	string* Get_password();
	void Set_ID(string *);
	string* Get_ID();
private:
	string *_password;
	string *_ID;
};

