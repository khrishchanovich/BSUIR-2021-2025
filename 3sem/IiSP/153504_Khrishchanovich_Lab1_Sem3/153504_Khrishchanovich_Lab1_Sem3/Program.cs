using System;
using _153504_Khrishchanovich_Lab1_Sem3.Entities;

namespace _153504_Khrishchanovich_Lab1_Sem3
{
    class Program
    {
        static void Main(string[] args)
        {
            Bank bank = new Bank();
            bank.AddDeposit("Первый вклад", 10);
            bank.AddDeposit("Второй вклад", 20);
            bank.AddDeposit("Третий вклад", 30);

            Console.WriteLine("Все вклады: ");
            for (int i = 0; i < bank.Deposits.Count; ++i)
            {
                Console.WriteLine(bank.Deposits[i]);
            }

            bank.AddClient("Андрей Попов");
            bank.AddClient("Олег Смирнов");
            bank.AddClient("Артем Козлов");

            Console.WriteLine("Клиенты: ");
            for (int i = 0; i < bank.Clients.Count; ++i)
            {
                Console.WriteLine(bank.Clients[i]);
            }

            bank.AddTransaction(bank.GetClient("Андрей Попов"), bank.GetDeposit("Первый вклад"), 100);
            bank.AddTransaction(bank.GetClient("Олег Смирнов"), bank.GetDeposit("Второй вклад"), 200);
            bank.AddTransaction(bank.GetClient("Артем Козлов"), bank.GetDeposit("Третий вклад"), 300);

            Console.WriteLine("Транзакции: ");
            for (int i = 0; i < bank.Transactions.Count; ++i)
            {
                Console.WriteLine(bank.Transactions[i]);
            }

            Console.WriteLine("Вклад Андрей Попова после внесения 500 рублей: ");
            bank.AddMoney("Андрей Попов", "Первый вклад", 500);
            Console.WriteLine(bank.GetTransaction("Андрей Попов", "Первый вклад"));

            Console.WriteLine("Общая сумма платежа: ");
            Console.WriteLine(bank.TotalPayment());
        }
    }
}
