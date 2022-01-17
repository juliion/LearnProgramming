using System;
using System.Collections;
using System.Collections.Generic;

namespace Homework_generics
{
    public class MyList<T> : IEnumerable<T> 
    {
        public Node<T> Head { get; private set; }
        public Node<T> Tail { get; private set; }
        public int Count { get; private set; }

        public void AddLast(T val)
        {
            var tmp = new Node<T>() { Data = val };
            if (Count == 0)
                Head = Tail = tmp;
            else
            {
                Tail.Next = tmp;
                tmp.Prev = Tail;
                Tail = tmp;
            }

            Count++;
        }
        public void AddFirst(T val)
        {
            var tmp = new Node<T>() { Data = val };
            tmp.Next = Head;

            if (Count != 0)
                Head.Prev = tmp;

            if (Count == 0)
                Head = Tail = tmp;
            else
                Head = tmp;

            Count++;
        }
        public void InsertAt(T val, int ind)
        {
            if (ind == Count + 1)
                AddLast(val);
            else if (ind == 0)
                AddFirst(val);
            else
            {
                int i = 0;
                var ins = Head;
                while (i < ind)
                {
                    ins = ins.Next;
                    i++;
                }
                var prevIns = ins.Prev;
                var tmp = new Node<T>() { Data = val };
                if (prevIns != null && Count != 1)
                    prevIns.Next = tmp;
                tmp.Next = ins;
                tmp.Prev = prevIns;
                ins.Prev = tmp;

                Count++;
            }
        }
        public void InsertRangeAt(T[] arr, int ind)
        {
            foreach (T item in arr)
            {
                InsertAt(item, ind);
                ind++;
            }
        }
        public void RemoveFirst()
        {
            if (Count != 0)
            {
                Head = Head.Next;
                Count--;
                if (Count == 0)
                    Tail = null;
                else
                    Head.Prev = null;
            }
            Count--;
        }
        public void RemoveLast()
        {
            if (Count == 1)
                Head = Tail = null;
            else
            {
                Tail.Prev.Next = null;
                Tail = Tail.Prev;
            }
            Count--;
        }
        public void RemoveAt(int ind)
        {
            if (ind == 0)
                RemoveFirst();
            else if (ind == Count - 1)
                RemoveLast();
            else
            {
                Node<T> current = Head;
                for (int i = 0; i < ind - 1; i++)
                {
                    current = current.Next;
                }
                current.Next = current.Next.Next;
                Count--;
            }
        }
        public void RemoveRangeAt(int ind, int count)
        {
            for (int i = 0; i < count; i++)
                RemoveAt(ind);
        }

        public void PrintForward()
        {
            var cur = Head;
            while (cur != null)
            {
                Console.Write($"{cur.Data} ");
                cur = cur.Next;
            }

            Console.WriteLine();
        }

        public IEnumerator<T> GetEnumerator()
        {
            var cur = Head;
            while (cur != null)
            {
                yield return cur.Data;
                cur = cur.Next;
            }

        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}
