using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_interfaces
{
    class Program
    {
        static void Main(string[] args)
        {
            Incoming incP = new Incoming();
            Sold soldP = new Sold();
            Decommissioned decP = new Decommissioned();
            Random rnd = new Random();
            for (int i = 0; i < 5; i++)
            {
                int price = rnd.Next(20, 50);
                int energy = rnd.Next(50, 70);
                float fat = rnd.Next(1, 3);
                float volume = rnd.Next(1, 3);
                DateTime date = new DateTime(rnd.Next(2021, 2023), rnd.Next(1, 13), rnd.Next(1, 29));
                Milk m = new Milk("Milk", "Prostokvashino", price, energy, fat, volume, date, 8);
                incP.Add(m);
                if (m.IsSpoiled)
                    decP.Add(m);
                else
                    soldP.Add(m);
            }
            for (int i = 0; i < 100; i++)
            {
                int price = rnd.Next(70, 150);
                int energy = rnd.Next(80, 100);
                float strength = rnd.Next(6, 12);
                float volume = rnd.Next(1, 2);
                Wine w = new Wine("Red wine", "Villa Krim", price, energy, strength, volume, (float)1.2);
                incP.Add(w);
                if (w.IsBroken || w.TakeFire)
                    decP.Add(w);
                else
                    soldP.Add(w);
            }
            for (int i = 0; i < 5; i++)
            {
                int price = rnd.Next(50, 100);
                float volume = rnd.Next(1, 2);
                GlassCleaner gC = new GlassCleaner("Glass cleaning spray", "Mr. Proper", price, volume);
                incP.Add(gC);
                if(gC.TakeFire)
                    decP.Add(gC);
                else
                    soldP.Add(gC);
            }
            for (int i = 0; i < 10; i++)
            {
                int price = rnd.Next(50, 100);
                float volume = rnd.Next(1, 2);
                SprayPaint sP = new SprayPaint("Spray paint", "New Ton", price, "red", volume);
                incP.Add(sP);
                if (sP.TakeFire)
                    decP.Add(sP);
                else
                    soldP.Add(sP);
            }
            incP.PrintProducts();
            soldP.PrintProducts();
            decP.PrintProducts();

        }
    }
}
