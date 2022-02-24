//1. Определить комбинированный (структурный) тип, содержащий информацию о студенте: фио, возраст, курс, группа. Разработать необходимые конструкторы, деструктор, оператор перегрузки.
//2. Инициализировать список, хранящий данные структурного типа.
//3. Разработать функтор сравнения, который позволит выбрать способ сравнения записей в массиве (по фио либо другому полю).
//4. Создать вектор элементов структурного типа, поместив в контейнер не объект, а указатель на него (для снижения вычислительных затрат на манипуляции с ним), заполнить элементы вектора.
//5. Выберите поле сортировки и отсортируйте вектор.
//6. Очистите вектор.

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

struct students
{
    std::string surname;
    std::string first_name;
    std::string second_name;
    int age;
    int cource;
    std::string group;
    students(std::string name0, std::string name1, std::string name2, int drevnost, int kurs, std::string gruppa) :
        surname(name0), first_name(name1), second_name(name2), age(drevnost), cource(kurs), group(gruppa)
    {}
};

int main()
{
    std::list <students> yniver;
    yniver.push_back(students("Safrin", "Alexander", "Andreevich", 21, 4, "AS-54"));
    std::for_each(yniver.begin(), yniver.end(), [](auto a)
        {
            std::cout << a.surname << " " << a.first_name << " " << a.second_name << ", " << a.age << " years old" << std::endl;
            std::cout << "\tGroup " << a.group << " of the " << a.cource << " cource." << std::endl;
        }
    );
/*    std::vector <students> yniver_2_0;
    int *b;
    std::for_each(yniver.begin(), yniver.end(), [b](auto a)
        {
            b = &a;
            std::cout << b << "\t" << *b << std::endl;
            //yniver_2_0.push_back(b);
        }
    );
    std::for_each(yniver_2_0.begin(), yniver_2_0.end(), [](auto a)
        {
            std::cout << a.surname << " " << a.first_name << " " << a.second_name << ", " << a.age << " years old" << std::endl;
            std::cout << "\tGroup " << a.group << " of the " << a.cource << " cource." << std::endl;
        }
    );*/
}