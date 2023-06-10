using System;
using System.Threading.Tasks;
using System.Collections.Generic;
using Library8;
using System.IO;
using System.Threading;

namespace _153504_Khrishchanovich_Lab8
{
    class Program
    {
        static object locker = new object();

        static MusicCollection[] music = new MusicCollection[2];

        static IProgress<string> progress = new Progress<string>(msg => Console.WriteLine(msg));


        static MemoryStream memoryStream = new MemoryStream();
        static async Task Main(string[] args)
        {



            music[0] = new MusicCollection { Singer = "abcd", Songs = 3 };
            music[1] = new MusicCollection { Singer = "xyz" };

            StreamService<MusicCollection> streamService = new StreamService<MusicCollection>();

            var task1 = streamService.WriteToStreamAsync(memoryStream, music, progress);

            var task2 = streamService.CopyFromStreamAsync(music, "lr8H.json");


            await Task.WhenAll(task1, task2);

            var Elements = await streamService.GetStatisticsAsync("lr8H.json", IsNotEmpty);

            Console.WriteLine($"Количество певцов, чьи песни загружены в плейлист:\t{Elements}");

            for (int i = 1; i <= 2; ++i)
            {
                Thread thread = new Thread(new ThreadStart(Method));

                if (i == 1)
                    thread.Priority = ThreadPriority.Highest;
                else
                    thread.Priority = ThreadPriority.Lowest;
                thread.Start();
            }

        }

        public static void Method()
        {
            lock (locker)
            {

                StreamService<MusicCollection> streamService = new StreamService<MusicCollection>();

                try
                {
                    if (Thread.CurrentThread.Priority == ThreadPriority.Highest)
                    {
                        Console.WriteLine($"\nпоток {Thread.CurrentThread.GetHashCode()} исполняет Write");

                        streamService.WriteToStreamAsync(memoryStream, music, progress);

                    }

                    else
                    {

                        Console.WriteLine($"\nпоток {Thread.CurrentThread.GetHashCode()} исполняет Copy");

                        streamService.CopyFromStreamAsync(music, "lrrr.json");

                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                }
            }
        }

        public static bool IsNotEmpty(MusicCollection playlist)
            => !playlist.IsEmpty();
    }
}
