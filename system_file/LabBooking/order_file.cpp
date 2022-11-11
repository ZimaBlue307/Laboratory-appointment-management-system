#include "order_file.h"

Order::Order()
{
	this->init_map();
}
void Order::spp(string &data)
{
	
}
void Order::init_map()
{
	this->m.clear();
	this->m_size = 1;
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;
	string time_interval;
	string lab_id;
	string stu_id;
	string stu_name;
	string status;
	
	while (ifs >> data && ifs >> time_interval && ifs >> lab_id && ifs >> stu_id && ifs >> stu_name && ifs >> status)
	{
		int pos = data.find(':');
		string key;
		string value;
		map<string, string> temp;
		temp.clear();
		key = data.substr(0, pos);
		value = data.substr(pos + 1, data.size() - 1 - pos);
		temp.insert(pair<string, string>(key, value));

		pos = time_interval.find(':');
		key = time_interval.substr(0, pos);
		value = time_interval.substr(pos + 1, time_interval.size() - 1);
		temp.insert(pair<string, string>(key, value));

		pos = lab_id.find(':');
		key = lab_id.substr(0, pos);
		value = lab_id.substr(pos + 1, lab_id.size() - 1);
		temp.insert(pair<string, string>(key, value));

		pos = stu_id.find(':');
		key = stu_id.substr(0, pos);
		value = stu_id.substr(pos + 1, stu_id.size() - 1);
		temp.insert(pair<string, string>(key, value));

		pos = stu_name.find(':');
		key = stu_name.substr(0, pos);
		value = stu_name.substr(pos + 1, stu_name.size() - 1);
		temp.insert(pair<string, string>(key, value));

		pos = status.find(':');
		key = status.substr(0, pos);
		value = status.substr(pos + 1, status.size() - 1);
		temp.insert(pair<string, string>(key, value));
		
		m.insert(pair<int, map<string, string>>(this->m_size, temp));
		this->m_size++;		

	}
	ifs.close();
	
}
void Order::updata()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out);
	for (map<int, map<string, string>>::iterator it = m.begin(); it != m.end(); it++)
	{		
		ofs << "data:" << it->second["data"] << "  ";
		ofs << "time_interval:" << it->second["time_interval"] << "  ";
		ofs << "lab_id:" << it->second["lab_id"] << "  ";
		ofs << "stu_id:" << it->second["stu_id"] << "  ";
		ofs << "stu_name:" << it->second["stu_name"] << "  ";
		ofs << "status:" << it->second["status"] << endl;
	}
	ofs.close();
}