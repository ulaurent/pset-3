//Collatz Conjecture

int collatz (int n){
    if (n == 1){
        return 1;
    }
    //If even 
    else if ((n%2) == 0){
        return 1 + collatz (n/2);
    }
    // Else the number is odd
    else {
        return 1 + collatz(3*n+1);
    }
}