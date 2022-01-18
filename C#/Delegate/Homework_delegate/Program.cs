using System;

namespace Homework_delegate
{
    class Program
    {
        public static T Find<T>(T[] array, Predicate<T> condition)
        {
            foreach (T item in array)
            {
                if (condition(item))
                    return item;
            }
            return default(T);
        }
        static void Main(string[] args)
        {
            int[] arr = new int[10];
            Random rnd = new Random();
            for (int i = 0; i < arr.Length; i++)
                arr[i] = rnd.Next(-20, 20);
            Console.WriteLine("Array: ");
            for (int i = 0; i < arr.Length; i++)
                Console.Write($"{arr[i]} ");
            Console.WriteLine();
            Console.Write($"Result of find element < 0: {Find(arr, (elem) => elem < 0)} ");
            Console.WriteLine();
        }
    }
}
