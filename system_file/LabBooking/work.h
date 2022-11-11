#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Identity.h"
#include <fstream>
#include "File.h"
#include "student.h"
#include "teacher.h"
#include "Manager.h"

class Work
{
public:
	void show_root_menu();
	void login(string filename, int flag);
	void manager_work(Identity*manager);
	void student_work(Identity*student);
	void teacher_work(Identity*teacher);

	void dowork();
};