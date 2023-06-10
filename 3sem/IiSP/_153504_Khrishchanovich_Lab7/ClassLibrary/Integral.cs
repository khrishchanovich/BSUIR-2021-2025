using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using System.Threading;

namespace _153504_Khrishchanovich_Lab7
{
    public class Integral
    {
        private Stopwatch Time;

        private Func<double, string> Message;
        public Integral(Func<double, string> EVENT)
        {
            Message = EVENT;

            Time = new Stopwatch();

        }
        private double f(double x)
        {
            return Math.Sin(x);
        }
        public double RectangleMethod()
        {
            double LowerBound = 0,
                    UpperBound = 1,
                    Step = 0.00001,
                    Sum = 0;

            Time.Restart();

            int prevProgress = -1;

            for (double x1 = 0, x = LowerBound; x <= UpperBound; x += Step)
            {

                if (x < UpperBound)
                {
                    for (int i = 0; i < 100000; ++i) { }

                    x1 = x + Step / 2;

                    if (x1 >= 2)
                        continue;

                    Sum += f(x1);

                    if (prevProgress != (int)(x * 100.0))
                        Console.WriteLine(Message(x * 100));

                }

                prevProgress = (int)(x * 100.0);
            }

            Time.Stop();

            return Sum * Step;
        }

        public void CheckTime()
        {
            Console.WriteLine($"\nTime Spent: {Time.ElapsedMilliseconds}");
        }
    }
}
