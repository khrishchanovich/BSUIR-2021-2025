using Lab5.Application.Abstractions;
using Lab5.Domain.Entities;
using Lab5.UI.Constants;
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
    [QueryProperty("SelectedSushi", "SelectedSushi")]
    public partial class EditViewModel : ObservableObject
    {
        private readonly ISushiService _sushiService;
        private readonly ISushiSetService _sushiSetService;

        [ObservableProperty]
        Sushi selectedSushi;

        [ObservableProperty]
        string editedName;
        [ObservableProperty]
        string editedDescription;
        [ObservableProperty]
        int editedAmount;
        [ObservableProperty]
        SushiSet editedSet;

        public EditViewModel(ISushiService sushiService, ISushiSetService sushiSetService)
        {
            _sushiService = sushiService;
            _sushiSetService = sushiSetService;

        }

        public ObservableCollection<SushiSet> Sets { get; set; } = new();

        [RelayCommand]
        async Task InitStartData()
        {
            await GetSets();
            editedName = selectedSushi.Name;
            editedDescription = selectedSushi.Description;
            editedAmount = selectedSushi.Amount;
            editedSet = selectedSushi.SushiSet;
        }

        async Task GetSets()
        {
            var sets = await _sushiSetService.GetAllAsync();
            await MainThread.InvokeOnMainThreadAsync(() =>
            {
                Sets.Clear();
                foreach (var set in sets)
                {
                    Sets.Add(set);
                }

            });
        }

        [RelayCommand]
        async Task SaveChanges()
        {
            await _sushiService.UpdateAsync(selectedSushi);
            await Shell.Current.GoToAsync("../..");
        }


        [RelayCommand]
        public async Task PickPicture()
        {
            var result = await FilePicker.PickAsync(new PickOptions()
            {
                PickerTitle = "Pick Image",
                FileTypes = FilePickerFileType.Images
            });

            if (result == null)
                return;

            string[] songImagePaths = Directory.GetFiles(PathConstants.ImagesFolder, $"{selectedSushi.Id}.*");
            foreach (var imagePath in songImagePaths)
            {
                if (File.Exists(imagePath))
                {
                    File.Delete(imagePath);
                }
            }


            var destinationPath = Path.Combine(PathConstants.ImagesFolder,
                $"{selectedSushi.Id}{Path.GetExtension(result.FullPath)}");

            FileInfo fileInfo = new FileInfo(result.FullPath);
            if (fileInfo.Exists)
            {
                fileInfo.CopyTo(destinationPath, true);
            }

            OnPropertyChanged($"{nameof(selectedSushi)}");
        }

    }
}
