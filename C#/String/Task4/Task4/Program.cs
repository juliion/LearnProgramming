using System;

namespace Task4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter string: ");
            string str = Console.ReadLine();
            string[] words = str.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int ind = 0;
            string[] newWords = new string[0];
            foreach (string word in words)
            {
                string newWord = word;
                foreach (char ch in newWord)
                {
                    if (CountLetter(word, ch) > 1)
                        newWord = RemoveAllNextLetters(newWord, ch);
                }
                Array.Resize(ref newWords, newWords.Length + 1);
                newWords[ind] = newWord;
                ind++;
            }
            string newStr = string.Join(" ", newWords);
            Console.WriteLine("New string: " + newStr);
        }
        static int CountLetter(string str, char l)
        {
            int count = 0;
            foreach (char ch in str)
            {
                if (ch == l)
                    count++;
            }
            return count;
        }
        static string RemoveAllNextLetters(string str, char l)
        {
            int indFirst = str.IndexOf(l);
            int ind = str.IndexOf(l, indFirst + 1);
            while ((ind = str.IndexOf(l, indFirst + 1)) != -1)
                str = str.Remove(ind, 1);
            return str;
        }
    }
}
