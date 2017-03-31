using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Renamer
{
    class DirHandler
    {
        public string[] pathList;
        public string extensions { get; set;}
        public string path { get; set; }

        public DirHandler()
        {
            this.extensions = "*.*";
            this.path = @"C:\";
        }

        public void findPath()
        {
            pathList = Directory.GetFiles(this.path, this.extensions);
        }

        public void findPath(string _path, string _ext)
        {
            pathList = Directory.GetFiles(@_path, _ext);
        }

        public void findPath(string _path)
        {
            pathList = Directory.GetFiles(@_path, this.extensions);           
        }
    }
}
