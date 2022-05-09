using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CheckIfNumIsPrime
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter number: ");
            int number = int.Parse(Console.ReadLine());
            if(IsPrime(number))
                Console.WriteLine("Number is prime!");
            else
                Console.WriteLine("Number is not prime!");
        }
        public static bool IsPrime(int number)
        {
            if (number <= 1) 
                return false;
            if (number == 2) 
                return true;
            if (number % 2 == 0) 
                return false;

            int border = (int)Math.Floor(Math.Sqrt(number));

            for (int i = 3; i <= border; i += 2)
            {
                if (number % i == 0)
                    return false;
            }

            return true;
        }
    }
}
