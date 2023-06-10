using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khrishchanovich_Lab2.Entities
{
    public class Deposit
    {
        public string Name { get; set; }
        public double Percent { get; set; }
        public Deposit(string name, double percent)
        {
            Name = name;
            Percent = percent;
        }
    }
}
