using Lab5.Domain.Entities;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using Windows.System;

namespace Lab5.Persistense.Data
{
    public class AppDbContext : DbContext
    {
        public DbSet<SushiSet> SushiSets { get; set; } = null!;
        public DbSet<Sushi> Sushis { get; set; } = null!;

        public AppDbContext(DbContextOptions<AppDbContext> options)
                : base(options)
        {
            Database.EnsureCreated();
        }
    }
}
