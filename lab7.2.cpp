//Пусть имеется контейнер, представляющий базу данных о покупателях: фио, e-mail, количество покупок, сумма покупок. 
//Необходимо определить всех наиболее частых покупателей для создания списка рассылки для оправки рекламных материалов по почте.
//Список рассылки не должен содержать превышать 500 адресатов.Оценить количество проходов по клиентской базе.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dataBase
{
	string name0, name1, name2, email;
	int kolvo, summ;
	dataBase(string n0, string n1, string n2, string milo, int count, int dohod) :
		name0(n0), name1(n1), name2(n2), email(milo), kolvo(count), summ(dohod)
	{};
};

void output(dataBase a)
{
	cout << a.name0 << " " << a.name1 << " " << a.name2 << endl << "email: " << a.email << endl << "Совершено " << a.kolvo << " покупок на сумму " << a.summ << " рублей." << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	vector<dataBase> conteiner;
	conteiner.push_back(dataBase("Aniskin", "Dmitry", "Viktorovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Breschuk", "Dmitry", "Alexandrovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Grigoruk", "Alina", "Aleksandrovna", "fektoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Ratkevich", "Alexey", "Igorevich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Dobrolinsky", "Ilya", "Vitalievich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Isachenko", "Anton", "Genadievich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Kovalevich", "Egor", "Mikhailovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Kalita", "Ekaterina", "Yurievna", "fektoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Klimashevich", "Mikhail", "Dmitrievich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Shestakov", "Mark", "Maksimovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Kozik", "Ilya", "Dmitrievich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Safrin", "Alexander", "Andreevich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Slyunin", "Ivan", "Aleksandrovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Kunitsky", "Alexander", "Vasilyevich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Makarevich", "Maxim", "Yurievich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Miskevich", "Alexander", "Alexandrovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Novik", "Vadim", "Genadievich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Stepanyuk", "Roman", "Viktorovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Stepanik", "Riman", "Viktorovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Rakhley", "Vitaly", "Sergeevich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Demidovich", "Anna", "Genadievna", "fektoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Safrin", "Alexander", "Alexandrovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Safrin", "Dmitry", "Alexandrovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Aniskin", "Maxim", "Viktorovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Breschuk", "Alina", "Alexandrovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Grigoruk", "Dmitry", "Aleksandrovna", "fektoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Ratkevich", "Ilya", "Igorevich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Dobrolinsky", "Alexey", "Vitalievich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Isachenko", "Egor", "Genadievich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	conteiner.push_back(dataBase("Kovalevich", "Anton", "Mikhailovich", "ktoto@mail.ru", rand() % 100 + 1, rand() % 10000 + 1));
	for_each(conteiner.begin(), conteiner.end(), output);
	{
		int n = conteiner.size();
		dataBase replacer("","","","",0,0);
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (conteiner[j].kolvo < conteiner[j + 1].kolvo)	//сортировка по количеству покупок
				{
					replacer = conteiner[j];
					conteiner[j] = conteiner[j + 1];
					conteiner[j + 1] = replacer;
				};
			}
		}
	};
	cout << "----------------------------------------------------------------" << endl;
	for_each(conteiner.begin(), conteiner.end(), output);
	cout << "----------------------------------------------------------------" << endl;
	int n = 10; //500
	cout << "Рассылку получат " << n << " покупателей, совершивших наибольшее количество покупок" << endl << "Рассылку получили:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << conteiner[i].name0 << " " << conteiner[i].name1 << " " << conteiner[i].name2 << endl;
	}
}