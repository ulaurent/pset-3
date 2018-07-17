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
        int octave;
        int place;
        int section;
        char letter;
        char accidental;

            //First step find out what Octave you are in
            // If its A4 auto return hertz equal to 440
            if(note[0]=='A' && note[1]== '4'){
                hertz = 440;
                return hertz;
            }
            
            else{
                if(strlen(note) == 2){
                    letter = note[0];
                    octave = (int)note[1];
                    place = 440 *((octave - 4) * 2);

                    if (note[0] == 'B'){
                        hertz = place*(2^(2/12));
                    }
                    if (note[0] == 'G'){
                        hertz = place/(2^(2/12));
                    }
                    if (note[0] == 'F'){
                        hertz = place/(2^(4/12));
                    }
                    if (note[0] == 'E'){
                        hertz = place/(2^(5/12));
                    }
                    if (note[0] == 'D'){
                        hertz = place/(2^(7/12));
                    }
                    if (note[0] == 'C'){
                        hertz = place/(2^(9/12));
                    }
                }
                //Parameters if string consist of accidentals
                else {
                    letter = note[0];
                    accidental = note[1];
                    octave = (int)note[2];
                    place = 440 *((octave - 4) * 2);

                    if (letter == 'B'){
                        section = place*(2^(2/12));

                        if(accidental == '#'){
                            hertz = section * (2^(2/12));
                            return hertz;
                        }
                        else{
                        // accidental is a flat 'b'
                            hertz = section /(2^(1/12));
                            return hertz;
                        }
                    }

                    if (note[0] == 'G'){
                        section = place/(2^(2/12));

                        if(accidental == '#'){
                            hertz = section * (2^(2/12));
                            return hertz;
                        }
                        else{
                        // accidental is a flat 'b'
                            hertz = section /(2^(1/12));
                            return hertz;
                        }
                    }
                    if (note[0] == 'F'){
                        section = place/(2^(4/12));

                        if(accidental == '#'){
                            hertz = section * (2^(2/12));
                            return hertz;
                        }
                        else{
                        // accidental is a flat 'b'
                            hertz = section /(2^(1/12));
                            return hertz;
                        }
                    }
                    if (note[0] == 'E'){
                        section = place/(2^(5/12));
                        if(accidental == '#'){
                            hertz = section * (2^(2/12));
                            return hertz;
                        }
                        else{
                        // accidental is a flat 'b'
                            hertz = section /(2^(1/12));
                            return hertz;
                        }
                    }
                    if (note[0] == 'D'){
                        section = place/(2^(7/12));
                        if(accidental == '#'){
                            hertz = section * (2^(2/12));
                            return hertz;
                        }
                        else{
                        // accidental is a flat 'b'
                            hertz = section /(2^(1/12));
                            return hertz;
                        }
                    }
                    if (note[0] == 'C'){
                        section = place/(2^(9/12));

                        if(accidental == '#'){
                            hertz = section * (2^(2/12));
                            return hertz;
                        }
                        else{
                        // accidental is a flat 'b'
                            hertz = section /(2^(1/12));
                            return hertz;
                        }
                    }


                }
            }
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
