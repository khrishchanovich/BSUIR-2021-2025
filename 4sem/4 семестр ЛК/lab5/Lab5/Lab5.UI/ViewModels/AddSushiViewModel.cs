using Lab5.Application.Abstractions;
using Lab5.Domain.Entities;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Microsoft.Maui.ApplicationModel;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.UI.ViewModels
{
    public partial class AddSushiViewModel : ObservableObject
    {
        private readonly ISushiService _sushiService;
        private readonly ISushiSetService _sushiSetService;

        [ObservableProperty]
        string name;
        [ObservableProperty]
        string description;
        [ObservableProperty]
        int amount;

        [ObservableProperty]
        SushiSet selectedSet;

        public AddSushiViewModel(ISushiService sushiService, ISushiSetService sushiSetService)
        {
            _sushiService = sushiService;
            _sushiSetService = sushiSetService;
        }
        public ObservableCollection<SushiSet> SushiSets { get; set; } = new();

        [RelayCommand]
        async Task AddSushi()
        {
            Sushi sushi = new Sushi();
            sushi.Name = name;
            sushi.Description = description;
            sushi.SushiSet = selectedSet;
            await _sushiService.AddAsync(sushi);
            Microsoft.Maui.Controls.Application.Current.MainPage.DisplayAlert("Sushi added", ":)", "Ok");
        }
        [RelayCommand]
        async Task InitStartData()
        {
            await GetSets();
        }

        async Task GetSets()
        {
            var sets = await _sushiSetService.GetAllAsync();
            await MainThread.InvokeOnMainThreadAsync(() =>
            {
                SushiSets.Clear();
                foreach (var set in sets)
                {
                    SushiSets.Add(set);
                }

            });
        }
    }
}
