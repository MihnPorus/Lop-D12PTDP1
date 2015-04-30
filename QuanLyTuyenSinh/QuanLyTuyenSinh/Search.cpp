#include "Search.h"


void Search::Search_HienThi(list<ThiSinh>::iterator it)
{
	it->HienThi();
}

int Search::Search_Name(list<ThiSinh>::iterator it, string * name)
{
	if (it->Get_Hoten()->compare(name->c_str()) == 0)
	{
		Search_HienThi(it); 
		cout << "\n\t\t\t ---------------------- \n" << endl;
		return 1;
	}
	return 0;
	
}

int Search::Search_QueQuan(list<ThiSinh>::iterator it, string* quequan)
{
	if (it->Get_Diachi()->compare(quequan->c_str()) == 0)
	{
		Search_HienThi(it);
		cout << "\n\t\t\t ---------------------- \n" << endl;
		return 1;
	}
	return 0;
}

int Search::Search_NgaySinh(list<ThiSinh>::iterator it, string* ngaysinh)
{
	if (it->Get_Ngaysinh()->compare(ngaysinh->c_str()) == 0)
	{
		Search_HienThi(it);
		cout << "\n\t\t\t ---------------------- \n" << endl;
		return 1;
	}
	return 0;

}

void Search::Search_MaxDiem(list<ThiSinh> *thisinh)
{
	string *temp = new string;
	float max = 0;
	for (list<ThiSinh>::iterator i = thisinh->begin(); i != thisinh->end(); i++)
	{
		float tong = *i->Get_tongdiem();
		if (tong > max)
		{
			max = tong;
			*temp = *i->Get_sobaodanh();
		}
	}
	cout << "This sinh co tong diem cao nhat!" << endl;
	cout << "________________________________________________________________________________\n" << endl;
	for (list<ThiSinh>::iterator it = thisinh->begin(); it != thisinh->end(); it++)
	{
		if (it->Get_sobaodanh()->compare(temp->c_str()) == 0)
		{
			it->HienThi();

		}
	}
	return;
}

int Search::Search_Thisinh(list<ThiSinh>* thisinh, int (*Point_method)(list<ThiSinh>::iterator, string*))
{
	string* key_word = new string; int count = 0;
	cout << "Nhap tu khoa: "; fflush(stdin); getline(cin, *key_word);
	cout << "________________________________________________________________________________" << endl;
	for (list<ThiSinh>::iterator it = thisinh->begin(); it != thisinh->end(); it++)
	{
		count +=  Point_method(it, key_word);
	}
	return count;
}

bool Search::max(list<ThiSinh>::iterator a, list<ThiSinh>::iterator b)
{
	return a->Get_tongdiem()> b->Get_tongdiem();
}
