using SQLite;

namespace Lab3.Entities
{
    public class SushiSet
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        public string Title { get; set; }
        public string Amount { get; set; }
    }
}
