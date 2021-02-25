//参数设置
#define MANAGER_NAME "root"             //管理员账户密码
#define MANAGER_PASSWORD "1"

typedef enum Menu           //菜单选项
{
    Add, Change, Delete, Show, Search, Exit
}MENU;

typedef enum Message        //用户信息选项
{
    ID, Name
}MESSAGE;

typedef struct Student      //学生信息
{
    char Name[50];
    char ID[50];
    struct Student *Next;

}stu, *Pstu;

Pstu Head;
Pstu Now;
unsigned int Count=0;       //学生人数
char ManagerName[50];
char ManagerPassword[50];