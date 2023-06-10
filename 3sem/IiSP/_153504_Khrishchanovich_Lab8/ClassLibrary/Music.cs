using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Library8
{
    [Serializable]
    public class MusicCollection
    {
        public string Singer { get; set; } = "";

        public int Songs { get; set; } = 0;

        public MusicCollection()
        {
        }

        public void LoadSong()
        {
            ++Songs;
        }

        public bool IsEmpty() => Songs == 0;

        public override string ToString()
            => ($"Исполнитель:\t{Singer}\nКоличество песен:\t{Songs}\n");
    }
}
