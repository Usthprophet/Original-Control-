#pragma once

bool TestForTextOperate = false;		//���Կ���


//�����ַ����Ĵ���
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

bool CommandName(std::string &Context,std::string &CommandName)		//�Ƿ����ҵ�һ������
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
	Context = Context.substr(CommandSitu, Context.length());		//ֱ�Ӱ�����й�ȥ
	return true;
}


bool Parameter(std::string &Context, std::string &Parameter)		//�Ƿ����ҵ�һ������
{
	int CommandSitu = Context.find(']');

	if (CommandSitu == Context.npos)
	{
		std::cout << "A wrong Position and We can not find a whole Parameter\n";
		return false;
	}

	Parameter = Context.substr(0, CommandSitu+1);
	Context = Context.substr(CommandSitu+1, Context.length());		//ֱ�Ӱ�����й�ȥ
	return true;
}


void FuncMapping(std::string FuncName,std::string FactorName)
{
	if (TestForTextOperate == true)
	{
		std::cout << "FuncName is:" << FuncName << " FactorName is:" << FactorName << "\n";
		getchar();
	}


	if (FuncName == "sleep")			//��ʱ
	{
		int FindSitu = FactorName.find(']');
		FactorName = FactorName.substr(1, FindSitu-1);
		NOOOOOP(FactorName);
	}

	else if (FuncName == "click")		//���
	{
		if (TestForTextOperate == true)std::cout << "In click\n";

		std::string x; std::string y;
		std::string POSITION;
		std::string SITUATION;		//		ON/OFF

		//�������Ҽ�
		int FindSitu = FactorName.find(',');
		POSITION = FactorName.substr(1,FindSitu-1);
		FactorName = FactorName.substr(FindSitu + 1, FactorName.length());

		//����x����
		FindSitu = FactorName.find(',');
		x = FactorName.substr(1, FindSitu-1);
		FactorName = FactorName.substr(FindSitu + 1, FactorName.length()-FindSitu-1);

		//����y����
		FindSitu = FactorName.find(')');
		y = FactorName.substr(0, FindSitu );
		FactorName = FactorName.substr(FindSitu + 1, FactorName.length() - FindSitu - 1);

		//����״̬
		FindSitu = FactorName.find(']');
		SITUATION = FactorName.substr(1, FindSitu - 1);

		if (SITUATION=="")		//û��ON/OFF������
		{

			if (TestForTextOperate == true)std::cout << "Without On/OFF the (x,y)is" << x <<" "<< y << "and Position is" << POSITION << "\n";
			ClickByOnce(x, y, POSITION);
		}
		else//��ҪON/OFF������
		{
			FactorName = FactorName.substr(FindSitu + 1, FactorName.length() - FindSitu - 1);

			if (TestForTextOperate == true)std::cout << "With On/OFF the (x,y)is" << x <<" "<< y << " Position:" << POSITION <<" SITUATION is"<<SITUATION<< "\n";

			ClickByOnce(x,y,POSITION,SITUATION);			
		}

	}
	else if (FuncName == "fun")			//���ܼ�
	{
		if (TestForTextOperate == true)std::cout << "In FUN\n";
		std::string FUNCTION;

		//��FUNCTION���п��ܳ��ֵ�ON/OFFһ��������
		int FindSitu = FactorName.find(']');
		FUNCTION = FactorName.substr(1, FindSitu - 1);


		FindSitu = FUNCTION.find(',');
		if (FindSitu == FactorName.npos)		//û�б��Ҳ��û��ON/OFF	����ִ����SITUATION������FuncStrϵ�к���
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

	else if (FuncName == "type")			//����
	{
		if (TestForTextOperate == true)std::cout << "Function type\n";
		int CommandSitu = FactorName.find(']');
		FactorName = FactorName.substr(1, CommandSitu-1);
		CharMapped(FactorName);
	}

}



void SentenceAnalysis(std::string Context)			//��ʽ����
{
	Filter(Context, ' ');
	Filter(Context, '\n');
	Filter(Context, (char)9);

	std::cout << Context<<"     fuck";


	while (true)
	{
		Sleep(DelayTime);
		//��һ���з֣��г���������
		std::string CmdName;
		if (CommandName(Context, CmdName) == false) return;
		else
		{
			//�����й���
			std::string FuncStr;
			if (Parameter(Context, FuncStr) == false) return;
			else
			{
				FuncMapping(CmdName, FuncStr);
				
			}
		}
	}
}