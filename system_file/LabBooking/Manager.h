#pragma once
#include "Identity.h"
using namespace std;
#include "File.h"
#include <fstream>
#include "student.h"
#include "teacher.h"
#include <vector>
#include <algorithm>
#include "lab.h"

struct student_info
{
	int s_id;
	string m_name;
	string m_pwd;
};

struct teacher_info
{
	int t_id;
	string m_name;
	string m_pwd;
};

struct lab_info
{
	string id;
	string name;
};

class Manager :public Identity
{
public:
	Manager();
	Manager(string name, string pwd);
	virtual void sub_menu();
	void add_account();
	void show_account();
	void add_lab();
	void show_lab();
	void clear_order();
	void init_vector();
	bool check(int id,int flag);
	~Manager();
	
	vector<student_info> vs;
	vector<teacher_info> vt;
	vector<lab_info> vl;
};