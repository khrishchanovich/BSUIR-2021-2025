using Lab3.Entities;
using Lab3.Services;

namespace Lab3.ViewModel
{
    public class PickerPageViewModel
    {
        IDbService db;
        public List<SushiSet> Sets { get; set; }
        public PickerPageViewModel(IDbService _db)
        {
            db = _db;
            db.Init();
            Sets =new List<SushiSet>(db.GetAllSushiSet());
        }
        public List<Sushi> GetSushi(SushiSet route)
        {
            return db.GetDescription(route.Id).ToList();
        }
    }
}
