#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Attendance {
    int userId;
    char name[40];
    char sec[10];
    char date[20];
    char status[20];
};

struct node{
    struct node *next;
    struct Attendance data;
};
extern struct node *head;
struct node *CreateNode(struct Attendance a);
struct node *insertAttendance(struct Attendance a);
void ViewAttendance();
void saveAttendance(struct Attendance a);
void addAttendance();
void displayAttendance();
void viewAttendanceSummary();
void viewMyAttendance();

#endif
