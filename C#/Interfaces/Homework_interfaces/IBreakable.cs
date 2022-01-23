using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_interfaces
{
    public interface IBreakable
    {
        bool IsBroken { get; set; }
        void Broke();
    }
}
