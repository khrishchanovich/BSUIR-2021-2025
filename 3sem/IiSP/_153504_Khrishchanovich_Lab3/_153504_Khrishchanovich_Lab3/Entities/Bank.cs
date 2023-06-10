using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khrishchanovich_Lab3.Entities
{
    public class Bank
    {
        public Dictionary<string, Deposit> Deposits { get; set; }
        public List<Client> Clients { get; set; }
        public List<Transaction> Transactions { get; set; }

        public delegate void Delegate(string message);
        public event Delegate? AddDepositNotify;

        public event Delegate? AddClientNotify;

        public event Delegate? MakeTransactionNotify;

        public Bank()
        {
            Deposits = new Dictionary<string, Deposit>();
            Clients = new List<Client>();
            Transactions = new List<Transaction>();
        }

        public double TotalPayment()
        {
            int numberOfTransactions = Transactions.Count;
            double totalPayment = 0;
            for (int i = 0; i < numberOfTransactions; i++)
            {
                totalPayment += Transactions[i].GetPayment();
            }
            return totalPayment;
        }
        public void AddDeposit(string IdDeposit, string name, double percent)
        {
            Deposit new_deposit = new Deposit(name, percent);
            Deposits.Add(IdDeposit, new_deposit);
            AddDepositNotify?.Invoke($"Deposit witn name {name} and percent rate {percent}% was added");
        }
        public void AddClient(string firstname, string lastname)
        {
            Client new_client = new Client(firstname, lastname);
            Clients.Add(new_client);
            AddClientNotify?.Invoke($"Сlient with the first name {firstname} and last name {lastname} was added");
        }
        public void AddTransaction(Client client, Deposit deposit, int sum = 0)
        {
            Transaction newTransaction = new Transaction(client, deposit, sum);
            Transactions.Add(newTransaction);
            MakeTransactionNotify?.Invoke($"{client.FirstName} {client.LastName} added deposit witn name {deposit.Name} and percent rate {deposit.Percent}% ");
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
            return (Deposits.ToList().Find(t => (t.Value.Name == name))).Value;
        }

        public Transaction? GetDeal(string name, string lastname, string firstname)
        {
            return Transactions.Find(transaction => transaction.Client.LastName == lastname && transaction.Client.FirstName == firstname && transaction.Deposit.Name == name);
        }

        public void AddSum(string firstname, string lastname, string name, int sum)
        {
            GetDeal(name, lastname, firstname).AddSum(sum);
        }

        public List<string> GetSortDepositNames()
        {
            List<string> names = Deposits.OrderBy(t => t.Value.Percent).Select(t => t.Value.Name).ToList();
            return names;
        }
        public double GetTotalPercent()
        {
            return Transactions.Sum(t => t.Deposit.Percent);
        }
        public double GetTotalSum()
        {
            return Transactions.Sum(t => t.Sum);
        }
        public string GetNameByMaxPercent()
        {
            return Transactions.OrderByDescending(t => t.GetPersonSum()).First().Client.FirstName;
        }
        public int CountOfClient(int s)
        {
            int count = Transactions.Aggregate(0, (c, t) => (t.Sum > s) ? c + 1 : c); // агрегация - объединение в одну систему 
            return count;
        }
        public List<(string, int)> GetListSum()
        {
            List<(string,int)> sums = Transactions.GroupBy(t => t.Client).Select(c =>(c.Key.FirstName, c.Sum(t => t.Sum))).ToList();
            return sums;
        }

    }
}

