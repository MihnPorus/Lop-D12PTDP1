#include "Login.h"


Login::Login()
{
	_password = new string;
	_ID = new string;
}


Login::~Login()
{
	delete _ID;
	delete _password;
}

void Login::Nhap() const
{
	*_ID = *InPut::InPut_ID();
	cout << "Nhap password: "; fflush(stdin); *_password = *InPut::Input_password();
}

void Login::Set_password(string *_password)
{
	this->_password = _password;
}

void Login::HienThi() const
{
	cout << "ID: " <<* _ID << endl;
}

string* Login::Get_password()
{
	return _password;
}

void Login::Set_ID(string *_ID)
{
	this->_ID = _ID;
}

string* Login::Get_ID()
{
	return _ID;
}
