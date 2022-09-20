#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

int checkForChar(string text, char c);
string stringSlice(string text, int beg, int end);

int main(int argc, string argv[]) 
{
    // string slice = stringSlice("Allicadoo", 0, 5);
    // printf("yeah?: %i\n", checkForChar("VCHPRZGJNTLSKFBDPWAXEUYVOI", 'P'));
    // printf("Allicadoo sliced from A to a is: %s\n", slice);
    printf("%i\n", 2 != 2);
    return 0;
}

int checkForChar(string text, char c)
{
  for (int i = 0; i < strlen(text); i++)
  {
    if (c == text[i])
    {
      return 0;
    }
  }
  return 1;
}

string stringSlice(string text, int beg, int end)
{
  int len = end - beg;
  // char newt[len];
  char *newt = malloc(len);
  for (int i = 0; i <= len; i++)
  {
    newt[i] = text[beg + i];
    // printf("Newt is %s\n", newt);
  }
  return newt;
}