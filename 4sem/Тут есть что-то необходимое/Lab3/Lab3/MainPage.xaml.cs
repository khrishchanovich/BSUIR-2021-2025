using Lab3.Entities;
using Lab3.Services;

namespace Lab3;

public partial class MainPage : ContentPage
{
	IDbService db;
    public List<SushiSet> SushiSet { get; set; } = new();
    public List<Sushi> Sushi { get; set; } = new();
    public MainPage(IDbService _db)
	{
		db = _db;
		SushiSet = db.GetAllSushiSet().ToList();
        InitializeComponent();
    }
}

