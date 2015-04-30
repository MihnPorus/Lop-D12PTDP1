#include "Manager.h"
int main(int _Argc, char* *_Argv)
{
	Manager *manage = new Manager;
	manage->Menu1();
	delete manage;
	return _Argc;
}