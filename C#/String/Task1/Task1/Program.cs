using System;

namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter string: ");
            string str = Console.ReadLine();
            PrintInfo(str);
        }
        static int CountAny(string characters, string str)
        {
            int count = 0;
            foreach (char chStr in str)
            {
                foreach (char ch in characters)
                {
                    if (chStr == ch)
                        count++;
                }
            }
            return count;
        }
        static int CountLetters(string str)
        {
            int count = 0;
            foreach (char chStr in str)
            {
                if (char.IsLetter(chStr))
                    count++;
            }
            return count;
        }

        static void PrintInfo(string str)
        {
            Console.WriteLine("----------------------------");
            Console.WriteLine("Total сharacters: " + str.Length);
            Console.WriteLine("Spaces: " + CountAny(" ", str));
            Console.WriteLine("Digits: " + CountAny("0123456789", str));
            Console.WriteLine("Punctuation marks: " + CountAny(",.!?-:", str));
            Console.WriteLine("Letters: " + CountLetters(str));
            Console.WriteLine("----------------------------");
        }
    }
}
