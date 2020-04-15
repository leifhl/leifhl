#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		cerr << "用法:" << argv[0] << " filename\n";
		exit(EXIT_FAILURE);
	}
	string filein(argv[1]);
	string fileout(argv[1], 6);
	string str;
	fileout += "json";
	cout << filein + "\n" + fileout << endl;
	ifstream fin(filein);
	if (!fin.is_open())
	{
		cerr << "无法打开文件" << filein << endl;
		fin.close();
	}
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		// cout << line << endl;
		size_t where = line.find("=");
		if (where != string::npos)
		{
			string str1(line, 0, where);
			string str2(line, ++where, line.length());
			// cout << str1 << endl;
			// cout << str2 << endl;
			where = 0;
			str += "\n \"" + str1 + "\": \"" + str2 + "\",";
			// fout << str << endl;
		}
	}
	fin.close();
	string out(str, 0, str.length() - 1);
	ofstream fout(fileout);
	if (!fout.is_open())
	{
		cerr << "无法打开文件" << fileout << endl;
		fout.close();
	}
	fout << "{";
	fout << out << endl;
	fout << "}" << endl;
	fout.close();
	cout << "转换成功!" << endl;
	return 0;
}