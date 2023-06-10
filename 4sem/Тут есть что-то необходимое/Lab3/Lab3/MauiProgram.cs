using Lab3.Services;
using Lab3.View;
using Lab3.ViewModel;

namespace Lab3;

public static class MauiProgram
{
	public static MauiApp CreateMauiApp()
	{
		var builder = MauiApp.CreateBuilder();
		builder
			.UseMauiApp<App>()
			.ConfigureFonts(fonts =>
			{
				fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
				fonts.AddFont("OpenSans-Semibold.ttf", "OpenSansSemibold");
			});

        builder.Services.AddTransient<IDbService, SQLiteService>();
        builder.Services.AddSingleton<PickerPage>();
		builder.Services.AddSingleton<PickerPageViewModel>();

        builder.Services.AddTransient<CurrencyConverterViewModel>();
        builder.Services.AddTransient<СurrencyСonverterPage>();
        builder.Services.AddHttpClient<IRateService, RateService>(opt => opt.BaseAddress = new Uri("https://www.nbrb.by/api/exrates/rates"));

        return builder.Build();
	}
}
