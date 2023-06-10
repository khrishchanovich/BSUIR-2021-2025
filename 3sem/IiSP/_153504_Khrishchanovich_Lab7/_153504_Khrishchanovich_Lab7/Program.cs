using System;
using _153504_Khrishchanovich_Lab7;
using System.Threading;

namespace _153504_Khrishchanovich_Lab7
{
    class Program
    {
            static Semaphore ThreadHandler = new Semaphore(2, 2);

            static void Main(string[] args)
            {
                ThreadStart start = new ThreadStart(Method);

                Thread PrimaryThread = new Thread(start),
                        SecondThread = new Thread(start),
                        ThirdThreadToCheckSemaphore = new Thread(Method);

                PrimaryThread.Priority = ThreadPriority.Highest;
                SecondThread.Priority = ThreadPriority.Lowest;

                PrimaryThread.Start();
                SecondThread.Start();

                ThirdThreadToCheckSemaphore.Start();
            }

            static public string ProgressMessage(double percent)
            {
                return ($"{Thread.CurrentThread.ManagedThreadId} ======> Completed by: {(int)percent} %");
            }

            public static void Method()
            {
                ThreadHandler.WaitOne();

                Integral integral = new Integral(ProgressMessage);

                Console.WriteLine($"\nПоток {Thread.CurrentThread.GetHashCode()} завершен с результатом: {integral.RectangleMethod()}");

                integral.CheckTime();

                ThreadHandler.Release();

            }
        }
}
