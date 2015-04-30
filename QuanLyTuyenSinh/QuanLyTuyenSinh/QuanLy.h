#pragma once
#include "Login.h"
#include "Nguoi.h"
class QuanLy: public Login , public virtual Nguoi , virtual VaoRaChuan
{
public:
	QuanLy();
	~QuanLy();
	void Nhap() const override;
	void HienThi() const override;
	void Set_email(string *);
	string* Get_email();
	void Set_sodienthoai(string *);
	string* Get_sodienthoai();
private:
	string *_email;
	string *_sodienthoai;
};

