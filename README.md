# C语言课设
## 使用说明

## 函数说明

### void Init()
* 初始化链表
* 从数据文件从读取数据输入到链表中
* 若时间长考虑做个过场动画

### void Login()
* 输入账号、密码，判断是否登陆成功
* 密码错误，重新登陆
* 登陆成功跳转至主菜单

### int Choose_Print(char)
* 如图所示的菜单选择，接受一个字符（↑↓、ws、WS）进行上下选择
```
                                添加数据

                                更改数据

                        ->      删除数据        <-

                                展示数据

                                查找数据

                                退出程序
```
* 返回选择的菜单所对应的值
* 跳转至主菜单

### void MainMenu()
* 先进行菜单上下选择 `Choose_Print`
* 输入 `Enter` 进入对应菜单
```
0 Add_Information()
1 Change_Information()
2 Delete_Information()
3 Show_Information()
4 Search_Information()
5 Exit_Program()
```

### void Quit()
* 从各个菜单完成操作后按任意键返回主菜单
* 刷新屏幕

### void Add_Information()
* 在链表末尾添加数据
* Now始终为链表的最后一个成员
* Count+1

### void Change_Information()
* 输入ID，修改该ID的任意数据（未完成）

### void Delete_Information()
* 输入ID，从链表中删除该成员
* 显示要删除的信息，询问是否确认删除
* 若无此ID，显示删除失败
* 若删除成功 Count-1；

### void Search_Information()
* 输入ID，显示该成员的数据
* 可在此处直接跳转至修改（未完成）

### void Show_Information()
* 展示全部数据
* 可翻页（未完成）
* 按一定顺序显示（未完成）

### void Exit_Program()
* 将当前链表， 输出到数据文件中
* 退出程序
