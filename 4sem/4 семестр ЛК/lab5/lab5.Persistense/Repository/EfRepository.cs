﻿using lab5.Domain.Abstractions;
using lab5.Domain.Entities;
using lab5.Persistense.Data;
using Microsoft.EntityFrameworkCore;
using System.Linq.Expressions;

namespace lab5.Persistense.Repository;

public class EfRepository<T> : IRepository<T> where T : Entity
{
    protected readonly AppDbContext _db;
    protected readonly DbSet<T> _entities;

    public EfRepository(AppDbContext db)
    {
        _db = db;
        _entities = db.Set<T>();
    }

    public async Task AddAsync(T entity)
    {
        await _entities.AddAsync(entity);
        await _db.SaveChangesAsync();
    }

    public async Task DeleteAsync(T entity)
    {
        await Task.Run(() => _entities.Remove(entity));
        await _db.SaveChangesAsync();
    }

    public async Task<T?> FirstOrDefaultAsync(Func<T, bool> filter)
    {
        return await Task.Run(() => _entities.FirstOrDefault(filter));
    }

    public async Task<T?> GetByIdAsync(int id)
    {
        return await Task.Run(() => _entities.FirstOrDefault(e => e.Id == id));
    }

    public async Task<IEnumerable<T>> ListAllAsync()
    {
        return await _entities.ToListAsync();
    }

    public async Task<IEnumerable<T>> ListAsync(Func<T, bool> filter)
    {
        return await Task.Run(() => _entities.Where(filter).ToList());
    }

    public async Task UpdateAsync(T entity)
    {
        await Task.Run(() => _entities.Update(entity));
        await _db.SaveChangesAsync();
    }
}