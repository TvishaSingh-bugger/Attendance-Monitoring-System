#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "authentication.c"
#include "teachers.c"
#include "student.c"
#include "attendanceTeacher.c"



// Attendance Module for Student
struct Attendance
{
  int userId;
  char name[40];
  char sec[10];
  char date[20];
  char status[20];
};

struct node
{
  struct node *next;
  struct Attendance data;
};

struct node *createNode(struct Attendance a)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = a;
  temp->next = NULL;
  return temp;
}

struct node *insertAttendance(struct node *studenthead, struct Attendance a)
{
  struct node *temp = createNode(a);
  if (studenthead == NULL)
  {
    studenthead = temp;
    return studenthead;
  }
  struct node *ptr = studenthead;
  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = temp;
  return studenthead;
}

void viewMyAttendance(struct node *studenthead)
{
  int id;
  printf("Enter the Student Id:");
  scanf("%d", &id);
  if (studenthead == NULL)
  {
    printf("No record found!\n");
    return;
  }
  struct node *temp = studenthead;
  int found = 0;
  while (temp != NULL)
  {
    if (temp->data.userId == id)
    {
      printf("UserId:%d  Name:%s  Section:%s  Date:%s  Status:%s\n", temp->data.userId, temp->data.name, temp->data.sec, temp->data.date, temp->data.status);
      found = 1;
      break;
    }
    temp = temp->next;
  }
  if (found == 0)
  {
    printf("No attendance record was found!\n");
    return;
  }
}