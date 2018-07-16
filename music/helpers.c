// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as /Y to eighths
  int duration(string fraction)
    {
      int X = atoi (&fraction[0]);
      int Y = atoi (&fraction[2]);

      int eighths = (8/Y)*X;

      return eighths;
    }

// Calculates frequency (in Hz) of a note
    int frequency(string note)
    {
        int hertz;
        int octave;
        int place;
        string letter;
        //string accidental;

        //First step find out what Octave you are in
        if(strlen(note) == 2){
            if(note[0]=='A' && note[1]== 4){
                hertz = 440;
                return hertz;
            }
            else{
                letter = &note[0];
                octave = note[1];
                place = 440 *((octave - 4) * 2);
            }
        }
    }
        /*else{
            letter = note[0];
            accidental = note[1];
            octave = note[2];

        }*/
    // TODO


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
