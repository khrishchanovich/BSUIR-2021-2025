using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khryshchanovich_Lab4
{
    internal class MyCustomComparer<T> : IComparer<T>
        where T : Car
    {
        public int Compare(T x, T y)
        {
            if (x is null || y is null)
            {
                throw new ArgumentException("Invalid argument value");
            }
            return y.Name.Length - x.Name.Length;
        }
    }
}

