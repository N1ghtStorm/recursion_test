using System;
using System.Diagnostics;

namespace csharptest
{
    class Program
    {
        static void Main(string[] args)
        {
            var sw1 = new Stopwatch();
            sw1.Start();
            some_1(0);
            sw1.Stop();
            Console.WriteLine(sw1.ElapsedTicks);
            var sw2 = new Stopwatch();
            sw2.Start();
            var a = 0;
            some_2(ref a);
            sw2.Stop();
            Console.WriteLine(sw2.ElapsedTicks);
        }

        static void some_1(int a)
        {
            if (a >= 15000)
            {
                return;
            }
            a++;
            some_1(a);
        }

        static void some_2(ref int a)
        {
            if (a >= 15000)
            {
                return;
            }
            a++;
            some_2(ref a);
        }
    }
}
