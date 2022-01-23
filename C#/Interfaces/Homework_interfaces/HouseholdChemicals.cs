using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_interfaces
{
    public abstract class HouseholdChemicals : Product
    {
        public TypeHouseholdChemcs Type { get; set; }
        protected HouseholdChemicals(string name, string brand, int price, TypeHouseholdChemcs type) : base(name, brand, price)
        {
            Type = type;
        }

        public override void printInfo()
        {
            base.printInfo();
            Console.Write("Type: ");
            switch (Type)
            {
                case TypeHouseholdChemcs.cleaners:
                    Console.WriteLine("cleaners");
                    break;
                case TypeHouseholdChemcs.paintsAndVarnishes:
                    Console.WriteLine("paints and varnishes");
                    break;
            }
        }
    }
}
