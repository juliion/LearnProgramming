using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_inheritance
{
    public class Car : Auto
    {
        public int NumberOfSeats { get; set; }
        public Car(string color, string model, string prodYear, int numberOfWheels, int power, int speed, int numberOfSeats) : base(color, model, prodYear, numberOfWheels, power, speed)
        {
            NumberOfSeats = numberOfSeats;
        }
        public override void Move()
        {
            Console.WriteLine("Car is driving");
        }
        public override void printInfo()
        {
            base.printInfo();
            Console.WriteLine($"Number of seats: {NumberOfSeats}");
        }
    }
}
