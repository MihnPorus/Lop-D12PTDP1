#pragma once
#include "ThiSinh.h"
class Search
{
public:
	bool max(list<ThiSinh>::iterator, list<ThiSinh>::iterator);
	void static Search_HienThi(list<ThiSinh>::iterator );
	int static Search_Name(list<ThiSinh>::iterator, string*);
	int static Search_QueQuan(list<ThiSinh>::iterator, string*);
	int static Search_NgaySinh(list<ThiSinh>::iterator, string*);
	void static Search_MaxDiem(list<ThiSinh>*);
	int static Search_Thisinh(list<ThiSinh>*, int (*Point_method)(list<ThiSinh>::iterator, string*));
};

