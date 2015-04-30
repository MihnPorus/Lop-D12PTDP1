#include "QuanLy.h"


QuanLy::QuanLy()
{
	_email = new string;
	_sodienthoai = new string;
}


QuanLy::~QuanLy()
{
	delete _email;
	delete _sodienthoai;
}

void QuanLy::Nhap() const
{
	Login::Nhap();
	cout << endl;
	Nguoi::Nhap();
	*_sodienthoai = *InPut::InPut_Sodienthoai();
	*_email = *InPut::InPut_email();
}

void QuanLy::HienThi() const
{
	Login::HienThi();
	Nguoi::HienThi();
	cout << "SDT: " << *_sodienthoai;
	cout << "Email: " << *_email;

}

void QuanLy::Set_email(string *_email)
{
	this->_email = _email;
}

string* QuanLy::Get_email()
{
	return _email;
}

void QuanLy::Set_sodienthoai(string *_sodienthoai)
{
	this->_sodienthoai = _sodienthoai;
}

string* QuanLy::Get_sodienthoai()
{
	return _sodienthoai;
}
