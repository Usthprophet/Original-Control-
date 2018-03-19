#pragma once

#include<cstdlib>

POINT GetPosition()				//��ȡ��ǰ���λ�õķ���
{
	POINT point;
	GetCursorPos(&point);
	//std::cout << "The position of mouse (X,Y) is :(" << point.x <<"  "<< point.y << ")\n";
	return point;
}

void MouseRegulation()		//���У׼
{
	POINT pointer=GetPosition();
	POINT tempPoint = pointer;

	while (true)
	{
		pointer = GetPosition();
		if (pointer.x != tempPoint.x||pointer.y!=tempPoint.y)
		{
			std::cout <<"x:"<< pointer.x << " y:" << pointer.y<<"\n";
			tempPoint = pointer;
		}
	}
}


/*
		�����ο�
		MOUSEEVENTF_LEFTDOWN		���ʾ����������
		MOUSEEVENTF_LEFTUP			���ʾ�������ɿ�
		MOUSEEVENTF_RIGHTDOWN		���ʾ����Ҽ�����
		MOUSEEVENTF_RIGHTUP			���ʾ����Ҽ��ɿ�
		MOUSEEVENTF_MIDDLEDOWN		���ʾ����м�����
		MOUSEEVENTF_MIDDLEUP		���ʾ����м��ɿ�

*/

void ClickByOnce(POINT point,int SITUATION)				//��ĳ�����Ĳ������е�������
{
	SetCursorPos(point.x, point.y);
	mouse_event(SITUATION, 0, 0, 0, 0); //�������  
}

bool ClickByOnce(std::string x,std::string y,std::string POSITION,std::string SITUATION)		//�����Խ�,��ON/OFF�ֿ�
{
	POINT point;
	point.x = atoi(x.c_str());
	point.y = atoi(y.c_str());
	int SITUINT = -1;

	if (SITUATION == "ON")
	{
		if (POSITION == "left")SITUINT = MOUSEEVENTF_LEFTDOWN;
		else if(POSITION=="right")SITUINT = MOUSEEVENTF_RIGHTDOWN;
		else std::cout << "A wrong Grammer for the factor POSITION in Click(With ON/OFF)is:" << POSITION << "\n";
	}
	else if (SITUATION == "OFF")
	{
		if (POSITION == "left")SITUINT = MOUSEEVENTF_LEFTUP;
		else if (POSITION == "right")SITUINT = MOUSEEVENTF_RIGHTUP;
		else std::cout << "A wrong Grammer for the factor POSITION in Click(With ON/OFF)is:" << POSITION << "\n";
	}
	else std::cout << "A mistake in Click (With ON/OFF),the factor of SITUATION must be ON/OFF,but it is:" << SITUATION << "\n";


	if (SITUINT == -1)std::cout << "A wrong situation in Click\n";
	else ClickByOnce(point,SITUINT);

	return true;
}

bool ClickByOnce(std::string x, std::string y, std::string POSITION)		//���أ�û��situation,Ĭ�ϵ��һ����������
{
	POINT point;
	point.x = atoi(x.c_str());
	point.y = atoi(y.c_str());
	int SITUINT = -1;

	if (POSITION == "left")
	{
		SITUINT = MOUSEEVENTF_LEFTDOWN;
		ClickByOnce(point, SITUINT);
		SITUINT = MOUSEEVENTF_LEFTUP;
		ClickByOnce(point, SITUINT);
	}
	else if (POSITION == "right")
	{
		SITUINT = MOUSEEVENTF_RIGHTDOWN;
		ClickByOnce(point, SITUINT);
		SITUINT = MOUSEEVENTF_RIGHTUP;
		ClickByOnce(point, SITUINT);
	}
	else std::cout << "A wrong Grammer for the factor POSITION in Click(Without Facotr)is:" << POSITION << "\n";
	if (SITUINT == -1)std::cout << "A wrong situation in Click(Without Factor)\n";

	return true;
}


