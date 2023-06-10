using Lab5.Application.Abstractions;
using Lab5.Domain.Entities;
using Lab5.UI.Pages;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Microsoft.Maui.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.UI.ViewModels
{
    public partial class AddSushiSetViewModel : ObservableObject
    {
        private readonly ISushiSetService _sushiSetService;

        [ObservableProperty]
        string title;
        [ObservableProperty]
        int amount;

        public AddSushiSetViewModel(ISushiSetService sushiSetService)
        {
            _sushiSetService = sushiSetService;
        }

        [RelayCommand]
        async Task AddSushiSet()
        {
            SushiSet set = new SushiSet();
            set.Title = title;
            set.Amount = amount;

            await _sushiSetService.AddAsync(set);
            Microsoft.Maui.Controls.Application.Current.MainPage.DisplayAlert("Sushi set added", ":)", "Ok");
        }
    }
}
