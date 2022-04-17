#pragma once
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

class PrintPublication
{

protected:

	string s_publisher; int i_publisher; 	//������������

	string s_year; int i_year;				//���

	string s_title; int i_title; 			//��������	

private:

	static int counter;						//���-�� �������

public:

	PrintPublication()
	{
		s_publisher = { "None" };
		s_year = { "None" };
		s_title = { "None" };

		i_publisher = 0;
		i_year = 0;
		i_title = 0;
		counter++;
	}

	~PrintPublication()
	{
		counter--;
	}

	static int getConter();

	void getPrintPublication();

	void setPublisher_s(string s_publisher);
	void setPublisher_i(int	i_publisher);

	void setYear_s(string s_year);
	void setYear_i(int	i_year);

	void setTitle_s(string s_title);
	void setTitle_i(int	i_title);
};