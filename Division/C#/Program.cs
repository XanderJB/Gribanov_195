using System;

namespace delenie1
{
    class Program
    {
        static void Main()
        {
            // для целых чисел
            int a = 40;
            int b = 8;
            Console.WriteLine((double) a / b);

            //плав. запятая
            float c = 3.6F;
            float d = 1.2F;
            Console.WriteLine(c / d);

            // размер оператора
            Console.WriteLine(sizeof(float));
            Console.WriteLine(sizeof(double));

            //исключение
            try
            {
                int x = 9;
                int y = x / 0;
                Console.WriteLine($"Результат: {y}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Иключение: {ex.Message}");
            }
        }
    }
}
