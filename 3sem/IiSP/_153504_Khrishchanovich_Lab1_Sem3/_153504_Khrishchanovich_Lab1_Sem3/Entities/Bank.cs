using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153504_Khrishchanovich_Lab1_Sem3.Collections;

namespace _153504_Khrishchanovich_Lab1_Sem3.Entities
{
    internal class Bank
    {
        public MyCustomCollection<Deposit> Deposits { get; set; }
        public MyCustomCollection<Client> Clients { get; set; }
        public MyCustomCollection<Transaction> Transactions { get; set; }

        public Bank()
        {
            Deposits = new MyCustomCollection<Deposit>();
            Clients = new MyCustomCollection<Client>();
        }

        public void AddDeposit(string name, double percent)
        {
            Deposit deposit = new Deposit(name, percent);
            Deposits.Add(deposit);
        }

        public void AddClient(string firstName, string surname)
        {
            Client client = new Client(firstName, surname);
            Clients.Add(client);
        }

        public void AddTransaction(Client client, Deposit deposit, int money)
        {
            Transaction transaction = new Transaction(client, deposit, money);
            Transactions.Add(transaction);
        }

        public void AddMoney(string firstName, string surname, string name, int money)
        {
            GetTransaction(firstName, surname, name).AddMoney(money);
        }

        public void AddNewMoney(Client client, Deposit deposit, int money)
        {
            for (int i = 0; i < Transactions.Count; ++i)
            {
                if (Transactions[i].Client == client && Transactions[i].Deposit == deposit)
                {
                    Transactions[i].AddMoney(money);
                }
            }
        }

        public Client GetClient(string fisrtName, string surname)
        {
            return Clients.Find(client => client.FirstName == fisrtName && client.Surname == surname);
        }

        public Deposit GetDeposit(string name)
        {
            return Deposits.Find(deposit => deposit.Name == name);
        }

        public Transaction GetTransaction(string firstName, string surname, string name)
        {
            return Transactions.Find(transaction => transaction.Client.FirstName == firstName && transaction.Client.Surname == surname && transaction.Deposit.Name == name);
        }

        public double TotalPayment()
        {
            int numberOfTransaction = Transactions.Count;
            double totalPayment = 0;
            for (int i = 0; i < numberOfTransaction; ++i)
            {
                totalPayment += Transactions[i].GetPayment();
            }
            return totalPayment;
        }
    }
}
