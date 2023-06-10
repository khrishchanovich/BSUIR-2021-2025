using _153504_Khryshchanovich_Lab4;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System;

namespace _153504_Khryshchanovich_Lab4
{
    class Program
    {
        static void Main(string[] args)
        {

            List<Car> cars = new List<Car>();
            cars.Add(new Car("Audi", "Germany", 2300));
            cars.Add(new Car("BMW", "Germany", 2500));
            cars.Add(new Car("Opel", "Japan", 1000));
            cars.Add(new Car("Maclaren", "France", 2000));
            cars.Add(new Car("Ji", "Belarus", 1500));

            FileService fileService = new FileService();
            fileService.SaveData(cars, "cars.bin");
            IEnumerable<Car> cars2 = new List<Car>();

            cars2 = fileService.ReadFile("cars.bin");
            foreach (Car car in fileService.ReadFile("cars.bin"))
            {
                Console.WriteLine(car.ToString());
            }

           // fileService.RenameFile("cars.bin", "new.bin");

            var newListOfCars = cars2.OrderBy(c => c.Name);
            Console.WriteLine("\nList of cars sortered by name:\n");
            foreach (Car c in newListOfCars)
            {
                Console.WriteLine(c.ToString());
            }

            newListOfCars = cars2.OrderBy(c => c.Price);
            Console.WriteLine("\nList of cars sortered by price:\n");
            foreach (Car c in newListOfCars)
            {
                Console.WriteLine(c.ToString());
            }

        }
    }
}
