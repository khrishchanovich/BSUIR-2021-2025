using Lab5.UI.ViewModels;

namespace Lab5.UI.Pages;

public partial class AddSushiPage : ContentPage
{
    public AddSushiPage(AddSushiViewModel vm)
    {
        InitializeComponent();
        BindingContext = vm;
    }
}