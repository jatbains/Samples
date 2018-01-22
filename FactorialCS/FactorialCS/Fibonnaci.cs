using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FactorialCS
{
    public class Fibonnaci
    {
        public int FibonnaciCalc(int n)
        {
            if (n <= 1)
                return n;

            return (FibonnaciCalc(n - 1) + FibonnaciCalc(n - 2));
        }

    }
    
    

}
