#include "Nguoi.h"




Nguoi::Nguoi()
{
	_ngaysinh = new string;
	_hoten = new string;
	_diachi = new string;
}

Nguoi::Nguoi(string* _hoten, string* _ngaysinh, string* _diachi)
{
	this->_hoten = _hoten;
	this->_ngaysinh = _ngaysinh;
	this->_diachi = _diachi;
}

Nguoi::~Nguoi()
{
	delete _ngaysinh;
	delete _diachi;
	delete _hoten;
}

void Nguoi::Nhap() const
{
	cout << "Nhap ho ten: "; fflush(stdin); getline(cin, *_hoten);
	*_ngaysinh = *InPut::InPut_ngaysinh();
	cout << "Nhap dia chi: "; fflush(stdin); getline(cin, *_diachi);
}

void Nguoi::HienThi() const
{
	cout << "Ho ten: " << _hoten->c_str() << endl;
	cout << "Ngay sinh: " << _ngaysinh->c_str() << endl;
	cout << "Dia chi: " << _diachi->c_str() << endl;
}

string* Nguoi::Get_Hoten()
{
	return _hoten;
}

void Nguoi::Set_Hoten(string* _hoten)
{
	this->_hoten ->append( _hoten->c_str());
}

string* Nguoi::Get_Ngaysinh()
{
	return _ngaysinh;
}

void Nguoi::Set_Ngaysinh(string* _ngaysinh)
{
	this->_ngaysinh->append(_ngaysinh->c_str());
}

string* Nguoi::Get_Diachi()
{
	return _diachi;
}

void Nguoi::Set_Diachi(string* _diachi)
{
	this->_diachi->append(_diachi->c_str());
}


