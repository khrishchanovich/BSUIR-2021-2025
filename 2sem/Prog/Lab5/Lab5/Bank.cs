using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    class Bank
    {
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

        public void AddClient(string name, int sum, int percent = 3, ClientType status = ClientType.usual)
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

}
