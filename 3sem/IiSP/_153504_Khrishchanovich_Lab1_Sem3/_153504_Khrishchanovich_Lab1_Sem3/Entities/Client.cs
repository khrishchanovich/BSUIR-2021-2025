using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khrishchanovich_Lab1_Sem3.Entities
{
    internal class Client
    {
        public string FirstName { get; set; }
        public string Surname { get; set; }
        public Client(string firstName, string surname)
        {
            FirstName = firstName;
            Surname = surname;
        }
    }
}
