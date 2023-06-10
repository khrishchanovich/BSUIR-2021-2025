using System;

// 6

namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a two-digit number: ");

            string n = Console.ReadLine();

            if (n[0] > n[1])
            {
                Console.WriteLine("The first digit is bigger than second digit .");
            }
            else
            {
                if (n[0] < n[1])
                {
                    Console.WriteLine("The second digit is bigger than first digit.");

                }
                else
                {
                    Console.WriteLine("The first digit and the second digit are equal.");
                }
            }
        }
    }
}
