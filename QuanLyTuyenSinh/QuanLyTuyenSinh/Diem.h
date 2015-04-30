#pragma once
#include "VaoRaChuan.h"
#include "InPut.h"
#include <vector>
class Diem: virtual VaoRaChuan
{
public:
	Diem();
	virtual ~Diem();
	void virtual Nhap() const override;
	void virtual HienThi() const override;
	void Set_sobaodanh( string* );
	string* Get_sobaodanh();
	float* Get_tongdiem();
	void Set_diem(pair< string, pair< vector<string>, vector<float> > >*);
	pair< string, pair< vector<string>, vector<float> > >* Get_diem();
	
	
private:
	string *_sobaodanh;
	pair< string, pair< vector<string>, vector<float> > > *_diem;
	float * _tongdiem;
};

