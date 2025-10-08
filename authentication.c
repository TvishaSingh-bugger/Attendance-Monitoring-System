#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teachers.c"
#include "student.c"
#include "attendanceTeacher.c"
#include "attendanceStudent.c"

// User Authentication

struct User
{
  char name[30];
  int userId;
  char passWord[30];
  char userCategory[30]; // student or Teacher
};
char enteredUser[30];
void userAuthentication()
{
  FILE *f1;
  struct User u;
  f1 = fopen("UserAuth.txt", "a");
  if (f1 == NULL)
  {
    printf("File not found!\n");
  }
  printf("Enter Your Name:");
  scanf("%s", u.name);

  printf("Enter your UserId:");
  scanf("%d", &u.userId);

  printf("Enter your password:");
  scanf("%s", u.passWord);

  printf("Enter your category (Teacher/Student):");
  scanf("%s", u.userCategory);

  fprintf(f1, "%s %d %s %s\n", u.name, u.userId, u.passWord, u.userCategory);

  fclose(f1);
}

int login()
{
  struct User u;
  FILE *f2;
  f2 = fopen("UserAuth.txt", "r");
  if (f2 == NULL)
  {
    printf("File not found!\n");
    return 0;
  }
  char userName[40];
  int UserId;
  char passWord[40];
  char userCategory[40];

  printf("Enter Name:");
  scanf("%s", userName);

  printf("Enter UserId:");
  scanf("%d", &UserId);

  printf("Enter PassWord:");
  scanf("%s", passWord);

  printf("Enter Your Category(Student/Teacher):");
  scanf("%s", userCategory);

  while (fscanf(f2, "%s %d %s %s\n", u.name, &u.userId, u.passWord, u.userCategory) != EOF)
  {
    if (UserId == u.userId && strcmp(passWord, u.passWord) == 0)
    {
      strcpy(enteredUser,u.name);
      printf("WELCOME!\n");
      fclose(f2);
      return 0;
    }
  }
  fclose(f2);
  printf("Invalid Credentials!\n");
  return 0;
}

void displayName()
{
  printf("Welcome %s",enteredUser);
}
