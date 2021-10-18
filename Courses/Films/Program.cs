using System;

namespace Films
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Здравствуйте, мой дорогой друг. Давайте выберем кино для вашего досуга"); //вывод сообщения на экран
            Console.WriteLine("Как вас зовут?");
            String name = Console.ReadLine(); //ввод переменной name, с помощью нее мы вводим свое имя, а компьютер "здоровается" с нами
            String point = "Здравствуйте, " + name;
            Console.WriteLine(point);

            Console.WriteLine("Что бы вы хотели посмотреть: аниме, сериалы, мультфильмы или приколы?");
            String genre = Console.ReadLine(); // readline отвечает за данные, которые вводит пользователь
            Console.WriteLine(genre);
            Console.WriteLine("В таком случае рекомендую посмотреть: ");
            if (genre == "аниме") //если пользователь выбирает Аниме, то выводится список из аниме сериалов
            {
                Console.WriteLine("Наруто");
                Console.WriteLine("Ван пис");
                Console.WriteLine("Тетрадь смерти");
            }
            else if (genre == "мультфильмы") // срабатывает блок else если пользовател выбирает Сериалы
            {
                Console.WriteLine("Южный парк");
                Console.WriteLine("Гриффины");
                Console.WriteLine("Симпсоны");
            }
            else if (genre == "приколы") // срабатывает блок else если пользовател выбирает Сериалы
            {
                Console.WriteLine("Иди в попу, я фея))))))");
            }
            else // срабатывает блок else если пользовател выбирает Сериалы
            {
                Console.WriteLine("Во все тяжкие");
                Console.WriteLine("Мандалорец");
                Console.WriteLine("Очень странные дела");
            }
            Console.ReadLine(); //выход из программы с помощью клавиши Enter
        }
    }
}
