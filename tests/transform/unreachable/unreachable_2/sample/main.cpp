#include <stdio.h>

int main(int Argc, char **Argv) {

  {
    if (int X = Argc; X > 1)
      ;
    else {
      printf("%s\n", "Command line arguments aren't specified!");
    }
    if (int X = Argc - 1)
      ;
    else {
      printf("%s\n", "Command line arguments aren't specified!");
    }
    return 0;
  }
}
