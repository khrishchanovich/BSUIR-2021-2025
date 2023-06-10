using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khrishchanovich_Lab2.Exceptions
{
    public class MyException : Exception
    {
        public MyException(string message) : base(message)
        {

        }
    }
}
