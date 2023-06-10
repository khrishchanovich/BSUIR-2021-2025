using SQLite;

namespace Lab3.Entities
{
    public class Sushi
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
        public int SushiSetId { get; set; }

    }
}
