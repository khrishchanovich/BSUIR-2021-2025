using Lab5.UI.Pages;

namespace Lab5.UI;

public partial class AppShell : Shell
{
    public AppShell()
    {
        InitializeComponent();
        Routing.RegisterRoute(nameof(SushiDetails), typeof(SushiDetails));
        Routing.RegisterRoute(nameof(AddSushiSetPage), typeof(AddSushiSetPage));
        Routing.RegisterRoute(nameof(AddSushiPage), typeof(AddSushiPage));
        Routing.RegisterRoute(nameof(EditPage), typeof(EditPage));
    }
}
