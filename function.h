//函数
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "setting.h"

void Init();
void Login();
void MainMenu();
void Quit();
void Add_Information();
void Change_Information();
void Delete_Information();
void Search_Information();
void Show_Information();
void Exit_Program();


void Init()                     //初始化
{
    Head = (Pstu)malloc(sizeof(stu));
    Head->Next = NULL;
    Now = Head;
    //读入文件
    //退出程序时修改文件
}

void Login()                    //登录
{
    printf("请输入账号密码：\n");
    printf("账号：");
    gets(ManagerName);
    printf("密码：");
    gets(ManagerPassword);

    int times = 0;      //密码错误次数
    while(strcmp(ManagerName, MANAGER_NAME)!=0 || strcmp(ManagerPassword, MANAGER_PASSWORD)!=0)
    {
        times++;
        if (times>5)
        {
            exit(0);
        }
        else
        {
            system("cls");
            printf("账号或密码错误\n");
            printf("请重新输入账号密码：\n");
            printf("账号：");
            gets(ManagerName);
            printf("密码：");
            gets(ManagerPassword);
        } 
    }

    system("cls");
    MainMenu();     //跳转到主菜单
}

void MainMenu()                 //主菜单
{
    char option;
    do
    {
        system("cls");
        puts("0.添加数据");
        puts("1.更改数据");
        puts("2.删除数据");
        puts("3.数据展示");
        puts("4.查找数据");
        puts("5.退出程序");
        option = getche();
    }while(option<'0'||option>'6');

    switch(option-'0')
    {
        case Add:
            system("cls");
            Add_Information();
            break;
        case Change:
            system("cls");
            Change_Information();
            break;
        case Delete:
            system("cls");
            Delete_Information();
            break;
        case Show:
            system("cls");
            Show_Information();
            break;
        case Search:
            system("cls");
            Search_Information();
            break;
        case Exit:
            system("cls");
            Exit_Program();
            break;
    }
}

void Quit()                     //退出（到主菜单）
{
    char option;
    printf("输入任意键回到主菜单\n");
    option = getch();
    system("cls");
    MainMenu();
}

void Add_Information()          //添加信息
{
    Pstu temp = (Pstu)malloc(sizeof(stu));
    puts("请输入名称：");
    scanf("%s", temp->Name);
    puts("请输入id：");
    scanf("%s", temp->ID);
    temp->Next = NULL;
    Now->Next = temp;
    Now = temp;
    Count++;
    Quit();
}

void Change_Information()       //修改信息
{     
    char id[50];
    printf("请输入要修改的id：");
    scanf("%s", id);

    Pstu temp = Head->Next;
    while (temp!=NULL)
    {
        if (strcmp(temp->ID, id)==0)
        {
            printf("%s\t\t%s\n", temp->ID, temp->Name);
            //任意选择一项去修改
            break;
        }
        temp = temp->Next;
    }
    if (temp==NULL)
    {
        printf("查无此人\n");
    }
    Quit();
}

void Delete_Information()       //删除信息
{
    char id[50];
    printf("请输入要删除的id：");
    scanf("%s", id);
    Pstu temp = Head;
    while (temp->Next!=NULL)
    {
        if (strcmp(temp->Next->ID, id)==0)
        {
            char option;
            printf("%s\t\t%s\n", temp->Next->ID, temp->Next->Name);
            printf("是否删除该消息（输入Enter确认删除）\n");
            option = getch();
            if (option==13)
            {
                Pstu delete = temp->Next;
                temp->Next = delete->Next;
                free(delete);
                Count--;
                printf("成功删除\n");
            }
            else
            {
                printf("取消删除\n");
            }
            break;
        }
        temp = temp->Next;
    }
    if (temp==NULL)
    {
        printf("查无此人, 删除失败\n");
    }

    Quit();
}

void Search_Information()       //查询信息
{
    char id[50];
    printf("请输入要查询的id：");
    scanf("%s", id);

    Pstu temp = Head->Next;
    while (temp!=NULL)
    {
        if (strcmp(temp->ID, id)==0)
        {
            printf("%s\t\t%s\n", temp->ID, temp->Name);
            break;
        }
        temp = temp->Next;
    }
    if (temp==NULL)
    {
        printf("查无此人\n");
    }
    Quit();
}

void Show_Information()         //显示信息
{
    Pstu temp = Head->Next;
    printf("一共有%d人\n", Count);
    while (temp!=NULL)
    {
        printf("%s\t\t%s\n", temp->ID, temp->Name);
        temp = temp->Next;
    }

    Quit();
}

void Exit_Program()
{
    //退出程序时修改文件
    exit(0);
}