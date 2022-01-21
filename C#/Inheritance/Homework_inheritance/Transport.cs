using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_inheritance
{
    public abstract class Transport
    {
        public string Color { get; set; }
        public string Model { get; set; }
        public DateTime ProdYear { get; set; }
        public Transport(string color, string model, string prodYear)
        {
            Color = color;
            Model = model;
            ProdYear = DateTime.Parse(prodYear);
        }
        public abstract void Move();
        public virtual void printInfo()
        {
            Console.WriteLine($"Color: {Color}");
            Console.WriteLine($"Model: {Model}");
            Console.WriteLine($"Year of production: {ProdYear}");
        }
    }
}
