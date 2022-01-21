using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_inheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            Transport[] transports ={
                new CargoPlane("White", "An-225", "1989.08.08", 88, 640000),
                new PassengerPlane("Grey", "Airbus A380", "2007.10.17", 79, 525),
                new Train("Blue", "DR1", "2011.10.12", 7),
                new Truck("Green", "MAZ-5440", "2014.05.05", 10, 400, 100, 6065, 25000),
                new Car("Black", "Audi A5", "2007.09.09", 4, 265, 250, 5)
            };
            foreach (Transport tr in transports)
            {
                tr.Move();
                tr.printInfo();
                Console.WriteLine("------------------------------");
            }
        }
    }
}
