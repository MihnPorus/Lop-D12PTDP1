#include "Diem.h"

Diem::Diem()
{
	_tongdiem = new  float;
	_sobaodanh = new string;
	_diem = new pair < string, pair< vector<string>, vector<float> > > ;
}


Diem::~Diem()
{
	delete _tongdiem;
	delete _sobaodanh;
	delete _diem;
}

void Diem::Nhap() const
{
	*_sobaodanh = *InPut::InPut_Sobaodanh();
	cout << "Nhap khoi thi: "; fflush(stdin); getline(cin, _diem->first); 

	cout << " Nhap diem cac mon!" << endl;
	*_tongdiem = 0;
	for (int i = 0; i < 3; i++)
	{
		char *mon = new char;
		float *diem = new float;
		cout << "Nhap ten mon: "; fflush(stdin); cin.getline(mon, 10);
		_diem->second.first.push_back(mon);
		cout << "Nhap diem: "; cin >> *diem; 
		_diem->second.second.push_back(*diem);
	}

}

void Diem::HienThi() const
{
	cout << "SBD: " << _sobaodanh->c_str() << endl;
	cout << "Khoi: " << _diem->first.c_str() << endl;
	cout << "Diem cac mon!" << endl;
	cout << "Mon:\t";
	for (vector<string>::iterator i = _diem->second.first.begin(); i != _diem->second.first.end(); i++)
	{
		cout << i->c_str() << "\t";

	}
	cout << endl;
	cout << "Diem:\t";
	for (vector<float>::iterator i = _diem->second.second.begin(); i != _diem->second.second.end(); i++)
	{
		cout << *i << "\t";

	}
	cout << endl;
	*_tongdiem = 0;
	for (vector<float> ::iterator i = _diem->second.second.begin(); i != _diem->second.second.end(); i++)
	{
		*_tongdiem += *i;
	}
	cout << "Tong diem: " << *_tongdiem << endl;
}

void Diem::Set_sobaodanh(string* _sobaodanh)
{
	this->_sobaodanh->append(_sobaodanh->c_str());
}

string* Diem::Get_sobaodanh()
{
	return _sobaodanh;
}

float* Diem::Get_tongdiem()
{
	return _tongdiem;
}

void Diem::Set_diem(pair< string, pair< vector<string>, vector<float> > >* _diem)
{
	this->_diem = _diem;
}

pair< string, pair< vector<string>, vector<float> > >* Diem::Get_diem()
{
	return _diem;
}


