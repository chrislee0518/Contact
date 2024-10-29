#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

//用枚举可以知道每个选项含义，0，1，2。。。增加代码可读性
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
//一个人信息的类型
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];

};

//通讯录类型
struct Contact
{
	struct PeoInfo data[MAX];//存放一个信息
	int size;

};


//函数声明
//初始化通讯录
void InitContact(struct Contact* ps);
//添加一个人的信息
void AddContact(struct Contact* ps);
//打印信息
void ShowContact(const struct Contact* ps);
//删除指定人信息
void DelContact(struct Contact* ps);
//查找指定人信息
void SearchContact(const struct Contact* ps);
//修改指定人信息
void ModifyContact(struct Contact* ps);
//按名字排序
void SortContact(struct Contact* ps);