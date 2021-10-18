using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace calculator
{
    public class CalculatorChecker
    {
        public static double ValidateCalculator(double a, double b, string operation)
        {
            if (operation == "+")
            {
                return (a + b);
            }

            if (operation == "-")
            {
                return (a - b);

            }
            if (operation == "*")
            {
                return (a * b);

            }
            if (operation == "/")
            {
                if (b == 0.0D)
                {
                    throw new DivideByZeroException();
                }
                return (a / b);
                try
                {
                    if (b == 0)
                    {
                        Console.WriteLine("Делить на 0 нельзя");

                        return 1;
                    }
                    else
                        Console.WriteLine("Результат :" + " " + a / b);

                }
                catch
                {
                    Console.WriteLine("Ошибка ввода");
                }
            }
            return 0;
        }

        static void Main()
        {
            
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine(@"Выберите арифметическое действие:
            - Умножение (введите 1)
            - Деление (введите 2)
            - Сложение (введите 3)
            - Вычитание (введите 4)");
            Console.ForegroundColor = ConsoleColor.Red;
            string q = Console.ReadLine();
            double a, b;
            Console.WriteLine(' ');
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Введите первое значение");
            Console.ForegroundColor = ConsoleColor.Red;
            a = double.Parse(Console.ReadLine());
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Введите второе значение");
            Console.ForegroundColor = ConsoleColor.Red;
            b = double.Parse(Console.ReadLine());
            Console.WriteLine(' ');
            if (q == "1")
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Результат умножения = {0}", a * b);
            }
            if (q == "2")
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Результат деления = {0}", a / b);
            }
            if (q == "3")
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Результат сложения = {0}", a + b);
            }
            if (q == "4")
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Результат вычитания = {0}", a - b);
            }
            Console.ReadKey();
        }
    }
}
