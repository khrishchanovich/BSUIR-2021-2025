using System;
using System.Xml.Serialization;
using System.Xml.Linq;
using System.Text.Json;
using System.Linq;
using System.IO;
using _153504_Khrishchanovich_Lab5.Domain;
using System.Collections.Generic;



namespace Serializer
{
    public class MySerializer : ISerializer
    {
        public void SerializeXML(IEnumerable<Airport> MyAirports, string fileName)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<Airport>));
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                xmlSerializer.Serialize(fs, MyAirports);
            }
        }
        public IEnumerable<Airport> DeSerializeXML(string fileName)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<Airport>));
            IEnumerable<Airport>? MyAirports;
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                MyAirports = xmlSerializer.Deserialize(fs) as IEnumerable<Airport>;
            }
            return MyAirports;
        }
        public void SerializeJSON(IEnumerable<Airport> MyAirports, string fileName)
        {

            File.WriteAllText(fileName, JsonSerializer.Serialize(MyAirports));

        }
        public IEnumerable<Airport> DeSerializeJSON(string fileName)
        {
            return JsonSerializer.Deserialize<IEnumerable<Airport>>(File.ReadAllText(fileName));

        }
        public void SerializeByLINQ(IEnumerable<Airport> MyAirports, string fileName)
        {
            XDocument xdoc = new XDocument();

            var xAirports = new XElement("Airports");


            foreach (var airport in MyAirports)
            {
                var xAirport = new XElement("Airport");
                xAirport.Add(new XAttribute("name", airport.AirportName));

                foreach (var runway in airport.Runways)
                {
                    xAirport.Add(new XElement("Runway",
                        new XAttribute("name", runway.Name),
                        new XAttribute("length", runway.Length)));
                }

                xAirports.Add(xAirport);
            }
            xdoc.Add(xAirports);
            xdoc.Save(fileName);
        }
        public IEnumerable<Airport> DeSerializeByLINQ(string fileName)
        {
            XDocument xdoc = XDocument.Load(fileName);

            var airports = xdoc.Element("Airports")?.Elements("Airport")
                .Select(a => new Airport(a.Attribute("name")?.Value.ToString(), a.Elements("Runway")
                                               .Select(r => new Runway(r.Attribute("name")?.Value.ToString(),
                                               Convert.ToInt32(r.Attribute("length")?.Value)))));

            return airports;
        }
    }
}
