using Lab5.Domain.Abstractions;
using Lab5.Domain.Entities;
using Lab5.Persistense.Data;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.Persistense.Repository
{
    public class EfUnityOfWork : IUnityOfWork
    {
        private readonly AppDbContext _context;
        private readonly Lazy<IRepository<SushiSet>> _touristRouteRepository;
        private readonly Lazy<IRepository<Sushi>> _sightRepository;

        public EfUnityOfWork(AppDbContext context)
        {
            _context = context;
            _touristRouteRepository = new Lazy<IRepository<SushiSet>>(() => new EfRepository<SushiSet>(context));
            _sightRepository = new Lazy<IRepository<Sushi>>(() => new EfRepository<Sushi>(context));
        }

        IRepository<SushiSet> IUnityOfWork.SushiSetRepository =>
            _touristRouteRepository.Value;
        IRepository<Sushi> IUnityOfWork.SushiRepository =>
            _sightRepository.Value;


        public async Task CreateDatabaseAsync()
        {
            await _context.Database.EnsureCreatedAsync();
        }

        public async Task RemoveDatabaseAsync()
        {
            await _context.Database.EnsureDeletedAsync();
        }

        public async Task SaveAllAsync()
        {
            await _context.SaveChangesAsync();
        }
    }
}
