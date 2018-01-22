using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StructuresCSharp
{
    class LNode
    {
        public int val;
        public LNode next;
    }
    class TNode
    {
        public int val;
        public TNode left;
        public TNode right;
    }
    class Program
    {

        static void Main(string[] args)
        {
            Program myProgram = new Program();

            myProgram.CreateList();
            
            Console.Out.WriteLine();
            myProgram.CreateTree();
            Console.ReadLine();
        }

        public void CreateList()
        {
            LNode head = null;
            int[] data = { 4, 8, 12, 1, 15, 5, 10 };
            int size = data.Length;

            for (int i=0; i<size;i++)
            {
                head = InsertLNode(head, data[i]);
            }

            PrintList(head);


        }

        void PrintList(LNode head)
        {
            LNode temp = head;
            while (temp != null)
            {
                Console.Out.Write(temp.val + " ");
                temp = temp.next;
            }
        }
        LNode InsertLNode(LNode head,int x)
        {
            if (head == null)
            {
                head = AllocLNode(x);
                return head;
            }
            LNode temp = head;
            while (temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = AllocLNode(x);
            return head;
        }
        LNode AllocLNode(int x)
        {
            LNode temp = new LNode();
            temp.val = x;
            temp.next = null;
            return temp;
        }
        void CreateTree()
        {
            TNode root = null;
            int[] data = { 4, 8, 12, 1, 15, 5, 10 };
            int size = data.Length;

            for (int i = 0; i < size; i++)
            {
                root = InsertTNode(root, data[i]);
            }

            PrintTree(root);

            Console.ReadLine();

        }
        TNode AllocTNode(int x)
        {
            TNode temp = new TNode();
            temp.val = x;
            temp.left = temp.right = null;
            return temp;
        }
        TNode InsertTNode(TNode node, int x)
        {
            if (node == null)
            {
                node = AllocTNode(x);
                return node;
            }
            if (x < node.val)
            {
                node.left = InsertTNode(node.left, x);
            }
            else
            {
                node.right = InsertTNode(node.right, x);
            }
            return node;
        }
        void PrintTree(TNode node)
        {
            if (node == null)
            {
                return;
            }
            PrintTree(node.left);
            Console.Out.Write(node.val + " ");
            PrintTree(node.right);
        }
    }
}
