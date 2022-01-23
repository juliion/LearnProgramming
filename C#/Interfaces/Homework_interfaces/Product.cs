using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_interfaces
{
    public abstract class Product
    {
        public string Name { get; set; }
        public string Brand { get; set; }
        public int Price { get; set; }
        protected Product(string name, string brand, int price)
        {
            Name = name;
            Brand = brand;
            Price = price;
        }
        public virtual void printInfo()
        {
            Console.WriteLine("Name: " + Name);
            Console.WriteLine("Brand: " + Brand);
            Console.WriteLine("Price: " + Price);
        }
    }
}
