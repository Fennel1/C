//函数
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "setting.h"

void Init();                        //初始化
void Login();                       //登录界面
int Choose_Menu(char);              //菜单选择
void MainMenu();                    //主菜单
void Quit();                        //返回到主菜单
void Add_Information();             //添加数据
int Choose_Change(char, Pstu);      //选择要修改的元素
void Change_Information();          //更改数据
void Delete_Information();          //删除数据
void Search_Information();          //查找数据
void Show_Information();            //展示数据
void Exit_Program();                //退出程序


void Init()                     //初始化
{
    Head = (Pstu)malloc(sizeof(stu));   //初始化链表
    Head->Next = NULL;
    Now = Head;

    FILE *fp;       //打开数据文件
    if ((fp = fopen("E:\\vscode\\Codefield\\CODE_C\\C_Multiple\\C语言课设\\data.txt", "r")) == NULL)
    {
        printf("\n\n\t\t\t数据导入失败，退出程序");     //导入失败提示
        exit(0);
    }

    Pstu temp = (Pstu)malloc(sizeof(stu));          //导入数据
    while (fscanf(fp, "%s %s", temp->ID, temp->Name) != EOF)
    {   
        temp->Next = NULL;
        Now->Next = temp;
        Now = temp;
        Count++;
        temp = (Pstu)malloc(sizeof(stu));
    }
    fclose(fp);         //关闭文件
}

void Login()                    //登录
{
    printf("\n\t\t\t请输入账号密码：\n\n\n");
    printf("\t\t\t账号：");
    gets(ManagerName);
    printf("\n\n\t\t\t密码：");
    gets(ManagerPassword);

    int times = 0;      //密码错误次数
    while(strcmp(ManagerName, MANAGER_NAME)!=0 || strcmp(ManagerPassword, MANAGER_PASSWORD)!=0)
    {
        times++;
        if (times>4)        //输入错误超过5次 退出程序
        {
            system("cls");
            printf("\n\n\t\t\t登录限制，程序退出\n\n");
            Sleep(200);
            exit(0);
        }
        else
        {
            system("cls");
            printf("\n\n\t\t\t账号或密码错误, 你还有%d次机会\n\n", 5-times);
            printf("\t\t\t请重新输入账号密码：\n\n");
            printf("\t\t\t账号：");
            gets(ManagerName);
            printf("\n\n\t\t\t密码：");
            gets(ManagerPassword);
        } 
    }

    system("cls");
    MainMenu();     //跳转到主菜单
}

int Choose_Menu(char option)             
{
    static int point=0;
    if ((option==72 || option=='w'|| option=='W')&& point!=0)   point--;            //上下控制
    else    if ((option==80|| option=='s'|| option=='S') && point!=5)   point++;

    printf("\n\n");

    for (int i=0; i<=5; i++)                //打印主菜单界面
    {
        if (i==point)   printf("\t\t\t->\t");
        else    printf("\t\t\t  \t");
        switch (i)
        {
            case 0:
                printf("添加数据");
                break;
            case 1:
                printf("更改数据");
                break;
            case 2:
                printf("删除数据");
                break;
            case 3:
               printf("展示数据");
                break;
            case 4:
                printf("查找数据");
                break;
            case 5:
                printf("退出程序");
                break;
        }
        if (i==point)   printf("\t<-\n\n");
        else    printf("\t  \n\n");
    }

    return point;       //返回选择的菜单
}

void MainMenu()                 //主菜单
{
    char option=0;      //检测键盘输入
    int point;          //用于界面跳转
    do{
        system("cls");
        point = Choose_Menu(option);
        option = getche();
    }while(option!=13);     //当检测到 Enter 时跳出

    switch(point)           //根据 Choose_Menu 返回的值跳转到各个菜单
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
    printf("\n\n\t\t\t输入任意键回到主菜单\n");
    option = getch();
    system("cls");
    MainMenu();
}

void Add_Information()          //添加信息
{
    Pstu temp = (Pstu)malloc(sizeof(stu));
    printf("\t\t\t请输入名称：");
    scanf("%s", temp->Name);
    printf("\n\n\t\t\t请输入id：");
    scanf("%s", temp->ID);

    temp->Next = NULL;          //插入到链表末尾
    Now->Next = temp;           //更新 Now 指针
    Now = temp;
    Count++;                    //更新计数

    Quit();
}

int Choose_Change(char option, Pstu change)
{
    static int point=0;
    if ((option==72 || option=='w'|| option=='W')&& point!=0)   point--;            //上下移动
    else    if ((option==80|| option=='s'|| option=='S') && point!=5)   point++;

    printf("\n\t\t\t请选择要修改的内容\n\n");

    for (int i=0; i<=2; i++)                //打印选择界面
    {
        if (i==point)   printf("\t\t\t->\t");
        else    printf("\t\t\t  \t");
        switch (i)
        {
            case 0:
                printf("ID：%s", change->ID);
                break;
            case 1:
                printf("名称：%s", change->Name);
                break;
        }
        if (i==point)   printf("\t\t<-\n\n");
        else    printf("\t\t\n\n");
    }

    return point;
}

void Change_Information()       //修改信息
{     
    char Change_ID[50];
    printf("\n\t\t\t请输入要修改的id：");
    scanf("%s", Change_ID);

    Pstu temp = Head->Next;
    while (temp!=NULL)          //在链表中查找 Change_ID
    {
        if (strcmp(temp->ID, Change_ID)==0)     //查找成功
        {
            char option=0;      //检测键盘输入
            int point;          //选择的要修改的元素的值
            do{
                system("cls");
                point = Choose_Change(option, temp);
                option = getche();
            }while(option!=13);         //检测到 Enter 时跳出

            switch(point)
            {
                case ID:
                    printf("\t\t\t将ID修改为：");
                    scanf("%s", temp->ID);
                    printf("\n\n\t\t\tID修改成功");
                    break;
                case Name:
                    printf("\n\t\t\t将名称修改为：");
                    scanf("%s", temp->Name);
                    printf("\n\n\t\t\t名称修改成功");
                    break;
            }
            //修改多项，确认不修改后再跳出 ***
            break;      //修改完成，跳出循环
        }
        temp = temp->Next;
    }
    if (temp==NULL)     //若
    {
        printf("\n\t\t\t查无此人\n");
    }

    Quit();
}

void Delete_Information()       //删除信息
{
    char Delete_ID[50];
    printf("\n\t\t\t请输入要删除的id：");
    scanf("%s", Delete_ID);

    Pstu temp = Head;
    while (temp->Next!=NULL)        //在链表中查找此数据
    {
        if (strcmp(temp->Next->ID, Delete_ID)==0)      //查找成功
        {
            printf("\n\n\t\t\tID：%s\t\t名称：%s\n\n", temp->Next->ID, temp->Next->Name);

            char option;
            printf("\t\t\t是否删除该消息（输入Enter确认删除）\n");
            option = getch();
            if (option==13)     //确认删除
            {
                Pstu delete = temp->Next;
                temp->Next = delete->Next;
                free(delete);
                Count--;                    //计数减一
                printf("\t\t\t成功删除\n");
            }
            else
            {
                printf("\t\t\t取消删除\n");
            }
            break;      //删除完成，跳出循环
        }
        temp = temp->Next;
    }
    if (temp->Next==NULL)       //查找失败
    {
        printf("\t\t\t查无此人, 删除失败\n");
    }

    Quit();
}

void Search_Information()       //查询信息
{
    char Search_ID[50];
    printf("\n\t\t\t请输入要查询的id：");
    scanf("%s", Search_ID);

    Pstu temp = Head->Next;
    while (temp!=NULL)
    {
        if (strcmp(temp->ID, Search_ID)==0)
        {
            printf("\n\t\t\tID：%s\t\t名称：%s\n\n", temp->ID, temp->Name);
            //询问是否要修改或删除 ***
            break;
        }
        temp = temp->Next;
    }
    if (temp==NULL)
    {
        printf("\n\t\t\t查无此人\n");
    }
    Quit();
}

void Show_Information()         //显示信息
{
    Pstu temp = Head->Next;
    printf("\n\t\t\t一共有%d人\n\n", Count);

    while (temp!=NULL)
    {
        printf("\t\t\tID：%s\t\t名称：%s\n\n", temp->ID, temp->Name);
        temp = temp->Next;
    }

    //每10条信息换下一页 ***
    //以各种顺序排序 ***

    Quit();
}

void Exit_Program()
{
    //退出程序时修改文件 ***
    exit(0);
}