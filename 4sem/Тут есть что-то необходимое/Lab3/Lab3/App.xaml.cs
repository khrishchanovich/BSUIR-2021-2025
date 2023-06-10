using Lab3.ViewModel;

namespace Lab3;

public partial class App : Application
{
	public App()
	{
		InitializeComponent();

		MainPage = new AppShell();
	}
}
