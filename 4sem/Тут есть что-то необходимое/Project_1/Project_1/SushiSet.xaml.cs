using Project_1.Entities;
using Project_1.Services;

namespace Project_1;

public partial class SushiSet : ContentPage
{
    IDbService db;
    public List<SushiSet> SushiSets { get; set; } = new();
    public List<Sushi> Sushi { get; set; } = new();
    public string Amount { get; internal set; }

    public SushiSet(IDbService _db)
    {
        db = _db;
        SushiSets = db.GetAllSushiSet().ToList();
        InitializeComponent();
    }
}


