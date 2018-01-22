using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hello
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter whether windows or linux");

            int t = Console.Read();

            
            switch (t)
            {
                case 'w':
                    Console.WriteLine("Windows PC");
                    break;
                case 'l':
                    Console.WriteLine("Linux PC");
                    break;

                default:
                    Console.WriteLine("Unknown PC");
                    break;

            }

            string platform;
            int i = 0;
            platform = "The platform is " + i;
            for ( i = 0; i <12; i++)
            {
                platform = $"The platform is {i}";
                Console.WriteLine(platform);
            }
            
            Console.WriteLine("Welcome to Windows!");

            Console.ReadLine();
            Console.ReadLine();
        }
    }
}
