using System;

namespace Lab6
{
    class Program
    {
        static void Main(string[] args)
        {
            Food dessert = new Desserts("Торт \"Лайм\"", 15, 10);

            Food BaseCocktail = new Cocktails("Сок", 7, false);

            BaseCocktail.ChangeName("Апельсиновый Сок");

            BaseCocktail.View();

            Cocktails DerivedCocktail = new Cocktails("\"Снежные просторы\"", 10, false);

            DerivedCocktail.ChangeName("\"Снежные просторы\"");

            DerivedCocktail.View();

        }
    }
}
