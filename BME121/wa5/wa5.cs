using System;
using System.IO;

namespace Bme121.Wa5
{
    /// <StudentPlan>Biomedical Engineering</StudentPlan>
    /// <StudentDept>Department of Systems Design Engineering</StudentDept>
    /// <StudentInst>University of Waterloo</StudentInst>
    /// <StudentName>Ning, Hui Yi</StudentName>
    /// <StudentUserID>hy3ning</StudentUserID>
    /// <StudentAcknowledgements>
    /// I declare that, except as acknowledged below, this is my original work.
    /// Acknowledged contributions of others:
    /// </StudentAcknowledgements>


    public class Program
    {
		// use an array of counters
		static int[] wordCount = new int[25];
		// count of words of length 1 are stored at index 0
		// count of words of length 2 are stored at index 1 ...
		
		
        public static void Main(string[] args)
        {
            FileStream inFile = new FileStream(@"wa5.txt", FileMode.Open, FileAccess.Read);
			StreamReader inStream = new StreamReader(inFile);
			
			// store each line that is read
			string line = "";
			
			// skip lines until we read the starting line
			while(line != "THE CANTERVILLE GHOST")
			{
				line = inStream.ReadLine();
			}
			
			// loop until we read the ending line
			while(line != "Virginia blushed.")
			{
				// process the first and each intermediate line
				ProcessLine(line);
				line = inStream.ReadLine();
			}
			
			// process the very last line
			ProcessLine(line);
			
            //display final results
			for(int i=0;i<25;i++)
            {
                Console.WriteLine("number of words of length {0}:{1}",i+1,wordCount[i]);
            }
        }
		
		static void ProcessLine(string line)
		{
			// split the line into words
            char[]delimiter={' ','-'};
            string []words = line.Split(delimiter);
			
			// loop over the words
            for(int i=0;i<words.Length;i++)
            {
                // trim each word
                char[]cc={',','.','?','!',';',':','[',']','(',')','|','_','+','-','"','\''};
                words[i]=words[i].Trim(cc);
                
                // increase counter based on word length
                int wordLength=words[i].Length;
                for(int j=1;j<=25;j++)
                {
                    if(wordLength==j) wordCount[j-1]++;
                }
            }
				

				

				
				
		}
    }
}
