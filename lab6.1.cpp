//1.  Определите класс template & lt; class T& gt; struct S { T val; }; .
//2.  Добавьте конструктор, чтобы можно было инициализировать его типом T.
//3.  Определите переменные типов S<int>, S<char>, S<double>, S<string> и S<vector<int>>; инициализируйте их значениями по своему выбору.
//4.  Прочитайте эти значения и выведите их на экран.
//5.  Добавьте шаблонную функцию get(), возвращающую ссылку на значение val.
//6.  Разместите функцию get() за пределами класса.
//7.  Разместите значение val в закрытом разделе.
//8.  Выполните п. 4, используя функцию get().
//9.  Добавьте шаблонную функцию set(), чтобы можно было изменить значение val.
//10. Замените функции get() и set() оператором operator[ ] ().
//11. Напишите константную и неконстантную версии оператора operator[] ().
//12. Определите функцию template<class T> read_val(T& v), выполняющую ввод данных из потока cin в переменную v.
//13. Используйте функцию read_val(), чтобы считать данные в каждую из переменных, перечисленных в п. 3, за исключением переменной S< vector<int> >.


#include <iostream>
#include <vector>
#include <string.h>
#include <string>

template<class T>
struct S
{
public:
    S(T data) : val(data)
    {
        std::cout << "Hello. It's me, constuctor"/*" with parameters"*/ << std::endl;
    }
    void get();
private:
    T val;
};

template <typename T>
void S<T>::get()
{
    return val;
};

int main()
{
    /*
    S<int> first_try(149);
    std::cout << first_try.val << std::endl << std::endl;     //before 5.
    S<char> second_try(149);
    std::cout << second_try.val << std::endl << std::endl;    //before 5.
    S<double> third_try(149.2);
    std::cout << third_try.val << std::endl << std::endl;     //before 5.
    S<std::string> fourth_try("text");
    std::cout << fourth_try.val << std::endl << std::endl;    //before 5.
    S<std::vector<int>> fifth_try({ 10, 15, 20 });
    std::cout << fifth_try.val[0] << ", " << fifth_try.val[1] << ", " << fifth_try.val[2] << std::endl << std::endl;  //before 5.
    */

    S<int> first_try(149);
    std::cout << std::endl << first_try.get();     //что-то пошло не так
    S<char> second_try(149);
    std::cout << second_try.get() << std::endl << std::endl;    
    S<double> third_try(149.2);
    std::cout << third_try.get() << std::endl << std::endl;     
    S<std::string> fourth_try("text");
    std::cout << fourth_try.get() << std::endl << std::endl;
    S<std::vector<int>> fifth_try({ 10, 15, 20 });
    std::cout << fifth_try[0].get() << ", " << fifth_try[1].get() << ", " << fifth_try[2].get() << std::endl << std::endl;  
}