#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

/*
第一次实现通讯录:
用的结构体数组来实现
*/
struct people
{
    char name[30];//名字
    int age;//年龄
    char sex[20];//性别
    char telephone[20];//电话
};
struct Contact
{
    int size;
    struct people date[MAX];
};


//打印菜单
void print_Menu()
{
    printf("**************************\n");
    printf("****1.add     2.delete****\n");
    printf("****3.change  4.find******\n");
    printf("****5.show      0.exit ***\n");
    printf("**************************\n");
}


//初始化
void inti(struct Contact* ps)
{
    memset(ps->date ,0 ,sizeof(ps->date));
    ps->size = 0;//设置通讯录最初只有0个元素
}

void add(struct Contact* ps)
{
    if(ps->size >= MAX)
    {
        printf("通讯录以满\n");
    }
    else
    {
        printf("请输入姓名:>");
        scanf("%s",ps->date[ps->size].name);
        printf("请输入年龄:>");
        scanf("%d",&(ps->date[ps->size].age));
        printf("请输入性别:>");
        scanf("%s",ps->date[ps->size].sex);
        printf("请输入电话:>");
        scanf("%s",ps->date[ps->size].telephone);
        
        ps->size++;
        printf("添加成功!!!\n");
    }
}


//删除
void delete(struct Contact* ps)
{
    if(ps->size == 0)
    {
        printf("当前通讯录没有联系人\n");
    }
    else
    {
        printf("请输入要删除人的姓名?\n");
        char delname[30];
        scanf("%s",&delname);

        //1.查找要删除的人在什么位置
        int i = 0;
        for(i = 0 ; i < ps->size ; i++)
        {
            //字符串比较用strcmp
            if(0 == strcmp(ps->date[i].name , delname))
            {
                break;
            }
        }

        if(i == ps->size)
        {
            printf("不存在此人\n");
        }
        else
        {
            //删除
            int j = 0;
            for(j = i ; j < ps->size-1 ; j++)
            {
                ps->date[j] = ps->date[j + 1];
            }
            ps->size--;
            printf("删除成功!\n");
        }

    }
}

//改
void change_name(struct Contact* ps , int i)
{
    printf("请输入修改后的姓名>");
    char newname[30];
    scanf("%s",newname);

    //char* strcpy(char * destination , char * source);
    strcpy(ps->date[i].name , newname);
    printf("修改成功!!!\n");
}

void change_age(struct Contact* ps , int i)
{
    printf("请输入修改后的年龄>");
    int newage;
    scanf("%d",&newage);
    
    ps->date[i].age = newage;
    printf("修改成功!!!\n");
}
void change_sex(struct Contact* ps , int i)
{
    printf("请输入修改后的性别>");
    char newsex[20];
    scanf("%s",newsex);

    strcpy(ps->date[i].sex , newsex);
    printf("修改成功!!!\n");
}
void change_telephone(struct Contact* ps , int i)
{
    printf("请输入修改后的电话>");
    char newtelephone[20];
    scanf("%s",newtelephone);

    strcpy(ps->date[i].telephone , newtelephone);
    printf("修改成功!!!\n");
}
void change(struct Contact* ps)
{
    if(ps->size == 0)
    {
        printf("当前通讯录没有联系人\n");
    }
    else
    {
        printf("请输入要修改的人的姓名>");
        char changename[30];
        scanf("%s",changename);

        //找到要修改人的下标
        int i = 0;
        for(i = 0 ; i < ps->size ; i++)
        {
            if(0 == strcmp(ps->date[i].name , changename))
            {
                break;
            }   
        }
        if(i == ps->size)
        {
            printf("不存在此人\n");
        }
        else
        {
            //修改
            printf("**************************\n");
            printf("****1.name     2.age****\n");
            printf("****3.sex  4.telephone******\n");
            printf("**************************\n");
            printf("要修改什么?\t请选择>");

            int input;
            scanf("%d",&input);

            switch (input)
            {
                case 1:
                    change_name(ps,i);
                    break;
                case 2:
                    change_age(ps,i);
                    break;
                case 3:
                    change_sex(ps,i);
                    break;
                case 4:
                    change_telephone(ps,i);
                    break; 
                default:
                    printf("选择错误!!!\n");
                    break;
            }
        } 
    }
}


//查找
void find_name(struct Contact* ps)
{
    printf("请输入查找的人的姓名>");
    char find_name[30];
    scanf("%s",find_name);
    for(int i = 0 ; i < ps->size ; i++)
    {
        if(ps->date[i].name[30] == find_name[30])
        {
            printf("%-20s\t %-5s\t %-5s\t %-20s\n","名字","年龄","性别","电话");
            printf("%-20s \t %-5d\t %-5s\t %-20s \n",
            ps->date[i].name,
            ps->date[i].age,
            ps->date[i].sex,
            ps->date[i].telephone
            ); 
            break;
        }
    }
}
void find_age(struct Contact* ps)
{
    printf("请输入查找的人的年龄>");
    int find_age;
    scanf("%d",&find_age);
    for(int i = 0 ; i < ps->size ; i++)
    {
        if(ps->date[i].age == find_age)
        {
            printf("%-20s\t %-5s\t %-5s\t %-20s\n","名字","年龄","性别","电话");
            printf("%-20s \t %-5d\t %-5s\t %-20s \n",
            ps->date[i].name,
            ps->date[i].age,
            ps->date[i].sex,
            ps->date[i].telephone
            ); 
            break;
        }
    }
}
void find_sex(struct Contact* ps)
{
    printf("请输入查找的人的性别>");
    char find_sex[20];
    scanf("%s",find_sex);
    for(int i = 0 ; i < ps->size ; i++)
    {
        if(ps->date[i].sex[20] == find_sex[20])
        {
            printf("%-20s\t %-5s\t %-5s\t %-20s\n","名字","年龄","性别","电话");
            printf("%-20s \t %-5d\t %-5s\t %-20s \n",
            ps->date[i].name,
            ps->date[i].age,
            ps->date[i].sex,
            ps->date[i].telephone
            ); 
            break;
        }
    }
}
void find_telephone(struct Contact* ps)
{
    printf("请输入查找的人的电话>");
    char find_telephone[30];
    scanf("%s",find_telephone);
    for(int i = 0 ; i < ps->size ; i++)
    {
        if(ps->date[i].telephone[30] == find_telephone[30])
        {
            printf("%-20s\t %-5s\t %-5s\t %-20s\n","名字","年龄","性别","电话");
            printf("%-20s \t %-5d\t %-5s\t %-20s \n",
            ps->date[i].name,
            ps->date[i].age,
            ps->date[i].sex,
            ps->date[i].telephone
            ); 
            break;
        }
    }
}
void find(struct Contact* ps)
{
    printf("**************************\n");
    printf("****1.name     2.age****\n");
    printf("****3.sex  4.telephone******\n");
    printf("**************************\n");
    printf("根据什么进行查找?\t请选择>");

    int input;
    scanf("%d",&input);

    switch (input)
    {
        case 1:
            find_name(ps);
            break;
        case 2:
            find_age(ps);
            break;
        case 3:
            find_sex(ps);
            break;
        case 4:
            find_telephone(ps);
            break;    
        default:
            printf("选择错误!!!\n");
            break;
    }
}


//打印
void show(const struct Contact* ps)
{
    if(ps->size == 0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        int i = 0;
        printf("%-20s\t %-5s\t %-5s\t %-20s","名字","年龄","性别","电话");
        
        for(i = 0 ; i < ps->size ; i++)
        {
            printf("\n");
            printf("%-20s\t %-5d\t %-5s\t %-20s",
                ps->date[i].name,
                ps->date[i].age,
                ps->date[i].sex,
                ps->date[i].telephone
            );

        }
    }
    printf("\n");
}


int main()
{
    struct Contact con;//con就是通讯录,包含1000个元素的数和size6934502301850
    inti(&con);

    int input;
    do
    {
        print_Menu();
        scanf("%d",&input);   
        switch (input)
        {        
        case 0:
            break;
        case 1:
            add(&con);
            break;
        case 2:
            delete(&con);
            break;
        case 3:
            change(&con);
            break;
        case 4:
            find(&con);
            break;
        case 5:
            show(&con);
            break;    
        default:
            printf("选择错误!!!\n");
            break;
        }
    } 
    while (input);
    
    return 0;
}