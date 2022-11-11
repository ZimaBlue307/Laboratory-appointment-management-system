#pragma once
#include <iostream>
#include <string>
using namespace std;

class Identity
{
public:
	virtual void sub_menu() = 0;

	string m_name;//姓名
	string m_pwd;//密码
};