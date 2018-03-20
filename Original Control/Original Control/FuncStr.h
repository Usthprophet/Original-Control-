#pragma once
//example:			keybd_event(ch, 0, 0, 0);//����a��				keybd_event(ch, 0, KEYEVENTF_KEYUP, 0);//�ɿ�a��

void ClickInOnePosition(char ch,int SITUATION)	//���е�һ��ȷ�ϰ�����û���Զ��ɼ�
{
	keybd_event(ch, 0, SITUATION, 0);//����a��
}

int FuncStr(std::string FStr)		//������ע�����еĹ��ܼ�����ֱ��ʹ�ã�������Ӧ���ܼ���ӳ��
{
	if (FStr == "Enter") { return VK_RETURN; }
	else if (FStr == "Ctrl") { return VK_CONTROL; }
	else if (FStr == "Alt") { return VK_MENU; }
	else if (FStr == "Shift") { return VK_SHIFT; }
	else if (FStr == "Caps") { return VK_CAPITAL; }
	else if (FStr == "Tab") { return VK_TAB; }
	else if (FStr == "Win") { return VK_LWIN; }
	else if (FStr == "Esc") { return VK_ESCAPE; }
	else if (FStr == "Space") { return VK_SPACE; }
	else if (FStr == "Back") { return VK_BACK; }

	//��������
	else if (FStr == "Left") { return VK_LEFT; }
	else if (FStr == "Right") { return VK_RIGHT; }
	else if (FStr == "Up") { return VK_UP; }
	else if (FStr == "Down") { return VK_DOWN; }

	else if (FStr[0] == 'F')		//F1��F12��ӳ��
	{
		int StrLen = FStr.length();

		if (StrLen<=1&& StrLen>=4 &&FStr[1]<'0' && FStr[1]>'9')return -1;
		else
		{
			int num = FStr[1] - '0';
			if (StrLen == 3 && FStr[2] >= '0' &&  FStr[2] <= '9')num = num * 10 + FStr[2] - '0';
			return 111+num;
		}
	}

	return -1;
}

bool ClickFuncStr(std::string FStr)		//һ�����������ַ�������ӳ�䲢����Ĺ���
{
	int ch = FuncStr(FStr);

	if (ch > 0)
	{
		ClickOneLetter((char)ch);
		return true;
	}
	else
	{
		std::cout << "In fun[function,on/off] grammer,the factor of function is wrong:" << FStr << "\n";
		return false;
	}
}

bool ClickFuncStr(std::string FStr, std::string SITUATION)		//һ�����أ������ɼ�
{
	int ch = FuncStr(FStr);

	if (ch > 0)
	{
		if(SITUATION=="ON")		ClickInOnePosition((char)ch,0);
		else if(SITUATION=="OFF")	ClickInOnePosition((char)ch, KEYEVENTF_KEYUP);
		else
		{
			std::cout << "In fun[function,on/off] grammer,the SITUATION must be ON/OFF,but it is :" << SITUATION << "\n";
		}
		return true;
	}
	else
	{
		std::cout << "In fun[function,on/off] grammer,the factor of function is wrong:" << FStr << "\n";
		return false;
	}
}


void NOOOOOP(std::string tt)
{
	int t = atoi(tt.c_str());
	Sleep(t);
}