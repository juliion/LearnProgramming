using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_inheritance
{
    public class Train : Transport
    {
        public int NumberOfCarriage { get; set; }
        public Train(string color, string model, string prodYear, int numberOfCarriage) : base(color, model, prodYear)
        {
            NumberOfCarriage = numberOfCarriage;
        }
        public override void Move()
        {
            Console.WriteLine("Train rides on the rails");
        }
        public override void printInfo()
        {
            base.printInfo();
            Console.WriteLine($"Number of carriage: {NumberOfCarriage}");
        }
    }
}
