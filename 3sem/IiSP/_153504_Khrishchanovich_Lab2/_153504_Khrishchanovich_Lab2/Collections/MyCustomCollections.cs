using _153504_Khrishchanovich_Lab2.Exceptions;
using _153504_Khrishchanovich_Lab2.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Khrishchanovich_Lab2.Collections
{
    public class MyCustomCollection<T> : List<T>, ICustomCollection<T>
    {
        public new T this[int index]
        {
            get
            {
                if (index >= Count)
                {
                    throw new IndexOutOfRangeException();
                }
                return base[index];
            }
            set
            {
                if (index >= Count)
                {
                    throw new IndexOutOfRangeException();
                }
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
            {
                throw new MyException("Object item is not in the collection");

            }
            else base.Remove(item);
        }
        public T RemoveCurrent()
        {
            T current = Current();
            base.Remove(current);
            return current;
        }

    }
}
