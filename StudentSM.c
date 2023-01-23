#include "StudentSM.h"

int main() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;

    while (1) {
        welcome();

        char c = _getch();
        switch (c) {
            case '1':  //录入学生信息
                inputStudent(head);
                break;
            case '2':  //打印学生信息
                break;
            case '3':  //统计学生人数
                break;
            case '4':  //查找学生信息
                break;
            case '5':  //修改学生信息
                break;
            case '6':  //删除学生信息
                break;
            case '7':  //按成绩排序
                break;
            case '8':  //退出系统
                break;
            default:
                break;

        }
    }

    return 0;
}

void welcome() {
    printf("*********************************\n");
    printf("*\t学生成绩管理系统\t*\n");
    printf("*********************************\n");
    printf("*\t请选择功能列表\t\t*\n");
    printf("*********************************\n");
    printf("*\t1.录入学生信息\t\t*\n");
    printf("*\t2.打印学生信息\t\t*\n");
    printf("*\t3.统计学生人数\t\t*\n");
    printf("*\t4.查找学生信息\t\t*\n");
    printf("*\t5.修改学生信息\t\t*\n");
    printf("*\t6.删除学生信息\t\t*\n");
    printf("*\t7.按成绩排序\t\t*\n");
    printf("*\t8.退出系统\t\t*\n");
    printf("*********************************\n");
}


// 录入学生信息
void inputStudent(Node *head) {
    Node *move = head;
    while (move->next != NULL) move = move->next;
    Node *fresh = (Node *) malloc(sizeof(Node));
    fresh->next = NULL;
    printf("请输入学生的学号、姓名、成绩：");
    scanf("%d%s%d", &fresh->stu.stuNum, &fresh->stu.name, &fresh->stu.score);
    move->next = fresh;

    system("pause");
    system("cls");
}