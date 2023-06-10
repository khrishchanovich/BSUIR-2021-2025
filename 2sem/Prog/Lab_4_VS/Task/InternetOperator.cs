using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task
{
    public class InternetOperator
    {
        private static InternetOperator instance;
        private Tariff tariffUSE;
        private string nameOperator;
        private int numberUser;
        private double tariffCommon;
        private InternetOperator() // КОНСТРУКТОР ПРИВАТНЫЙ!!!
        { }

        public string GetName()
        {
            return nameOperator;
        }

        public int GetNumberUser()
        {
            return numberUser;
        }

        public double GetCommonTariff()
        {
            return tariffCommon;
        }

        public void TariffUpOperator(double up)
        {
            tariffUSE.TariffUp(up);
        }

        public void TariffDownOperator(double down)
        {
            tariffUSE.TariffDown(down);
        }

        public double GetTotalGain()
        {
            return tariffUSE.CurrentTariff() * (numberUser - tariffCommon);
        }

        public static InternetOperator GetInstance() // без создания объекта, так как конструктор приватный (см. вверх!)
        {
            if (instance == null)
                instance = new InternetOperator();

            return instance;
        }
    }
}
