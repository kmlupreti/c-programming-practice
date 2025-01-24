// program to count number of favourite linux distros
// Each person should cast their vote and the result will be display at the end
#include <stdio.h>
#include <strings.h>
#define TOTAL_DISTROS (sizeof distro_list / sizeof(struct distro))

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

int get_distro_name(char *name) {
  char c;
  int len = 0;
  printf("enter distro name to vote:\n");
  while ((c = getchar()) != EOF && c != '\n')
    name[len++] = c;
  // add null terminator and increment value of len
  // only if name was populated
  if (len > 0)
    name[len++] = '\0';
  return len;
}

void display_distros() {
  printf("\nDistro list to vote from:\n");
  for (int i = 0; i <= 10; i++) {
    printf("%s\n", distro_list[i].name);
  }
}

int main() {
  char *distro_name;
  int matched_index = -1;
  display_distros();
  while (get_distro_name(distro_name) > 0) {
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
  for (int i = 0; i < TOTAL_DISTROS; i++) {
    printf("Distro\t\tTotal votes\n");
    printf("%s\t\t%d", (distro_list[i]).name, (distro_list[i]).count);
  }
  return 0;
}
