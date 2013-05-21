#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv) {
  printf("Finding comparison literal:\n");

  char secret[80];

  //Found the offset in a hex editor, only valid if string literal is only thing changed in source
  //...also might depend on gcc version... I'm using 4.2.1
  FILE* file = fopen("chal1", "r+");
  fseek(file, 3914, SEEK_SET);

  //This can get thrown off easily by secret key formatting or length.
  fscanf(file, "%80[0-9a-zA-Z ]", secret);

  printf("Secret found: %s\n", secret);

  printf("Test 1: Read and run\n");
  printf("Running with found secret:\n");
  printf("./chal1 %s\n", secret);
  fflush(stdout);

  int status = execl("./chal1", "./chal1", secret);

  return 0;
}
