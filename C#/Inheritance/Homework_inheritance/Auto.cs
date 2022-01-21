using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_inheritance
{
    public abstract class Auto : Transport
    {
        public int NumberOfWheels { get; set; }
        public int Power { get; set; }
        public int Speed { get; set; }
        protected Auto(string color, string model, string prodYear, int numberOfWheels, int power, int speed) : base(color, model, prodYear)
        {
            NumberOfWheels = numberOfWheels;
            Power = power;
            Speed = speed;
        }
        public override void printInfo()
        {
            base.printInfo();
            Console.WriteLine($"Number of wheels: {NumberOfWheels}");
            Console.WriteLine($"Power: {Power}");
            Console.WriteLine($"Speed: {Speed}");
        }
    }
}
