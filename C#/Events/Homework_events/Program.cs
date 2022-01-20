using System;
using System.ComponentModel;

namespace Homework_events
{
    class Program
    {
        public static void Test(object sender, PropertyChangedEventArgs e)
        {
            Console.WriteLine($"Changed property {e.PropertyName}");
        }
        static void Main(string[] args)
        {
            Author a1 = new Author("Erich", "Remarque", "Germany");
            a1.PropertyChanged += Test;
            a1.Name = "Erich Maria";
        }
    }
}
