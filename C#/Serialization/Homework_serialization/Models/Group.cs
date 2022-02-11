using System;
using System.Collections.Generic;

namespace Homework_serialization.Models
{
    [Serializable]
    public class Group
    {
        public string Name { get; set; }
        public int Course { get; set; }
        public List<Student> Students { get; set; }
        public Group(string name, int course)
        {
            Name = name;
            Course = course;
            Students = new List<Student>();
        }
        public Group(string name, int course, List<Student> students)
        {
            Name = name;
            Course = course;
            Students = students;
        }
        public void AddStudent(Student s)
        {
            Students.Add(s);
        }
        public void RemoveStudent(Student s)
        {
            Students.Remove(s);
        }
        public override string ToString()
        {
            string res = $"{Name} \n   Курс: {Course}\n   Студенты:\n";
            int count = 1;
            foreach (var student in Students)
            {
                res += $"\t {count}) {student} \n";
                count++;
            }
            return res;
        }
    }
}
