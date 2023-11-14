#include <stdio.h>
long factorial(int n) {
// Faulty base case
if (n > 1) {
return n * factorial(n);
}
return 1;
}
int main() {
int number = 5;
long result = factorial(number);
printf("Factorial of %d is %ld\n", number, result);
return 0;
}