#pragma once
#include <iostream>
#include <string>
#include <map>
#include "File.h"
#include <fstream>
using namespace std;
class Order
{
public:
	Order();
	void updata();
	void init_map();
	void spp(string &s);
	
	map<int,map<string,string>> m;
	int m_size;
};