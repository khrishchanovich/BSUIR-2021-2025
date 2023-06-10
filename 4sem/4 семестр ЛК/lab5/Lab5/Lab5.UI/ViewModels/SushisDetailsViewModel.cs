using Lab5.Domain.Entities;
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
    [QueryProperty("SelectedSushi", "SelectedSushi")]
    public partial class SushiDetailsViewModel : ObservableObject
    {
        [ObservableProperty]
        Sushi selectedSushi;

        [RelayCommand]
        async Task GoToEditPage()
        {
            var navigationParameter = new Dictionary<string, object>
            {
                {"SelectedSushi", selectedSushi}
            };
            await Shell.Current.GoToAsync($"{nameof(EditPage)}", navigationParameter);
        }
    }
}
