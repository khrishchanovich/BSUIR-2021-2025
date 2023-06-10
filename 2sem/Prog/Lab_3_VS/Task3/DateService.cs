using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task3
{
    class DateService
    {

        public string GetDay(string date_)
        {

            string str_year = date_;
            str_year = str_year.Remove(0, 6);

            while (str_year[0] == '0')
            {
                str_year = str_year.Remove(0, 1);
            }

            string str_month = date_;
            str_month = str_month.Remove(0, 3);
            str_month = str_month.Remove(2, 5);

            if (str_month[0] == '0')
            {
                str_month = str_month.Remove(0, 1);
            }

            string str_day = date_;
            str_day = str_day.Remove(2, 8);

            if (str_day[0] == '0')
            {
                str_day = str_day.Remove(0, 1);
            }

            int year = Int32.Parse(str_year);

            int month = Int32.Parse(str_month);

            int day = Int32.Parse(str_day);

            DateTime date = new DateTime(year, month, day);

            int day_ = (int)date.DayOfWeek;

            string DayOfWeek = string.Empty;

            switch (day_)
            {
                case 1:
                    DayOfWeek = "Monday"; break;
                case 2:
                    DayOfWeek = "Tuesday"; break;
                case 3:
                    DayOfWeek = "Wednesday"; break;
                case 4:
                    DayOfWeek = "Thursday"; break;
                case 5:
                    DayOfWeek = "Friday"; break;
                case 6:
                    DayOfWeek = "Saturday"; break;
                case 7:
                    DayOfWeek = "Sunday"; break;
            }

            return DayOfWeek;
        }

        public int GetDaySpan(string lhs_date, string rhs_date)
        {
            string lhs_str_year = lhs_date;
            lhs_str_year = lhs_str_year.Remove(0, 6);


            while (lhs_str_year[0] == '0')
            {
                lhs_str_year = lhs_str_year.Remove(0, 1);
            }

            string lhs_str_month = lhs_date;
            lhs_str_month = lhs_str_month.Remove(0, 3);
            lhs_str_month = lhs_str_month.Remove(2, 5);

            if (lhs_str_month[0] == '0')
            {
                lhs_str_month = lhs_str_month.Remove(0, 1);
            }

            string lhs_str_day = lhs_date;
            lhs_str_day = lhs_str_day.Remove(2, 8);

            if (lhs_str_day[0] == '0')
            {
                lhs_str_day = lhs_str_day.Remove(0, 1);
            }

            int lhs_year = Int32.Parse(lhs_str_year);

            int lhs_month = Int32.Parse(lhs_str_month);

            int lhs_day = Int32.Parse(lhs_str_day);

            string rhs_str_year = rhs_date;
            rhs_str_year = rhs_str_year.Remove(0, 6);


            while (rhs_str_year[0] == '0')
            {
                rhs_str_year = rhs_str_year.Remove(0, 1);
            }

            string rhs_str_month = rhs_date;
            rhs_str_month = rhs_str_month.Remove(0, 3);
            rhs_str_month = rhs_str_month.Remove(2, 5);

            if (rhs_str_month[0] == '0')
            {
                rhs_str_month = rhs_str_month.Remove(0, 1);
            }

            string rhs_str_day = rhs_date;
            rhs_str_day = rhs_str_day.Remove(2, 8);

            if (rhs_str_day[0] == '0')
            {
                rhs_str_day = rhs_str_day.Remove(0, 1);
            }

            int rhs_year = Int32.Parse(rhs_str_year);

            int rhs_month = Int32.Parse(rhs_str_month);

            int rhs_day = Int32.Parse(rhs_str_day);

            DateTime start = new DateTime(lhs_year, lhs_month, lhs_day);
            DateTime end = new DateTime(rhs_year, rhs_month, rhs_day);


            return (int)(end - start).TotalDays;
        }
    }
}
