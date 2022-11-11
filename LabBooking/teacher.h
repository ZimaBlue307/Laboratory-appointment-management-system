#pragma once
#include "Identity.h"
#include "order_file.h"
using namespace std;
#include <vector>
#include <map>

class Teacher :public Identity
{
public:
	Teacher();
	Teacher(int id, string name, string pwd);
	virtual void sub_menu();
	void all_order();
	void audit_order();
	void work_order();
	int check(int opt);
	~Teacher();
	//职工号
	int t_id;
	Order *o;
	vector<int> vc;
};