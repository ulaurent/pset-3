// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
  int duration(string fraction)
    {
      int X = atoi (&fraction[0]);
      int Y = atoi (&fraction[2]);

      int eighths = (8/Y)*X;

      return eighths;
    }

// Calculates frequency (in Hz) of a note
   // int frequency(string note)
   // {
    // TODO
   // }

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
