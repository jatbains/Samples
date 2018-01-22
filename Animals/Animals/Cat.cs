using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animals
{
    public class Cat : Animals
    {

        public string favtoy = "Ball";
        

        public Cat(string name,string noise,string toy) : base (name,noise)
        {
            this.favtoy = toy;

        }

        public override void WalksAround()
        {
            Console.WriteLine(this.GetName() + " Stalks around");
        }

        public new string WhereitLives()
        {
            return "Home";
        }
    }
}
