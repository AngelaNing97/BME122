using System;
using static System.Console;

namespace Bme121.Wa3
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
            //display all numbers under 1000 cents
            //n/100 to display answer in dollars
            for(long n=0;n<1000;n++) 
            {
                WriteLine("{0}: ",n/100.0);
                
            //nested for-loop to calculate solutions
            //n>=a>=b>=c>=d
            //a+b+c=d=n
                for(long a=0; a<=n; a++)
                {
                    for(long b=0;b<=a;b++)
                    {
                        for(long c=0;c<=b;c++)
                        {
                            long d=n-a-b-c;
                            if(a*b*c*d==n*100*100*100 && d<=c)
                            {
                                WriteLine("  {0} {1} {2} {3}", a/100.0, b/100.0,c/100.0,d/100.0);
                            }
                        }
                    }
                 }
            
            }
        }

    }
}
