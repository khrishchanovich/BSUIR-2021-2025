using Lab5.UI.ViewModels;

namespace Lab5.UI.Pages;

public partial class MainPage : ContentPage
{
    public MainPage(MainViewModel vm)
    {
        InitializeComponent();
        BindingContext = vm;
    }
}