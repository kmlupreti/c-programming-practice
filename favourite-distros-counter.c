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
  while ((*name = getchar()) != EOF)
    ;
}
int main() {
  char *distro_name;
  int len;
  while ((len = get_distro_name(distro_name)) >= 0) {
    for (int i = 0; i < TOTAL_DISTROS; i++) {
      if (strcasecmp(distro_name, (distro_list[i]).name))
        (distro_list[i]).count++;
    }
  }
  for (int i = 0; i < TOTAL_DISTROS; i++) {
    printf("Distro\t\tTotal votes\n");
    printf("%s\t\t%d", (distro_list[i]).name, (distro_list[i]).count);
  }
}
