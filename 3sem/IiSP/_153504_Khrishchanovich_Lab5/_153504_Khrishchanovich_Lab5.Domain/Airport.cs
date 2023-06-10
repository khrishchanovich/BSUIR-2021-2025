using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khrishchanovich_Lab5.Domain
{
    [Serializable]
    public class Airport
    {
        public string AirportName { get; set; }
        public List<Runway> Runways { get; init; }
        public Airport() { }
        public Airport(string airportName, IEnumerable<Runway> runways)
        {
            Runways = new List<Runway>();
            AirportName = airportName;
            foreach (var runway in runways)
            {
                Runways.Add(runway);
            }
        }
        public void AddRunway(string runwayName, int runwayLenght)
        {
            Runways.Add(new Runway(runwayName, runwayLenght));
        }
        public void GetAirportDescription()
        {
            Console.WriteLine($"Airport name:{AirportName}");
            foreach (Runway r in Runways)
            {
                Console.WriteLine(r.ToString());
            }
        }
    }
}
