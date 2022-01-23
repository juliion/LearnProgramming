using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_interfaces
{
    public interface IPerishable
    {
        DateTime ExpirationDate { get; set; }
        bool IsSpoiled { get; }
        int MaxTemp { get; set; }
        bool canSpoil(int currentTemp);
    }
}
