using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_interfaces
{
    public class Decommissioned : Warehouse
    {
        public Decommissioned() : base()
        {
        }

        public Decommissioned(Product[] products) : base(products)
        {
        }

        public override void PrintProducts()
        {
            Console.WriteLine("Decommissioned products:");
            Console.WriteLine("======================================");
            base.PrintProducts();
        }
    }
}
