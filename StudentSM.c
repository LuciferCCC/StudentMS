#include "StudentSM.h"

int main() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;

    loadStudent(head);

    while (1) {
        welcome();

        char c = _getch();
        switch (c) {
            case '1':  //¼��ѧ����Ϣ
                inputStudent(head);
                break;
            case '2':  //��ӡѧ����Ϣ
                printStudent(head);
                break;
            case '3':  //ͳ��ѧ������
                countStudent(head);
                break;
            case '4':  //����ѧ����Ϣ
                findStudent(head);
                break;
            case '5':  //�޸�ѧ����Ϣ
                modifyStudent(head);
                break;
            case '6':  //ɾ��ѧ����Ϣ
                deleteStudent(head);
                break;
            case '7':  //���ɼ�����
                sortStudent(head);
                break;
            case '8':  //�˳�ϵͳ
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
    printf("*\tѧ���ɼ�����ϵͳ\t*\n");
    printf("*********************************\n");
    printf("*\t��ѡ�����б�\t\t*\n");
    printf("*********************************\n");
    printf("*\t1.¼��ѧ����Ϣ\t\t*\n");
    printf("*\t2.��ӡѧ����Ϣ\t\t*\n");
    printf("*\t3.ͳ��ѧ������\t\t*\n");
    printf("*\t4.����ѧ����Ϣ\t\t*\n");
    printf("*\t5.�޸�ѧ����Ϣ\t\t*\n");
    printf("*\t6.ɾ��ѧ����Ϣ\t\t*\n");
    printf("*\t7.���ɼ�����\t\t*\n");
    printf("*\t8.�˳�ϵͳ\t\t*\n");
    printf("*********************************\n");
}


// ¼��ѧ����Ϣ
void inputStudent(Node *head) {
    Node *move = head;
    while (move->next != NULL) move = move->next;
    Node *fresh = (Node *) malloc(sizeof(Node));
    fresh->next = NULL;
    printf("������ѧ����ѧ�š��������ɼ���");
    scanf("%d%s%d", &fresh->stu.stuNum, &fresh->stu.name, &fresh->stu.score);
    move->next = fresh;
    saveStudent(head);
    system("pause");
    system("cls");
}

// ��ӡѧ������Ϣ
void printStudent(Node *head) {
    Node *move = head->next;
    while (move != NULL) {
        printf("ѧ�ţ�%d ������%s �ɼ���%d\n", move->stu.stuNum, move->stu.name, move->stu.score);
        move = move->next;
    }
    system("pause");
    system("cls");
}

// ͳ��ѧ������
void countStudent(Node *head) {
    int cnt = 0;
    Node *move = head->next;
    while (move != NULL) cnt++, move = move->next;
    printf("ѧ��������Ϊ��%d\n", cnt);
    system("pause");
    system("cls");
}

// ��ѯѧ����Ϣ
void findStudent(Node *head) {
    int stuNum;
    printf("������Ҫ����ѧ����ѧ�ţ�");
    scanf("%d", &stuNum);
    Node *move = head->next;
    while (move != NULL) {
        if (move->stu.stuNum == stuNum) {
            printf("ѧ�ţ�%d ������%s �ɼ���%d\n", move->stu.stuNum, move->stu.name, move->stu.score);
            system("pause");
            system("cls");
            return;
        }
        move = move->next;
    }
    printf("δ�鵽ѧ����Ϣ\n");
    system("pause");
    system("cls");
}

// ѧ����Ϣ�����ļ�
void saveStudent(Node *head) {
    FILE *file = fopen("stu.txt", "w");
    if (file == NULL) {
        printf("���ļ�ʧ��\n");
        return;
    }
    Node *move = head->next;
    while (move != NULL) {
        if (fwrite(&move->stu, sizeof(Student), 1, file) != 1)
            printf("����%s���ִ���\n", move->stu.name);
        move = move->next;
    }
    fclose(file);
}

// ��ȡѧ����Ϣ
void loadStudent(Node *head) {
    FILE *file = fopen("./stu.txt", "r");
    if (file == NULL) {
        printf("δ�ҵ�ѧ���ļ���������ȡ\n");
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
    printf("��ȡ�ɹ�\n");
}

// �޸�ѧ����Ϣ
void modifyStudent(Node *head) {
    printf("��������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
    int stuNum = 0;
    scanf("%d", &stuNum);
    Node *move = head->next;
    while (move != NULL) {
        if (move->stu.stuNum == stuNum) {
            printf("������ѧ���������ɼ���");
            scanf("%s%d", &move->stu.stuNum, &move->stu.score);
            printf("�޸�ѧ����Ϣ�ɹ�\n");
            break;
        }
        move = move->next;
    }
    if (move == NULL) printf("δ�ҵ�ѧ����Ϣ\n");
    saveStudent(head);
    system("pause");
    system("cls");
}

// ɾ��ѧ����Ϣ
void deleteStudent(Node *head) {
    printf("������Ҫɾ����ѧ��ѧ�ţ�");
    int stuNum;
    scanf("%d", &stuNum);
    Node *move = head->next;
    while (move != NULL) {
        if (stuNum == move->next->stu.stuNum) {
            Node *tmp = move->next;
            move->next = move->next->next;
            free(tmp);
            tmp = NULL;
            printf("ɾ��ѧ���ɹ�\n");
            break;
        }
        move = move->next;
    }
    if (move == NULL) printf("δ�ҵ�ѧ����Ϣ\n");
    saveStudent(head);
    system("pause");
    system("cls");
}

// ���ɼ�����
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