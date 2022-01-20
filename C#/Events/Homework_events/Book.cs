namespace Homework_events
{
    public class Book
    {
        public string Title { get; set; }
        public Author Author { get; set; }
        public int Year { get; set; }

        public Book(string title, Author author, int year)
        {
            Title = title;
            Author = author;
            Year = year;
        }

        public override string ToString()
        {
            return $"Title: {Title} \n Author: {Author} \n Year: {Year}";
        }
    }
}
