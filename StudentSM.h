#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // _getch:不需要回车，直接获取输入的字符

typedef struct _Student {
    int stuNum;
    char name[20];
    int score;
} Student;

typedef struct _Node {
    Student stu;
    struct _Node *next;
} Node;

void welcome();
void inputStudent(Node *head);
void printStudent(Node* head);
void countStudent(Node *head);
void findStudent(Node* head);
void saveStudent(Node * head);
void loadStudent(Node* head);
void modifyStudent(Node *head);
void deleteStudent(Node *head);
void sortStudent(Node *head);