using System;
using _153504_Khrishchanovich_Lab1_Sem3.Entities;

namespace _153504_Khrishchanovich_Lab1_Sem3
{
    class Program
    {
        static void Main(string[] args)
        {
            Journal journal = new Journal();
            Bank bank = new Bank();

            bank.AddDeposit("deposit1", 10);
            bank.AddDeposit("deposit2", 15);
            bank.AddDeposit("deposit3", 20);

            Console.WriteLine("Deposits:");
            for (int i = 0; i < bank.Deposits.Count; i++)
            {
                Console.WriteLine(bank.Deposits[i]);
            }

            bank.AddClient("Ivan", "Ivanov");
            bank.AddClient("Ivan", "Sidorov");
            bank.AddClient("Ivan", "Petrov");

            Console.WriteLine("Clients:");
            for (int i = 0; i < bank.Clients.Count; i++)
            {
                Console.WriteLine(bank.Clients[i]);
            }

            bank.AddTransaction(bank.GetClient("Ivan", "Ivanov"), bank.GetDeposit("deposit1"), 100);
            bank.AddTransaction(bank.GetClient("Ivan", "Sidorov"), bank.GetDeposit("deposit2"), 200);
            bank.AddTransaction(bank.GetClient("Ivan", "Petrov"), bank.GetDeposit("deposit3"), 300);

            Console.WriteLine("Deals:");
            for (int i = 0; i < bank.Transactions.Count; i++)
            {
                Console.WriteLine(bank.Transactions[i]);
            }

            Console.WriteLine("Ivanov's bank deposit after adding 450 to the amount:");
            bank.AddMoney("Ivan", "Ivanov", "deposit1", 450);
            Console.WriteLine(bank.GetTransaction("Ivan", "Ivanov", "FirstDeposit"));

            Console.WriteLine("Total sum:");
            Console.WriteLine(bank.TotalPayment());

            foreach (var client in bank.Clients)
            {

            }

        }
    }
}
