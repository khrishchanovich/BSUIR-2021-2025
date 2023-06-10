using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khryshchanovich_Lab4
{
    internal class Car
    {
        public string Name { get; set; }
        public string Country { get; set; }
        public int Price { get; set; }
        public Car(string name, string country, int price)
        {
            Name = name;
            Country = country;
            Price = price;
        }
        public override string ToString()
        {
            return Name + " Manufacturer's country: " + Country + $" Price: {Price}";
        }


    }
}
