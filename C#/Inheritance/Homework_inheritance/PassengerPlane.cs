using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_inheritance
{
    public class PassengerPlane : Airplane
    {
        public int NumberOfSeats { get; set; }
        public PassengerPlane(string color, string model, string prodYear, int wingLength, int numberOfSeats) : base(color, model, prodYear, wingLength)
        {
            NumberOfSeats = numberOfSeats;
        }
        public override void Move()
        {
            Console.WriteLine("Passenger plane is flying");
        }
        public override void printInfo()
        {
            base.printInfo();
            Console.WriteLine($"Number of seats: {NumberOfSeats}");
        }
    }
}
