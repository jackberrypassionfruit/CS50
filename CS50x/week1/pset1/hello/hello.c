#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Please input a string: ");
    printf("hello, %s\n", name);
}