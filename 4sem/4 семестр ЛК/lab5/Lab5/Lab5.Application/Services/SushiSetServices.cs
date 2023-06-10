using Lab5.Application.Abstractions;
using Lab5.Domain.Abstractions;
using Lab5.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.Application.Services
{
    public class SushiSetService : ISushiSetService
    {
        IUnityOfWork unityOfWork;
        public SushiSetService(IUnityOfWork unityOfWork)
        {
            this.unityOfWork = unityOfWork;
        }
        public async Task<SushiSet> AddAsync(SushiSet entity)
        {
            await unityOfWork.SushiSetRepository.AddAsync(entity);
            await unityOfWork.SaveAllAsync();
            return entity;
        }

        public async Task<SushiSet> DeleteAsync(int id)
        {
            SushiSet set = await GetByIdAsync(id);
            await unityOfWork.SushiSetRepository.DeleteAsync(set);
            await unityOfWork.SaveAllAsync();
            return set;
        }

        public async Task<IEnumerable<SushiSet>> GetAllAsync()
        {
            return await unityOfWork.SushiSetRepository.ListAllAsync();
        }

        public async Task<SushiSet> GetByIdAsync(int id)
        {
            return await unityOfWork.SushiSetRepository.GetByIdAsync(id);
        }

        public async Task<SushiSet> UpdateAsync(SushiSet entity)
        {
            await unityOfWork.SushiSetRepository.UpdateAsync(entity);
            await unityOfWork.SaveAllAsync();
            return entity;
        }

    }
}
