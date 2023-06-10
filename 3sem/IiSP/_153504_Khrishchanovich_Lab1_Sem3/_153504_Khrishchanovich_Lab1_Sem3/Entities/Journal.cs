using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153504_Khrishchanovich_Lab1_Sem3.Collections;

namespace _153504_Khrishchanovich_Lab1_Sem3.Entities
{
    internal class Journal
    {
        private MyCustomCollection<string> AddDeposit = new MyCustomCollection<string>();
        private MyCustomCollection<string> AddClient = new MyCustomCollection<string>();
        private MyCustomCollection<string> AddTransactrion = new MyCustomCollection<string>();

        public void OnDepositAdd(string deposit)
        {
            AddDeposit.Add(deposit);
        }

        public void OnClientAdd(string client)
        {
            AddDeposit.Add(client);
        }

        public void OnTransactionAdd(string transaction)
        {
            AddDeposit.Add(transaction);
        }

        public void ViewDeposit()
        {
            Console.WriteLine("Существующие вклады: ");

            foreach (var name in AddDeposit)
            {
                Console.WriteLine(name);
            }
        }

        public void ViewClient()
        {
            Console.WriteLine("Существующие клиенты: ");

            foreach (var name in AddClient)
            {
                Console.WriteLine(name);
            }
        }

        public void ViewTransaction()
        {
            Console.WriteLine("Прошедшие транзакции: ");
                
            foreach (var name in AddTransactrion)
            {
                Console.WriteLine(name);
            }
        }

    }
}
