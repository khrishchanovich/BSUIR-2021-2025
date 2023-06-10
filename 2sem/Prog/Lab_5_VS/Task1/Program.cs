using System;
using System.Collections.Generic;

namespace c_sharp_lab5
{
    enum ClientType : int
    {
        usual,
        VIP
    };

    class Bank
    {
        public class Client
        {

            private class Deposit
            {
                private int sum;
                private int percent;

                public Deposit()
                {
                    sum = 0;
                    percent = 0;
                }
                public Deposit(int value, int percent)
                {
                    sum = value;
                    this.percent = percent;
                }
                public int Sum()
                {
                    return sum;
                }

                public int setPercent(int sum_)
                {
                    this.sum = sum_ * percent / 100;
                    return sum;
                }
                public void IncDeposit(int value)
                {
                    setPercent(sum += value);
                }
            };

            private int VIP;
            private string name = "";
            private Deposit deposit;

            public Client()
            {
                deposit = new Deposit();
                name = "";
                VIP = 0;
            }
            public Client(string nm, int dep, int percent, int VIP_status = 0)
            {
                name = nm;
                deposit = new Deposit(dep, percent);
                VIP = VIP_status;
            }

            public string Name()
            {
                return name;
            }

            public int ClientDeposit()
            {
                return deposit.setPercent(deposit.Sum());
            }
            public string Info()
            {
                return "\nимя: " + name + " вклад: " + ClientDeposit().ToString();
            }
        };

        private List<Client> clients;

        private string name;

        public Bank()
        {
            name = "";
            clients = new List<Client>();
        }
        public Bank(string nm)
        {
            name = nm;
            clients = new List<Client>();
        }

        public void AddClient(string name, int sum, int percent = 3, int status = 0)
        {
            clients.Add(new Client(name, sum, percent, status));
        }

        public void AddClient(Client person)
        {
            clients.Add(person);
        }

        public void PrintInfo()
        {
            foreach (var person in clients)
            {
                Console.WriteLine(person.Info());
            }
        }

        public int Benefit()
        {
            int sum = 0;

            foreach (var person in clients)
            {
                sum += person.ClientDeposit();
            }

            return sum;
        }
    };

    class Program
    {
        static void Main(string[] args)
        {
            Bank bank = new Bank("MyBank");

            char answer = '1';
            do
            {
                Console.WriteLine("Введите имя клиента:");
                string name = Console.ReadLine();

                string sum_str;

                int sum;

                do
                {
                    Console.WriteLine("Введите сумму на его счету:");

                    sum_str = Console.ReadLine();

                } while (!Int32.TryParse(Console.ReadLine(), out sum));

                bank.AddClient(name, sum);

                //Bank.Client NewClient = new Bank.Client(name, sum, percent, status);
                //bank.AddClient(NewClient);

                Console.WriteLine("Продолжить ввод? (1/0)");

                answer = char.Parse(Console.ReadLine());

            } while (answer != '0');

            bank.PrintInfo();

        }
    }
}