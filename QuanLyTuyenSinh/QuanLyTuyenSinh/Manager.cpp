#include "Manager.h"


Manager::Manager()
{
	thisinh = new list < ThiSinh > ;
	ReadFile::Read_Thisinh(string(File_Diem), string(File_Thisinh), thisinh);
}

Manager::~Manager()
{
	delete thisinh;
}

bool Manager::DangNhap()
{
	string *id = new string;
	string *pass = new string;
	cout << "_______________________________________&&&______________________________________\n" << endl;
	cout << "ID:\t\t"; fflush(stdin); getline(cin, *id); InPut::Input_Chuthuong(id);
	cout << "Password:\t"; fflush(stdin); pass = InPut::Input_password(); 
	return ReadFile::Read_Login(string(File_Login), id, pass);
}

void Manager::DangKy()
{
	QuanLy *quanly = new QuanLy;
	quanly->Nhap();
	WriteFile::WriteFile_Quanly(string(File_Login), string(File_Quanly), quanly);
	return;
}

void Manager::Menu1()
{
	bool loop = true; int chon; int count = 0;
	while (loop)
	{
		system("cls");
		cout << "\n--------------------------- QUAN LY TUYEN SINH DAI HOC -------------------------" << endl;
		cout << "\n\t  01 - Dang nhap!" << endl;
		cout << "\n\t  02 - Dang ky!" << endl;
		cout << "\n\t  03 - Thoat!" << endl;
		cout << "_______________________________________&&&______________________________________" << endl;
		cout << "\nChon chuc nang thu : ";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			system("cls"); bool yes = false;
			cout << "\n----------------------------------- DANG NHAP ----------------------------------" << endl;
			while (loop)
			{
				try
				{
					if (count >= 3)
					{
						cout << "\n_______________________________________&&&______________________________________" << endl;
						cout << "Ban da co tai khoan chua? Yes/No\n>> "; string a; getline(cin, a); InPut::Input_Chuanhoa(&a);
						if (a.compare("No") == 0)
						{
							loop = false; count = 0;
							break;
						}
						else{
							goto DK;
						}
					}
					else
					{
					DK:
						if (DangNhap() == false){
							count++;
							throw underflow_error("Nhap khong dung ID hoac Password. Vui long nhap lai!\n");
						}
						yes = true;
						loop = false;
					}

				}
				catch (underflow_error e)
				{
					system("cls");
					cout << "\n----------------------------------- DANG NHAP ----------------------------------" << endl;
					cout << "\n_______________________________________&&&______________________________________" << endl;
					cout << e.what() << endl;
				}
			}
			loop = true;
			if (yes)
			{
				Menu2();
			}
			break;
		}

		case 2:
		{
			system("cls");
			cout << "_______________________________________&&&______________________________________\n" << endl;
			DangKy();
			break;
		}
		
		case 3:
		{
			loop = false;
			break;
		}
		default:
			break;
		}
	}
}

void Manager::Menu2()
{
	bool loop = true; int chon;
	while (loop)
	{
		system("cls");
		cout << "\n--------------------------- QUAN LY TUYEN SINH DAI HOC -------------------------" << endl;
		cout << "\n_______________________________________&&&______________________________________" << endl;
		cout << "\n------------------------------ DANG NHAP THANH CONG ----------------------------" << endl;
		cout << "\n\t  01 - Bo sung them thong tin thi sinh vao du lieu!" << endl;
		cout << "\n\t  02 - Xem danh sach tat ca cac thi sinh!" << endl;
		cout << "\n\t  03 - Cap nhat thong tin diem cho thi sinh!" << endl;
		cout << "\n\t  04 - Tim kiem thong tin!" << endl;
		cout << "\n\t  05 - Thoat!" << endl;
		cout << "_______________________________________&&&______________________________________" << endl;
		cout << "\nChon chuc nang thu : ";
		cin >> chon;
		switch (chon)
		{
		case  1:
		{
			system("cls");
			char c;
			do
			{
				cout << "________________________________________________________________________________\n" << endl;
				ThiSinh *a = new ThiSinh;
				a->Nhap();
				WriteFile::Write_Thisinh(string(File_Thisinh),string(File_Diem), a);
				thisinh->push_back(*a);
				cout << "---------------------------- Thong tin vua nhap --------------------------------\n" << endl;
				a->HienThi();
				cout << "\nCo muon tiep tuc them thong tin sinh vien khac? Enter/Esc" << endl;
				c = _getch();
			} while (c != 27 && c == 13);
			break;
		}

		case 2:
		{
			system("cls");
			cout << "________________________________________________________________________________\n" << endl;
			cout << "---------------------------- DANH SACH THI SINH --------------------------------\n" << endl;
			for (list<ThiSinh>::iterator it = thisinh->begin(); it != thisinh->end(); it++)
			{
				it->HienThi();
				cout << "\n\n\t\t\t ---------------------- \n" << endl;
				cout << "\n";
			}
			system("pause");
			break;
		}

		case 3:
		{
			system("cls");
			cout << "________________________________________________________________________________\n" << endl;
			cout << "--------------------------- CAP NHAT DIEM THI SINH -----------------------------\n" << endl;
			char ch;
			do
			{
				while (true)
				{
					try
					{

						cout << "________________________________________________________________________________\n" << endl;
						int k = 0;
						string *str = new string;
						cout << "Nhap ma so thi sinh can thay doi: "; fflush(stdin); cin >> *str; InPut::Input_Chuhoa(str);
						for (list<ThiSinh>::iterator it = thisinh->begin(); it != thisinh->end(); it++)
						{
							if (it->Get_sobaodanh()->compare(str->c_str()) == 0)
							{
								k++;
								cout << "Sinh vien thi khoi " << it->Get_diem()->first.c_str() << endl;
								char c;
								do
								{
									int dem = 0;
									while (true)
									{
										try
										{

											string *str1 = new string;
											cout << "Nhap mon can thay doi: "; fflush(stdin); cin >> *str1; 
											for (int i = 0; i < it->Get_diem()->second.first.size(); i++)
											{
												if (it->Get_diem()->second.first.at(i).compare(str1->c_str()) == 0)
												{
													dem++;
													float *a = new float;
													cout << "Diem cu: " << it->Get_diem()->second.second[i] << "\t";
													cout << "Diem moi: "; cin >> *a;
													it->Get_diem()->second.second[i] = *a;
													cout << "________________________________________________________________________________\n" << endl;
													cout << "---------------------- Thong tin thi sinh vua thay doi -------------------------\n" << endl;
													it->HienThi();
													cout << "\n________________________________________________________________________________\n" << endl;

													break;
												}

											}
											if (dem == 0)
											{
												throw underflow_error("\nNhap sai ten mon. Vui long nhap lai!");
											}
											break;
										}
										catch (underflow_error e)
										{
											cout << e.what() << endl;
										}
									}
									cout << "\nCo muon tiep tuc thay doi diem mon khac? Enter/Esc" << endl;
									c = _getch();
								} while (c != 27 && c == 13);
								WriteFile::Write_Up_Diem(string(File_Diem),thisinh);
								break;
							}
						}
						if (k == 0)
						{
							throw underflow_error("\nKhong co sinh vien do. Vui long nhap lai ma!");
						}
						break;
					}
					catch (underflow_error e)
					{
						cout << e.what() << endl;
					}
				}
				cout << "\nCo muon tiep tuc them thong tin sinh vien khac? Enter/Esc" << endl;
				ch = _getch();
			} while (ch != 27 && ch == 13);
			WriteFile::Write_Up_Diem(string(File_Diem), thisinh);
			break;
		}

		case 4:
		{
			TimKiem();
			break;
		}
		case 5:
		{
			loop = false;
			break;
		}
		default:
			break;
		}
	}
}

void Manager::TimKiem()
{
	bool loop = true; int chon;
	while (loop)
	{
		system("cls");
		cout << "\n--------------------------- QUAN LY TUYEN SINH DAI HOC -------------------------" << endl;
		cout << "\n_______________________________________&&&______________________________________" << endl;
		cout << "\n------------------------------- CHUC NANG TIM KIEM -----------------------------" << endl;
		cout << "\n\t  01-Tim kiem theo ten!" << endl;
		cout << "\n\t  02-Tim kiem theo que quan!" << endl;
		cout << "\n\t  03-Tim kiem theo ngay sinh!" << endl;
		cout << "\n\t  04-Tim kiem theo tong diem cao nhat!" << endl;
		cout << "\n\t  05-Thoat!" << endl;
		cout << "_______________________________________&&&______________________________________" << endl;
		cout << "\nChon chuc nang: ";
		cin >> chon;
		switch (chon)
		{

		case 1:
		{
			system("cls");
			int count=0;
			while (true)
			{
				try
				{
					cout << "________________________________________________________________________________\n" << endl;
					cout << "------------------------------- Tim theo ten -----------------------------------\n" << endl;
					count = Search::Search_Thisinh(thisinh, Search::Search_Name);
					if (count==0)
					{
						throw underflow_error("Khong co thi sinh can tim. Vui long nhap lai!");
					}
					break;
				}
				catch (underflow_error e)
				{
					cout << e.what() << endl;
				}
				
			}
			cout << "\n________________________________________________________________________________\n" << endl;
			system("pause");
			break;
			
		}

		case 2:
		{
			system("cls");
			int count = 0;
			while (true)
			{
				try
				{
					cout << "________________________________________________________________________________\n" << endl;
					cout << "----------------------------- Tim theo dia chi ---------------------------------\n" << endl;
					count = Search::Search_Thisinh(thisinh, Search::Search_QueQuan);
					if (count == 0)
					{
						throw underflow_error("Khong co thi sinh can tim. Vui long nhap lai!");
					}
					break;
				}
				catch (underflow_error e)
				{
					cout << e.what() << endl;
				}

			}
			cout << "\n________________________________________________________________________________\n" << endl;
			system("pause");
			break;
		}

		case 3:
		{
			system("cls");
			int count = 0;
			while (true)
			{
				try
				{
					cout << "________________________________________________________________________________\n" << endl;
					cout << "---------------------------- Tim theo ngay sinh --------------------------------\n" << endl;
					count = Search::Search_Thisinh(thisinh, Search::Search_NgaySinh);
					if (count == 0)
					{
						throw underflow_error("Khong co thi sinh can tim. Vui long nhap lai!");
					}
					break;
				}
				catch (underflow_error e)
				{
					cout << e.what() << endl;
				}

			}
			cout << "\n________________________________________________________________________________\n" << endl;
			system("pause");
			break;
		}

		case 4:
		{
			system("cls");
			cout << "________________________________________________________________________________\n" << endl;
			cout << "---------------------------- Tim theo max diem --------------------------------\n" << endl;
			Search::Search_MaxDiem(thisinh);
			cout << "\n________________________________________________________________________________\n" << endl;
			system("pause");
			break;
		}
		case 5:
		{
			loop = false;
			break;
		}
		default:
			break;
		}
	}
	

}


