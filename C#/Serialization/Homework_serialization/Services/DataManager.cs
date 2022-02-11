using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using Homework_serialization.Models;

namespace Homework_serialization.Services
{
    public static class DataManager
    {
        public static void SaveDate(string path, Faculty faculty)
        {
            BinaryFormatter bf = new BinaryFormatter();
            using (FileStream fs = new FileStream(path, FileMode.OpenOrCreate, FileAccess.Write))
                bf.Serialize(fs, faculty);
            Console.WriteLine("Данные успешно сохранены!");
        }

        public static Faculty LoadData(string path)
        {
            BinaryFormatter bf = new BinaryFormatter();
            Faculty res;
            using (FileStream fs = new FileStream(path, FileMode.Open, FileAccess.Read))
                res = (Faculty)bf.Deserialize(fs);
            Console.WriteLine("Данные успешно загружены!");
            return res;
        }
    }
}
