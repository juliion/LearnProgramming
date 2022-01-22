using System;

namespace Task5
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
                for (int i = 0; i < newWord.Length; i++)
                {
                    char ch = newWord[i];
                    int lastInd = newWord.LastIndexOf(ch);
                    if (CountLetter(word, ch) > 1 && i == lastInd)
                    {
                        newWord = newWord.Remove(lastInd, 1);
                        i--;
                    }
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
    }
}
