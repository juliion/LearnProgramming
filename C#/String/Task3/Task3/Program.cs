using System;

namespace Task3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter string: ");
            string str = Console.ReadLine();
            string[] words = str.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            string[] uniqueWords = new string[0];
            int ind = 0;
            foreach (string word in words)
            {
                if (CountWordInStr(str, word) <= 1)
                {
                    Array.Resize(ref uniqueWords, uniqueWords.Length + 1);
                    uniqueWords[ind] = word;
                    ind++;
                }
            }
            string newStr = string.Join(" ", uniqueWords);
            Console.WriteLine(newStr);
        }
        static int CountWordInStr(string str, string word)
        {
            int count = 0;
            string[] words = str.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            foreach (string w in words)
            {
                if (w.Equals(word))
                    count++;
            }
            return count;
        }
    }
}
