using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Project_1.Entities;
using Project_1.Services;

namespace Project_1
{
    public class PickerModel
    {
        IDbService db;
        public List<SushiSet> Routes { get; set; }
        public PickerModel(IDbService _db)
        {
            db = _db;
            Routes = new List<SushiSet>(db.GetAllSushiSet());
        }
        public List<Sushi> GetSushi(SushiSet set)
        {
            return db.GetDescription(set.Id).ToList();
        }
    }
}


