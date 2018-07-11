#include <cs50.h>
#include <stdio.h>

int main(void){
    string name = get_string("Name: ");
    char initials[4];
    int counter = 0;
    
    for(int i = 0; i < strlen(name); i++) {
        
        if (isupper(name[i])){
            
            initials[counter] = name[i];
            counter++;
        }
    }
}