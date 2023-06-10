using System;
using _153504_Khrishchanovich_Lab2.Entities;

namespace _153504_Khrishchanovich_Lab2
{
    class Program
    {
        static void Main(string[] args)
        {

            Journal journal = new Journal();
            journal.AddDepositNotify += journal.DisplayMessage;
            journal.AddClientNotify += journal.DisplayMessage;
            journal.MakeTransactionNotify += (string message) => Console.WriteLine(message);



            Bank bank = new Bank();
            bank.ClientAdded += journal.LogEvent;
                
            journal.AddDepositToBank(bank, "deposit1", 10);
            journal.AddDepositToBank(bank, "deposit2", 20);
            journal.AddDepositToBank(bank, "deposit3", 15);

            Console.WriteLine("\nDeposits:");
            foreach (Deposit deposit in bank.Deposits)
            {
                Console.WriteLine(deposit);
            }

            journal.AddClientToBank(bank, "Ivan", "Ivanov");
            journal.AddClientToBank(bank, "Alexandr", "Petrov");
            journal.AddClientToBank(bank, "Ivan", "Sidorov");

            Console.WriteLine("\nClients:");
            foreach (Client client in bank.Clients)
            {
                Console.WriteLine(client);
            }

            journal.MakeBankTransaction(bank, bank.GetClientByName("Ivan", "Ivanov"), bank.GetDepositByName("deposit1"), 100);
            journal.MakeBankTransaction(bank, bank.GetClientByName("Alexandr", "Petrov"), bank.GetDepositByName("deposit2"), 100);

            Console.WriteLine("\nDeals:");
            for (int i = 0; i < bank.Transactions.Count; i++)
            {
                Console.WriteLine(bank.Transactions[i]);
            }
        }
    }
}
