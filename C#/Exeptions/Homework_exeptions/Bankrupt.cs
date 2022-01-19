using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_exeptions
{

    [Serializable]
    public class Bankrupt : Exception
    {
        public Bankrupt() : this("You are bankrupt") { }
        public Bankrupt(string message) : base(message) { }
        public Bankrupt(string message, Exception inner) : base(message, inner) { }
        protected Bankrupt(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
