#include "StudentSM.h"

int main() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;

    while (1) {
        welcome();

        char c = _getch();
        switch (c) {
            case '1':  //¼��ѧ����Ϣ
                inputStudent(head);
                break;
            case '2':  //��ӡѧ����Ϣ
                break;
            case '3':  //ͳ��ѧ������
                break;
            case '4':  //����ѧ����Ϣ
                break;
            case '5':  //�޸�ѧ����Ϣ
                break;
            case '6':  //ɾ��ѧ����Ϣ
                break;
            case '7':  //���ɼ�����
                break;
            case '8':  //�˳�ϵͳ
                break;
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

    system("pause");
    system("cls");
}