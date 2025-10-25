#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "attendance.h"


struct node *head=NULL;


struct node *CreateNode(struct Attendance a)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = a;
  temp->next = NULL;
  return temp;
}

struct node *insertAttendance(struct Attendance a)
{
  struct node *temp = CreateNode(a);
  if (head == NULL)
  {
    head = temp;
    return head;
  }
  struct node *ptr =head;
  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = temp;
  return head;
}

void ViewAttendance(){
  FILE *f1;
  f1=fopen("attendance.txt","r");
  if(f1==NULL){
    printf("No records found!\n");
    return;
  }
  struct Attendance a;
  while(fscanf(f1,"%d%s%s%s%s\n",&a.userId,a.name,a.sec,a.date,a.status)!=EOF){
    insertAttendance(a);
  }
  fclose(f1);
}


void addAttendance() {
    struct Attendance a;
    printf("Enter UserId:\n");
    scanf("%d",&a.userId);
    printf("Enter Name:\n");
    scanf("%s",a.name);
    printf("Enter Section:\n");
    scanf("%s",a.sec);
    printf("Enter Date (YYYY-MM-DD):\n");
    scanf("%s",a.date);
    printf("Enter Status (Present/Absent):\n ");
    scanf("%s",a.status);
    insertAttendance(a);
    saveAttendance(a);
    printf("Attendance added successfully!\n");
}


void saveAttendance(struct Attendance a){
  FILE *f1=fopen("attendance.txt","a");
  if(f1==NULL){
    printf("File not found\n");
    return;
  }
  fprintf(f1,"%d %s %s %s %s\n",a.userId,a.name,a.sec,a.date,a.status);
  fclose(f1);
}

void displayAttendance()
{
  if (head == NULL)
  {
    printf("No records found!\n");
    return;
  }
  printf("Attendance Record!\n");
  struct node *temp = head;
  while (temp != NULL)
  {
    printf("UserId:%d  Name:%s  Section:%s  Date:%s  Status:%s\n", temp->data.userId, temp->data.name, temp->data.sec, temp->data.date, temp->data.status);
    temp = temp->next;
  }
  printf("\n");
}


void viewAttendanceSummary()
{
  if (head == NULL)
  {
    printf("No record Found!\n");
    return;
  }
  int totalStudents = 0, present = 0, absent = 0;
  struct node *temp = head;
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


void viewMyAttendance()
{
  int id;
  printf("Enter the Student Id:");
  scanf("%d", &id);
  if (head == NULL)
  {
    printf("No record found!\n");
    return;
  }
  struct node *temp = head;
  int found = 0;
  while (temp != NULL)
  {
    if (temp->data.userId == id)
    {
      printf("UserId:%d  Name:%s  Section:%s  Date:%s  Status:%s\n", temp->data.userId, temp->data.name, temp->data.sec, temp->data.date, temp->data.status);
      found=1;
    }
    temp = temp->next;
  }
  if (found == 0)
  {
    printf("No attendance record was found!\n");
    return;
  }
}
