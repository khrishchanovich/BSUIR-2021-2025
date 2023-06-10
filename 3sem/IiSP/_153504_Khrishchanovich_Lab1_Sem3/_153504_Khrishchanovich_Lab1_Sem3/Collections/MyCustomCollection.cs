using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153504_Khrishchanovich_Lab1_Sem3.Iterfaces;


namespace _153504_Khrishchanovich_Lab1_Sem3.Collections
{
    internal class MyCustomCollection<T> : List<T>, ICustomCollection<T>, IEnumerable<T>
    {
        new T this[int index]
        {
            get
            {
                if (index < 0 || index >= base.Count)
                    throw new IndexOutOfRangeException();

                return base[index];
            }
            set
            {
                base[index] = value;
            }
        }

        public void Reset()
        {
            base.GetEnumerator();
        }
        public void Next()
        {
            base.GetEnumerator().MoveNext();
        }
        public T Current()
        {
            return base.GetEnumerator().Current;
        }
        public new int Count
        {
            get
            {
                return base.Count;
            }
        }
        public new void Add(T item)
        {
            base.Add(item);
        }
        public new void Remove(T item)
        {
            if (!base.Contains(item))
                throw new Exception("Объект не найден");

            base.Remove(item);
        }
        public T RemoveCurrent()
        {
            T current = Current();
            base.Remove(current);
            return current;
        }
    }
}
