/* Helper functions for music contains a duration, frequency, and rest function
to help read each note of a song a user inputs*/

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
    int duration(string fraction){

        //Coverts the fraction values of the notes to integers, then returns the eigths value
        int X = (int) fraction[0] - '0';
        int Y = (int) fraction[2] - '0';

        int eighths = (8/Y)*X;

        return eighths;
    }

// Calculates frequency (in Hz) of a note
    int frequency(string note){
        // Local Variables introduced
        double hertz;
        double octave = 0.0;
        double steps = 0.0;
        char letter = note[0];
        char select = '\0';


        //First step find whether it has an accidental, through analyzing the length of the string
        if (strlen(note) == 3){
            select = note[2];
        }
        else if(strlen(note) < 3){
            select = note[1];
        }

        // Based on whether it has an accidental, proceed to calculating the octave input
        if(((int)(select-'0')) > 4){
            octave = 440.0 *(((int)(select -'0')-4.0)*2);

        }
        else if (((int)(select -'0')) < 4 && ((int)(select -'0')) >= 1){
            octave = 440.0*(4 - ((int)(select -'0')) );

        }
        else if (((int)(select -'0')) == 4){
            octave = 440.0;

        }


        // Once octave has been found, it can be either from A1 through A8 or more, just know you are at A
        // Now you have to Figure out what Letter the user inputted,
        // in order to know how many steps you want to move from A.

        if (letter == 'B'){
            steps += 2.0;
        }
        else if (letter == 'G'){
            steps -= 2.0;
        }
        else if (letter == 'F'){
            steps -= 4.0;
        }
        else if (letter == 'E'){
            steps -= 5.0;
        }
        else if (letter == 'D'){
            steps -= 7.0;
        }
        else if (letter == 'C'){
            steps -= 9.0;
        }

        // The steps from A to the letter requested has been figured out, Depending on the letter requested
        // Now determine whether it is a flat or sharp

        if(strlen(note) == 3){
            // If it has a sharp accidental, add one step
            if(note[1]== '#'){
              steps += 1.0;
            }
            // If it has a flat accidental, minus one step
            else if (note[1] == 'b'){
              steps -= 1.0;
            }
          }

        // Now calculate the whole frequency of the note your are currently located at in a unit of hertz
        double stepsfixed = (steps/12.0);
        double form = 2.0;
        double expon = pow(form, stepsfixed);

        hertz = octave * expon;
        return hertz;
    }



// Determines whether a string represents a rest
    bool is_rest(string s){

        if (strlen(s) == 0){
            return true;
        }
        else {
            return false;
        }
}
