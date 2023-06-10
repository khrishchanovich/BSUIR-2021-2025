using System;
using System.Collections.Generic;

// 5

namespace Lab5
{
    enum ClientType : int
    {
        usual,
        VIP
    };

    class Program
    {
        static void Main(string[] args)
        {
            Bank bank = new Bank("MyBank");

            char answer = '1';
            do
            {
                Console.WriteLine("Введите имя клиента:");
                string name = Console.ReadLine();

                string sum_str;

                int sum;

                Console.WriteLine("Введите сумму на его счету:");

                sum = Convert.ToInt32(Console.ReadLine());

                bank.AddClient(name, sum);

                Console.WriteLine("Продолжить ввод? (1/0)");

                answer = char.Parse(Console.ReadLine());

            } while (answer != '0');

            bank.PrintInfo();

        }
    }
}