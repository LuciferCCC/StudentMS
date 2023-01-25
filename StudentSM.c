#include "StudentSM.h"

int main() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;

    loadStudent(head);

    while (1) {
        welcome();

        char c = _getch();
        switch (c) {
            case '1':  //录入学生信息
                inputStudent(head);
                break;
            case '2':  //打印学生信息
                printStudent(head);
                break;
            case '3':  //统计学生人数
                countStudent(head);
                break;
            case '4':  //查找学生信息
                findStudent(head);
                break;
            case '5':  //修改学生信息
                modifyStudent(head);
                break;
            case '6':  //删除学生信息
                deleteStudent(head);
                break;
            case '7':  //按成绩排序
                sortStudent(head);
                break;
            case '8':  //退出系统
                system("cls");
                printf("Bye Bye\n");
                exit(0);
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
    saveStudent(head);
    system("pause");
    system("cls");
}

// 打印学生新信息
void printStudent(Node *head) {
    Node *move = head->next;
    while (move != NULL) {
        printf("学号：%d 姓名：%s 成绩：%d\n", move->stu.stuNum, move->stu.name, move->stu.score);
        move = move->next;
    }
    system("pause");
    system("cls");
}

// 统计学生人数
void countStudent(Node *head) {
    int cnt = 0;
    Node *move = head->next;
    while (move != NULL) cnt++, move = move->next;
    printf("学生总人数为：%d\n", cnt);
    system("pause");
    system("cls");
}

// 查询学生信息
void findStudent(Node *head) {
    int stuNum;
    printf("请输入要查找学生的学号：");
    scanf("%d", &stuNum);
    Node *move = head->next;
    while (move != NULL) {
        if (move->stu.stuNum == stuNum) {
            printf("学号：%d 姓名：%s 成绩：%d\n", move->stu.stuNum, move->stu.name, move->stu.score);
            system("pause");
            system("cls");
            return;
        }
        move = move->next;
    }
    printf("未查到学生信息\n");
    system("pause");
    system("cls");
}

// 学生信息存入文件
void saveStudent(Node *head) {
    FILE *file = fopen("stu.txt", "w");
    if (file == NULL) {
        printf("打开文件失败\n");
        return;
    }
    Node *move = head->next;
    while (move != NULL) {
        if (fwrite(&move->stu, sizeof(Student), 1, file) != 1)
            printf("保存%s出现错误\n", move->stu.name);
        move = move->next;
    }
    fclose(file);
}

// 读取学生信息
void loadStudent(Node *head) {
    FILE *file = fopen("./stu.txt", "r");
    if (file == NULL) {
        printf("未找到学生文件，跳过读取\n");
        return;
    }

    Node *fresh = (Node *) malloc(sizeof(Node));
    fresh->next = NULL;

    Node *move = head->next;

    while (fread(&fresh->stu, sizeof(Student), 1, file) == 1) {
        move->next = fresh;
        move = fresh;
        fresh = (Node *) malloc(sizeof(Node));
        fresh->next = NULL;
    }
    free(fresh);
    fclose(file);
    printf("读取成功\n");
}

// 修改学生信息
void modifyStudent(Node *head) {
    printf("请输入需要修改的学生学号：");
    int stuNum = 0;
    scanf("%d", &stuNum);
    Node *move = head->next;
    while (move != NULL) {
        if (move->stu.stuNum == stuNum) {
            printf("请输入学生姓名、成绩：");
            scanf("%s%d", &move->stu.stuNum, &move->stu.score);
            printf("修改学生信息成功\n");
            break;
        }
        move = move->next;
    }
    if (move == NULL) printf("未找到学生信息\n");
    saveStudent(head);
    system("pause");
    system("cls");
}

// 删除学生信息
void deleteStudent(Node *head) {
    printf("请输入要删除的学生学号：");
    int stuNum;
    scanf("%d", &stuNum);
    Node *move = head->next;
    while (move != NULL) {
        if (stuNum == move->next->stu.stuNum) {
            Node *tmp = move->next;
            move->next = move->next->next;
            free(tmp);
            tmp = NULL;
            printf("删除学生成功\n");
            break;
        }
        move = move->next;
    }
    if (move == NULL) printf("未找到学生信息\n");
    saveStudent(head);
    system("pause");
    system("cls");
}

// 按成绩排序
void sortStudent(Node *head) {
    Node *save = NULL;
    Node *move = NULL;
    for (Node *turn = head->next; turn->next != NULL; turn = turn->next) {
        for (move = head->next; move->next != save; move = move->next)
            if (move->stu.score > move->next->stu.score) {
                Student tmp = move->stu;
                move->stu = move->next->stu;
                move->next->stu = tmp;
            }
        save = move;
    }
    printStudent(head);
}