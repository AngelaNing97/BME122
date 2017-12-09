using System;
using static System.Console;

namespace Bme121.PA1
{
    /// <StudentPlan>Biomedical Engineering</StudentPlan>
    /// <StudentDept>Department of Systems Design Engineering</StudentDept>
    /// <StudentInst>University of Waterloo</StudentInst>
    /// <StudentName>Ning, Hui Yi</StudentName>
    /// <StudentUserID>Hy3ning</StudentUserID>
    /// <StudentAcknowledgements>
    /// I declare that, except as acknowledged below, this is my original work.
    /// Acknowledged contributions of others:
    /// </StudentAcknowledgements>
    
    static partial class Program
    {
        static void Main( )
        {
            //variables
            double density,tension,index,radius,frequency,pressure;

            WriteLine();
            
            //title of program
            WriteLine("Microsphere free resonant frequency calculator");
            WriteLine();
            
            //Prompt user to enter the 5 parameters
            WriteLine("Enter the following five parameters.");
            Write("Ambient plus blood-vessel pressures (Pa): ");
            pressure = double.Parse(ReadLine());
            
            Write("Blood density (kg/m^3): ");
            density = double.Parse(ReadLine());
            
            Write("Blood surface tension(N/m): ");
            tension = double.Parse(ReadLine());
            
            Write("Polytropic index: ");
            index = double.Parse(ReadLine());
            
            Write("Microsphere radius(m): ");
            radius = double.Parse(ReadLine());
            
            //display result
            //f= free resonant frequency
            //call helper method
            frequency = FindingFrequency(pressure,tension,index,radius,density);
            WriteLine();
            WriteLine("Free resonant frequency is {0} Hz", frequency.ToString("0.##e+000"));
            WriteLine();
            
        }
            //helper method, for calculation
            /*the parameter variables in the helper method are different 
              from those in the main method, even though they have the 
              same names*/
    static double FindingFrequency(double pressure,double tension,double index,double radius, double density)
        {
            double piInverse = 1/(2*Math.PI);
            double denominatorInRoot = density* (Math.Pow(radius,2));
            double numeratorInRoot= (3*index*pressure + ((3*index - 1)*2*tension/radius));
            
            double frequency = piInverse*(Math.Sqrt(numeratorInRoot/denominatorInRoot));
            
            return frequency;
        }
    }
}
