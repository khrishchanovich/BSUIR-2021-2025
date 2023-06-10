using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    class Deposit
    {
        private int sum;
        private int percent;

        public Deposit()
        {
            sum = 0;
            percent = 0;
        }
        public Deposit(int value, int percent)
        {
            sum = value;
            this.percent = percent;
        }
        public int Sum()
        {
            return sum;
        }

        public int setPercent(int sum_)
        {
            this.sum = sum_ * percent / 100;
            return sum;
        }
        public void IncDeposit(int value)
        {
            setPercent(sum += value);
        }
    };
}
