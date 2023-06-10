using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.UI.Constants
{
    public static class PathConstants
    {
        public static string AppData
        => Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData);

        public const string RootFolder = "153504_Khrishchanovich";

        public static string DbFolder => Path.Combine(AppData, RootFolder);
        public static string ImagesFolder => Path.Combine(AppData, RootFolder, "Images");
    }
}
