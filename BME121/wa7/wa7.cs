using System;
using static System.Console;
using System.IO;
using MediCal;
using System.Collections.Generic;

    /// <StudentPlan>Biomedical Engineering</StudentPlan>
    /// <StudentDept>Department of Systems Design Engineering</StudentDept>
    /// <StudentInst>University of Waterloo</StudentInst>
    /// <StudentName>Ning, Hui Yi</StudentName>
    /// <StudentUserID>hy3ning</StudentUserID>
    /// <StudentAcknowledgements>
    /// I declare that, except as acknowledged below, this is my original work.
    /// Acknowledged contributions of others:
    /// </StudentAcknowledgements>

namespace Bme121.Wa7
{
    static partial class Program
    {
        static void Main( )
        {
            DrugRecords lastYear = new DrugRecords( "RXQT1404.txt", "RXQT1502.txt", "RXQT1502.txt", "RXQT1503.txt" );
            //DrugRecords lastYear = new DrugRecords( "RXQT1503-100.txt" );
            
            int count = 0;
            List<Drug> vitaminList=new List<Drug>();
            foreach( Drug drug in lastYear.DrugList )
            {
                if(drug.Name.Contains("VITAMIN"))
                {
                    count++;
                    vitaminList.Add(drug);
                    WriteLine( $"{count,6:n0} - {drug}" );
                }
            }
            
            //deleted code
            /*Drug [] vitaminDrugs= new Drug [count];
                
            foreach(Drug drug in lastYear.Druglist)
            {
                for(int i=0;i<count;i++)
                {
                    if(drug.Name.Contains("VITAMIN"))
                    {
                        vitaminDrugs[i]=drug;
                        WriteLine( $"{i,6:n0} - {drug}" );
                    }
                }
            }*/
            
        }
    }
}
