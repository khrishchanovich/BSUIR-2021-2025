using Lab5.UI.ViewModels;

namespace Lab5.UI.Pages;

public partial class AddSushiSetPage : ContentPage
{
    public AddSushiSetPage(AddSushiSetViewModel vm)
    {
        InitializeComponent();
        BindingContext = vm;
    }
}