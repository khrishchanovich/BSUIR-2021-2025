using System;

namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            Function Number = new Function();

            Number.Swap(n);
        }
    }
}
