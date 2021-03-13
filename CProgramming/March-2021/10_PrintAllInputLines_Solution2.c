
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

int get_line(char buffer[]) {
  fgets(buffer, MAX_SIZE, stdin);

  int len = strlen(buffer);
  buffer[len - 1] = 0;

  return len - 1;
}

int main() {
  char buffer[MAX_SIZE + 1];
  int len;
  const unsigned int limit = 20;

  while((len = get_line(buffer)) > 0) {
    if(len > limit) {
      printf("%s\n", buffer);
    }
  }

  return 0;
}
