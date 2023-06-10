using Lab5.Application.Abstractions;
using Lab5.Domain.Entities;
using Lab5.UI.Pages;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.UI.ViewModels
{
    public partial class SushisViewModel : ObservableObject
    {
        private readonly ISushiSetService _sushiSetService;
        private readonly ISushiService _sushiService;

        public SushisViewModel(ISushiSetService setService, ISushiService sushiService)
        {
            _sushiSetService = setService;
            _sushiService = sushiService;
        }

        public ObservableCollection<SushiSet> SushiSets { get; set; } = new();
        public ObservableCollection<Sushi> Sushis { get; set; } = new();

        [ObservableProperty]
        SushiSet selectedSushiSet;

        [ObservableProperty]
        Sushi selectedSushi;

        [RelayCommand]
        async void UpdateGroupList()
        {
            await GetSushiSets();
        }


        [RelayCommand]
        async void UpdateMemberList()
        {
            await GetSushis();

        }

        [RelayCommand]
        async void ShowDetails(Sushi sushi)
        {
            await GoToDetailsPage(sushi);
        }

        public async Task GetSushiSets()
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

        public async Task GetSushis()
        {
            var sushis = await _sushiService.GetAllByRouteAsync(SelectedSushiSet);
            await MainThread.InvokeOnMainThreadAsync(() =>
            {
                Sushis.Clear();
                foreach (var sushi in sushis)
                {
                    Sushis.Add(sushi);
                }
            });
        }

        async Task GoToDetailsPage(Sushi sushi)
        {
            var navigationParameter = new Dictionary<string, object>
            {
                {"SelectedSushi", sushi}
            };
            await Shell.Current.GoToAsync($"{nameof(SushiDetails)}", navigationParameter);
        }

    }
}
