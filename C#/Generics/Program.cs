using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_generics
{
    class Program
    {
        static void Main(string[] args)
        {
            MyList<int> l = new MyList<int>();
            //▪ добавление элемента в конец списка; 
            for (int i = 0; i < 10; i++)
                l.AddLast(i);
            Console.WriteLine("List after adding 10 elements to the end:");
            l.PrintForward();
            Console.WriteLine();
            //▪ добавление элемента в указанную позицию;
            l.InsertAt(500, 5);
            Console.WriteLine("List after insert 500 at index 5:");
            l.PrintForward();
            Console.WriteLine();
            //▪ добавление диапазона элементов в указанную позицию; 
            int[] arr = { 20, 30, 40 };
            l.InsertRangeAt(arr, 2);
            Console.WriteLine("List after adding a range {20, 30, 40} at index 2:");
            l.PrintForward();
            Console.WriteLine();
            //▪ удаление элемента с начала списка; 
            l.RemoveFirst();
            Console.WriteLine("List after remove first element:");
            l.PrintForward();
            Console.WriteLine();
            //▪ удаление элемента из указанной позиции;
            l.RemoveAt(8);
            Console.WriteLine("List after remove element at index 8:");
            l.PrintForward();
            Console.WriteLine();
            //▪ удаление диапазона элементов из указанной позиции; 
            l.RemoveRangeAt(6, 3);
            Console.WriteLine("List after remove 3 element at index 6:");
            l.PrintForward();
            Console.WriteLine();
        }
    }
}
