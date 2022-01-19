using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_exeptions
{
    class Program
    {
        static void Main(string[] args)
        {
            int create, menu, cont;
            Money money = new Money();
            Console.WriteLine("Create a bank account:");
            do
            {
                Console.WriteLine("1 - Enter copecks");
                Console.WriteLine("2 - Enter hryvnia and copecks");
                create = Int32.Parse(Console.ReadLine());
                Console.Clear();
            } while (create != 1 && create != 2);
            switch (create)
            {
                case 1:
                    Console.WriteLine("Enter copecks:");
                    int copecks = Int32.Parse(Console.ReadLine());
                    money = new Money(copecks);
                    break;
                case 2:
                    Console.WriteLine("Enter hryvnia:");
                    int hryvnia = Int32.Parse(Console.ReadLine());
                    Console.WriteLine("copecks:");
                    int cop = Int32.Parse(Console.ReadLine());
                    money = new Money(hryvnia, cop);
                    break;
            }
            Console.Clear();
            try
            {
                do
                {
                    Console.WriteLine("Enter action number:");
                    do
                    {
                        Console.WriteLine("1 - View balance");
                        Console.WriteLine("2 - Top up your account");
                        Console.WriteLine("3 - Withdraw money");
                        menu = Int32.Parse(Console.ReadLine());
                        Console.Clear();
                    } while (menu < 1 || menu > 3);
                    switch (menu)
                    {
                        case 1:
                            Console.WriteLine("Your balance:");
                            Console.WriteLine(money);
                            break;
                        case 2:
                            int wayTopUp;
                            do
                            {
                                Console.WriteLine("Choose a way:");
                                Console.WriteLine("1 - add");
                                Console.WriteLine("2 - multiply");
                                wayTopUp = Int32.Parse(Console.ReadLine());
                                Console.Clear();
                            } while (wayTopUp != 1 && wayTopUp != 2);
                            switch (wayTopUp)
                            {
                                case 1:
                                    Console.WriteLine("Enter the number of copecks you want to add:");
                                    int copecks = Int32.Parse(Console.ReadLine());
                                    money += copecks;
                                    break;
                                case 2:
                                    Console.WriteLine("Enter the number by which you want to multiply the money:");
                                    int c = Int32.Parse(Console.ReadLine());
                                    money *= c;
                                    break;
                            }
                            Console.WriteLine("Balance changed successfully!");
                            break;
                        case 3:
                            int wayWithdraw;
                            do
                            {
                                Console.WriteLine("Choose a way:");
                                Console.WriteLine("1 - subtraction");
                                Console.WriteLine("2 - division");
                                wayWithdraw = Int32.Parse(Console.ReadLine());
                                Console.Clear();
                            } while (wayWithdraw != 1 && wayWithdraw != 2);
                            switch (wayWithdraw)
                            {
                                case 1:
                                    Console.WriteLine("Enter the number of cents you want to subtract:");
                                    int copecks = Int32.Parse(Console.ReadLine());
                                    money -= copecks;
                                    break;
                                case 2:
                                    Console.WriteLine("Enter the number by which you want to divide the money:");
                                    int c = Int32.Parse(Console.ReadLine());
                                    money /= c;
                                    break;
                            }
                            Console.WriteLine("Balance changed successfully!");
                            break;
                    }
                    Console.WriteLine();
                    Console.WriteLine("Enter 1 to continue:");
                    cont = Int32.Parse(Console.ReadLine());
                    Console.Clear();
                } while (cont == 1);
            }
            catch (Bankrupt e)
            {
                Console.WriteLine(e.Message);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }    
    }
}
