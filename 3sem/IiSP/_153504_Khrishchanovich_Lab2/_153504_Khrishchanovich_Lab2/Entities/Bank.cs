using _153504_Khrishchanovich_Lab2.Collections;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khrishchanovich_Lab2.Entities
{
    public class Bank
    {
        public MyCustomCollection<Deposit> Deposits { get; set; }
        public MyCustomCollection<Client> Clients { get; set; }
        public MyCustomCollection<Transaction> Transactions { get; set; }

        public event EventHandler<string> ClientAdded;

        public Bank()
        {
            Deposits = new MyCustomCollection<Deposit>();
            Clients = new MyCustomCollection<Client>();
            Transactions = new MyCustomCollection<Transaction>();
        }

        public double TotalPayment()
        {
            int numberOfTransaction = Transactions.Count;
            double totalPayment = 0;
            for (int i = 0; i < numberOfTransaction; i++)
            {
                totalPayment += Transactions[i].GetPayment();
            }
            return totalPayment;
        }
        public void AddDeposit(string name, double percent)
        {
            Deposit new_deposit = new Deposit(name, percent);
            Deposits.Add(new_deposit);
        }
        public void AddClient(string firstname, string lastname)
        {
            Client new_client = new Client(firstname, lastname);
            Clients.Add(new_client);
            ClientAdded?.Invoke(this, $"Client {firstname} added ...");
        }
        public void AddTransaction(Client client, Deposit deposit, int sum = 0)
        {
            Transaction new_deal = new Transaction(client, deposit, sum);
            Transactions.Add(new_deal);
        }
        public void AddNewSum(Client client, Deposit deposit, int sum)
        {
            for (int i = 0; i < Transactions.Count; i++)
            {
                if (Transactions[i].Client == client && Transactions[i].Deposit == deposit)
                {
                    Transactions[i].AddSum(sum);
                }
            }
        }
        public Client? GetClientByName(string firstname, string lastname)
        {
            return Clients.Find(client => client.FirstName == firstname && client.LastName == lastname);
        }

        public Deposit? GetDepositByName(string name)
        {
            return Deposits.Find(deposit => deposit.Name == name);
        }

        public Transaction? GetTransaction(string name, string lastname, string firstname)
        {
            return Transactions.Find(deal => deal.Client.LastName == lastname && deal.Client.FirstName == firstname && deal.Deposit.Name == name);
        }

        public void AddSum(string firstname, string lastname, string name, int sum)
        {
            GetTransaction(name, lastname, firstname).AddSum(sum);
        }
    }
}
