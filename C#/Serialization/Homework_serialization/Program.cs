using System;
using System.Collections.Generic;
using Homework_serialization.Models;
using Homework_serialization.Services;

namespace Homework_serialization
{
    public class Program
    {
        static void Main(string[] args)
        {
            Student s1 = new Student("Иван", "Иванов", 2);
            Student s2 = new Student("Алиса", "Алисова", 5);
            Student s3 = new Student("Мария", "Марченко", 4);
            Student s4 = new Student("Валерий", "Соколов", 1);
            Student s5 = new Student("Дмитрий", "Дмитров", 5);
            Group gr1 = new Group("Гр-01", 1, new List<Student>(new Student[]{ s1, s2 }));
            Group gr2 = new Group("Гр-12", 2, new List<Student>(new Student[] { s3, s4 }));
            Group gr3 = new Group("Гр-23", 3);
            gr3.AddStudent(s5);
            Faculty f1 = new Faculty("Информатика", 12333, new List<Group>(new Group[] { gr1, gr2 }));
            f1.AddGroup(gr3);
            Console.WriteLine("f1:");
            Console.WriteLine("======================================");
            Console.WriteLine(f1);
            Console.WriteLine("======================================");
            Console.WriteLine();

            string fpath = @"../../../Data/faculty.dat";
            DataManager.SaveDate(fpath, f1);
            Faculty f1_copy = DataManager.LoadData(fpath);

            Console.WriteLine("\nf1_copy:");
            Console.WriteLine("======================================");
            Console.WriteLine(f1_copy);
            Console.WriteLine("======================================");

        }
    }
}
