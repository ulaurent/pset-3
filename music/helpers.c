// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as /Y to eighths
  int duration(string fraction)
    {
      int X = (int) fraction[0] - '0';
      int Y = (int) fraction[2] - '0';

      int eighths = (8/Y)*X;

      return eighths;
    }

// Calculates frequency (in Hz) of a note
    int frequency(string note)
    {
        double hertz;
        double octave = 0.0;
        double steps = 0.0;
        char letter = note[0];
        char select = '\0';


        //First step find whether it has an accidental
        if (strlen(note) == 3){
            select = note[2];
        }
        else if(strlen(note) < 3){
            select = note[1];
        }


        if(((int)(select-'0')) > 4){
            octave = 440.0 *(((int)(select -'0')-4.0)*2);
            //return octave;
        }
        else if (((int)(select -'0')) < 4 && ((int)(select -'0')) >= 1){
            octave = 440.0*(4 - ((int)(select -'0')) );
            //return octave;
        }
        else if (((int)(select -'0')) == 4){
            octave = 440.0;
            //return octave;
        }


          //octave has been found, it can be either from A1 through A8 or more, just know you are at A

          // Now you have to Figure out what Letter the user inputted, in order to know how many steps you want to move from A

          if (letter == 'B'){
            steps += 2.0;
            //return steps;
          }
          else if (letter == 'G'){
            steps -= 2.0;
            //return steps;
          }
          else if (letter == 'F'){
            steps -= 4.0;
            //return steps;
          }
          else if (letter == 'E'){
            steps -= 5.0;
            //return steps;
          }
          else if (letter == 'D'){
            steps -= 7.0;
            //return steps;
          }
          else if (letter == 'C'){
            steps -= 9.0;
            //return steps;
          }

          // The steps from A to the letter requested has been figured out, Depending on the letter requested
         // Now determine whether it is a flat or sharp

          if(strlen(note) == 3){
            if(note[1]== '#'){
              steps += 1.0;
              //return steps;
            }
            else if (note[1] == 'b'){
              steps -= 1.0;
              //return steps;
            }
          }

        double stepsfixed = (steps/12.0);
        double form = 2.0;
        double expon = pow(form, stepsfixed);

        hertz = octave * expon;
        return hertz;
    }



// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0){
        return true;
    }
    else {
        return false;
    }
    // TODO
}
