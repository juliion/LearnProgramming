using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_interfaces
{
    public abstract class Food : Product
    {
        public KindFood Kind { get; set; }
        public int Energy { get; set; }
        protected Food(string name, string brand, int price, KindFood kind, int energy) : base(name, brand, price)
        {
            Kind = kind;
            Energy = energy;
        }

        public override void printInfo()
        {
            base.printInfo();
            Console.Write("Kind: ");
            switch (Kind)
            {
                case KindFood.dairy:
                    Console.WriteLine("dairy");
                    break;
                case KindFood.alcohol:
                    Console.WriteLine("alcohol");
                    break;
            }
            Console.WriteLine("Energy: " + Energy);
        }
    }
}
