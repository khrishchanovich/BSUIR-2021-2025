using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khrishchanovich_Lab1_Sem3.Entities
{
    internal class Transaction
    {
        public Client Client { get; set; }
        public Deposit Deposit { get; set; }
        public int Money { get; set; }

        public Transaction(Client client, Deposit deposit, int money)
        {
            Client = client;
            Deposit = deposit;
            Money = money;
        }

        public void AddMoney(int money)
        {
            Money += money;
        }

        public double GetPayment()
        {
            return Money + Money * (Deposit.Percent / 100);
        }
    }
}
