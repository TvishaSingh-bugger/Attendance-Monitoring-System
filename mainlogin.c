#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "authentication.c"
#include "teachers.c"
#include "student.c"
#include "attendanceTeacher.c"
#include "attendanceStudent.c"

int main()
{
  int choice;
  struct Node *teacherhead=NULL;
  struct node *studenthead=NULL;

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
      if (strcmp(category, "Teacher") == 0 || strcmp(category, "teacher") == 0)
      {
        displayMessageTeacher();
        teachersChoice(teacherhead);
      }
      else if (strcmp(category, "Student") == 0 || strcmp(category, "student") == 0)
      {
        displayMessageStudent();
        studentChoice(studenthead);
      }
      else
      {
        printf("Invalid Category!\n");
      }
    }
    break;
    case 3:
      printf("Exiting the Program...\n");
      return;
    default:
      printf("Invalid Choice!\n");
      break;
    }
  }

  return 0;
}
