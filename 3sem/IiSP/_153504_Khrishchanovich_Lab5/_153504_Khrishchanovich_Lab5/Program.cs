using System;
using Serializer;
using _153504_Khrishchanovich_Lab5.Domain;
using System.Collections.Generic;

namespace _153504_Khrishchanovich_Lab5
{
    [Serializable]
    class Program
    {
        static void Main(string[] args)
        {
            List<Runway> runway1 = new List<Runway>();
            runway1.Add(new Runway("Runway1", 100));
            runway1.Add(new Runway("Runway2", 200));
            List<Runway> runway2 = new List<Runway>();
            runway2.Add(new Runway("Runway3", 300));
            runway2.Add(new Runway("Runway4", 400));

            Airport airport1 = new Airport("Airport1", runway1);
            Airport airport2 = new Airport("Airport2", runway2);
            Airport airport3 = new Airport("Airport3", runway2);
            Airport airport4 = new Airport("Airport4", runway1);

            List<Airport> airports = new List<Airport>();
            airports.Add(airport1);
            airports.Add(airport2);
            airports.Add(airport3);
            airports.Add(airport4);

            foreach (Airport airport in airports)
            {
                airport.GetAirportDescription();
            }

            string fileName = "airportsXML.xml";
            MySerializer serializer = new MySerializer();
            serializer.SerializeXML(airports, fileName);
            Console.WriteLine("\nСollection of airports(XML)");
            IEnumerable<Airport> airportsXML = serializer.DeSerializeXML(fileName);
            foreach (Airport airport in airportsXML)
            {
                airport.GetAirportDescription();
            }

            fileName = "airportsJSON.json";
            serializer.SerializeJSON(airports, fileName);
            Console.WriteLine("\nСollection of airports(JSON)");
            IEnumerable<Airport> airportJSON = serializer.DeSerializeJSON(fileName);
            foreach (Airport airport in airportJSON)
            {
                airport.GetAirportDescription();
            }

            fileName = "airportsLINQ.json";
            serializer.SerializeByLINQ(airports, fileName);
            Console.WriteLine("\nСollection of airports(LINQ-to-XML)");
            IEnumerable<Airport> airportLINQ = serializer.DeSerializeByLINQ(fileName);
            foreach (Airport airport in airportLINQ) \
            {
                airport.GetAirportDescription();
            }
        }
    }
}
