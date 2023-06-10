using Project_1.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_1.Services
{
    public interface IDbService
    {
        public IEnumerable<SushiSet> GetAllSushiSet();
        public IEnumerable<Sushi> GetDescription(int id);
        void Init();
    }
}
