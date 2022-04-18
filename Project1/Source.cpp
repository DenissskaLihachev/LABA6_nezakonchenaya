#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

void firstTask();
void secondTask();
void individualTask();
void additionalTask();

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	while (true)
	{

		cout << "\t\t\t/////      /////  ////////  //////     ///  ///      ///\n";
		cout << "\t\t\t//////    //////  ////////  //////     ///  ///      ///\n";
		cout << "\t\t\t///  //////  ///  ///       /// ///    ///  ///      ///\n";
		cout << "\t\t\t///   ////   ///  //////    ///  ///   ///  ///      ///\n";
		cout << "\t\t\t///          ///  //////    ///   ///  ///  ///      ///\n";
		cout << "\t\t\t///          ///  ///       ///    /// ///  ///      ///\n";
		cout << "\t\t\t///          ///  ////////  ///     //////  ///      ///\n";
		cout << "\t\t\t///          ///  ////////  ///      /////  ////////////\n";
		cout << "\t\t\t--------------------------------------------------------\n";


		cout << "\t\t\t\t\t|1)������� 1             |\n\t\t\t\t\t|2)������� 2             |\n\t\t\t\t\t" <<
			"|3)�������������� �������|\n\t\t\t\t\t|4)�������������� �������|\n\t\t\t\t\t---------------" <<
			"-----------\n\t\t\t\t\t�����: ";
		int menuChoice; cin >> menuChoice;

		switch (menuChoice)
		{
		case(1): { std::system("cls"); firstTask();      break; }
		case(2): { std::system("cls"); secondTask();     break; }
		case(3): { std::system("cls"); individualTask(); break; }
		case(4): { std::system("cls"); additionalTask(); break; }
		default: {std::cout << "������� �������� ��������..."; _getch(); std::system("cls"); break; }
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region firstGeneralTask


//������� 1
//	�������� �����, �������������� ����� ������ � ��������� ���������� �������(Deposit).�
//	���� ������ ���� 2 �������� ���� : ����� ������(sum) � ���������� ������(rate).��� ����
//	���������� ������ � ����������� ����.
//	����� ������ ������������ ������ ��� �������� �������(� ������������).� ����������
//	������ ����� �������� �� ��������(����� ����������� ������).
//	������ ����� �������� ����� ���������� �������, ������� ����������� ������� ����� �
//	������������ � ���������� �������.
//	���������� ������������� ������� ��� ������� ������, ������� ��������� ������
//	������� � ������� ������� ����� �� � �������.
//	������������ ������� ����� ��� ������� �������.����� � ����������� ����� ������������
//	����� ������� ��������� ����� �������(��������� �� ���� ������� ��������� �������) ���
//	������� ������� ����� �������(� ������� ������������� �������).


class Deposit
{
private:

	float		 sum;
	static float rate;

public:

	friend void ShowProfit(Deposit*, int);

	Deposit()
	{
		sum = 0;
	}

	Deposit(int a)
	{
		sum = a;
	}

	float getRate()
	{
		return rate;
	}

	float getSum()
	{
		return sum;
	}

	float Receiving_a_profit()
	{
		return sum = sum + (sum * (rate / 100));
	}

	void updateRate(float rate, int a)
	{
		if (a == '1')
		{
			this->rate = this->rate + rate;
			cout << "���������� ������ �������� �� " << rate << "%";
		}
		else if (a == '2')
		{
			this->rate = this->rate - rate;
			cout << "���������� ������ �������� �� " << rate << "%";
		}
		else
		{
			cout << "������������ ��������� ��������, ����� �������� ����!!" << endl;
		}
		_getch(); system("cls");
	}
};

void ShowProfit(Deposit* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " -� ������"
			<< "\n������� ���������� ������ = [ " << mas[i].rate << " ]"
			<< "\n������� = [ " << mas[i].Receiving_a_profit() << " ]\n";
	}
}

float Deposit::rate = 10.5;


void firstTask()
{
	int size;
	int deposSum;
	int choice;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Deposit depos(10000);

	cout << "������� ���������� ������ - [ " << depos.getRate() << "% ]";

	cout << "\n\n������� ������ �������"; cin >> size;

	Deposit* deposMas = new Deposit[size];

	system("cls");

	for (int i = 0; i < size; i++)
	{
		cout << "������� ����� " << i + 1 << "-�� ��������: ";
		cin >> deposSum;
		deposMas[i] = Deposit(deposSum);
	}

	system("cls");

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	while (true)
	{
		cout << "1) ������� ��� �������\n2) ������� ������� �������� ��������\n3) ��������/�������� ���������� ������";
		cout << "\n�����: ";
		cin >> choice;

		system("cls");

		switch (choice)
		{
			case(1):
			{
				ShowProfit(deposMas, size);

				_getch(); system("cls"); break;
			}
			case(2):
			{
				for (int i = 0; i < size; i++)
				{
					cout << i + 1 << "-� ������, ��� ������� �� ������ ������ = " << deposMas[i].getSum() << endl;
				}
				_getch(); system("cls"); break;
			}
			case(3):
			{
				int rate;
				int choicee;

				cout << endl << endl;
				cout << "������� �� ������� ����� ��������� ��� ��������� ���������� ������: ";
				cin >> rate;

				cout << "1) ���������\n2) ���������: "; cin >> choicee;

				system("cls");

				depos.updateRate(rate, choicee);

				choicee = 0;

				break;

				_getch(); system("cls"); break;
			}
		}

	}

	_getch();
}

#pragma endregion 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region secondTask

//������� 2
//	�������� ��������� �����������, ������� ����� ��������� ��������� ������ �����
//	�������� ����������.��� ����� ���������� �������� ������� � ������� �������� ������������.
//	������� ������� ����� ��������� �������(���� � ������������, ���, ��������).��������
//	����������� ���� �� ������ ����� ���������� �������� ��� ������� - �����������.���� �����
//	����� ��� ����������� ����� ���������, ��� ��� ��� ����������� ���� �� ������.
//	������������ �������� ��� ���� ����� ������ �������(�������������� ���� � �����,
//	�����) � ������(�������������� ���� � ��������, �����, ���������� �������).����� ��
//	�������� ����������� ��� ������ ������ ����� ����� ��������(�������������� ���� �
//	����������).
//		��� ������� ������ �������� ����������� ������ : �������, �������, ������������ �
//	������ ������ ������.���� ������� ������ ���� ��������� ��� ��������� �����(������ �
//	������� ��������������� �������).
//	������ ������ ���� ���������� � ��������� �������(������ �.h� � �.cpp�).
//	�������� 3 ������� ��� �������� �������(������, �����, �������).���������� �������
//	�����.��������� ������ ��������� ������������ ��������� ��� �������.�� ��� ������
//	��������, ������ ������ ���� �������.
//	����� �������� ������� ��� ������ ������ ���� �������� � ���������� ���������(��
//	������������ ����).

#include "��������_�������.h"
#include "�������.h"
#include "�����.h"
#include "��������.h"

int PrintPublication::counter = 0;


void secondTask()
{
	Journal* Journals = NULL;
	Journal* headJournals = NULL;
	Journal* tailJournals = NULL;

	Book* Books = NULL;
	Book* headBooks = NULL;
	Book* tailBooks = NULL;

	TextBook* TextBooks = NULL;
	TextBook* headTextBooks = NULL;
	TextBook* tailTextBooks = NULL;

	while (true)
	{
		system("cls");
		cout << "1) �������� ������\n2) �������� �����\n3) �������� �������\n4) ����� ���� ��������";
		cout << "\n5) ����� ���� ����\n6) ����� ���� ���������\n7) ����� ���� �������� �������\n�����: ";
		int choice;
		cin >> choice;

		system("cls");

		switch (choice)
		{
			case (1):
			{
			string	s_publisher, s_year, s_title, s_number, s_month;
			int		i_publisher, i_year, i_title, i_number, i_month;

			Journals->newJournal(Journals, headJournals, tailJournals);



			system("cls");
			cout << "\n��� ������ \"�����������\":\n1) �������������\n2) ���������\n�����: ";
			int choicee;
			cin >> choicee;

			system("cls");

			switch (choicee)
			{
				case (1):
				{
					cout << "\n������� ������������: ";
					cin >> i_publisher;
					Journals->setPublisher_i(i_publisher);
					break;
				}
				case (2):
				{
					cout << "\n������� ������������: ";
					getline(cin, s_publisher);
					Journals->setPublisher_s(s_publisher);
					break;
				}
			}

			system("cls");

			cout << "\n��� ������ \"���\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ���: ";
					cin >> i_year;
					Journals->setYear_i(i_year);
					break;
				}
				case (2):
				{
					cout << "\n������� ���: ";
					getline(cin, s_year);
					Journals->setYear_s(s_year);
					break;
				}
			}


			system("cls");
			cout << "\n��� ������ \"��������\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");
			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ��������: ";
					cin >> i_title;
					Journals->setTitle_i(i_title);
					break;
				}
				case (2):
				{
					cout << "\n������� ��������: ";
					getline(cin, s_title);
					Journals->setTitle_s(s_title);
					break;
				}
			}

			system("cls");
			cout << "\n��� ������ \"�����\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");
			switch (choice)
			{
				case (1):
				{
					cout << "\n������� �����: ";
					cin >> i_number;
					Journals->setNumber_i(i_number);
					break;
				}
				case (2):
				{
					cout << "\n������� �����: ";
					getline(cin, s_number);
					Journals->setNumber_s(s_number);
					break;
				}

			}

			system("cls");
			cout << "\n��� ������ \"�����\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� �����: ";
					cin >> i_month;
					Journals->setMonth_i(i_month);
					break;
				}
				case (2):
				{
					cout << "\n������� �����: ";
					getline(cin, s_month);
					Journals->setMonth_s(s_month);
					break;
				}
			}	
			break;
		}

			case (2):
			{
			string	s_publisher, s_year, s_title, s_subject, s_author, s_numberOfPages;
			int		i_publisher, i_year, i_title, i_subject, i_author, i_numberOfPages;

			Books->newBook(Books, headBooks, tailBooks);

			system("cls");
			cout << "\n��� ������ \"�����������\":\n1) �������������\n2) ���������\n�����: ";
			int choice;
			cin >> choice;
;
			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ������������: ";
					cin >> i_publisher;
					Books->setPublisher_i(i_publisher);
					break;
				}
				case (2):
				{
					cout << "\n������� ������������: ";
					getline(cin, s_publisher);
					Books->setPublisher_s(s_publisher);
					break;
				}
			}

			system("cls");
			cout << "\n��� ������ \"���\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n\t������� ���: ";
					cin >> i_year;
					Books->setYear_i(i_year);
					break;
				}
				case (2):
				{
					cout << "\n������� ���: ";
					getline(cin, s_year);
					Books->setYear_s(s_year);
					break;
				}
			}

			system("cls");
			cout << "\n��� ������ \"��������\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ��������: ";
					cin >> i_title;
					Books->setTitle_i(i_title);
					break;
				}
				case (2):
				{
					cout << "\n������� ��������: ";
					getline(cin, s_title);
					Books->setTitle_s(s_title);
					break;
				}
			}

			system("cls");

			cout << "\n��� ������ \"��������\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ��������: ";
					cin >> i_subject;
					Books->setSubject_i(i_subject);
					break;
				}
				case (2):
				{
					cout << "\n������� ��������: ";
					getline(cin, s_subject);
					Books->setSubject_s(s_subject);
					break;
				}
			}

			system("cls");
			cout << "\n��� ������ \"�����\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ������: ";
					cin >> i_author;
					Books->setAuthor_i(i_author);
					break;
				}
				case (2):
				{
					cout << "\n������� ������: ";
					getline(cin, s_author);
					Books->setAuthor_s(s_author);
					break;
				}
			}

			system("cls");
			cout << "\n��� ������ \"���������� �������\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ���������� �������: ";
					cin >> i_numberOfPages;
					Books->setNumberOfPages_i(i_numberOfPages);
					break;
				}
				case (2):
				{
					cout << "\n������� ���������� �������: ";
					getline(cin, s_numberOfPages);
					Books->setNumberOfPages_s(s_numberOfPages);
					break;
				}
			}
			break;
		}

			case (3):
			{
			string	s_publisher, s_year, s_title, s_subject, s_author, s_numberOfPages, s_purpose;
			int		i_publisher, i_year, i_title, i_subject, i_author, i_numberOfPages, i_purpose;

			TextBooks->newTextBooks(TextBooks, headTextBooks, tailTextBooks);

			system("cls");
			cout << "\n��� ������ \"�����������\":\n1) �������������\n2) ���������\n�����: ";
			int choice;
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ������������: ";
					cin >> i_publisher;
					TextBooks->setPublisher_i(i_publisher);
					break;
				}
				case (2):
				{
					cout << "\n������� ������������: ";
					getline(cin, s_publisher);
					TextBooks->setPublisher_s(s_publisher);
					break;
				}
			}

			system("cls");
			cout << "\n��� ������ \"���\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ���: ";
					cin >> i_year;
					TextBooks->setYear_i(i_year);
					break;
				}
				case (2):
				{
					cout << "\n������� ���: ";
					getline(cin, s_year);
					TextBooks->setYear_s(s_year);
					break;
				}
			}

			system("cls");
			cout << "\n��� ������ \"��������\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ��������: ";
					cin >> i_title;
					TextBooks->setTitle_i(i_title);
					break;
				}
				case (2):
				{
					cout << "\n������� ��������: ";
					getline(cin, s_title);
					TextBooks->setTitle_s(s_title);
					break;
				}
			}

			system("cls");
			cout << "\n��� ������ \"��������\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ��������: ";
					cin >> i_subject;
					TextBooks->setSubject_i(i_subject);
					break;
				}
				case (2):
				{
					cout << "\n������� ��������: ";
					getline(cin, s_subject);
					TextBooks->setSubject_s(s_subject);
					break;
			}
			}

			system("cls");
			cout << "\n��� ������ \"�����\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case(1):
				{
					cout << "\n������� ������: ";
					cin >> i_author;
					TextBooks->setAuthor_i(i_author);
					break;
				}
				case (2):
				{
					cout << "\n������� ������: ";
					getline(cin, s_author);
					TextBooks->setAuthor_s(s_author);
					break;
				}
			}


			system("cls");
			cout << "\n��� ������ \"���������� �������\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ���������� �������: ";
					cin >> i_numberOfPages;
					TextBooks->setNumberOfPages_i(i_numberOfPages);
					break;
				}
				case (2):
				{
					cout << "\n������� ���������� �������: ";
					getline(cin, s_numberOfPages);
					TextBooks->setNumberOfPages_s(s_numberOfPages);
					break;
				}
			}

			system("cls");
			cout << "\n��� ������ \"����������\":\n1) �������������\n2) ���������\n�����: ";
			cin >> choice;

			system("cls");

			switch (choice)
			{
				case (1):
				{
					cout << "\n������� ����������: ";
					cin >> i_purpose;
					TextBooks->setPurpose_i(i_purpose);
					break;
				}
				case (2):
				{
					cout << "\n������� ����������: ";
					getline(cin, s_purpose);
					TextBooks->setPurpose_s(s_purpose);
					break;
				}
			}
			break;
		}

			case (4):
			{
			Journals->getJournal(Journals, headJournals, tailJournals);
			cout << "\n";
			_getch();
			system("cls");
			break;
		}

			case (5):
			{
			Books->getBook(Books, headBooks, tailBooks);
			cout << "\n";
			_getch();
			system("cls");
			break;
		}

			case (6):
			{
			TextBooks->getTextBook(TextBooks, headTextBooks, tailTextBooks);
			cout << "\n";
			_getch();
			system("cls");
			break;
		}

			case (7):
			{
			cout << "\n\n\t\t�������: ";
			Journals->getJournal(Journals, headJournals, tailJournals);

			cout << "\n\n\t\t�����: ";
			Books->getBook(Books, headBooks, tailBooks);

			cout << "\n\n\t\t��������: ";
			TextBooks->getTextBook(TextBooks, headTextBooks, tailTextBooks);

			cout << "\n\n\n\t����� �������� �������: " << PrintPublication::getConter() << "\n\n\t\t";
			_getch();
			break;
		}
		}
	}
}

#pragma endregion

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region individualTask

void individualTask()
{

}

#pragma endregion

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





void additionalTask()
{
	_getch();
}











