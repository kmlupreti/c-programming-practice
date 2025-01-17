#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
  int id;
  char name[20];
  char password[20];
  float balance;
};

struct User new_user(char name[], char password[]) {
  struct User user;
  user.id = rand();
  strcpy(user.name, name);
  strcpy(user.password, password);
  user.balance = 0.0;
  return user;
}

void user_info(struct User *user) {
  printf("\n************user info*********************\n");
  printf("id: %d\n", user->id);
  printf("username: %s\n", user->name);
  printf("password: %s\n", user->password);
  printf("balance: %.2f\n", user->balance);
  printf("*******************************************\n");
}

void add_balance(struct User *user, float balance) { user->balance += balance; }

int main() {
  char username[20];
  char password[20];
  printf("enter username:\n");
  scanf("%s", username);
  printf("enter pasword:\n");
  scanf("%s", password);
  struct User user = new_user(username, password);
  while (1) {
    printf("choose an option\n");
    printf("1.show user info\n2.add balance\nother key to quit\n");
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      user_info(&user);
    } else if (opt == 2) {
      printf("how much balance do you want to add?\n");
      float balance;
      scanf("%f", &balance);
      add_balance(&user, balance);
    } else
      break;
  }
  return 0;
}
