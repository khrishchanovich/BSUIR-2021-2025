using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace _153504_Khrishchanovich_Lab2.Entities
{
    public class Journal
    {
        public delegate void Delegate(string message); // делегат как указатель на метод, с помощью чего мы можем этот метод вызвать
        public event Delegate? AddDepositNotify;  // ? - проверка на null

        public event Delegate? AddClientNotify;

        public event Delegate? MakeTransactionNotify;
        public void AddDepositToBank(Bank bank, string name, double percent)
        {
            bank.AddDeposit(name, percent);
            AddDepositNotify?.Invoke($"Deposit witn name {name} and percent rate {percent}% was added"); // Invoke способ вызвать делегат, ? - чтобы не получить исключения, то есть делаем проверку,
            // чтобы убедиться, что делегат не пуст(нет ссылок на метод(ы))
        }

        public void LogEvent(object sender, string messge)
        {
            Console.WriteLine(messge);
        }
        public void AddClientToBank(Bank bank, string firstname, string lastname)
        {
            bank.AddClient(firstname, lastname);
            AddClientNotify?.Invoke($"Сlient with the first name {firstname} and last name {lastname} was added");
        }
        public void MakeBankTransaction(Bank bank, Client client, Deposit deposit, int sum = 0)
        {
            bank.AddTransaction(client, deposit, sum);
            MakeTransactionNotify?.Invoke($"{client.FirstName} {client.LastName} added deposit witn name {deposit.Name} and percent rate {deposit.Percent}% ");
        }
        public void DisplayMessage(string message)
        {
            Console.WriteLine(message);
        }

    }
}
