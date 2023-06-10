using System;
using System.Collections.Generic;

namespace Task2
{

    enum TariffType: int
    {
        usual,
        VIP
    };

    class InternetOperator
    {
        public class User
        {
            private class Tariff
            {
                private int tariff;
                private int traffic;

                public Tariff()
                {
                    tariff = 0;
                    traffic = 0;
                }

                public Tariff(int value, int traffic)
                {
                    tariff = value;
                    this.traffic = traffic;
                }

                public int Sum()
                {
                    return traffic;
                }

            };

            private int VIP;
            private int traffic;
            private string name = "";
            private Tariff tariff;

            public User()
            {
                tariff = new Tariff();
                traffic = 0;
                name = "";
                VIP = 0;
            }

            public User(string nameTEMP, int tariffTEMP, int trafficTEMP, int VIPTEMP)
            {
                name = nameTEMP;
                tariff = new Tariff(tariffTEMP, trafficTEMP);
                VIP = VIPTEMP;
            }

            public string Name()
            {
                return name;
            }

            public int UserTariff()
            {
                return tariff.Sum();
            }

            public string Info()
            {
                return "\nПользователь: " + name + "Тариф: " + tariff + "Траффик: " + traffic;
            }
        };

        private List<User> user;

        private string name;

        public InternetOperator()
        {
            name = "";
            user = new List<User>();
        }

        public InternetOperator(string nm)
        {
            name = nm;
            user = new List<User>();
        }

        public void AddUser(string name, int tariff, int traffic, int status = 0)
        {
            user.Add(new User(name, tariff, traffic, status));
        }

        public void AddUser(User person)
        {
            user.Add(person);
        }

        public void PrintInfo()
        {
            foreach (var person in user)
            {
                Console.WriteLine(person.Info());
            }
        }

    };

    class Program
    {
        static void Main(string[] args)
        {
            InternetOperator op = new InternetOperator("Tariff");

            char answer = '1';
            do
            {
                Console.WriteLine("Введите имя пользователя: ");
                string name = Console.ReadLine();

                Console.WriteLine("Введите сумму тариффа: ");
                int tariff = Convert.ToInt32(Console.ReadLine());

                Console.WriteLine("Введите количество траффика: ");
                int traffic = Convert.ToInt32(Console.ReadLine());

                Console.WriteLine("Продолжить ввод? (1/0)");

                answer = char.Parse(Console.ReadLine());
            } while (answer != '0');
            op.PrintInfo();
        }
    };
}
