using System;

namespace Task2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter string: ");
            string str = Console.ReadLine();
            Console.Write("Enter character: ");
            char ch = char.Parse(Console.ReadLine());
            int ind = str.LastIndexOf(ch);
            string newStr = str.Replace(ch, char.ToUpper(ch)).Substring(0, ind);
            Console.WriteLine(newStr);
        }
    }
}
