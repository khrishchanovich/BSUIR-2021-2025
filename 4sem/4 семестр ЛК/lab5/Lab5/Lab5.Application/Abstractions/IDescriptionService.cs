using Lab5.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.Application.Abstractions
{
    public interface ISushiService : IBaseService<Sushi>
    {
        Task<IEnumerable<Sushi>> GetAllByRouteAsync(SushiSet set);
    }
}
