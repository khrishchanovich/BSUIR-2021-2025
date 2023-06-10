using System;
using System.Threading.Tasks;
using System.IO;
using System.Collections.Generic;
using System.Runtime.Serialization.Formatters.Binary;

namespace Library8
{
    public class StreamService<T>
    {
        public async Task WriteToStreamAsync(Stream stream, IEnumerable<T> data, IProgress<string> progress)
        {
            progress?.Report("Write to stream committed");
            BinaryFormatter formatter = new BinaryFormatter();

            MemoryStream buffer = new MemoryStream();

            formatter.Serialize(buffer, data);

            //await Task.Run(() =>
            {
              await  stream.WriteAsync(buffer.ToArray());
            };


            Console.WriteLine();
            progress?.Report("Write to stream successfull");

        }

        public async Task CopyFromStreamAsync(object stream, string filename)
        {
            using (FileStream fs = new FileStream(filename, FileMode.OpenOrCreate))
            {
                await System.Text.Json.JsonSerializer.SerializeAsync(fs, stream, stream.GetType());
            }

            await Process();

            Console.WriteLine();
        }

        public async Task<int> GetStatisticsAsync(string filename, Func<T, bool> filter)
        {
            var objs = System.Text.Json.JsonSerializer.Deserialize<IEnumerable<T>>(File.ReadAllText(filename));

            int size = 0;

            await Task.Run(() =>
            {
                Console.WriteLine();

                foreach (var obj in objs)
                {
                    Console.WriteLine(obj.ToString());

                    if (filter(obj))
                        ++size;
                }
            });

            return size;
        }

        private async Task Process()
        {
            Console.WriteLine();

            var p = new Progress<string>(m =>
            {
                Console.Write($"\r{m}");
            });

            await GetProgress(p);
        }

        private async Task GetProgress(IProgress<string> progress)
        {
            for (int i = 0; i <= 100; i += 10)
            {
                await Task.Delay(100);
                progress?.Report(new string($"Завершено на : {i} %"));
            }
        }
    }
}
