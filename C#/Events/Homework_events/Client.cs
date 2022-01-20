using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace Homework_events
{
    public class Client : INotifyPropertyChanged
    {
        string _name;
        string _surname;
        DateTime _birthday;
        string _phNum;
        public string Name
        {
            get => _name;
            set
            {
                _name = value;
                OnPropertyChanged("Name");
            }
        }
        public string Surname
        {
            get => _surname;
            set
            {
                _surname = value;
                OnPropertyChanged("Surname");
            }
        }
        public DateTime Birthday
        {
            get => _birthday;
            set
            {
                _birthday = value;
                OnPropertyChanged("Birthday");
            }
        }
        public string PhNum
        {
            get => _phNum;
            set
            {
                _phNum = value;
                OnPropertyChanged("PhNum");
            }
        }

        public Client(string name, string surname, DateTime birthday, string phNum)
        {
            Name = name;
            Surname = surname;
            Birthday = birthday;
            PhNum = phNum;
        }

        public override string ToString()
        {
            return $"{Surname} {Name} \n Birthday:{Birthday} \n Phone number{PhNum}";
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged([CallerMemberName] string prop = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
        }
    }
}
