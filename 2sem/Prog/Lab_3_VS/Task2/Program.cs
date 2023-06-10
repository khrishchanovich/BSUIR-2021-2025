using System;
using Task2.Services;

namespace Task2
{
    class Program
    {
        static void Main(string[] args)
        {
            double z = Convert.ToDouble(Console.ReadLine());

            Function Result = new Function();

            Result.Calculator(z);
        }
    }
}
