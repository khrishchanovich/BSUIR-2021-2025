using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//10

namespace Task1
{
    class Function
    {
        public int Swap(int n)
        {
            int first = n / 100;
            int last = n % 10;

            int t = first;
            first = last;
            last = t;

            int mid = (n % 100) / 10;

            int result = last + mid * 10 + first * 100;

            Console.WriteLine(result);

            return result;
        }
    }
}
