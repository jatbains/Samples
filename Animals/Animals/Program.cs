using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace Animals
{
    class Program
    {
        enum Fruit
        {
            APPLE,
            BANANA,
            PEAR,
            ORANGE
        }
        static void Main(string[] args)
        {
            Dictionary<Fruit, string> myFruits = new Dictionary<Fruit, string>();

            myFruits.Add(Fruit.APPLE, "Apple");
            myFruits.Add(Fruit.BANANA, "Banana");
            myFruits.Add(Fruit.ORANGE, "Orange");
            myFruits.Add(Fruit.PEAR, "Pear");

            Queue<string> myQueue = new Queue<string>();
            Stack<Cat> stCats = new Stack<Cat>();
            Cat temp = stCats.Peek();
            Console.WriteLine(temp.WhereitLives());
            Stack<int> intStack = new Stack<int>();

            Console.WriteLine(myFruits.TryGetValue(Fruit.ORANGE,out string fruit));
            Console.WriteLine(fruit);

            
            foreach (Fruit x in myFruits.Keys)
            {
                myFruits.TryGetValue(x, out string fruits);
                Console.WriteLine(fruits);
                //Console.WriteLine(x.ToString());
            }
             
            Dictionary<int,Cat> myCats = new Dictionary<int, Cat>();

            
            Cat myCat = new Cat("Tabby", "Meow", "Ball");
            Cat JoeCat = new Cat("Blackie", "Blah", "Chew");
            Cat BillCat = new Cat("Brownie", "Growl", "Tire");

            myCats.Add(1, myCat);
            myCats.Add(2, JoeCat);
            myCats.Add(3, BillCat);
            myCats.TryGetValue(2, value: out Cat uCat);

            // Compare the two
            Console.WriteLine(uCat.GetName());
            uCat.WalksAround();

            Animals myAnimal = myCat;

            Console.WriteLine(myAnimal.WhereitLives());            

            myCat.WalksAround();
            

            myAnimal.WalksAround();

            Console.WriteLine(myAnimal.GetType());

            Console.WriteLine(myAnimal.GetHashCode());

            Console.WriteLine(myCat.WhereitLives());

            Console.ReadLine();
        }
    }
}
