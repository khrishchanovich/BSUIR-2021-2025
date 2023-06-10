using Lab3.ViewModel;

namespace Lab3.View;

public partial class —urrency—onverterPage : ContentPage
{
    public —urrency—onverterPage(CurrencyConverterViewModel viewModel)
    {
        InitializeComponent();
        BindingContext = viewModel;
    }
}