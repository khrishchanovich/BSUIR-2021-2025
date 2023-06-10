using System.Collections.Generic;

namespace _153504_Khrishchanovich_Lab5.Domain
{
    public interface ISerializer
    {
        IEnumerable<Airport> DeSerializeByLINQ(string fileName);
        IEnumerable<Airport> DeSerializeXML(string fileName);
        IEnumerable<Airport> DeSerializeJSON(string fileName);
        void SerializeByLINQ(IEnumerable<Airport> CCC, string fileName);
        void SerializeXML(IEnumerable<Airport> CCC, string fileName);
        void SerializeJSON(IEnumerable<Airport> CCC, string fileName);
    }
}
