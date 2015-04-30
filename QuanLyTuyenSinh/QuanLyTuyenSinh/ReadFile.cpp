#include "ReadFile.h"


bool ReadFile::Read_Login(const string &list_path, string *_id, string* _pass)
{

	ifstream Login_in(string(list_path).c_str(), ifstream::in);
	if (!Login_in) {
		cout << "Dau vao file khong hop le. Vui long kiem tra lai!";
		return false;
	}
	string str[2],line;
	while (getline(Login_in,line))
	{
		stringstream lines(line);
		getline(lines, str[0], ';');
		getline(lines, str[1], ';');
		if (!str[1].empty())
		{
			if (_id->compare(str[0].c_str()) == 0 && _pass->compare(str[1].c_str())==0)
			{
				return true;
				Login_in.close();
			}
		}
		
	}
	Login_in.close();
	return false;

}

void ReadFile::Read_Thisinh(const string &list_path1, const string &list_path2, list <ThiSinh> *thisinh)
{
	
	ifstream Thisinh_in(string(list_path2).c_str(), ifstream::in);
	if (!Thisinh_in) {
		cout << "Dau vao: " << string(list_path2).c_str()<<" xay ra loi.Vui long kiem tra lai!";
		return;
	}
	ifstream Diem_in(string(list_path1).c_str(), ios::in);
	if (!Diem_in) {
		cout << "Dau vao: " << string(list_path1).c_str() << " xay ra loi.Vui long kiem tra lai!";
		return;
	}
	string str[12], line1,line2;
	while (getline(Thisinh_in,line1)&&getline(Diem_in,line2))
	{
		ThiSinh *temp = new ThiSinh;
		pair < string, pair< vector<string>, vector<float> > > *temp_diem = new pair < string, pair< vector<string>, vector<float> > > ;
		stringstream lines1(line1);
		stringstream lines2(line2);
		temp_diem->second.second.clear();
		temp_diem->second.first.clear();
		getline(lines1, str[0], ';');
		getline(lines1, str[1], ';');
		getline(lines1, str[2], ';');
		getline(lines1, str[3], ';');
		getline(lines2, str[4], ';');
		getline(lines2, str[5], ';');
		getline(lines2, str[6], ';');
		getline(lines2, str[7], ';');
		getline(lines2, str[8], ';');
		getline(lines2, str[9], ';');
		getline(lines2, str[10], ';');
		getline(lines2, str[11], ';');
		if (!str[0].empty() && !str[1].empty() && !str[2].empty() && !str[3].empty() &&
			!str[4].empty() && !str[5].empty() && !str[6].empty() && !str[7].empty() &&
			!str[8].empty() && !str[9].empty() && !str[10].empty() && !str[11].empty())
		{
			temp->Set_sobaodanh(&str[0]);
			temp->Set_Hoten(&str[1]);
			temp->Set_Ngaysinh(&str[2]);
			temp->Set_Diachi(&str[3]);
			temp_diem->first = str[5];
			for (int i = 0; i < 5;i+=2)
			{
				temp_diem->second.first.push_back(str[i + 6]);
				temp_diem->second.second.push_back(atof(str[i + 7].c_str()));
			}
			temp->Set_diem(temp_diem);
			thisinh->push_back(*temp);
		}
	}
	Thisinh_in.close();
	Diem_in.close();
}
