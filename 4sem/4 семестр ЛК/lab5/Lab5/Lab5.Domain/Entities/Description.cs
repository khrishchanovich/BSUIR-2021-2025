using Lab5.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.Domain.Entities
{
    public class Sushi : Entity
    {
        public string Name { get; set; }
        public string Description { get; set; }
        public int Amount { get; set; }
        public int SushiSetId { get; set; }
        public SushiSet SushiSet { get; set; }
    }
}
