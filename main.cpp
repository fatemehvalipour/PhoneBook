#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <windows.h>
struct info{

    char name [200];
    char id[50];
    char age[3];
    char field[50];
    char phnum[20];
    char address[400];
    char gender[20];
    struct info* next;
};
info *head;
info *findElement(int x)
{
    info *node = (info*)malloc(sizeof(info*));
    info *prev = (info*)malloc(sizeof(info*));
    node = head;
    int i=1;
    while (i != x)
        {
            i++;
            prev = node;
            node = node->next;
        }
    return prev;
}
info *findElement2(int x)
{
    info *node = (info*)malloc(sizeof(info*));
    info *prev = (info*)malloc(sizeof(info*));
    node = head;
    int i=1;
    while (i != x)
        {
            i++;
            prev = node;
            node = node->next;
        }
    return node;
}
void add_end(info *head,info *new_info)
{
    info *temp;
    temp = head;
    while(temp->next != NULL)
       {
           temp = temp->next;
       }
    temp->next=new_info;

}
void add_front(info **head,info *new_info)
{
    new_info->next = *head;
    *head = new_info;
}
void ReadFile()
{
    FILE *fp;
    fp = fopen("phone.txt","r");
    if ( fp == NULL )
    {
        printf("Data couldn`t be loaded.\n");
    }
    else
    {
    int x = 0;
	while (1) {
        info* temp = (info*)malloc(sizeof(info));
		fscanf(fp, "%s\n", temp->name);
		fscanf(fp, "%s\n", temp->id);
		fscanf(fp, "%s\n", (temp->age));
		fscanf(fp, "%s\n", (temp->field));
		fscanf(fp, "%s\n", temp->phnum);
		fscanf(fp, "%s\n", temp->address);
		fscanf(fp, "%s\n", temp->gender);
		temp->next = NULL;
		fseek(fp, 2, SEEK_CUR);
		x++;
		if(x == 1)
            add_front(&head,temp);
        else
            add_end(head,temp);
        char c = fgetc(fp);
        if(c == EOF){
            break;
        }
        fseek(fp,-1, SEEK_CUR);
	         }
    }
	fclose(fp);
	printf("The information has been loaded from file.\n");
	printf("\n");
}

void print_all();
void delete1()
{
    print_all();
    if (head != NULL)
    {
        int x;
        char a;
        printf("which contact do you want to delete?(enter the number)\n");
        scanf("%d",&x);
        printf("\n");
        info *prev = (info*)malloc(sizeof(info));
        info *current = (info*)malloc(sizeof(info));
        info *temp = (info*)malloc(sizeof(info));
        prev = findElement(x);
        current = findElement2(x);
        printf("this is the contact:\n");
                printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",current->name,current->id,current->age,current->field,current->phnum,current->address,current->gender);
                printf("\n");
                printf("Are you sure you want to delete it?(y/n)\n");
                a = getche();
                printf("\n");
                printf("\n");
                if(a == 'y')
                   {
                        if(current == head)
                       {
                            temp = current->next;
                            free(current);
                            head = temp;
                       }
                       else
                       {
                           temp = current->next;
                           free(current);
                           prev->next = temp;
                       }
                    printf("The requested account has been deleted.\n");
                    printf("\n");
                   }
                   else if(a == 'n')
                       {
                           printf("Your account has not been deleted.\n");
                           printf("\n");
                       }
    }
}
void editN()
{
    char str[200];
    print_all();
    if(head != NULL)
    {
        int x;
        printf("which contact do you want to edit?(enter the number).\n");
        scanf("%d",&x);
        printf("enter the new name:\n");
        scanf("%s",str);
        info* node;
        node = (info*)malloc(sizeof(info));
        node = findElement2(x);
        strcpy(node->name,str);
        printf("this is the edited contact:\n");
        printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",node->name,node->id,node->age,node->field,node->phnum,node->address,node->gender);
        printf("\n");
    }
}
void editId()
{
    char str[50];
    print_all();
    if(head != NULL)
    {
        int x;
        printf("which contact do you want to edit?(enter the number).\n");
        scanf("%d",&x);
        printf("enter the new ID:\n");
        scanf("%s",str);
        info* node;
        node = (info*)malloc(sizeof(info));
        node = findElement2(x);
        strcpy(node->id,str);
        printf("this is the edited contact:\n");
        printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",node->name,node->id,node->age,node->field,node->phnum,node->address,node->gender);
        printf("\n");
      }
}

void editPhnum()
{
    char str[20];
    print_all();
    if(head != NULL)
    {
        int x;
        printf("which contact do you want to edit?(enter the number).\n");
        scanf("%d",&x);
        printf("enter the new phone number:\n");
        scanf("%s",str);
        info* node;
        node = (info*)malloc(sizeof(info));
        node = findElement2(x);
        strcpy(node->phnum,str);
        printf("this is the edited contact:\n");
        printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",node->name,node->id,node->age,node->field,node->phnum,node->address,node->gender);
        printf("\n");
     }
}

void searchN()
{
    char *name = (char*)malloc(200*sizeof(char));
    info *current = (info*)malloc(sizeof(info));
    current = head;
   if (current == NULL)
        printf("The list is empty.\n");
    else
    {
        printf("Enter the name you want to search: \n");
        scanf("%s",name);
        printf("\n");
        int x=0;
        for(current = head;current != NULL;current = current->next)
        {
            if(strcmp(current->name,name) == 0)
            {

                 printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",current->name,current->id,current->age,current->field,current->phnum,current->address,current->gender);
                 printf("\n");
                 x++;
            }
        }
        if(x==0)
            printf("The search did not have any results.\n");
     }
}
void search_id()
{
    char *id = (char*)malloc(50*sizeof(char));
    info *current = (info*)malloc(sizeof(info));
    current = head;
    if (current == NULL)
        printf("The list is empty.\n");
    else
    {
        printf("Enter the Id you want to search:\n");
        scanf("%s",id);
        int x=0;
        for(current = head;current != NULL;current = current->next)
        {
            if(strcmp(current->id,id) == 0)
            {
                 printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",current->name,current->id,current->age,current->field,current->phnum,current->address,current->gender);
                 printf("\n");
                 x++;
            }
        }
        if(x == 0)
            printf("The search did not have any results.\n");
    }
}
void search_age()
{
    char *age = (char*)malloc(3*sizeof(char));
    info *current = (info*)malloc(sizeof(info));
    current = head;
if (current == NULL)
        printf("The list is empty.\n");
    else
    {
        printf("Enter the age you want to search:\n");
        scanf("%s",age);
        int x=0;
        for(current = head;current != NULL;current = current->next)
        {
            if(strcmp(current->age,age) == 0)
            {
                 printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",current->name,current->id,current->age,current->field,current->phnum,current->address,current->gender);
                 printf("\n");
                 x++;
            }
        }
        if(x == 0)
            printf("The search did not have any results.\n");
    }
}
void search_phnum()
{
    char *phnum = (char*)malloc(50*sizeof(char));
    info *current = (info*)malloc(sizeof(info));
    current = head;
if (current == NULL)
        printf("The list is empty.\n");
    else
    {
        printf("Enter the phone number you want to search:\n");
        scanf("%s",phnum);
        int x=0;
        for(current = head;current != NULL;current = current->next)
        {
            if(strcmp(current->phnum,phnum) == 0)
            {
                 printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",current->name,current->id,current->age,current->field,current->phnum,current->address,current->gender);
                 printf("\n");
                 x++;
            }
        }
        if(x == 0)
            printf("The search did not have any results.\n");
    }
}
void search_address()
{
    char *address = (char*)malloc(400*sizeof(char));
    info *current = (info*)malloc(sizeof(info));
    current = head;
if (current == NULL)
        printf("The list is empty.\n");
    else
    {
        printf("Enter the address you want to search:\n");
        scanf("%s",address);
        int x=0;
        for(current = head;current != NULL;current = current->next)
        {
            if(strcmp(current->address,address) == 0)
            {
                 printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",current->name,current->id,current->age,current->field,current->phnum,current->address,current->gender);
                 printf("\n");
                 x++;
            }
        }
        if(x == 0)
            printf("The search did not have any results.\n");
    }
}
void search_field()
{
    char *field = (char*)malloc(50*sizeof(char));
    info *current = (info*)malloc(sizeof(info));
    current = head;
if (current == NULL)
        printf("The list is empty.\n");
    else
    {
        printf("Enter the address you want to search:\n");
        scanf("%s",field);
        int x=0;
        for(current = head;current != NULL;current = current->next)
        {
            if(strcmp(current->field,field) == 0)
            {
                 printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",current->name,current->id,current->age,current->field,current->phnum,current->address,current->gender);
                 printf("\n");
                 x++;
            }
        }
        if(x == 0)
            printf("The search did not have any results.\n");
    }
}
void search_gender()
{
    char *gender = (char*)malloc(20*sizeof(char));
    info *current = (info*)malloc(sizeof(info));
    current = head;
if (current == NULL)
        printf("The list is empty.\n");
    else
    {
        printf("male or female?\n");
        scanf("%s",gender);
        int x=0;
        for(current = head;current != NULL;current = current->next)
        {
            if(strcmp(current->gender,gender) == 0)
            {
                 printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",current->name,current->id,current->age,current->field,current->phnum,current->address,current->gender);
                 printf("\n");
                 x++;
            }
        }
        if(x==0)
            printf("The search did not have any results.\n");
    }
}
void insertAfter(info*temp)
{
    int x;
    info *current = (info*)malloc(sizeof(info*));
    print_all();
    if(head != NULL)
    {
        printf("enter the number of contact that you want to add a new contact after it:\n");
        scanf("%d",&x);
        current = findElement2(x);
        temp->next = current->next;
        current->next = temp;
        printf("%s ,%s ,%s ,%s ,%s ,%s ,%s \n",current->next->name,current->next->id,current->next->age,current->next->field,current->next->phnum,current->next->address,current->next->gender);
        printf("\n");
        printf("new contact added.\n");
    }
}
void print_all()
{

    info *temp = (info*)malloc(sizeof(info*));
    temp = head;
    if(temp == NULL)
        printf("The list is empty.\n");
    else
    {
        int n = 1;
        while(temp != NULL)
        {
           printf("contact %d : %s ,%s ,%s ,%s ,%s ,%s ,%s \n",n,temp->name,temp->id,temp->age,temp->field,temp->phnum,temp->address,temp->gender);
           printf("\n");
           n++;
           temp = temp->next;
        }
    }
}
void insertEnd(info *ptr)
{
    if(head == NULL)
        add_front(&head,ptr);
    else
        add_end(head,ptr);
    printf("new element added.\n");

}

void CopyToFile()
{
    FILE *fp;
    info *cur;
    fp = fopen("phone.txt","w");
    cur = head;
    if(cur == NULL)
    {
        printf("nothing to write back in the file...\n");
        return;
    }
    for(cur = head; (cur); cur = cur->next){
        if(cur->next != NULL){
            fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n-\n",cur->name,cur->id,cur->age,cur->field,cur->phnum,cur->address,cur->gender);
        } else {
            fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n-",cur->name,cur->id,cur->age,cur->field,cur->phnum,cur->address,cur->gender);
        }
    }
    fclose(fp);
}
void menu()
{
    puts("What do you want to do?\n");
    puts("1.insert a new contact.\n");
    puts("2.search between contacts.\n");
    puts("3.print  all of the contacts.\n");
    puts("4.delete one of the contacts.\n");
    puts("5.edit the name of the contacts.\n");
    puts("6.load the information from a file.\n");
    puts("7.exit.\n");
    puts("enter a number between 1 to 7:\n");
}
int searchAdd(info * temp)
{
    info *current = (info*)malloc(sizeof(info));
    current = head;
    int a = 0;
    for(current = head;current != NULL;current = current->next)
        {
            if(strcmp(current->name,temp->name) == 0)
            {
                 if(strcmp(current->id,temp->id) == 0)
                {
                    if(strcmp(current->age,temp->age) == 0)
                    {
                         if(strcmp(current->field,temp->field) == 0)
                            {
                                if(strcmp(current->phnum,temp->phnum) == 0)
                                {
                                     if(strcmp(current->address,temp->address) == 0)
                                    {
                                        if(strcmp(current->gender,temp->gender) == 0)
                                        {
                                             a = 1;
                                        }
                                    }
                                }
                            }
                    }
                }
            }

    return a;
}
}
info* enterinfo()
{
    info *ptr = (info*)malloc(sizeof(info));
    puts("enter the information:\n");
    printf("name : ");
        scanf("%s",ptr->name);
        getchar();
        printf("id : ");
        scanf("%s",ptr->id);
        getchar();
        printf("age : ");
        scanf("%s",(ptr->age));
        getchar();
        printf("field : ");
        scanf("%s",ptr->field);
        getchar();
        printf("phone number : ");
        scanf("%s",ptr->phnum);
        getchar();
        printf("address : ");
        scanf("%s",ptr->address);
        getchar();
        printf("male or female? : ");
        scanf("%s",ptr->gender);
        getchar();
        printf("\n");
        ptr->next=NULL;
    return ptr;

}
int main()
{
    int n;
    menu();
    do
    {
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        {
            system("color 3F");
            info *fat = (info*)malloc(sizeof(info));
            system("cls");
            fat = enterinfo();
            if (head == NULL)
                insertEnd(fat);
            else if(searchAdd(fat))
                insertEnd(fat);
            else
                insertAfter(fat);
            CopyToFile();
            printf("press any key to go back to menu \n");
            getch();
            system("cls");
            menu();
           break;
       }
    case 2:
        int t;
        system("cls");
        system("color 2F");
        puts("What kind of search do you want to do?\n");
        puts("1.name\n");
        puts("2.Id\n");
        puts("3.age\n");
        puts("4.field\n");
        puts("5.phone number\n");
        puts("6.address\n");
        puts("7.gender\n");
        scanf("%d",&t);
        switch(t)
        {
        case 1:
            system("cls");
            searchN();
            break;
        case 2:
            system("cls");
            search_id();
            break;
        case 3:
            system("cls");
            search_age();
            break;
        case 4:
            system("cls");
            search_field();
            break;
        case 5:
            system("cls");
            search_phnum();
            break;
        case 6:
            system("cls");
            search_address();
            break;
        case 7:
            system("cls");
            search_gender();
            break;
        }
        printf("press any key to go back to menu... \n");
        getch();
        system("cls");
        menu();
        break;
    case 3:
        system("cls");
        system("color 8F");
        print_all();
        CopyToFile();
        printf("press any key to go back to menu \n");
        getch();
        system("cls");
        menu();
        break;
    case 4:
        system("cls");
        system("color 4F");
        delete1();
        CopyToFile();
        printf("press any key to go back to menu \n");
        getch();
        system("cls");
        menu();
        break;
    case 5:
        int s;
        system("cls");
        system("color F0");
        puts("What kind of edit do you want to do?\n");
        puts("1.name\n");
        puts("2.Id\n");
        puts("3.phone number\n");
        scanf("%d",&s);
        switch(s)
        {
        case 1:
            system("cls");
            editN();
            break;
        case 2:
            system("cls");
            editId();
            break;
        case 3:
            system("cls");
            editPhnum();
            break;
        }
        CopyToFile();
        printf("press any key to go back to menu \n");
        getch();
        system("cls");
        menu();
        break;
    case 6:
        system("cls");
        system("color 3F");
        ReadFile();
        CopyToFile();
        printf("press any key to go back to menu \n");
        getch();
        system("cls");
        menu();
        break;
    case 7:
        {
            system("cls");
            system("color 1F");
            char str[]="thanks for using my phone book.";
            for(int k=0;k<strlen(str);k++)
            {
                printf("%c",str[k]);
                usleep(100000);
            }
            printf("\n");
            break;
        }
    }
    }while(n != 7);
    return 0;
}
