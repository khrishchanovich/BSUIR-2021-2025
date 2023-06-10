using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.Domain.Entities
{
    public class SushiSet : Entity
    {
        public string Title { get; set; }
        public int Amount { get; set; }
        public List<Sushi> Sushis { get; set; } = new();
    }
}