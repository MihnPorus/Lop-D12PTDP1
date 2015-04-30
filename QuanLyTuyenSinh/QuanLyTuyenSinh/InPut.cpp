#include "InPut.h"


string * InPut::InPut_Sodienthoai()
{
	do
	{
		try
		{
			string *std = new string;
			cout << "Nhap SDT: ";
			cin >> *std;
			if (std->length() >= 10 && std->length() <= 11)
			{
				return std;
			}
			else
			{
				throw underflow_error("So dien thoai dai tu 10-11 chu so. Nhap lai!");
			}
		}
		catch (underflow_error e)
		{
			cout << e.what() << endl;
		}

	} while (true);
}

string * InPut::InPut_ID()
{


	while (true)
	{
		try{
			ifstream Login_in(string(File_Login).c_str(), ifstream::in);
			if (!Login_in) {
				cout << "Dau vao khong hop le, kiem tra lai!";
				return 0;
			}
			string *str1 = new string;
			cout << "Nhap ID: "; fflush(stdin);
			cin >> *str1;
			Input_Chuthuong(str1);
			string ch, str,line;
			while (getline(Login_in,line)) {
				stringstream liness(line);
				getline(liness, ch, ';');
				getline(liness, str, ';');
				if (str1->compare(ch.c_str()) == 0)
				{
					throw underflow_error("ID bi trung, nhap lai!");
					Login_in.close();
				}
				
			}
			Login_in.close();
			return str1;
		}
		catch (underflow_error e)
		{
			cout << e.what() << endl;
		}

	}
}

string * InPut::InPut_Sobaodanh()
{

	while (true)
	{
		try{
			ifstream Diem_in(string(File_Diem).c_str(), ifstream::in);
			if (!Diem_in) {
				cout << "Dau vao khong hop le, kiem tra lai!";
				return 0;
			}
			string *str2 = new string;
			cout << "Nhap so bao danh: ";
			cin >> *str2;
			Input_Chuhoa(str2);
			string line, str[8];
			while (getline(Diem_in, line))
			{
				stringstream lines(line);
				getline(lines, str[0], ';');
				getline(lines, str[1], ';');
				getline(lines, str[2], ';');
				getline(lines, str[3], ';');
				getline(lines, str[4], ';');
				getline(lines, str[5], ';');
				getline(lines, str[6], ';');
				getline(lines, str[7], ';');
				if (str2->compare(str[0].c_str()) == 0)
				{
					Diem_in.close();
					throw underflow_error("SBD bi trung, nhap lai!");
				}
				
			}
			Diem_in.close();
			return str2;
		}
		catch (underflow_error e)
		{
			cout << e.what() << endl;
		}

	}
}

string * InPut::InPut_ngaysinh()
{
	do
	{
		try
		{
			string *std = new string;
			cout << "Nhap ngay sinh (DD/MM/YYYY): ";
			cin >> *std;
			if (std->length() == 10)
			{
				return std;
			}
			else
			{
				throw underflow_error("Nhap hai so tro len cho moi vung (ex: 29/06/1994). Nhap lai!");
			}
		}
		catch (underflow_error e)
		{
			cout << e.what() << endl;
		}

	} while (true);
}

string * InPut::InPut_email()
{
	while (true)
	{
		try{
			ifstream Quanly_in(string(File_Quanly).c_str(), ifstream::in);
			if (!Quanly_in) {
				cout << "Dau vao khong hop le, kiem tra lai!";
				return 0;
			}
			string *strs = new string;
			fflush(stdin);
			cout << "Nhap email: ";
			getline(cin, *strs);
			if (((strs->find_last_of("@") - strs->find_first_of("@")) != 0) || (strs->find("@") == 4294967295))
			{
				throw underflow_error("Email khong hop le. Nhap lai!");
			}
			string line,str[6];
			while (getline(Quanly_in,line)) {
				stringstream liness(line);
				getline(liness, str[0], ';');
				getline(liness, str[1], ';');
				getline(liness, str[2], ';');
				getline(liness, str[3], ';');
				getline(liness, str[4], ';');
				getline(liness, str[5], ';');
				if (str[0].empty())
				{
					break;
				}
				else
				{
					if (strs->compare(str[4].c_str()) == 0)
					{
						throw underflow_error("Email nay da co nguoi su dung. Nhap lai!");
					}
				}
			}
			Quanly_in.close();
			return strs;
		}
		catch (underflow_error e)
		{
			cout << e.what() << endl;
		}

	}
}

string * InPut::Input_password()
{
	string *_pass = new string;
	char ch;
	ch = _getch();
	while (ch != 13){
		if (ch != 8){
			_pass->push_back(ch);
			cout << '*';
		}
		else
		{
			_pass->pop_back();
		}
		ch = _getch();
	}
	Input_Chuthuong(_pass);
	return _pass;
}

void InPut::Input_Chuhoa(string * temp)
{
	transform(temp->begin(), temp->end(), temp->begin(), ::toupper);
}

void InPut::Input_Chuthuong(string *temp)
{
	transform(temp->begin(), temp->end(), temp->begin(), ::tolower);
}

void InPut::Input_Chuanhoa(string * s)
{
	string::iterator it = s->begin();
	Input_Chuthuong(s);
	*it = toupper(*it);
}



