
int main(int Argc, char **Argv) {

  {
    int X;
    (X = Argc) > 1;

    {int Argc = X};
    return X - 1;
  }
}
