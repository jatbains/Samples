using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animals
{
    public interface IHabitat
    {
        void SetLocation(string place);
        string WhereitLives();
    }
}
