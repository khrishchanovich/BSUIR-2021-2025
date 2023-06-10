using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khrishchanovich_Lab5.Domain
{
    [Serializable]
    public class Runway
    {
        public string Name { get; set; }
        public int Length { get; set; }
        public Runway()
        {
            Name = "Undefined";
            Length = 0;
        }
        public Runway(string name, int length)
        {
            Name = name;
            Length = length;
        }
        public override string ToString()
        {
            return $"Runway name: {Name}, runway length: {Length}";
        }
    }
}
