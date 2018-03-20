#include<iostream>
#include<Windows.h>
#include<string>


int DelayTime = 50;
int WaitingBeforeRun = 1000;
#include"TypeKeyBoard.h"
#include"FuncStr.h"
#include"MouseEvent.h"
#include"TextContextOperate.h"
#include"FileControl.h"
using namespace std;




void ViewMenu()
{
	std::cout
		<< "Choose your function:(by inputing the words or Capital symbol\n\n"
		<< "Regulation		------- For the Regulation of Screen \n"
		<< "Execute			-------	For Execute one Script\n"
		<< "Menu			-------	For clean Screan and view Manu\n"
		<< "ViewParameters	-------	For Checking and Exchange the Delay time\n";
}

void TestForOneCode()
{
	std::string fuck = "click[le ft, (25, 125)]\nfun[Win , ON]t  ype [r]\nfun[Win ,OFF]\nty  pe[cmd]\n";
	//fuck = "click[left, (25, 125),ON]";
	//fuck = "fun[Space]";
	SentenceAnalysis(fuck);			//进行预处理
}

bool IsNum(std::string Num)
{
	for (int i = 0; i < Num.length(); i++)
	{
		if (Num.at(i)<'0' || Num.at(i)>'9')return false;
	}
	return true;
}

void ExcuteManu(int argc, char *argv[])
{
	string FilePath;

	if (argc == 1)
	{
		std::cout << "We have no situation of text file,please input manually\n";
		std::cin >> FilePath;
	}
	else
	{
		std::string PathStr;
		if (IsNum(argv[1]) == false)PathStr = argv[1];
		if (argc>2&&IsNum(argv[2]) == false)PathStr = argv[2];

		std::cout << "We have a path in argv is\n  " << PathStr << "\n";
		FilePath = PathStr;
	}

	std::string CodeStr;
	CodeStr = readFileIntoString(FilePath.data());


	std::cout << "Shall we loop these Code Segment?(y/n)";
	std::string CommandStr;
	std::cin >> CommandStr;
	if (CommandStr == "y")		//执行阶段
	{
		Sleep(WaitingBeforeRun);
		std::cout << "Start Acting!\n\n";

		while (true)
		{
			SentenceAnalysis(CodeStr);

		}
	}
	else if (CommandStr == "n")
	{
		Sleep(WaitingBeforeRun);
		std::cout << "Start Acting!\n\n";

		SentenceAnalysis(CodeStr);
	}
	else std::cout << "A wrong input ,please input y or n again.\n";
}

void ViewParametersManu()
{
	std::cout << "The DelayTime Now is: " << DelayTime << " if you want to exchange, type 'y' or type other keyboard to be back\n";
	getchar();
	char ch = getchar();

	if (ch == 'y')
	{
		std::cout << "Input a new value for DelayTime:  ";
		std::cin >> DelayTime;

		std::cout << "Successed! Now the DelayTime is " << DelayTime<<"\n";
	}
	return;
}

void InsertDelayTime(int argc, char *argv[])
{
	if (argc > 1 && IsNum(argv[1]) == true)
	{
		std::cout << "Insert " << argv[1] << "As Delay Time per code\n";
		DelayTime = atoi(argv[1]);
		std::cout << "Press any key to continue\n";
		getchar();
	}
	else if (argc > 2 && IsNum(argv[2]) == true)
	{
		std::cout << "Insert " << argv[2] << "As Delay Time per code\n";
		DelayTime = atoi(argv[2]);
		std::cout << "Press any key to continue\n";
		getchar();
	}
	return ;
}


int main(int argc, char *argv[])
{
	//抽取格式为 数字 的 文件参数

	if(argc>1)InsertDelayTime(argc, argv);

	system("cls");
	std::string CommandStr;
	ViewMenu();


	while (std::cin >> CommandStr)
	{
		if (CommandStr == "Regulation" || CommandStr == "R" || CommandStr == "r")
		{
			MouseRegulation();
		}
		else if (CommandStr == "Execute" || CommandStr == "E" || CommandStr == "e")
		{
			ExcuteManu(argc,argv);
		}

		else if (CommandStr == "ViewParameters" || CommandStr == "V" || CommandStr == "v")
		{
			ViewParametersManu();
		}

		else if (CommandStr == "Menu" || CommandStr == "M" || CommandStr == "m")
		{
			system("cls");
			ViewMenu();
		}

		else
			std::cout << "A strange command for me,retry again\n";
	}

	return 0;
}



//进行语法定义

//[ ctrl/TAB  ]