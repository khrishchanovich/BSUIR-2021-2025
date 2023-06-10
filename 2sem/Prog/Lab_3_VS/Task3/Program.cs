using System;

namespace Task3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите дату в формате dd.mm.yyyy:");
            string date = Console.ReadLine();

            DateService Date = new DateService();

            Console.WriteLine(Date.GetDay(date));

            Console.WriteLine("Определить количество пройденных дней между " + date + " и:");
            string NewDate = Console.ReadLine();

            Console.WriteLine(Date.GetDaySpan(date, NewDate));
        }
    }
}
