using System;

namespace Task1
{
    class Program
    {
        static void printArray(int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
                Console.Write(arr[i] + " ");
            Console.WriteLine();
        }

        static void Main(string[] args)
        {
            Console.Write("Enter array size: ");
            int size = Int32.Parse(Console.ReadLine());
            int[] arr = new int[size];

            Random rnd = new Random();
            int min = 0, max = 3;
            for (int i = 0; i < arr.Length; i++)
                arr[i] = rnd.Next(min, max);
            Console.WriteLine("Before:");
            printArray(arr);

            int indZero = Array.IndexOf(arr, 0);
            while(indZero != -1)
            {
                for (int i = indZero; i < arr.Length - 1; i++)
                    arr[i] = arr[i + 1];
                arr[arr.Length - 1] = -1;
                indZero = Array.IndexOf(arr, 0);
            }

            Console.WriteLine("After:");
            printArray(arr);

        }
    }
}
