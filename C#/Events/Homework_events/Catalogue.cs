using System.Collections;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace Homework_events
{
    public class Catalogue : IEnumerable, INotifyPropertyChanged
    {
        Book[] _books;
        public Book[] Books
        {
            get => _books;
            set
            {
                _books = value;
                OnPropertyChanged("Books");
            }
        }

        public Catalogue(Book[] books)
        {
            Books = books;
        }
        public IEnumerator GetEnumerator() => Books.GetEnumerator();

        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged([CallerMemberName] string prop = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
        }
    }
}
