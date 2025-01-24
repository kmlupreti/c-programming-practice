// program to count number of favourite linux distros
// Each person should cast their vote and the result will be display at the end
#include <stdio.h>
#include <strings.h>
#define TOTAL_DISTROS (sizeof distro_list / sizeof(struct distro))
#define MAX_DISTRO_NAME 15

struct distro {
  char *name;
  int count;
};

struct distro distro_list[] = {
    {"Arch linux", 0},    {"Debian", 0},     {"Ubuntu", 0},
    {"Linux Mint", 0},    {"Pop OS!", 0},    {"Fedora", 0},
    {"Manjaro", 0},       {"Void linux", 0}, {"Red hat linux", 0},
    {"Elementary OS", 0}, {"Others", 0},

};

int get_distro_name(char *name, int max_len) {
  // handle invalid name and max_len arguments
  if (name == NULL || max_len <= 0)
    return 0;
  char c;
  int len = 0;
  printf("enter distro name to vote:\n");
  while (len < max_len - 1 && (c = getchar()) != EOF && c != '\n')
    name[len++] = c;
  // add null terminator and increment value of len
  // only if distro name was provided
  if (len > 0)
    name[len] = '\0';
  return len;
}

void display_distros() {
  printf("\nDistro list to vote from:\n");
  for (int i = 0; i <= 10; i++) {
    printf("%s\n", distro_list[i].name);
  }
}

int main() {
  char distro_name[MAX_DISTRO_NAME];
  int matched_index = -1;
  display_distros();
  while (get_distro_name(distro_name, MAX_DISTRO_NAME) > 0) {
    for (int i = 0; i < TOTAL_DISTROS; i++) {
      if (strcasecmp(distro_name, (distro_list[i]).name) == 0) {
        matched_index = i;
        (distro_list[i]).count++;
      }
    }
    if (matched_index >= 0) {
      printf("You voted for \"%s\" distro\n", distro_list[matched_index].name);
      matched_index = -1; // reset index
    } else
      printf("Error: distro with that name not found\n");
  }
  printf("Distro    Total votes\n");
  for (int i = 0; i < TOTAL_DISTROS; i++) {
    printf("%s  %d\n", (distro_list[i]).name, (distro_list[i]).count);
  }
  return 0;
}
