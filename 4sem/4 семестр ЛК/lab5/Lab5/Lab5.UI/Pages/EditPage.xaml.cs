using Lab5.UI.ViewModels;

namespace Lab5.UI.Pages;

public partial class EditPage : ContentPage
{
    public EditPage(EditViewModel vm)
    {
        InitializeComponent();
        BindingContext = vm;
    }
}