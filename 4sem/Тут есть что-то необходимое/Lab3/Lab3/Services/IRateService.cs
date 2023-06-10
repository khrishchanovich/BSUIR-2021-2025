using Lab3.Entities;

public interface IRateService
{
    public Task<IEnumerable<Rate>> GetRates(DateTime date);
}

