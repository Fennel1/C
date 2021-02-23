//函数
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "setting.h"
// Init()

void Init()                     //初始化
{
    pHead = (Pstu)malloc(sizeof(stu));
    pHead->pNext = NULL;
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
            printf("请输入账号密码：\n");
            printf("账号：");
            gets(ManagerName);
            printf("密码：");
            gets(ManagerPassword);
        } 
    }

    MainMenu();     //跳转到主菜单
}

void MainMenu()                 //主菜单
{
    char option;
    do
    {
        system("cls");
        //界面
        option = getche();
    }while(option>0);

    switch(option)
    {
        case Add:
            break;
        case Change:
            break;
        case Delete:
            break;
        case Show:
            break;
        case Search:
            break;
        case Exit:
            break;
    }
}

void Quit()                     //退出（到主菜单）
{

}

void Add_Information()          //添加信息
{

}

void Change_Information()       //修改信息
{     

}

void Delete_Information()       //删除信息
{

}

void Search_Information()       //查询信息
{

}

void Show_Information()         //显示信息
{

}