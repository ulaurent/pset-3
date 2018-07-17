// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
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
        int hertz;
        int octave = 0;
        int steps = 0;
        char letter = note[0];


            //First step find out what octave
        if(strlen(note) == 3){
          if(((int)(note[2]-'0')) > 4){
            octave = 440 *(((int)(note[2]-'0')-4)*2);
            return octave;
          }
          else if (((int)(note[2]-'0')) < 4 && ((int)(note[2]-'0')) >= 1){
            octave = 440*(4 - ((int)(note[2]-'0')) );
            return octave;
          }
          else if (((int)(note[2]-'0')) == 4){
            octave = 440;
            return octave;
          }
        }
        else if (strlen(note) < 3){
          if(((int)(note[1]-'0')) > 4){
            octave = 440 *(((int)(note[1]-'0')-4)*2);
            return octave;
          }
          else if (((int)(note[1]-'0')) < 4 && ((int)(note[1]-'0')) >= 1){
            octave = 440*(4 - ((int)(note[1]-'0')) );
            return octave;
          }
          else if (((int)(note[1]-'0')) == 4){
            octave = 440;
            return octave;
          }
        }



          //octave has been found, it can be either from A1 through A8 or more, just know you are at A

          // Now you have to Figure out what Letter the user inputted, in order to know how many steps you want to move from A
          if (letter == 'A'){
            return octave;
          }
          if (letter == 'B'){
            steps += 2;
            return steps;
          }
          if (letter == 'G'){
            steps -= 2;
            return steps;
          }
          if (letter == 'F'){
            steps -= 4;
            return steps;
          }
          if (letter == 'E'){
            steps -= 5;
            return steps;
          }
          if (letter == 'D'){
            steps -= 7;
            return steps;
          }
          if (letter == 'C'){
            steps -= 9;
            return steps;
          }
          /// The steps from A to the letter requested has been figured out, Depending on the letter requested
          /// Now determine whether it is a flat or sharp

          if(strlen(note) == 3){
            if(note[1]== '#'){
              steps += 1;
              return steps;
            }
            else if (note[1] == 'b'){
              steps -= 1;
              return steps;
            }
          }

          hertz = octave * 2^(steps/12);
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
