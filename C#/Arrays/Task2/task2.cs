using System;

namespace Task2
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
            int min = -10, max = 10;
            for (int i = 0; i < arr.Length; i++)
                arr[i] = rnd.Next(min, max);
            Console.WriteLine("Before:");
            printArray(arr);

            int[] positiveElem = new int[0];
            int[] negativeElem = new int[0];
            int i1 = 0, i2 = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                if(arr[i] >= 0)
                {
                    Array.Resize(ref positiveElem, positiveElem.Length + 1);
                    positiveElem[i1] = arr[i];
                    i1++;
                }   
                else
                {
                    Array.Resize(ref negativeElem, negativeElem.Length + 1);
                    negativeElem[i2] = arr[i];
                    i2++;
                }
            }
            int j1 = 0, j2 = 0; 
            for (int i = 0; i < arr.Length; i++)
            {
                if(j2 < negativeElem.Length)
                {
                    arr[i] = negativeElem[j2];
                    j2++;
                }
                else
                {
                    arr[i] = positiveElem[j1];
                    j1++;
                }
            }

            Console.WriteLine("After:");
            printArray(arr);
        }
    }
}
