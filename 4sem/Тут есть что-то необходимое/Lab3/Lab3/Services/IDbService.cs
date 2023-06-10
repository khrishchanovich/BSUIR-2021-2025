using Lab3.Entities;

namespace Lab3.Services
{
    public interface IDbService
    {
        IEnumerable<SushiSet> GetAllSushiSet();
        IEnumerable<Sushi> GetDescription(int id);
        void Init();
    }
}
