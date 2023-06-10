using Lab3.Entities;
using Lab3.ViewModel;

namespace Lab3;

public partial class PickerPage : ContentPage
{
	PickerPageViewModel _viewModel;
	public PickerPage(PickerPageViewModel viewModel)
	{
		_viewModel= viewModel;
		InitializeComponent();
		BindingContext= viewModel;
	}

    private void OnPicker(object sender, EventArgs e)
    {
        var picker = (Picker)sender;
        int selectedIndex = picker.SelectedIndex;

        if (selectedIndex != -1)
        {
            SushiSet set = (SushiSet)picker.ItemsSource[selectedIndex];
            collectionView.ItemsSource = _viewModel.GetSushi(set);
        }
    }
}