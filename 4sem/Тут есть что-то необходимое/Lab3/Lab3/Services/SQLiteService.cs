using Lab3.Entities;
using SQLite;

namespace Lab3.Services
{
    public class SQLiteService: IDbService
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
            AddSushi("Ролл с креветкой", "креветка, сливочный сыр, томат", setId);
            AddSushi("Нидзи", "филе лосося, филе тунца, сливочный сыр, такуан, огурец, рукола.", setId);
            AddSushi("Бостон", "креветка, сливочный сыр, ананас, салат Айсберг, соус сладко-ореховый, икра Тобико оранжевая.", setId);
            AddSushi("Ролл с лососем", "филе лосося, сливочный сыр, огурец, икра Тобико оранжевая.", setId);

            setId = AddSushiSet("Женский каприз", "4 ролла, 32 шт.");
            AddSushi("Филадельфия с огурцом", "Филе лосося, сливочный сры, огурец", setId);
            AddSushi("Ролл с тунцом", "филе тунца, сливочный сыр, такуан", setId);
            AddSushi("Бостон", "креветка, сливочный сыр, ананас, салат Айсберг, соус сладко-ореховый, икра Тобико оранжевая.", setId);
            AddSushi("Манхетен с салатом Айсберг", "филе лосося, сливочный сыр, огурец, салат Айсберг, кунжут", setId);

            setId = AddSushiSet("Шримп Фрай сет", "3 ролла, 25 шт.");
            AddSushi("Куранчи фрай", "креветка, сливочный сыр, огурец, икра Тобико оранжевая, панировка", setId);
            AddSushi("Изуми фрай", "креветка, сливочный сыр, омлет Тамаго, соус сладко-ореховый, икра Тобико черная, панировка", setId);
            AddSushi("Пабло Фрай", "креветка, сливочный сыр, огурец, имбирь маринованный, соус ореховый, панировка", setId);

        }
        public IEnumerable<SushiSet> GetAllSushiSet()
        {
            return db.Table<SushiSet>().ToList(); 
        }
        public IEnumerable<Sushi> GetDescription(int id)
        {
            return db.Table<Sushi>().Where(s => s.SushiSetId == id).ToList();
        }
        public int AddSushiSet(string title, string amount)
        {
            SushiSet set = new SushiSet
            {
                Title = title,
                Amount = amount,
            };
            db.Insert(set);
            return set.Id;
        }
        public void AddSushi(string name, string description, int sushiSetId)
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
