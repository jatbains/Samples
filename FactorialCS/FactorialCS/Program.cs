using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace FactorialCS
{
    class FibFact
    {
        static FibFact()
        {
            FibFact mprog = new FibFact();
            fib = new Fibonnaci();
            fac = new Factorial();
        }
        static void Main(string[] args)
        {
            ArrayList alist = new ArrayList();
        
            alist.Add("Ben");
            alist.Add("George");

            string name = "Jim Bains";
            name.ToLower();

            StringBuilder nString = new StringBuilder("Hello ");
            Console.WriteLine(nString.Append(" Again"));
            Console.WriteLine(nString);
            Console.WriteLine(name.ToLower() + " " + name.ToUpper());
            Console.WriteLine(name.Contains("Jim"));
            // Doubly linked list
            LinkedList<string> mlist = new LinkedList<string>();
            string[] slist = mlist.ToArray();
            

            foreach (var item in alist)
            {
                Console.WriteLine(item);
            }
            
            string file = "myfile.txt";
            FileIo getFile = new FileIo(0,file);
            
            Console.WriteLine("Hello to C#");

            getFile.GetAFile(file);

            int[] nums = new int[10];
            int len = nums.Length;

            foreach (int row in nums)
            {
                Console.WriteLine(row);
            }
   

            Console.WriteLine(fac.FactorialCal(10));

            Console.WriteLine(fib.FibonnaciCalc(10));

          

            Random r = new Random();
            double v = r.NextDouble();

            Console.WriteLine("Random number is " + v);

            Console.Read();

        }

        public static Fibonnaci fib;
        public static Factorial fac;

    }
}
