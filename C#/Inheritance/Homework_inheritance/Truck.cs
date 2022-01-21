using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_inheritance
{
    public class Truck : Auto
    {
        public int Length { get; set; }
        public int Weight { get; set; }
        public Truck(string color, string model, string prodYear, int numberOfWheels, int power, int speed, int length, int weight) : base(color, model, prodYear, numberOfWheels, power, speed)
        {
            Length = length;
            Weight = weight;
        }
        public override void Move()
        {
            Console.WriteLine("Truck is driving");
        }
        public override void printInfo()
        {
            base.printInfo();
            Console.WriteLine($"Length: {Length}");
            Console.WriteLine($"Weight: {Weight}");
        }
    }
}
