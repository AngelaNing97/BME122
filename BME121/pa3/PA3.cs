using System;
using static System.Console;
using System.IO;
using System.Linq;

namespace Bme121.Pa3
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
    
    static partial class Program
    {
        static void Main( )
        {
            string inputFile  = @"21_training.csv";
            string outputFile = @"21_training_edges.csv";
            int height;  // image height (number of rows)
            int width;  // image width (number of columns)
            Color[ , ] inImage;
            Color[ , ] outImage;

            
            // Read the input image from its csv file.
            FileStream inFile = new FileStream(inputFile, FileMode.Open, FileAccess.Read);
			StreamReader inStream = new StreamReader(inFile);
            
            height= int.Parse(inStream.ReadLine());
            width=int.Parse(inStream.ReadLine());
            inImage=new Color [height,width];
            
            int row;
            int col;
            
            for(row=0;row<height;row++)
            {
                    string line=inStream.ReadLine();
                    
                    //split each line aroung ","
                    string []components=line.Split(',');
                    
                for(col=0;col<width;col++)
                {
                    int alpha,red,green,blue;

                   
                    
                    //converet the string array into int array
                    alpha=int.Parse(components[4*col]);
                    red=int.Parse(components[4*col+1]);
                    green=int.Parse(components[4*col+2]);
                    blue=int.Parse(components[4*col+3]);
                    
                    //initialize the color objects;
                    //put them into 2D array;
                    Color c =Color.FromArgb(alpha,red,green,blue);
                    inImage[row,col]=c;
                }
            }
                inStream.Dispose();
                inFile.Dispose();
                
                outImage=new Color[height,width];
                // outImage=inImage;
                for(row=0;row<height;row++)
                {
                    for(col=0;col<width;col++)
                    {
                        //discard edges
                        if(row==0||row==height-1||col==0||col==(width)-1) outImage[row,col]=inImage[row,col];
                        
                        // Generate the output image using Kirsch edge detection.
                        else{
                            outImage[row,col]=GetKirschEdgeValue(inImage[row-1,col-1],inImage[row-1,col],inImage[row-1,col+1],
                                                                    inImage[row,col-1],  inImage[row,col],  inImage[row,col+1],
                                                                    inImage[row+1,col-1],inImage[row+1,col],inImage[row+1,col+1]);
                            }
                    }
                }
          
            
           
            // Write the output image to its csv file.
            FileStream outFile = new FileStream(outputFile,FileMode.Open, FileAccess.Write);
            StreamWriter outStream = new StreamWriter(outFile);
            
            for(int i=0;i<height;i++)
            {
                string [] words = new string[width];
                
                for(int j=0;j<width;j++)
                {
                    string alpha=Convert.ToString(outImage[i,j].A);
                    string red=Convert.ToString(outImage[i,j].R);
                    string green=Convert.ToString(outImage[i,j].G);
                    string blue=Convert.ToString(outImage[i,j].B);
                    
                    words[j] = alpha + "," + red + "," + green + "," + blue;
                    
                }
                
               // outStream.WriteLine( string.Join(",", words) );
                Console.WriteLine(string.Join(",", words));
            }
            outStream.Dispose();
            outFile.Dispose();
            
            
        }
    
        // This method computes the Kirsch edge-detection value for pixel color
        // at the centre location given the centre-location pixel color and the
        // colors of its eight neighbours.  These are numbered as follows.
        // The resulting color has the same alpha as the centre pixel, 
        // and Kirsch edge-detection intensities which are computed separately
        // for each of the red, green, and blue components using its eight neighbours.
        // c1 c2 c3
        // c4    c5
        // c6 c7 c8
       private static Color GetKirschEdgeValue( 
            Color c1, Color c2,     Color c3, 
            Color c4, Color centre, Color c5, 
            Color c6, Color c7,     Color c8 )
        {
            //the alpha for centre
            int alphaCentre=centre.A;
            
            //the the intensity of each color for the nine objects using properties
            int r1=c1.R;
            int b1=c1.B;
            int g1=c1.G;
            
            int r2=c2.R;
            int b2=c2.B;
            int g2=c2.G;
            
            int r3=c3.R;
            int b3=c3.B;
            int g3=c3.G;
                        
            int r4=c4.R;
            int b4=c4.B;
            int g4=c4.G;
        
            int r5=c5.R;
            int b5=c5.B;
            int g5=c5.G;
            
            int r6=c6.R;
            int b6=c6.B;
            int g6=c6.G;
            
            int r7=c7.R;
            int b7=c7.B;
            int g7=c7.G;
            
            int r8=c8.R;
            int b8=c8.B;
            int g8=c8.G;
            
            int redCentre=GetKirschEdgeValue(r1,r2,r3,r4,r5,r6,r6,r8);
            int greenCentre=GetKirschEdgeValue(g1,g2,g3,g4,g5,g6,g7,g8);
            int blueCentre=GetKirschEdgeValue(b1,b2,b3,b4,b5,b6,b7,b8);

            Color newCentre=Color.FromArgb(alphaCentre,redCentre,greenCentre,blueCentre);
            return newCentre;
        }
        
        // This method computes the Kirsch edge-detection value for pixel intensity
        // at the centre location given the pixel intensities of the eight neighbours.
        // These are numbered as follows.
        // i1 i2 i3
        // i4    i5
        // i6 i7 i8
        static int GetKirschEdgeValue( 
            int i1, int i2, int i3, 
            int i4,         int i5, 
            int i6, int i7, int i8 )
        {
            int []operators =new int [8];
            operators[0]=i1*5+i2*5+i3*5+i4*-3+i5*-3+i6*-3+i7*-3+i8*-3;
            operators[1]=i2*5+i3*5+i5*5+i4*-3+i1*-3+i6*-3+i7*-3+i8*-3;
            operators[2]=i1*-3+i2*-3+i3*5+i4*-3+i5*5+i6*-3+i7*-3+i8*5;
            operators[3]=i1*-3+i2*-3+i3*-3+i4*-3+i5*5+i6*-3+i7*5+i8*5;
            operators[4]=i1*-3+i2*-3+i3*-3+i4*-3+i5*-3+i6*5+i7*5+i8*5;
            operators[5]=i1*-3+i2*-3+i3*-3+i4*5+i5*-3+i6*5+i7*5+i8*-3;
            operators[6]=i1*5+i2*-3+i3*-3+i4*5+i5*-3+i6*5+i7*-3+i8*-3;
            operators[7]=i1*5+i2*5+i3*-3+i4*5+i5*-3+i6*-3+i7*-3+i8*-3;
            
            int max= operators.Max();
            if(max<0) max=0;
            if(max>255) max=255;
            
            return max;
        }
    }
    
    // Implementation of part of System.Drawing.Color.
    // This is needed because .Net Core doesn't seem to include the assembly 
    // containing System.Drawing.Color even though docs.microsoft.com claims 
    // it is part of the .Net Core API.
    struct Color
    {
        int alpha;
        int red;
        int green;
        int blue;
        
        public int A { get { return alpha; } }
        public int R { get { return red;   } }
        public int G { get { return green; } }
        public int B { get { return blue;  } }
        
        public static Color FromArgb( int alpha, int red, int green, int blue )
        {
            Color result = new Color( );
            result.alpha = alpha;
            result.red   = red;
            result.green = green;
            result.blue  = blue;
            return result;
        }
    }
}

