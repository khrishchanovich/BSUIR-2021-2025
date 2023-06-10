using Lab5.UI.ViewModels;

namespace Lab5.UI.Pages;

public partial class SushiDetails : ContentPage
{
    public SushiDetails(SushiDetailsViewModel vm)
    {
        InitializeComponent();
        BindingContext = vm;
    }
}