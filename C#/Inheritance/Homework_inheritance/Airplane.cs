using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_inheritance
{
    public abstract class Airplane : Transport
    {
        public int WingLength { get; set; }
        public Airplane(string color, string model, string prodYear, int wingLength) : base(color, model, prodYear)
        {
            WingLength = wingLength;
        }
        public override void printInfo()
        {
            base.printInfo();
            Console.WriteLine($"Wing length: {WingLength}");
        }
    }
}
