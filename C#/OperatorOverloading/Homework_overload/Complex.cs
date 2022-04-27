using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_overload
{
    class Complex
    {
        public double A { get; set; }
        public double B { get; set; }
        public Complex(double a, double b)
        {
            A = a;
            B = b;
        }
        public static bool operator ==(Complex c1, Complex c2)
        {
            return (c1.A == c2.A) && (c1.B == c2.B);
        }
        public static bool operator !=(Complex c1, Complex c2)
        {
            return (c1.A != c2.A) || (c1.B != c2.B);
        }
        public static Complex operator +(Complex c1, Complex c2)
        {
            return new Complex(c1.A + c2.A, c1.B + c2.B);
        }
        public static Complex operator +(Complex c, int n)
        {
            return c + new Complex(n, 0);
        }
        public static Complex operator +(int n, Complex c)
        {
            return new Complex(n, 0) + c;
        }
        public static Complex operator -(Complex c1, Complex c2)
        {
            return new Complex(c1.A - c2.A, c1.B - c2.B);
        }
        public static Complex operator -(Complex c, int n)
        {
            return c - new Complex(n, 0);
        }
        public static Complex operator -(int n, Complex c)
        {
            return new Complex(n, 0) - c;
        }
        public static Complex operator *(Complex c1, Complex c2)
        {
            return new Complex(c1.A * c2.A - c1.B * c2.B, c1.B * c2.A + c1.A * c2.B);
        }
        public static Complex operator *(Complex c, int n)
        {
            return c * new Complex(n, 0);
        }
        public static Complex operator *(int n, Complex c)
        {
            return new Complex(n, 0) * c;
        }
        public static Complex operator /(Complex c1, Complex c2)
        {
            return new Complex((c1.A * c2.A + c1.B * c2.B)/(c2.A * c2.A + c2.B * c2.B), (c1.B * c2.A - c1.A * c2.B) / (c2.A * c2.A + c2.B * c2.B));
        }
        public static Complex operator /(Complex c, int n)
        {
            return c / new Complex(n, 0);
        }
        public static Complex operator /(int n, Complex c)
        {
            return new Complex(n, 0) / c;
        }
        public override string ToString()
        {
            string str = $"{A}";
            if (B > 0)
                str += "+";
            if(B != 0)
                str += $"{B}i";
            return str;
        }
    }
}
