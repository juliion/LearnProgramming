using System;

namespace Homework_serialization.Models
{
    [Serializable]
    public class Student
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        public int Rating { get; set; }
        public Student(string name, string surname, int rating)
        {
            Name = name;
            Surname = surname;
            Rating = rating;
        }

        public override string ToString()
        {
            return $"{Surname} {Name}, Рейтинг: {Rating}";
        }
    }
}
