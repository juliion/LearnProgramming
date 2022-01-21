using System;

namespace Task3
{
    class Program
    {
        static void printMatrix(int[,] arr)
        {
            Console.Write("   ");
            for (int i = 0; i < arr.GetLength(1); i++)
                Console.Write(i + " ");
            Console.WriteLine();
            Console.Write("   ");
            for (int i = 0; i < arr.GetLength(1); i++)
                Console.Write("--");
            Console.WriteLine();
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                Console.Write(i + "| ");
                for (int j = 0; j < arr.GetLength(1); j++)
                    Console.Write(arr[i, j] + " ");
                Console.WriteLine();
            }
        }
        static void Main(string[] args)
        {
            Console.Write("Enter number of rows: ");
            int row = Int32.Parse(Console.ReadLine());
            Console.Write("Enter number of columns: ");
            int col = Int32.Parse(Console.ReadLine());
            int[,] arr = new int[row, col];

            Random rnd = new Random();
            int min = 0, max = 10;
            for (int i = 0; i < arr.GetLength(0); i++)
                for (int j = 0; j < arr.GetLength(1); j++)
                    arr[i, j] = rnd.Next(min, max);
            Console.WriteLine("Before: ");
            printMatrix(arr);
            Console.WriteLine();
            Console.Write("Enter first column number: ");
            int c1 = Int32.Parse(Console.ReadLine());
            Console.Write("Second: ");
            int c2 = Int32.Parse(Console.ReadLine());
            Console.WriteLine();
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                int temp = arr[i, c1];
                arr[i, c1] = arr[i, c2];
                arr[i, c2] = temp;
            }
            Console.WriteLine("After: ");
            printMatrix(arr);
        }
    }
}
