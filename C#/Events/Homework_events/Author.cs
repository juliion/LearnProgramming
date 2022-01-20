using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace Homework_events
{
    public class Author : INotifyPropertyChanged
    {
        string _name;
        string _surname;
        string _country;
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
        public string Сountry
        {
            get => _country;
            set
            {
                _country = value;
                OnPropertyChanged("Сountry");
            }
        }

        public Author(string name, string surname, string сountry)
        {
            Name = name;
            Surname = surname;
            Сountry = сountry;
        }

        public override string ToString()
        {
            return $"{Surname} {Name} \n Country: {Сountry}";
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged([CallerMemberName] string prop = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
        }
    }
}
