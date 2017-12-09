using System;
using static System.Console;

namespace Bme121.WA1
{
    /// <StudentPlan>Biomedical Engineering</StudentPlan>
    /// <StudentDept>Department of Systems Design Engineering</StudentDept>
    /// <StudentInst>University of Waterloo</StudentInst>
    /// <StudentName>Ning, Huiyi</StudentName>
    /// <StudentUserID>Hy3ning</StudentUserID>
    /// <StudentAcknowledgements>
    /// I declare that, except as acknowledged below, this is my original work.
    /// Acknowledged contributions of others:
    /// </StudentAcknowledgements>
    
    static partial class Program
    {
        static void Main( )
        {
            //three variables that store the three words
            //entered by user
            string first;
            string second;
            string third;
            
            //start of program
            WriteLine("WA1 words program");
            WriteLine();
            
            //prompt user to enter three words
            Write("Enter a word [1 of 3]: ");
            first = ReadLine();
            
            Write("Enter a word [2 of 3]: ");
            second = ReadLine();
            
            Write ("Enter a word [3 of 3]: ");
            third = ReadLine();
            
            //second part of program
            WriteLine();
            WriteLine("Here are you words in order as entered.");
            WriteLine("word1: " + first);
            WriteLine("word2: " + second);
            WriteLine("word3: " + third);
            
            //line the words up
            WriteLine();
            WriteLine("Here are your words in order on one line comma separated.");
            WriteLine("words: {0}, {1}, {2}", first, second, third);
            
            //reverse order and upper case
            WriteLine();
            WriteLine("Here are your words in reverse order and upper case");
            WriteLine("word3: " + third.ToUpper());
            WriteLine("word2: " + second.ToUpper());
            WriteLine("word1: " + first.ToUpper());
            //end of program
        }
    }
}
