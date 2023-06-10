﻿using Lab5.UI.Constants;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.UI.ValueConverters
{
    public class SushiIdToImageValueConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            try
            {
                int id = (int)value;
                string[] files = Directory.GetFiles(PathConstants.ImagesFolder, $"{id}.*");
                return ImageSource.FromFile(files[0]);
            }
            catch
            {
                return ImageSource.FromFile("dotnet_bot.png");
            }
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
