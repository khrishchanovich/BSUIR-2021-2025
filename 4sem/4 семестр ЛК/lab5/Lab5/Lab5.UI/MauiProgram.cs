using Lab5.Application.Abstractions;
using Lab5.Application.Services;
using Lab5.Domain.Abstractions;
using Lab5.Persistense.Repository;
using Lab5.UI.ViewModels;
using Lab5.UI.Pages;
using CommunityToolkit.Maui;
using Microsoft.Extensions.Logging;
using System.Reflection;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.Configuration.Json;
using Microsoft.EntityFrameworkCore;
using Lab5.Persistense.Data;
using Lab5.Domain.Entities;
using System.Net.WebSockets;

namespace Lab5.UI;

public static class MauiProgram
{
    public static MauiApp CreateMauiApp()
    {
        string settingsStream = "153504_Khrishchanovich.UI.appsettings.json";

        var builder = MauiApp.CreateBuilder();
        builder
            .UseMauiApp<App>()
            .UseMauiCommunityToolkit()
            .ConfigureFonts(fonts =>
            {
                fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
                fonts.AddFont("OpenSans-Semibold.ttf", "OpenSansSemibold");
            });


        var b = new ConfigurationBuilder();
        b.SetBasePath(Directory.GetCurrentDirectory());
        b.AddJsonFile("D:\\Lab5\\Lab5.UI\\appsettings.json");
        var config = b.Build();
        builder.Configuration.AddConfiguration(config);

        AddDbContext(builder);
        SetupServices(builder.Services);
        SeedData(builder.Services);


#if DEBUG
        builder.Logging.AddDebug();
#endif

        return builder.Build();
    }

    private static void SetupServices(IServiceCollection services)
    {
        //Services
        services.AddSingleton<IUnityOfWork, EfUnityOfWork>();
        services.AddSingleton<ISushiSetService, SushiSetService>();
        services.AddSingleton<ISushiService, SushiService>();


        //Pages
        services.AddSingleton<Sushis>();
        services.AddSingleton<MainPage>();
        services.AddTransient<SushiDetails>();
        services.AddTransient<AddSushiSetPage>();
        services.AddTransient<AddSushiPage>();
        services.AddTransient<EditPage>();

        //ViewModels
        services.AddSingleton<SushisViewModel>();
        services.AddSingleton<MainViewModel>();
        services.AddTransient<SushiDetailsViewModel>();
        services.AddTransient<AddSushiSetViewModel>();
        services.AddTransient<AddSushiViewModel>();
        services.AddTransient<EditViewModel>();

    }

    private static void AddDbContext(MauiAppBuilder builder)
    {
        var connStr = builder.Configuration.GetConnectionString("SqliteConnection");
        string dataDirectory = String.Empty;
#if ANDROID
		dataDirectory = FileSystem.AppDataDirectory + "/";
#endif
        connStr = String.Format(connStr, dataDirectory);

        var options = new DbContextOptionsBuilder<AppDbContext>()
                    .UseSqlite(connStr)
                    .Options;
        builder.Services.AddSingleton<AppDbContext>((s) => new AppDbContext(options));
    }

    public async static void SeedData(IServiceCollection services)
    {
        using var provider = services.BuildServiceProvider();
        var unityOfWork = provider.GetService<IUnityOfWork>();
        //await unitOfWork.RemoveDatabaseAsync();
        await unityOfWork.CreateDatabaseAsync();

        //Add sushi set
        IReadOnlyList<SushiSet> sets = new List<SushiSet>()
            {
                new SushiSet() { Title = "SushiSet1", Amount=20},
                new SushiSet() { Name = "SushiSet2", Amount=34}
            };
        foreach (var set in sets)
        {
            await unityOfWork.SushiSetRepository.AddAsync(set);
        }
        await unityOfWork.SaveAllAsync();
        //Add sushi
        int k = 1;
        foreach (var set in sets)
        {
            for (int i = 1; i < 10; i++)
            {
                await unityOfWork.SushiRepository.AddAsync(new Sushi()
                {
                    Name = $"Sushi{k++}",
                    SushiSet = set,
                    Description = $"Description{k}",
                    Amount = k
                });
            }
        }
        await unityOfWork.SaveAllAsync();

    }
}
