#pragma once
#include "Identity.h"
#include <fstream>
#include <vector>
#include "lab.h"
#include "File.h"
#include "order_file.h"
using namespace std;
class Student :public Identity
{
public:
	Student();
	Student(int id, string name, string pwd);
	virtual void sub_menu() ;
	void apply_order();
	void self_order();
	void cancel_order();
	~Student();

	//学号
	int s_id;
	vector<Lab> vl;
	Order *o;
};