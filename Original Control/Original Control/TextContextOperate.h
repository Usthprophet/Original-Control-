#pragma once

bool TestForTextOperate = false;		//测试开关


//用于字符串的处理
void Filter(std::string& Context,char ch)
{
	int index = 0;
	if (!Context.empty())
	{
		while ((index = Context.find(ch, index)) != std::string::npos)
		{
			Context.erase(index, 1);
		}
	}
}

bool CommandName(std::string &Context,std::string &CommandName)		//是否能找到一个命令
{
	if (Context.empty() == true)
	{
		std::cout << "Finished";
		return false;
	}


	int CommandSitu = Context.find('[');

	if (CommandSitu == Context.npos)
	{
		std::cout << "A wrong Position and We can not find a whole Command\n";
		return false;
	}

	CommandName = Context.substr(0, CommandSitu);
	Context = Context.substr(CommandSitu, Context.length());		//直接把这段切过去
	return true;
}


bool Parameter(std::string &Context, std::string &Parameter)		//是否能找到一个命令
{
	int CommandSitu = Context.find(']');

	if (CommandSitu == Context.npos)
	{
		std::cout << "A wrong Position and We can not find a whole Parameter\n";
		return false;
	}

	Parameter = Context.substr(0, CommandSitu+1);
	Context = Context.substr(CommandSitu+1, Context.length());		//直接把这段切过去
	return true;
}


void FuncMapping(std::string FuncName,std::string FactorName)
{
	if (TestForTextOperate == true)
	{
		std::cout << "FuncName is:" << FuncName << " FactorName is:" << FactorName << "\n";
		getchar();
	}


	if (FuncName == "sleep")			//延时
	{
		int FindSitu = FactorName.find(']');
		FactorName = FactorName.substr(1, FindSitu-1);
		NOOOOOP(FactorName);
	}

	else if (FuncName == "click")		//鼠标
	{
		if (TestForTextOperate == true)std::cout << "In click\n";

		std::string x; std::string y;
		std::string POSITION;
		std::string SITUATION;		//		ON/OFF

		//先切左右键
		int FindSitu = FactorName.find(',');
		POSITION = FactorName.substr(1,FindSitu-1);
		FactorName = FactorName.substr(FindSitu + 1, FactorName.length());

		//再切x坐标
		FindSitu = FactorName.find(',');
		x = FactorName.substr(1, FindSitu-1);
		FactorName = FactorName.substr(FindSitu + 1, FactorName.length()-FindSitu-1);

		//再切y坐标
		FindSitu = FactorName.find(')');
		y = FactorName.substr(0, FindSitu );
		FactorName = FactorName.substr(FindSitu + 1, FactorName.length() - FindSitu - 1);

		//再切状态
		FindSitu = FactorName.find(']');
		SITUATION = FactorName.substr(1, FindSitu - 1);

		if (SITUATION=="")		//没有ON/OFF的重载
		{

			if (TestForTextOperate == true)std::cout << "Without On/OFF the (x,y)is" << x <<" "<< y << "and Position is" << POSITION << "\n";
			ClickByOnce(x, y, POSITION);
		}
		else//需要ON/OFF的重载
		{
			FactorName = FactorName.substr(FindSitu + 1, FactorName.length() - FindSitu - 1);

			if (TestForTextOperate == true)std::cout << "With On/OFF the (x,y)is" << x <<" "<< y << " Position:" << POSITION <<" SITUATION is"<<SITUATION<< "\n";

			ClickByOnce(x,y,POSITION,SITUATION);			
		}

	}
	else if (FuncName == "fun")			//功能键
	{
		if (TestForTextOperate == true)std::cout << "In FUN\n";
		std::string FUNCTION;

		//连FUNCTION带有可能出现的ON/OFF一起切下来
		int FindSitu = FactorName.find(']');
		FUNCTION = FactorName.substr(1, FindSitu - 1);


		FindSitu = FUNCTION.find(',');
		if (FindSitu == FactorName.npos)		//没有标点也就没有ON/OFF	可以执行无SITUATION参数的FuncStr系列函数
		{
			if (TestForTextOperate == true)std::cout <<"FUNCTION is"<< FUNCTION << "  "<<std::endl;

			ClickFuncStr(FUNCTION);
		}
		else
		{
			std::string SITUATION=FUNCTION.substr(FindSitu+1,FactorName.length()- FindSitu);
			FUNCTION = FUNCTION.substr(0,FindSitu);

			if (TestForTextOperate == true)
			std::cout <<"FUNCTION is "<< FUNCTION<<" AND SITUATION is "<<SITUATION<<std::endl;


			ClickFuncStr(FUNCTION,SITUATION);
		}
	}

	else if (FuncName == "type")			//键盘
	{
		if (TestForTextOperate == true)std::cout << "Function type\n";
		int CommandSitu = FactorName.find(']');
		FactorName = FactorName.substr(1, CommandSitu-1);
		CharMapped(FactorName);
	}

}



void SentenceAnalysis(std::string Context)			//句式解析
{
	Filter(Context, ' ');
	Filter(Context, '\n');
	Filter(Context, (char)9);

	std::cout << Context<<"     fuck";


	while (true)
	{
		Sleep(DelayTime);
		//第一次切分，切出命令种类
		std::string CmdName;
		if (CommandName(Context, CmdName) == false) return;
		else
		{
			//接着切功能
			std::string FuncStr;
			if (Parameter(Context, FuncStr) == false) return;
			else
			{
				FuncMapping(CmdName, FuncStr);
				
			}
		}
	}
}