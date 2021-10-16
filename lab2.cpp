#include <iostream>
#include <string>

class Strochka
{
 public:
     Strochka()
     {
         chislo = 0;
     };
     void replace_letter(char replace_what)
     {
         int n;
         n = mnoga_bukaf.length();
         for (int i = 0; i < n; i++)
         {
             if (mnoga_bukaf[i] == replace_what)
             {
                 mnoga_bukaf[i] = mnoga_bukaf[0];
                 chislo += 1;
             }
         }
     };
     void set_string(std::string text)
     {
         mnoga_bukaf = text;
     };
     void set_0()
     {
         chislo = 0;
     };
     std::string get_string()
     {
         return mnoga_bukaf;
     };
     int get_number()
     {
         return chislo;
     };
 private:
     std::string mnoga_bukaf;
     int chislo;
};


int main()
{
    Strochka stroka;
    stroka.set_string("Give papa a cup of proper coffe in a copper coffe cup.");
    std::cout << "Original string:\n" << stroka.get_string() << "\n";
    stroka.replace_letter('c');
    std::cout << "\nString with replaced letters:\n" << stroka.get_string() << "\n";
    std::cout << "Number of replaces: " << stroka.get_number() << "\n\n\n";
}