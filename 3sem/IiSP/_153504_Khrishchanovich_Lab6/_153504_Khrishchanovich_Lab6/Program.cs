using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;

namespace _153504_Khrishchanovich_Lab6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string JSON = (@"D:\University\Glamazdin, Programming\_153504_Khrishchanovich_Lab6\_153504_Khrishchanovich_Lab6\files\FILE_JSON.json");

            List<Employee> employees = new List<Employee>(); ;

            employees.Add(new Employee("Robertov Robert Robertovich", 39, true));
            employees.Add(new Employee("Luisov Luis Luisovich", 73));
            employees.Add(new Employee("Donatelov Donatelo Donatelovich", 48, true));
            employees.Add(new Employee());

            string p1 = @"D:\University\Glamazdin, Programming\_153504_Khrishchanovich_Lab6\";

            Path.Combine(p1, "");



            Assembly asm = Assembly.LoadFrom(@"D:\University\Glamazdin, Programming\_153504_Khrishchanovich_Lab6\FileServiceLibrary\obj\Debug\net5.0\FileServiceLibrary.dll");

            Type? FileSer = asm?
                .GetType("FileServiceLibrary.FileService`1")?
                .MakeGenericType(typeof(Employee)) ?? null;

            if (FileSer is not null)
            {

                MethodInfo? SaveData = FileSer.GetMethod("SaveData");
                MethodInfo? ReadFile = FileSer.GetMethod("ReadFile");

                object? FileService = Activator.CreateInstance(FileSer);

                SaveData?.Invoke(FileService, new object[] { employees, JSON });

                List<Employee> emp = ReadFile?.Invoke(FileService, new object[] { JSON }) as List<Employee> ?? new List<Employee>();

                foreach (var item in emp)
                {
                    Console.WriteLine($" Name: {item.Name}\n Age: {item.Age}\n Work: {item.Work}\n");
                }
            }
        }
    }
}
