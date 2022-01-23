using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_interfaces
{
    public class Incoming : Warehouse
    {
        public Incoming() : base()
        {
        }

        public Incoming(Product[] products) : base(products)
        {
        }

        public override void PrintProducts()
        {
            Console.WriteLine("Incoming products:");
            Console.WriteLine("======================================");
            base.PrintProducts();
        }
    }
}
