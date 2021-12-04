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
	students replacer;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if ((student3[j].surname == student3[j + 1].surname))	//по имени, если фамилии одинаковы
			{
				if (student3[j].name > student3[j + 1].name)
				{
					replacer = student3[j];
					student3[j] = student3[j + 1];
					student3[j + 1] = replacer;
				}
			}
			else
			{
				if (student3[j].surname > student3[j + 1].surname)	//сортировка по фамилии
				{
					replacer = student3[j];
					student3[j] = student3[j+1];
					student3[j + 1] = replacer;
				};
			}
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

	//n = 5;

	students* student = new students[n];

	/*student[0].surname = "aaa";
	student[0].name = "petr";
	student[0].marks[0] = 1;
	student[0].marks[1] = 2;
	student[0].marks[2] = 3;

	student[1].surname = "aaa";
	student[1].name = "ivan";
	student[1].marks[0] = 2;
	student[1].marks[1] = 3;
	student[1].marks[2] = 4;

	student[2].surname = "a";
	student[2].name = "ccd";
	student[2].marks[0] = 3;
	student[2].marks[1] = 4;
	student[2].marks[2] = 5;

	student[3].surname = "abc";
	student[3].name = "gfd";
	student[3].marks[0] = 8;
	student[3].marks[1] = 4;
	student[3].marks[2] = 3;

	student[4].surname = "rhjkl";
	student[4].name = "tgysad";
	student[4].marks[0] = 1;
	student[4].marks[1] = 9;
	student[4].marks[2] = 2;*/


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
