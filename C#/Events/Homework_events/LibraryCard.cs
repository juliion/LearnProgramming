using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace Homework_events
{
    public class LibraryCard : INotifyPropertyChanged
    {
        Book _book;
        Client _client;
        DateTime _date;
        public Book Book
        {
            get => _book;
            set
            {
                _book = value;
                OnPropertyChanged("Book");
            }
        }
        public Client Client
        {
            get => _client;
            set
            {
                _client = value;
                OnPropertyChanged("Client");
            }
        }
        public DateTime Date
        {
            get => _date;
            set
            {
                _date = value;
                OnPropertyChanged("Date");
            }
        }

        public LibraryCard(Book book, Client client, DateTime date)
        {
            Book = book;
            Client = client;
            Date = date;
        }

        public override string ToString()
        {
            return $"Book: {Book} \n Client: {Client} \n Date: {Date}";
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged([CallerMemberName] string prop = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
        }
    }
}
