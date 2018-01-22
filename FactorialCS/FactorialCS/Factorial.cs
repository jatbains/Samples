using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FactorialCS
{
    public class Factorial
    {
        public int FactorialCal(int n)
        {
            if (n == 0)
                return 1;

            return (n * FactorialCal(n - 1));
        }
    }
}
