#pragma once
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

#include "��������_�������.h"

class Journal : public PrintPublication
{

private:

	Journal* next = NULL;
	Journal* prev = NULL;

protected:

	string s_number; int i_number;		//�����

	string s_month; int i_month;		//�����			

public:

	Journal()
	{
		s_number = { "None" };
		s_month = { "None" };

		i_number = 0;
		i_month = 0;
	}

	~Journal()
	{
		delete next;
		delete prev;
	}

	void getJournal(Journal*& Journals, Journal*& headJournals, Journal*& tailJournals);

	void newJournal(Journal*& Journals, Journal*& headJournals, Journal*& tailJournals);

	void setNumber_s(string s_number);
	void setNumber_i(int	i_number);

	void setMonth_s(string s_month);
	void setMonth_i(int	i_month);
};