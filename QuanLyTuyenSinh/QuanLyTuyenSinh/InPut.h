#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include "Defs.h"
#include <list>
using namespace std;
class InPut
{
public:

	string static * InPut_Sodienthoai();
	string static * InPut_ID();
	string static * InPut_Sobaodanh();
	string static * InPut_ngaysinh();
	string static * InPut_email();
	string static * Input_password();
	void static Input_Chuhoa(string *);
	void static Input_Chuthuong(string *);
	void static Input_Chuanhoa(string *);
};


