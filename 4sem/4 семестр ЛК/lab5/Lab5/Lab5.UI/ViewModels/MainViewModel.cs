using Lab5.UI.Pages;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.UI.ViewModels
{
    public partial class MainViewModel : ObservableObject
    {
        [RelayCommand]
        async Task GoToAddSushiSet()
        {
            await Shell.Current.GoToAsync(nameof(AddSushiSetPage));
        }
        [RelayCommand]
        async Task GoToAddSushi()
        {
            await Shell.Current.GoToAsync(nameof(AddSushiPage));
        }

    }
}
