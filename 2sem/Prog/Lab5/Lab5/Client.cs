using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    class Client
    {
        private ClientType VIP;
        private string name = "";
        private Deposit deposit;

        public Client()
        {
            deposit = new Deposit();
            name = "";
            VIP = 0;
        }
        public Client(string nm, int dep, int percent, ClientType VIP_status = ClientType.usual)
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
}
