using Lab5.Domain.Entities;

using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.Domain.Abstractions
{
    public interface IRepository<T> where T : Entity
    {
        public Task<T> GetByIdAsync(int id, CancellationToken cancellationToken = default,
                                    params Expression<Func<T, object>>[]? includesProperties);
        public Task<IReadOnlyList<T>> ListAllAsync(CancellationToken cancellationToken = default);
        public Task<IReadOnlyList<T>> ListAsync(Expression<Func<T, bool>> filter,
                                                CancellationToken cancellationToken = default,
                                                params Expression<Func<T, object>>[]? includesProperties);
        public Task AddAsync(T entity, CancellationToken cancellationToken = default);
        public Task UpdateAsync(T entity, CancellationToken cancellationToken = default);
        public Task DeleteAsync(T entity, CancellationToken cancellationToken = default);
        public Task<T> FirstOrDefaultAsync(Expression<Func<T, bool>> filter, CancellationToken cancellationToken = default);
    }
}
