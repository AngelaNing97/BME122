using System;
using static System.Console;

namespace Bme121.Wa4
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

            //save a dice roll for each player
            Dice player1Dice = new Dice( );
            Dice player2Dice = new Dice( );
            
            WriteLine("");

            //dispaly player 1 dice and the calculated results
            Write("player1, dice = {0}", player1Dice);
            Write(", min = {0}",player1Dice.Min());
            Write(", max = {0}",player1Dice.Max());
            WriteLine(", sum = {0},diff = {1},double:{2}.", player1Dice.Sum(),player1Dice.Diff(),player1Dice.Double());
            WriteLine(" ");
           
           //display player 2 dice and the calculated results
            WriteLine("player2, dice = {0}, min = {1}, max = {2}, sum = {3}, diff = {4}, double:{5}.", player2Dice, player2Dice.Min(),player2Dice.Max(),player2Dice.Sum(),player2Dice.Diff(),player2Dice.Double());
            
            // Report the winner under different criteria.
            
            WriteLine( );
            
            WriteLine( "{0,18}   {1}", "Game", "Winner" );
            
            Write( "{0,18} : ", "Smallest minimum" );
            if(player1Dice.Min()<player2Dice.Min()) WriteLine("player 1");
            else if(player1Dice.Min()>player2Dice.Min()) WriteLine("player 2");
            else WriteLine("tie");
            
            
            Write( "{0,18} : ", "Largest maximum" );
            if(player1Dice.Max()<player2Dice.Max()) WriteLine("player 2");
            else if(player1Dice.Max()>player2Dice.Max()) WriteLine("player 1");
            else WriteLine("tie");
            
            Write( "{0,18} : ", "Largest sum" );
            if(player1Dice.Sum()>player2Dice.Sum()) WriteLine("player 1");
            else if(player1Dice.Sum()<player2Dice.Sum()) WriteLine("player 2");
            else WriteLine("tie");
            
            Write( "{0,18} : ", "Largest difference" );
            if(player1Dice.Diff()>player2Dice.Diff()) WriteLine("player 1");
            else if(player1Dice.Diff()<player2Dice.Diff()) WriteLine("player 2");
            else WriteLine("tie");
            
            Write( "{0,18} : ", "Only double" );
            if(player1Dice.Double()==true && player2Dice.Double()==false) WriteLine("player 1");
            else if(player1Dice.Double()==false && player2Dice.Double()== true) WriteLine("player 2");
            else WriteLine("tie");
            
            WriteLine( );
        }
        
    }
    //create a dice
    //create methods to calculate max,min,sum,diff,double
   class Dice
    {
        int x=0;
        int y=0;
        static Random randomNumberGenerator=new Random();
        public Dice( )
        {   
            x=Dice.randomNumberGenerator.Next(1,7);
            y=Dice.randomNumberGenerator.Next(1,7);

        }
        
        public int Min( )
        {   
            int min;
            if(y>=x) min = this.x; 
            else min = this.y; 
            return min;
        }
        
        public int Max()
        {
            int max;
            if(y>=x) max = y;
            else max = x;
            return max;
        }
        
        public int Sum()
        {
            int sum = y+x;
            return sum;
        }
        
        public int Diff()
        {
            int diff;
            if(y>=x) diff=y-x;
            else diff=x-y;
            return diff;
        }
        
        public bool Double()
        {
            bool isSame;
            if(y==x) isSame=true;
            else isSame=false;
            return isSame;
            
        }
            
        public override string ToString()
        {
            return $"({x},{y})";
        }
        
        
    }

    
}
