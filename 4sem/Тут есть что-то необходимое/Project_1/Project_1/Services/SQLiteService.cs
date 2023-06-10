using Project_1.Entities;
using Project_1.Services;
using SQLite;
using System;

namespace Project_1.Services
{
    public class SQLiteService : IDbService
    {
        private SQLiteConnection db;

        public void Init()
        {
            if (db != null)
                return;
            string dbPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "Data.db");
            db = new SQLiteConnection(dbPath);

            db.DropTable<SushiSet>();
            db.DropTable<Sushi>();

            db.CreateTable<SushiSet>();
            db.CreateTable<Sushi>();

            int setId = AddSushiSet("Pink Set", "4 ролла, 32 шт.");
            AddDescription("Ролл с креветкой", "креветка, сливочный сыр, томат", setId);
            AddDescription("Нидзи", "филе лосося, филе тунца, сливочный сыр, такуан, огурец, рукола.", setId);
            AddDescription("Бостон", "креветка, сливочный сыр, ананас, салат Айсберг, соус сладко-ореховый, икра Тобико оранжевая.", setId);
            AddDescription("Ролл с лососем", "филе лосося, сливочный сыр, огурец, икра Тобико оранжевая.", setId);

            setId = AddSushiSet("Женский каприз", "4 ролла, 32 шт.");
            AddDescription("Филадельфия с огурцом", "Филе лосося, сливочный сры, огурец", setId);
            AddDescription("Ролл с тунцом", "филе тунца, сливочный сыр, такуан", setId);
            AddDescription("Бостон", "креветка, сливочный сыр, ананас, салат Айсберг, соус сладко-ореховый, икра Тобико оранжевая.", setId);
            AddDescription("Манхетен с салатом Айсберг", "филе лосося, сливочный сыр, огурец, салат Айсберг, кунжут", setId);

            setId = AddSushiSet("Шримп Фрай сет", "3 ролла, 25 шт.");
            AddDescription("Куранчи фрай", "креветка, сливочный сыр, огурец, икра Тобико оранжевая, панировка", setId);
            AddDescription("Изуми фрай", "креветка, сливочный сыр, омлет Тамаго, соус сладко-ореховый, икра Тобико черная, панировка", setId);
            AddDescription("Пабло Фрай", "креветка, сливочный сыр, огурец, имбирь маринованный, соус ореховый, панировка", setId);
        }

        public IEnumerable<SushiSet> GetAllSushiSet()
        {
            Init();
            return db.Table<SushiSet>().ToList();
        }
        public IEnumerable<Sushi> GetDescription(int id)
        {
            Init();
            return db.Table<Sushi>().Where(s => s.SushiSetId == id).ToList();
        }
        public int AddSushiSet(string title, string amount)
        {
            SushiSet set = new SushiSet;
            {
                Title = title,
                Amount = amount,
            };
            db.Insert(set);
            return set.Id;
        }
        public void AddDescription(string name, string description, int sushiSetId)
        {
            Sushi sushi = new Sushi
            {
                Name = name,
                Description = description,
                SushiSetId = sushiSetId,
            };
            db.Insert(sushi);
        }
    }
}

