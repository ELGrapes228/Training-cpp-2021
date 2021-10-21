#include <iostream>

struct students
{
	std::string surname;
	std::string name;
	int marks[3];
};

void studentsoutput(int n, struct students student2[])	// функция вывода структуры
{
	std::cout << "\n-----------------------------------";
	for (int i = 0; i < n; i++)
	{
		std::cout << "\nStudent No. " << i+1 << " " << student2[i].surname << " " << student2[i].name << "\nMarks: ";
		for (int j = 0; j < 3; j++)
		{
			std::cout << student2[i].marks[j] << " ";
		}
	}
	std::cout << "\n-----------------------------------";
};

void sortofsudents(int n, struct students student3[])	//сортировка структуры
{
	std::string copyofstring;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if ((student3[j].surname == student3[j + 1].surname) && (student3[j].name < student3[j + 1].name))	//по имени, если фамилии одинаковы
			{
				copyofstring = student3[j].surname;
				student3[j].surname = student3[j + 1].surname;
				student3[j + 1].surname = copyofstring;
				copyofstring = student3[j].name;
				student3[j].name = student3[j + 1].name;
				student3[j + 1].name = copyofstring;
			};
			if (student3[j].surname < student3[j + 1].surname)	//сортировка по фамилии
			{
				copyofstring = student3[j].surname;
				student3[j].surname = student3[j + 1].surname;
				student3[j + 1].surname = copyofstring;
			};
		}
	}
};

int main()
{
	int n;
	do	//ввод количества студентов
	{
		std::cout << "Type number of students (5 or more): ";
		std::cin >> n;
	}
	while (n < 5);

	students* student = new students[n];

	for (int i = 0; i < n; i++)		//ввод данных в структуру
	{
		std::cout << "\nStudent No. "<< i+1 <<"\nSurname: ";
		std::cin >> student[i].surname;	//фамилия
		std::cout << "Name: ";
		std::cin >> student[i].name;	//имя
		for (int j = 0; j < 3; j++)	//оценки
		{
			std::cout << "Mark No. " << j + 1 << ": ";
			std::cin >> student[i].marks[j];
		}
	}
	studentsoutput(n,student);	//вывод текущей структуры
	sortofsudents(n,student);	//сортировка
	studentsoutput(n,student);	//вывод текущей структуры
	std::cout << "\n";
	delete [] student;
	return 0;
}
