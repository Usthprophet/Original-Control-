#include<iostream>
#include<Windows.h>
#include<string>


int DelayTime = 5;
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
		<< "Regulation	------- For the Regulation of Screen \n"
		<< "Execute		-------	For Execute one Script\n"
		<< "Menu		-------	For clean Screan and view Manu\n";
}

void TestForOneCode()
{
	std::string fuck = "click[le ft, (25, 125)]\nfun[Win , ON]t  ype [r]\nfun[Win ,OFF]\nty  pe[cmd]\n";
	//fuck = "click[left, (25, 125),ON]";
	//fuck = "fun[Space]";
	SentenceAnalysis(fuck);			//进行预处理
}


int main(int argc, char *argv[])
{


	//TestForOneCode();
	//return 0;

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
			string FilePath;

			if (argc == 1)
			{
				std::cout << "We have no situation of text file,please input manually\n";
				std::cin >> FilePath;

			}
			else
			{
				std::cout << "We have a path in argv is\n  " << argv[1]<<"\n";
				FilePath = argv[1];

			}

			std::string CodeStr;
			CodeStr = readFileIntoString(FilePath.data());


			std::cout << "Shall we loop these Code Segment?(y/n)";
			std::cin >> CommandStr;
			if (CommandStr == "y")		//执行阶段
			{
				while (true)
				{
					SentenceAnalysis(CodeStr);

				}
			}
			else if (CommandStr == "n")
			{
				SentenceAnalysis(CodeStr);
			}
			else std::cout << "A wrong input ,please input y or n again.\n";
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


	//testText();
	//return 0;


}



//进行语法定义

//[ ctrl/TAB  ]