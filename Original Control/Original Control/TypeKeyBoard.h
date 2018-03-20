#pragma once

//���м��̲����ļ���


void ClickOneLetter(char ch)			//���ڽ���һ����ĸ����д	
{
	keybd_event(ch, 0, 0, 0);//����a��
	keybd_event(ch, 0, KEYEVENTF_KEYUP, 0);//�ɿ�a��
}


void LowerCase(char ch)
{
	//Сд��ĸ��һ����Сд�Ľ�λ
	ClickOneLetter(ch - ('a' - 'A'));
}

void ShiftClick(char ch)
{
	keybd_event(16, 0, 0, 0);//����Shift��
	ClickOneLetter(ch);
	keybd_event(16, 0, KEYEVENTF_KEYUP, 0);//�ɿ�Shift��
}


bool DotExchange(char &ch)		//�����ŵ�ת��		��shift
{
	if (ch == '[') { ch = 219; return true; }
	else if (ch == ']') { ch = 221; return true; }
	else if (ch == ',') { ch = 188; return true; }
	else if (ch == '.') { ch = 190; return true; }
	else if (ch == '/') { ch = 220; return true; }
	else if (ch == '-') { ch = 189; return true; }
	else if (ch == '=') { ch = 187; return true; }
	return false;
}

bool DotExchangeAdvanced(char &ch)		//�����ŵ� shiftת��
{
	if (ch == '!') { ch = '1'; return true; }
	else if (ch == '@') { ch = '2'; return true; }
	else if (ch == '#') { ch = '3'; return true; }
	else if (ch == '$') { ch = '4'; return true; }
	else if (ch == '%') { ch = '5'; return true; }
	else if (ch == '^') { ch = '6'; return true; }
	else if (ch == '&') { ch = '7'; return true; }
	else if (ch == '*') { ch = '8'; return true; }
	else if (ch == '(') { ch = '9'; return true; }
	else if (ch == ')') { ch = '0'; return true; }
	if (ch == '{') { ch = 219; return true; }
	else if (ch == '}') { ch = 221; return true; }
	else if (ch == '<') { ch = 188; return true; }
	else if (ch == '>') { ch = 190; return true; }
	else if (ch == '?') { ch = 220; return true; }
	else if (ch == '+') { ch = VK_ADD; return true; }

	return false;
}

bool CharMapped(char ch)			//�ܺ���
{
	//����
	if (ch >= '0'&&ch <= '9')ClickOneLetter(ch);
	//Сд��ĸ
	else if (ch >= 'a'&&ch <= 'z')LowerCase(ch);
	//��д��ĸ
	else if (ch >= 'A'&&ch <= 'Z')ShiftClick(ch);
	//���ŵ�ӳ�估ת��������		//������ʾ����һ�㣬������Ҫshift����
	else if (DotExchange(ch) == true)ClickOneLetter(ch);
	//shift�Ľ��׷���
	else if (DotExchangeAdvanced(ch) == true)ShiftClick(ch);

	else
	{
		std::cout << "Can not analysis this symbol,the ASC2 Value of this symbol is��" << ch << std::endl;
		return false;
	}
		
	return true;
}

bool CharMapped(std::string Str)		//��������
{
	for (int i = 0; i < Str.length(); i++)
	{
		if (CharMapped(Str.at(i)) == false)
		{
			std::cout << "One of the symbol in type function has been crashed\n";
			return false;
		}
	}
	return true;
}