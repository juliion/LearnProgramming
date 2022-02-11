using System;
using System.Collections.Generic;

namespace Homework_serialization.Models
{
    [Serializable]
    public class Faculty
    {
        public string Name { get; set; }
        public int Financing { get; set; }
        public List<Group> Groups { get; set; }
        public Faculty(string name, int financing)
        {
            Name = name;
            Financing = financing;
            Groups = new List<Group>();
        }

        public Faculty(string name, int financing, List<Group> groups)
        {
            Name = name;
            Financing = financing;
            Groups = groups;
        }
        public void AddGroup(Group s)
        {
            Groups.Add(s);
        }
        public void RemoveGroup(Group s)
        {
            Groups.Remove(s);
        }
        public override string ToString()
        {
            string res = $"Факультет: {Name} \nФонд: {Financing}\nГруппы:\n";
            foreach (var group in Groups)
                res += $" - {group} \n";
            return res;
        }
    }
}
