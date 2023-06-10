using Lab5.UI.ViewModels;
using Lab5.Domain.Entities;

namespace Lab5.UI.Pages;

public partial class Sushis : ContentPage
{
    public Sushis(SushisViewModel vm)
    {

        InitializeComponent();
        BindingContext = vm;
    }
}