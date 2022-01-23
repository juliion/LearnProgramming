using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_interfaces
{
    public class Milk : Food, IPerishable
    {
        public float Fat { get; set; }
        public float Volume { get; set; }
        public DateTime ExpirationDate { get; set; }

        public bool IsSpoiled => ExpirationDate > DateTime.Today;

        public int MaxTemp { get; set;  }

        public Milk(string name, string brand, int price, int energy, float fat, float volume, DateTime expirationDate, int maxTemp) : base(name, brand, price, KindFood.dairy, energy)
        {
            Fat = fat;
            Volume = volume;
            ExpirationDate = expirationDate;
            MaxTemp = maxTemp;
        }

        public override void printInfo()
        {
            base.printInfo();
            Console.WriteLine("Fat: " + Fat);
            Console.WriteLine("Volume: " + Volume);
            if(IsSpoiled)
                Console.WriteLine("!!!Spoiled!!!");
        }

        public bool canSpoil(int currentTemp)
        {
            return currentTemp > MaxTemp;
        }
    }
}
