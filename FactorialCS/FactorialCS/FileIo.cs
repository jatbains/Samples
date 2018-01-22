using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FactorialCS
{
    class FileIo
    {
        public int FileSize { get; set; }
        public string MyFile { get; set; }

        public FileIo(int fSize, string fname)
        {
            FileSize = fSize;
            MyFile = fname;
        }

        public void GetAFile(string fileName)
        {
            this.MyFile = fileName;
            int size = 200;
            this.FileSize = size;

            Console.WriteLine("File size is " + FileSize);
            try
            {
                File.Open(fileName, FileMode.Create);
            }
            catch (FileNotFoundException ex)
            {
                Console.WriteLine("Error is " + ex.ToString());
            }
            catch (Exception e)
            {
                throw e;
                // Cleanup
            }
        }

    }
    
    
}
