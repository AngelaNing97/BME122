using System;
using static System.Console;

namespace Bme121.Wa2
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
            string numberOrConstant, numberOrConstant2;
            double firstNumber, secondNumber;
            string operation;
            
            WriteLine();
            //title of calculator
            WriteLine("Simple Calculator");
            WriteLine();
            
            //prompt user to enter a number
            Write("Enter a number or constant [e pi]: ");
            numberOrConstant = ReadLine();

            //identify the type of number/constant
            if(numberOrConstant == "e") firstNumber = Math.E;
            else if(numberOrConstant == "pi") firstNumber = Math.PI;
            else firstNumber = double.Parse(numberOrConstant);
            
            //prompt user to enter an operation
            WriteLine();
            Write("Enter an operator(from the set + - * / % cos log sqrt): ");
            operation = ReadLine();
            
            WriteLine();
            //if the operation is not binary, then display the answer
            if(operation == "log" || operation == "cos" || operation == "sqrt")
            {
                if(operation == "log") WriteLine("Your result is {0}", Math.Log(firstNumber));
                else if(operation == "cos") WriteLine ("Your result is {0}", Math.Cos(firstNumber));
                else if(operation == "sqrt") WriteLine ("Your result is {0}", Math.Sqrt(firstNumber));
            }
            //if the operation is binary, then prompt user to enter another number/constant
            else
            {
                Write("Enter a second number or constant[e pi]: ");
                numberOrConstant2 = ReadLine();
                
                if(numberOrConstant2 == "e") secondNumber = Math.E;
                else if (numberOrConstant2 == "pi") secondNumber = Math.PI;
                else secondNumber = double.Parse(numberOrConstant2);
                
                WriteLine(); 
                //display answer
                if(operation=="+") WriteLine("Your result is {0}", firstNumber + secondNumber);
                else if(operation=="-") WriteLine("Your result is {0}", firstNumber - secondNumber);
                else if(operation=="*") WriteLine("Your result is {0}", firstNumber * secondNumber);
                else if(operation=="/") WriteLine("Your result is {0}", firstNumber/secondNumber);
                else if(operation=="%") WriteLine("Your result is {0}", firstNumber % secondNumber);
            } 
            
           
        }
    }
}
