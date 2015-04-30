#include "WriteFile.h"



void WriteFile::WriteFile_Quanly(const string& list_path1, const string& list_path2, QuanLy* quanly)
{
	ofstream Login_out(string(list_path1).c_str(), ofstream::out|ofstream::app);
	if (!Login_out) {
		cout << "Dau vao file khong hop le. Vui long kiem tra lai!";
		return;
	}
	ofstream QuanLy_out(string(list_path2).c_str(), ofstream::out | ofstream::app);
	if (!QuanLy_out) {
		cout << "Dau vao file khong hop le. Vui long kiem tra lai!";
		return;
	}
	
	Login_out << quanly->Get_ID()->c_str() << ";" << quanly->Get_password()->c_str() << ";" << endl;
	QuanLy_out << quanly->Get_ID()->c_str() << ";" << quanly->Get_Hoten()->c_str() << ";" << quanly->Get_Ngaysinh()->c_str() << ";" <<
		quanly->Get_Diachi()->c_str() << ";" << quanly->Get_email()->c_str() << ";" << quanly->Get_sodienthoai()->c_str()<< endl;
	QuanLy_out.close();
	Login_out.close();
	return;
}

void WriteFile::Write_Thisinh(const string& list_path1, const string& list_path2, ThiSinh* thisinh)
{
	ofstream Thisinh_out(string(list_path1).c_str(), ofstream::out |ofstream::app);
	if (!Thisinh_out) {
		cout << "Dau vao file khong hop le. Vui long kiem tra lai!";
		return;
	}
	ofstream Diem_out(string(list_path2).c_str(), ofstream::out|ofstream::app);
	if (!Diem_out) {
		cout << "Dau vao file khong hop le. Vui long kiem tra lai!";
		return;
	}
	Thisinh_out << thisinh->Get_sobaodanh()->c_str() << ";" << thisinh->Get_Hoten()->c_str() << ";" << thisinh->Get_Ngaysinh()->c_str() <<
		";" << thisinh->Get_Diachi()->c_str() << ";" << endl;
	
	
	Diem *diem = new Diem;
	*diem = *thisinh;
	Diem_out << diem->Get_sobaodanh()->c_str() << ";" << diem->Get_diem()->first.c_str() << ";";
	for (unsigned int i = 0; i < diem->Get_diem()->second.first.size(); i++)
	{
		Diem_out << diem->Get_diem()->second.first[i].c_str() << ";" << diem->Get_diem()->second.second[i] << ";";
	}
	Diem_out << endl;
	Thisinh_out.close();
	Diem_out.close();
}
void WriteFile::Write_Up_Diem(const string& list_path, list<ThiSinh>* thisinh)
{
	ofstream Diem_out(string(list_path).c_str(), ofstream::out);
	if (!Diem_out) {
		cout << "Dau vao file khong hop le. Vui long kiem tra lai!";
		return;
	}
	Diem *diem = new Diem;

	for (list<ThiSinh>::iterator it = thisinh->begin(); it != thisinh->end(); it++)
	{
		*diem = *it;
		Diem_out << diem->Get_sobaodanh()->c_str() << ";" << diem->Get_diem()->first.c_str() << ";";
		for (unsigned int i = 0; i < diem->Get_diem()->second.first.size(); i++)
		{
			Diem_out << diem->Get_diem()->second.first[i].c_str() << ";" << diem->Get_diem()->second.second[i] << ";";
		}
		Diem_out << endl;
	}
	Diem_out.close();
}
