using System;

// 5

namespace Task2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter the x-coordinate of the point: ");
            double x = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter the y-coordinate of the point: ");
            double y = Convert.ToDouble(Console.ReadLine());

            if ((x > 0 && y > 0) || (x > 0 && y < 0))
            {
                Console.WriteLine("No.");
            }
            else
            {
                if (x * x + y * y > 64 || x * x + y * y < 9)
                {
                    Console.WriteLine("No.");
                }
                else
                {
                    if (x * x + y * y < 64 && x * x + y * y > 9)
                    {
                        Console.WriteLine("Yes.");
                    }
                    else
                    {
                        if (x * x + y * y == 64 || x * x + y * y == 9)
                        {
                            Console.WriteLine("On the board.");
                        }
                    }
                }
            }
        }
    }
}
