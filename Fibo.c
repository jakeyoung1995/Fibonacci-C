/////////////////////////////////////////////////////////////////
//
// What are the prime numbers up to the number entered? Let's find out.
//
// Compile:  gcc Fibo.c -o  Fibo -lpthread
// 
// Run:      ./Fibo 
//
///////////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) 
{
int firstValue = 0, secondValue = 1, n = firstValue + secondValue, i;

printf("Enter a number to determine Fibonacci Sequence");
scanf("%d", &i); // Allow the user to enter a number when commanded

// Check to see if there are more than 1 numbers entered
if(argc > 1) { 
        printf("\n This is not a valid number. Please try again using only 1 number!");
        return 0;
    }

// Check to see if number is positive
if(i > 0) {

// Create child process
pid_t pid = fork();

// Check to ensure pid from fork() call is equal to 0 indicating child process
// Then perform loop to print each Fib number UP TO the number specified
if(pid == 0) {
    printf("Child: The first %d numbers in the Fibonacci Sequence are: \n", i);
    printf("0 %d", n);
    while (i > 2) {
        n = firstValue + secondValue;
        printf(" %d", n);
        firstValue = secondValue;
        secondValue = n;
        i--;
    }
    // If pid != 0, indicates parent process 
} else {
    printf("Please wait... \n");
    waitpid(pid, NULL, 0);
    printf("\nParent: the child process is done! ");
}
} else {
    // Result if i <= 0 then the number is invalid
return printf("The number entered is not a valid number. Please enter a number greater than 0");
}
return 0;
}