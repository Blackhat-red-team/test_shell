/**
 * main-Entry point of the program.
 * @num1: The first number to be added.
 * @num2: The second number to be added.
 * add_num - add two num and returns the result
 * Return: The sum of the two num.
 */
int add_num(int num1, int num2)
{
int sum;
sum = num1 + num2;
return (sum);
}

int main(void)
{
int z = 5;
int e = 10;
int result;

result = add_num(z, e);
printf("The sum is: %d\n", result);
return (0);
}
