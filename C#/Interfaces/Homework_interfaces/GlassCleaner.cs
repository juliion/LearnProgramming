using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_interfaces
{
    public class GlassCleaner : HouseholdChemicals, IFlammable
    {
        public float Volume { get; set; }
        public bool TakeFire { get; set; }

        public GlassCleaner(string name, string brand, int price, float volume) : base(name, brand, price, TypeHouseholdChemcs.cleaners)
        {
            Volume = volume;
            CatchFire();
        }
        public override void printInfo()
        {
            base.printInfo();
            Console.WriteLine("Volume: " + Volume);
            if (TakeFire)
                Console.WriteLine("!!!Take fire!!!");
        }
        public void CatchFire()
        {
            Random rnd = new Random();
            int v = rnd.Next(0, 100);
            if (v < 3)
                TakeFire = true;
            else
                TakeFire = false;
        }
    }
}
