using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task
{
    class Tariff
    {
        private double tariff = 45.6;

        private Tariff()
        { }

        public double CurrentTariff()
        {
            return tariff;
        }

        public void TariffUp(double up)
        {
            tariff += up;
        }

        public void TariffDown(double down)
        {
            tariff -= down;
        }

        private Tariff(double tariff)
        {
            this.tariff = tariff;
        }
    }
}
