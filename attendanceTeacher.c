#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "authentication.c"
#include "teachers.c"
#include "student.c"
#include "attendanceStudent.c"


// Attendance Module for Teacher
struct AttendanceTeacher
{
  int userId;
  char name[40];
  char sec[10];
  char date[20];
  char status[20];
};

struct Node
{
  struct Node *next;
  struct AttendanceTeacher data;
};

struct Node *CreateNode(struct AttendanceTeacher a)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = a;
  temp->next = NULL;
  return temp;
}

struct Node *insertAttendance(struct Node *teacherhead, struct AttendanceTeacher a)
{
  struct Node *temp = CreateNode(a);
  if (teacherhead == NULL)
  {
    teacherhead = temp;
    return teacherhead;
  }
  struct Node *ptr = teacherhead;
  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = temp;
  return teacherhead;
}

// View all attendance record for teacher

void displayAttendance(struct Node *teacherhead)
{
  if (teacherhead == NULL)
  {
    printf("No records found!\n");
    return;
  }
  printf("Attendance Record!\n");
  struct Node *temp = teacherhead;
  while (temp != NULL)
  {
    printf("UserId:%d  Name:%s  Section:%s  Date:%s  Status:%s\n", temp->data.userId, temp->data.name, temp->data.sec, temp->data.date, temp->data.status);
    temp = temp->next;
  }
  printf("\n");
}

// Attendance summary for teacher

void viewAttendanceSummary(struct Node *teacherhead)
{
  if (teacherhead == NULL)
  {
    printf("No record Found!\n");
    return;
  }
  int totalStudents = 0, present = 0, absent = 0;
  struct Node *temp = teacherhead;
  while (temp != NULL)
  {
    totalStudents++;
    if (strcmp(temp->data.status, "Present") == 0)
    {
      present++;
    }
    else
    {
      absent++;
    }
    temp = temp->next;
  }
  printf("Attendance Records!\n");
  printf("Total Number of Students:%d\n", totalStudents);
  printf("Present:%d\n", present);
  printf("Absent:%d\n", absent);
}
