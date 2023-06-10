using Lab5.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.Domain.Abstractions
{
    public interface IUnityOfWork
    {
        IRepository<SushiSet> SushiSetRepository { get; }
        IRepository<Sushi> SushiRepository { get; }

        public Task CreateDatabaseAsync();
        public Task RemoveDatabaseAsync();
        public Task SaveAllAsync();
    }
}
