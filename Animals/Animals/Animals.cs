using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animals
{
    public class Animals : IHabitat
    {
        private string name = "Monster";
        private string noise = "Growl";
        private string location = "Jungle";
      
        public int Age { get; set; }

        public void SetLocation(string place)
        {
            this.location = place;
        }
        public string WhereitLives()
        {
            return location;
        }
        public Animals() { }
        public Animals(string name, string noise)
        {
            this.name = name;
            this.noise = noise;
        }

        protected void ChangeName(string newName)
        {
            this.name = newName;
        }

        public string GetName()
        {
            return name;
        }
        public virtual void WalksAround()
        {
            Console.WriteLine(this.name + " Walks");
        }

        void IHabitat.SetLocation(string place)
        {
            throw new NotImplementedException();
        }

        string IHabitat.WhereitLives()
        {
            throw new NotImplementedException();
        }
    }
}
