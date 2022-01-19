using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_exeptions
{
    public class Money
    {
        private int _copecks;
        public int Hryvnia { get => _copecks / 100; }
        public int Copecks { get => _copecks % 100; }

        public Money()
        {
            _copecks = 0;
        }

        public Money(int copecks)
        {
            _copecks = copecks;
        }
        public Money(int hryvnia, int copecks)
        {
            _copecks = hryvnia * 100 + copecks;
        }
        public static bool operator ==(Money m1, Money m2)
        {
            return m1._copecks == m2._copecks;
        }
        public static bool operator !=(Money m1, Money m2)
        {
            return m1._copecks != m2._copecks;
        }
        public static Money operator +(Money m1, Money m2)
        {
            return new Money(m1._copecks + m2._copecks);
        }
        public static Money operator +(Money m, int c)
        {
            return new Money(m._copecks + c);
        }
        public static Money operator -(Money m1, Money m2)
        {
            int resCop = m1._copecks - m2._copecks;
            if (resCop < 0)
                throw new Bankrupt();
            return new Money(resCop);
        }
        public static Money operator -(Money m, int c)
        {
            int resCop = m._copecks - c;
            if (resCop < 0)
                throw new Bankrupt();
            return new Money(resCop);
        }
        public static Money operator *(Money m, int c)
        {
            if(c < 0)
                throw new Bankrupt();
            return new Money(m._copecks * c);
        }
        public static Money operator /(Money m, int c)
        {
            if (c < 0)
                throw new Bankrupt();
            return new Money(m._copecks / c);
        }
        public static bool operator >(Money m1, Money m2)
        {
            return m1._copecks > m2._copecks;
        }
        public static bool operator <(Money m1, Money m2)
        {
            return m1._copecks < m2._copecks;
        }
        public override string ToString()
        {
            return $"{Hryvnia},{Copecks}";
        }
    }
}
