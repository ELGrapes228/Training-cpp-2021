//Работа с текстовыми файлами
//Сформировать массив, каждый элемент которого имеет следующую структуру служащий : ФИО, число рождения, месяц рождения, год рождения, пол.
//Вывести на экран сообщение пользователю вида :
//Выберите действие :
//1 загрузить данные из файла
//2 вывод данных на экран
//3 сортировка базы данных по алфавиту(по фамилии)
//4 вывод : список людей, родившихся в заданном месяце
//5  вывод : фамилию самого старшего мужчины
//6 вывод : все фамилии, начинающиеся с заданной буквы
//0 выход из программы

#include <iostream>
#include <fstream>

using namespace std;

struct dataBase
{
    std::string name0, name1, name2, pol;
    int day, month, year;
};

int main()
{
    int k = 0;
    int n = 0;
    dataBase* massive = new dataBase[10000]; 
    setlocale(LC_ALL, "ru");
    char b = 0x0D;
    std::cout << b;
    do {    //цикл do while, в него заключена большая часть программы,
            //т. к. условие логически предполагает многократное использование программы при одном запуске.
            //При k = 0 программа выйдет из цикла
        cout    << "1 - загрузить данные из файла" << std::endl
                << "2 - вывод данных на экран" << std::endl
                << "3 - сортировка базы данных по алфавиту(по фамилии)" << std::endl
                << "4 - вывод: список людей, родившихся в заданном месяце" << std::endl
                << "5 - вывод: фамилию самого старшего мужчины" << std::endl
                << "6 - вывод: все фамилии, начинающиеся с заданной буквы" << std::endl
                << "0 - выход из программы" << std::endl
                << "Ваш выбор: ";
        cin >> k;
        if (k == 1) //1
        {
            std::ifstream file;
            file.open("3.3.txt");
            if (!file.is_open())
            {
                cout << "Файл не найден" << endl;
            }
            else
            {
                std::cout << "Файл открыт" << endl; 
                int i = 0;    //считает количество данных  
                while (!file.eof()) //все данные разделены пробелами, а каждая новая строка в файле - новый элемент массива
                {
                    file >> massive[i].name0;
                    file >> massive[i].name1;
                    file >> massive[i].name2;
                    file >> massive[i].pol;
                    file >> massive[i].day;
                    file >> massive[i].month;
                    file >> massive[i].year;
                    i++;
                }
                n = i;
            }
            file.close();
            
        }
        if (k == 2) //2
        {
            for (int j = 0; j < n; j++)
            {
                cout << massive[j].name0 << " "
                    << massive[j].name1 << " "
                    << massive[j].name2 << ", "
                    << massive[j].pol << " "
                    << massive[j].day << "."
                    << massive[j].month << "."
                    << massive[j].year << endl;
            }

        }
        if (k == 3) //3
        {
            dataBase replacer;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if ((massive[j].name0 == massive[j + 1].name0))	
                    {
                        if (massive[j].name1 == massive[j + 1].name1)
                        {
                            if (massive[j].name2 > massive[j + 1].name2)    //меняет местами, если фамилии и имена одинаковы, а первое отчество по алфавиту находится после второго
                            {
                                replacer = massive[j];
                                massive[j] = massive[j + 1];
                                massive[j + 1] = replacer;
                            }

                        }
                        else
                        {
                            if (massive[j].name1 > massive[j + 1].name1)    //меняет местами, если фамилии одинаковы, а имена - нет, причём первое по алфавиту находится после второго
                            {
                                replacer = massive[j];
                                massive[j] = massive[j + 1];
                                massive[j + 1] = replacer;
                            }
                        }
                    }
                    else    //меняет местами, если фамилии не одинаковы, а первая по алфавиту находится после второй
                    {
                        if (massive[j].name0 > massive[j + 1].name0)
                        {
                            replacer = massive[j];
                            massive[j] = massive[j + 1];
                            massive[j + 1] = replacer;
                        };
                    }
                }
            }
        }
        if (k == 4) //4
        {
            int month;
            cout << "Введите номер месяца: ";
            cin >> month;
            while (month < 1 || month > 12)
            {
                cout << "Вы ввели несуществующее значение. Попробуйте снова: ";
                cin >> month;
            }
            int wtf = 0;
            for (int i = 0; i < n; i++)
            {
                if (month == massive[i].month)
                {
                    wtf = wtf + 1;
                    cout << massive[i].name0 << " "
                        << massive[i].name1 << " "
                        << massive[i].name2 << ", "
                        << massive[i].pol << " "
                        << massive[i].day << "."
                        << massive[i].month << "."
                        << massive[i].year << endl;
                }
            }
            if (wtf == 0)
            {
                cout << "В этом месяце никто не родился." << endl;
            }
        }
        if (k == 5) //5
        {
            dataBase ded;
            ded.day = 33;
            ded.month = 12;
            ded.year = 999999999;
            ded.pol = "male";
            int x = 0;
            for (int i = 0; i < n; i++)
            {
                if (ded.pol == massive[i].pol)
                {
                    //идея такая:
                    //преобразовать дату в числовой эквивалент, который будет уникален для каждой даты. В этом случае, их будет легко сравнивать:
                    //день - наименее значимый отрезок времени, поэтому без коэффициентов
                    //месяц - уже значительнее, а чтобы он не накладывался случайно на день, домножаю его на 100
                    //год - самое значимое число, поэтому чтобы избежать наложения на месяц и день, домножается на 10 000
                    //Можно было бы брать меньшие коэффициенты, но так понятнее. На мой взгляд, это самый простой вариант.
                    //А если нужно будет заморочиться, то можно этим заняться и в другой раз
                    if (ded.year*10000 + ded.month*100 + ded.day >= massive[i].year*10000 + massive[i].month*100 + massive[i].day)
                    {
                        x = x + 1;
                        ded = massive[i];
                    }
                }
            }
            if (x != 1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (ded.pol == massive[i].pol && ded.year == massive[i].year && ded.month == massive[i].month && ded.day == massive[i].day)
                    {
                        cout << massive[i].name0 << endl;
                    }
                }
            }
            else
            {
                cout << ded.name0 << endl;
            }
        }
        if (k == 6) //6
        {
            char name0;
            cout << "Введите букву: ";
            cin >> name0;
            int wtf = 0;
            for (int i = 0; i < n; i++)
            {
                if (name0 == massive[i].name0[0])
                {
                    wtf = wtf + 1;
                    cout << massive[i].name0 << endl;
                }
            }
            if (wtf == 0)
            {
                cout << "Нет ни одной фамилии, начинающейся с буквы " << name0 << endl;
            }
        }
    } while (k != 0);   //0
}
