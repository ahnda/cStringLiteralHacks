#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv) {
  //Found the offset in a hex editor, only valid if string literal is only thing changed in source
  //...also might depend on gcc version... I'm using 4.2.1
  FILE* file = fopen("chal1", "r+");
  fseek(file, 3914, SEEK_SET);

  printf("Rewrite and run (spaces and buffer overflows are a pain in the ass)\n");

  fputs("a", file);
  fputc('\0', file);
  fclose(file);

  printf("Secret rewritten as \"a\"\n");
  printf("Now executing chal1...\n");
  printf("./chal1 a\n");
  fflush(stdout);

  int status = execl("./chal1", "./chal1", "a");

  return 0;
}
