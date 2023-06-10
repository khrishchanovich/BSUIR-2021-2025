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
    public class SushiService : ISushiService
    {
        IUnityOfWork unityOfWork;
        public SushiService(IUnityOfWork unitOfWork)
        {
            this.unityOfWork = unitOfWork;
        }
        public async Task<Sushi> AddAsync(Sushi entity)
        {
            await unityOfWork.SushiRepository.AddAsync(entity);
            await unityOfWork.SaveAllAsync();
            return entity;
        }

        public async Task<Sushi> DeleteAsync(int id)
        {
            Sushi sushi = await GetByIdAsync(id);
            await unityOfWork.SushiRepository.DeleteAsync(sushi);
            await unityOfWork.SaveAllAsync();
            return sushi;
        }

        public async Task<IEnumerable<Sushi>> GetAllAsync()
        {
            return await unityOfWork.SushiRepository.ListAllAsync();
        }

        public async Task<IEnumerable<Sushi>> GetAllByRouteAsync(SushiSet set)
        {
            return await unityOfWork.SushiRepository.ListAsync((Sushi s) => s.SushiSet == set);
        }

        public async Task<Sushi> GetByIdAsync(int id)
        {
            return await unityOfWork.SushiRepository.GetByIdAsync(id);
        }

        public async Task<Sushi> UpdateAsync(Sushi entity)
        {
            await unityOfWork.SushiRepository.UpdateAsync(entity);
            await unityOfWork.SaveAllAsync();
            return entity;
        }
    }
}
