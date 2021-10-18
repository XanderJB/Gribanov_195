/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
  
#include <iostream>
#include <exception>
 
double divide(int, int);
 
int main()
{
    int x = 20;
    int y = 0;
    try
    {
        double z = divide(x, y);
        std::cout << z << std::endl;
    }
    catch (const std::exception& err)
    {
        std::cout << "Ошибка! Обнаружено деление на 0" << std::endl;
    }
    std::cout << "Завершение прогрaммы" << std::endl;
    return 0;
}
 
double divide(int a, int b)
{
    if (b == 0)
        throw std::exception();
    return a / b;
}