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


		cout << "\t\t\t\t\t|1)Задание 1             |\n\t\t\t\t\t|2)Задание 2             |\n\t\t\t\t\t" <<
			"|3)Индивидуальное задание|\n\t\t\t\t\t|4)Дополнительное задание|\n\t\t\t\t\t---------------" <<
			"-----------\n\t\t\t\t\tВыбор: ";
		int menuChoice; cin >> menuChoice;

		switch (menuChoice)
		{
		case(1): { std::system("cls"); firstTask();      break; }
		case(2): { std::system("cls"); secondTask();     break; }
		case(3): { std::system("cls"); individualTask(); break; }
		case(4): { std::system("cls"); additionalTask(); break; }
		default: {std::cout << "Введено неверное значение..."; _getch(); std::system("cls"); break; }
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region firstGeneralTask


//Задание 1
//	Создайте класс, представляющий собой данные о некоторых банковских вкладах(Deposit).У
//	него должны быть 2 закрытых поля : сумма вклада(sum) и процентная ставка(rate).При этом
//	процентная ставка – статическое поле.
//	Сумма должна определяться только при создании объекта(в конструкторе).А процентная
//	ставка может меняться со временем(нужны статические методы).
//	Помимо этого создайте метод «Получение прибыли», который увеличивает текущую сумму в
//	соответствии с процентной ставкой.
//	Определите дружественную функцию для данного класса, которая принимает массив
//	вкладов и выводит текущие суммы их в консоль.
//	Пользователь вводить суммы для массива вкладов.Далее в бесконечном цикле пользователь
//	может выбрать увеличить сумму вкладов(запустить на всех вкладах получение прибыли) или
//	вывести текущие суммы вкладов(с помощью дружественной функции).


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
			cout << "Процентная ставка повышена на " << rate << "%";
		}
		else if (a == '2')
		{
			this->rate = this->rate - rate;
			cout << "Процентная ставка понижена на " << rate << "%";
		}
		else
		{
			cout << "Невозможнось выполения операции, введён неверный знак!!" << endl;
		}
		_getch(); system("cls");
	}
};

void ShowProfit(Deposit* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " -й клиент"
			<< "\nТекущая процентная ставка = [ " << mas[i].rate << " ]"
			<< "\nДепозит = [ " << mas[i].Receiving_a_profit() << " ]\n";
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

	cout << "Текущая процентная ставка - [ " << depos.getRate() << "% ]";

	cout << "\n\nВведите размер массива"; cin >> size;

	Deposit* deposMas = new Deposit[size];

	system("cls");

	for (int i = 0; i < size; i++)
	{
		cout << "Введите сумму " << i + 1 << "-го депозита: ";
		cin >> deposSum;
		deposMas[i] = Deposit(deposSum);
	}

	system("cls");

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	while (true)
	{
		cout << "1) Вывести все выплаты\n2) Вывести текущие депозиты клиентов\n3) Повысить/понизить процентную ставку";
		cout << "\nВыбор: ";
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
					cout << i + 1 << "-й клиент, ваш депозит на данный момент = " << deposMas[i].getSum() << endl;
				}
				_getch(); system("cls"); break;
			}
			case(3):
			{
				int rate;
				int choicee;

				cout << endl << endl;
				cout << "Введите на сколько нужно увеличить или уменьшить процентную ставку: ";
				cin >> rate;

				cout << "1) Увеличить\n2) Уменьшить: "; cin >> choicee;

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

//Задание 2
//	Напишите программу «Библиотека», которая может содержать несколько разных типов
//	печатных материалов.Для этого определите иерархию классов с помощью простого наследования.
//	Базовым классом будет «Печатное издание»(поля – издательство, год, название).Добавьте
//	статическое поле по общему учету количества объектов его классов - наследников.Этот класс
//	нужен для определения общих элементов, так что его экземпляров быть не должно.
//	Производными классами для него будут классы «Журнал»(дополнительные поля – номер,
//	месяц) и «Книга»(дополнительные поля – тематика, автор, количество страниц).Далее по
//	иерархии производным для класса «Книга» будет класс «Учебник»(дополнительное поле –
//	назначение).
//		Для каждого класса напишите необходимые методы : геттеры, сеттеры, конструкторы и
//	методы вывода данных.Поля классов должны быть закрытыми для обращения извне(только с
//	помощью соответствующих методов).
//	Классы должны быть определены в отдельных модулях(файлах «.h» и «.cpp»).
//	Создайте 3 массива для объектов классов(Журнал, Книга, Учебник).Изначально массивы
//	пусты.Программа должна позволять пользователю заполнять эти массивы.Он сам должен
//	выбирать, данные какого типа вводить.
//	Также создайте функцию для вывода данных всех массивов и количества элементов(из
//	статического поля).

#include "Печатное_издание.h"
#include "Журналы.h"
#include "Книги.h"
#include "Учебники.h"

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
		cout << "\n\t1 - Добавить журнал\n\t2 - Добавить книгу\n\t3 - Добавить учебник\n\t4 - Вывод всех журналов";
		cout << "\n\t5 - Вывод всех книг\n\t6 - Вывод всех учебников\n\t7 - Вывод всех печатных изданий\n\t0 - Выход\n\t";
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

#pragma region set_publisher

			system("cls");
			cout << "\n\tТип данных \"Издательтво\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			char choicee;
			cin >> choicee;

			system("cls");

			switch (choicee)
			{
			case (1):
			{
				cout << "\n\tВведите издательство: ";
				cin >> i_publisher;
				Journals->setPublisher_i(i_publisher);
				break;
			}
			case (2):
			{
				cout << "\n\tВведите издательство: ";
				getline(cin, s_publisher);
				Journals->setPublisher_s(s_publisher);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_year

			system("cls");
			cout << "\n\tТип данных \"Год\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите год: ";
				cin >> i_year;
				Journals->setYear_i(i_year);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите год: ";
				getline(cin, s_year);
				Journals->setYear_s(s_year);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_title

			system("cls");
			cout << "\n\tТип данных \"Название\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите название: ";
				cin >> i_title;
				Journals->setTitle_i(i_title);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите название: ";
				getline(cin, s_title);
				Journals->setTitle_s(s_title);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_number

			system("cls");
			cout << "\n\tТип данных \"Номер\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите номер: ";
				cin >> i_number;
				Journals->setNumber_i(i_number);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите номер: ";
				getline(cin, s_number);
				Journals->setNumber_s(s_number);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_month

			system("cls");
			cout << "\n\tТип данных \"Месяц\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите месяц: ";
				cin >> i_month;
				Journals->setMonth_i(i_month);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите месяц: ";
				getline(cin, s_month);
				Journals->setMonth_s(s_month);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion	
			break;
		}

		case (2):
		{
			string	s_publisher, s_year, s_title, s_subject, s_author, s_numberOfPages;
			int		i_publisher, i_year, i_title, i_subject, i_author, i_numberOfPages;

			Books->newBook(Books, headBooks, tailBooks);

#pragma region set_publisher

			system("cls");
			cout << "\n\tТип данных \"Издательтво\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			char kk;
			cin >> kk;

			int k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите издательство: ";
				cin >> i_publisher;
				Books->setPublisher_i(i_publisher);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите издательство: ";
				getline(cin, s_publisher);
				Books->setPublisher_s(s_publisher);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_year

			system("cls");
			cout << "\n\tТип данных \"Год\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите год: ";
				cin >> i_year;
				Books->setYear_i(i_year);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите год: ";
				getline(cin, s_year);
				Books->setYear_s(s_year);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_title

			system("cls");
			cout << "\n\tТип данных \"Название\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите название: ";
				cin >> i_title;
				Books->setTitle_i(i_title);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите название: ";
				getline(cin, s_title);
				Books->setTitle_s(s_title);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_subject

			system("cls");
			cout << "\n\tТип данных \"Тематика\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите тематику: ";
				cin >> i_subject;
				Books->setSubject_i(i_subject);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите тематику: ";
				getline(cin, s_subject);
				Books->setSubject_s(s_subject);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_author

			system("cls");
			cout << "\n\tТип данных \"Автор\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите автора: ";
				cin >> i_author;
				Books->setAuthor_i(i_author);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите автора: ";
				getline(cin, s_author);
				Books->setAuthor_s(s_author);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_numberOfPages

			system("cls");
			cout << "\n\tТип данных \"Количество страниц\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите количество страниц: ";
				cin >> i_numberOfPages;
				Books->setNumberOfPages_i(i_numberOfPages);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите количество страниц: ";
				getline(cin, s_numberOfPages);
				Books->setNumberOfPages_s(s_numberOfPages);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion
			break;
		}

		case (3):
		{
			string	s_publisher, s_year, s_title, s_subject, s_author, s_numberOfPages, s_purpose;
			int		i_publisher, i_year, i_title, i_subject, i_author, i_numberOfPages, i_purpose;

			TextBooks->newTextBooks(TextBooks, headTextBooks, tailTextBooks);

#pragma region set_publisher

			system("cls");
			cout << "\n\tТип данных \"Издательтво\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			char kk;
			cin >> kk;

			int k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите издательство: ";
				cin >> i_publisher;
				TextBooks->setPublisher_i(i_publisher);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите издательство: ";
				getline(cin, s_publisher);
				TextBooks->setPublisher_s(s_publisher);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_year

			system("cls");
			cout << "\n\tТип данных \"Год\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите год: ";
				cin >> i_year;
				TextBooks->setYear_i(i_year);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите год: ";
				getline(cin, s_year);
				TextBooks->setYear_s(s_year);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_title

			system("cls");
			cout << "\n\tТип данных \"Название\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите название: ";
				cin >> i_title;
				TextBooks->setTitle_i(i_title);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите название: ";
				getline(cin, s_title);
				TextBooks->setTitle_s(s_title);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_subject

			system("cls");
			cout << "\n\tТип данных \"Тематика\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите тематику: ";
				cin >> i_subject;
				TextBooks->setSubject_i(i_subject);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите тематику: ";
				getline(cin, s_subject);
				TextBooks->setSubject_s(s_subject);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_author

			system("cls");
			cout << "\n\tТип данных \"Автор\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите автора: ";
				cin >> i_author;
				TextBooks->setAuthor_i(i_author);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите автора: ";
				getline(cin, s_author);
				TextBooks->setAuthor_s(s_author);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_numberOfPages

			system("cls");
			cout << "\n\tТип данных \"Количество страниц\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите количество страниц: ";
				cin >> i_numberOfPages;
				TextBooks->setNumberOfPages_i(i_numberOfPages);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите количество страниц: ";
				getline(cin, s_numberOfPages);
				TextBooks->setNumberOfPages_s(s_numberOfPages);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion

#pragma region set_numberOfPages

			system("cls");
			cout << "\n\tТип данных \"Назначение\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
			cin >> kk;

			k = isInteger(kk);
			cin.get();
			system("cls");
			switch ((createMenu)k)
			{
			case createMenu::Exit: break;

			case createMenu::Integer:
			{
				cout << "\n\tВведите назначение: ";
				cin >> i_purpose;
				TextBooks->setPurpose_i(i_purpose);
				break;
			}
			case createMenu::String:
			{
				cout << "\n\tВведите назначение: ";
				getline(cin, s_purpose);
				TextBooks->setPurpose_s(s_purpose);
				break;
			}
			default:
			{
				cout << "\n\tВведено неверное значение... ";
				char p = _getch();
				break;
			}
			}

#pragma endregion
			break;
		}

		case (4):
		{
			Journals->getJournal(Journals, headJournals, tailJournals);
			cout << "\n\t";
			char p = _getch();
			system("cls");
			break;
		}

		case (5):
		{
			Books->getBook(Books, headBooks, tailBooks);
			cout << "\n\t";
			char p = _getch();
			system("cls");
			break;
		}

		case (6):
		{
			TextBooks->getTextBook(TextBooks, headTextBooks, tailTextBooks);
			cout << "\n\t";
			char p = _getch();
			system("cls");
			break;
		}

		case (7):
		{
			cout << "\n\n\t\tЖурналы: ";
			Journals->getJournal(Journals, headJournals, tailJournals);

			cout << "\n\n\t\tКниги: ";
			Books->getBook(Books, headBooks, tailBooks);

			cout << "\n\n\t\tУчебники: ";
			TextBooks->getTextBook(TextBooks, headTextBooks, tailTextBooks);

			cout << "\n\n\n\tВсего печатных изделий: " << PrintPublication::getConter() << "\n\n\t\t";
			char p = _getch();
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











