using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khrishchanovich_Lab3.Entities
{
    public class Transaction
    {
        public Client Client { get; set; }
        public Deposit Deposit { get; set; }
        public int Sum { get; set; }
        public Transaction(Client client, Deposit deposit, int sum)
        {
            Client = client;
            Deposit = deposit;
            Sum = sum;
        }
        public void AddSum(int sum)
        {
            Sum += sum;
        }
        public double GetPayment()
        {
            return Sum + Sum * (Deposit.Percent / 100);
        }
        public double GetPersonSum()
        {
            return Sum * (Deposit.Percent / 100);
        }
        public override string ToString()
        {
            return Client.ToString() + ": " + Deposit.ToString() + $" Sum: {Sum}";
        }
    }
}
