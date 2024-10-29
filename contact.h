#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

//��ö�ٿ���֪��ÿ��ѡ��壬0��1��2���������Ӵ���ɶ���
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT

};
//һ������Ϣ������
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];

};

//ͨѶ¼����
struct Contact
{
	struct PeoInfo data[MAX];//���һ����Ϣ
	int size;

};


//��������
//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);
//���һ���˵���Ϣ
void AddContact(struct Contact* ps);
//��ӡ��Ϣ
void ShowContact(const struct Contact* ps);
//ɾ��ָ������Ϣ
void DelContact(struct Contact* ps);
//����ָ������Ϣ
void SearchContact(const struct Contact* ps);
//�޸�ָ������Ϣ
void ModifyContact(struct Contact* ps);
//����������
void SortContact(struct Contact* ps);