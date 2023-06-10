using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//12

namespace Task2.Services
{
    class Function
    {
        public double Calculator(double z)
        {
            double x = (z > 0) ? (1 / Math.Sqrt(z-1)) : Math.Pow(z, 2) + 5;

            double y = Math.Pow(Math.Sin(Math.Pow(x, 2) - 1), 3) + Math.Log(Math.Abs(x)) + Math.Exp(x);

            Console.WriteLine(y);

            return y;
        }
    }
}
