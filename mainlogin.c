#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "attendance.h"
#include "authentication.h"

int main()
{
  int choice;
  while (1)
  {
    printf("ATTENDANCE SYSTEM\n");
    printf("1: Register User\n");
    printf("2: Login\n");
    printf("3: Exit\n");
    printf("Enter your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      userAuthentication();
      break;
    case 2:
    {
      login();
      char category[30];
      printf("Enter your category (Teacher/Student): ");
      scanf("%s", category);
      if(strcmp(category, "Teacher")==0)
      {
        teachersChoice();
      }
      else if(strcmp(category, "Student")==0)
      {
        studentChoice();
      }
      else
      {
        printf("Invalid Category!\n");
      }
    }
    break;
    case 3:
      printf("Exiting the Program...\n");
      return 0;
    default:
      printf("Invalid Choice!\n");
      break;
    }
  }

  return 0;
}
