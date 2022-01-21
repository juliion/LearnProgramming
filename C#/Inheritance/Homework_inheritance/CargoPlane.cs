using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_inheritance
{
    public class CargoPlane : Airplane
    {
        public int Weight { get; set; }
        public CargoPlane(string color, string model, string prodYear, int wingLength, int weight) : base(color, model, prodYear, wingLength)
        {
            Weight = weight;
        }
        public override void Move()
        {
            Console.WriteLine("Cargo plane is flying");
        }
        public override void printInfo()
        {
            base.printInfo();
            Console.WriteLine($"Weight: {Weight}");
        }
    }
}
