#pragma once
#include "VaoRaChuan.h"
#include "InPut.h"
#include <iostream>
#include <string>
using namespace std;

class Nguoi:  virtual VaoRaChuan
{
public:
	Nguoi(string* _hoten, string* _ngaysinh, string* _diachi);
	Nguoi();
	virtual ~Nguoi();
	void virtual Nhap() const override;
	void virtual HienThi() const override;
	string* Get_Hoten();
	void virtual Set_Hoten(string* _hoten);
	string* Get_Ngaysinh();
	void virtual Set_Ngaysinh(string* _ngaysinh);
	string* Get_Diachi();
	void virtual Set_Diachi(string* _diachi);
private:
	string *_hoten;
	string *_diachi;
	string *_ngaysinh;
};

