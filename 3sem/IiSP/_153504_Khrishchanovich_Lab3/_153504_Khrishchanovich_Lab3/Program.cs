using System;
using System.Collections.Generic;
using _153504_Khrishchanovich_Lab3.Entities;

namespace _153504_Khrishchanovich_Lab3
{
    class Program
    {
        static void Main(string[] args)
        {

            Bank bank = new Bank();

            bank.AddClientNotify += (string message) => Console.WriteLine(message);
            bank.MakeTransactionNotify += (string message) => Console.WriteLine(message);
            bank.AddDepositNotify += (string message) => Console.WriteLine(message);

            bank.AddDeposit("d2", "deposit2", 15);
            bank.AddDeposit("d1", "deposit1", 10);
            bank.AddDeposit("d3", "deposit3", 20);
            bank.AddDeposit("d4", "deposit4", 25);

            Console.WriteLine("\nDeposits:");
            foreach (var deposit in bank.Deposits)
            {
                Console.WriteLine(deposit.Value);
            }

            bank.AddClient("Ivan", "Ivanov");
            bank.AddClient("Alexandr", "Petrov");
            bank.AddClient("Ivan", "Sidorov");
            bank.AddClient("Petr", "Sidorov");

            Console.WriteLine("\nClients:");
            foreach (Client client in bank.Clients)
            {
                Console.WriteLine(client);
            }

            bank.AddTransaction(bank.GetClientByName("Ivan", "Ivanov"), bank.GetDepositByName("deposit1"), 100);
            bank.AddTransaction(bank.GetClientByName("Alexandr", "Petrov"), bank.GetDepositByName("deposit2"), 70);
            bank.AddTransaction(bank.GetClientByName("Ivan", "Sidorov"), bank.GetDepositByName("deposit3"), 200);
            bank.AddTransaction(bank.GetClientByName("Petr", "Sidorov"), bank.GetDepositByName("deposit4"), 50);

            Console.WriteLine("\nDeals:");
            foreach (Transaction transaction in bank.Transactions)
            {
                Console.WriteLine(transaction);
            }

            Console.WriteLine("\nList of deposits sortered by percent:");
            List<string> sortDepositNames = bank.GetSortDepositNames();
            foreach (string transactionName in sortDepositNames)
            {
                Console.WriteLine(transactionName);
            }

            double totalPercent = bank.GetTotalPercent();
            Console.WriteLine($"\nTotal percent:{totalPercent}");

            double totalSum = bank.GetTotalSum();
            Console.WriteLine($"\nTotal sum:{totalSum}");


            List<Transaction> transactions = new List<Transaction>();
            transactions.Add(bank.Transactions[0]);
            transactions.Add(bank.Transactions[1]);
            transactions.Add(bank.Transactions[2]);
            transactions.Add(bank.Transactions[3]);

            int s = 80;
            int count = bank.CountOfClient(s);
            Console.WriteLine($"Count of clients: {count}");

            List<int> sums = bank.GetListSum();
            Console.WriteLine("List of sums:");
            foreach (int sum in sums)
            {
                Console.WriteLine(sum);
            }





        }
    }
}
