using System;
using System.IO;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khryshchanovich_Lab4
{
    internal class FileService : IFileService<Car>
    {
        public IEnumerable<Car> ReadFile(string fileName)
        {
            bool exists = true;
            try
            {
                if (!File.Exists(fileName)) throw new Exception("No file with that name");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                exists = false;
            }
            if (exists)
            {
                using (BinaryReader reader = new BinaryReader(File.Open(fileName, FileMode.Open)))
                {
                    while (reader.PeekChar() > -1)
                    {
                        string name = reader.ReadString();
                        string country = reader.ReadString();
                        int price = reader.ReadInt32();
                        yield return new Car(name, country, price);
                    }
                }
            }
        }
        public void SaveData(IEnumerable<Car> data, string fileName)
        {
            try
            {
                using (BinaryWriter writer = new BinaryWriter(File.Open(fileName, FileMode.Create)))
                {
                    foreach (Car c in data)
                    {
                        writer.Write(c.Name);
                        writer.Write(c.Country);
                        writer.Write(c.Price);
                    }

                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

        }
        public void RenameFile(string fileName, string newFileName)
        {
            File.Move(fileName, newFileName, true);
        }
    }
}
