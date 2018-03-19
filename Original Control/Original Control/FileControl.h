#pragma once

#include<string>
#include<fstream>
#include<sstream>



//�����ļ���д�Ĳ���

//���ļ����뵽string��  
std::string readFileIntoString(const char * filename)
{
	std::ifstream ifile(filename);
	//���ļ����뵽ostringstream����buf��  
	std::ostringstream buf;
	char ch;
	while (buf&&ifile.get(ch))
		buf.put(ch);
	//������������buf�������ַ���  
	return buf.str();
}

int testText()
{
	//�ļ���  
	char * fn = "a.txt";
	std::string str;
	str = readFileIntoString(fn);
	std::cout << str << std::endl;
	system("pause");

	return 0;
}