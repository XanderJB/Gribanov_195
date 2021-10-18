using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.SmallBasic.Library;
namespace TurtleGame
{using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.SmallBasic.Library;

namespace TurtleTraining
{
	class Program
	{
        private static void WriteT(int size)
        {
            Turtle.Angle = 0;
            Turtle.Move(size);
            Turtle.TurnLeft();
            Turtle.Move(size / 2);
            Turtle.Turn(180);
            Turtle.Move(size);
        }
        private static void WriteO(int size)
        {
            Turtle.Angle = 0;
            for (int i = 0; i < 24; i++)
            {
                Turtle.Move(size);
                Turtle.Turn(15);
            }
        }
        private static void WriteR(int size)
        {
            Turtle.Angle = 0;
            Turtle.Move(size);
            Turtle.Y = Turtle.Y + size / 3;
            for (int i = 0; i < 12; i++)
            {
                Turtle.Move(size / 6);
                Turtle.Turn(30);
            }
        }
        static void Main(string[] args)
        {
            Turtle.Speed = 10;
            //ТОРТ
            Turtle.X = 200;
            Turtle.Y = 200;
            WriteT(100);
            Turtle.X = 260;
            Turtle.Y = 170;
            WriteO(8);
            Turtle.X = 350;
            Turtle.Y = 200;
            WriteR(60);
            Turtle.X = 430;
            Turtle.Y = 200;
            WriteT(60);
        }
    }
}
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Turtle.Move(10);
            }
        }
    }
}
