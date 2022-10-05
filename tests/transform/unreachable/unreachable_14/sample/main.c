#define STMT X = 5

int main(int Argc, char **Argv) {

  {
    int X;
    goto L;

  L:
    return 0;
  }
}
