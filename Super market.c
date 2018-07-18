#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
void dmod();
void AI();
void DI();
void IE();
void EI();
long long int gid()
{
    long long int x;
    FILE *fp;
    fp=fopen("sid.dat","r");
    fscanf(fp,"%lld",&x);
    fclose(fp);
    return x;

}
void sid(long long int x)
{
    FILE *fp;
    fp=fopen("sid.dat","w");
    fprintf(fp,"%lld",x);
    fclose(fp);
}
void doc();
void exit();
void show();
long long int j,k,l,m,n,o,p;
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void era(int x,int y)
{
    int i;
    gotoxy(x,y);
    for(i=0; i<=80; i++)
        printf(" ");
    gotoxy(x,y);
}

void ani()
{
    int i;
    for (i=55; i>=27; i--)
    {
        Sleep(20);
        gotoxy(i,5);
    }
    for (i=27; i<=55; i++)
    {
        Sleep(20);
        gotoxy(i,5);
    }
}
int t(int x,int y)
{
    time_t t = time(0);
    struct tm * now = localtime( & t );
    gotoxy(x,y);
    printf("Date: %d-%d-%d ",now->tm_mday,now->tm_mon+1,now->tm_year-100);
    gotoxy(x,y+2);
    printf("Time: %d:%d",now->tm_hour, now->tm_min);
    return 0;
}
long long int D()
{
    time_t t = time(0);
    struct tm * now = localtime( & t );
    return ((now->tm_mday*100+(now->tm_mon+1))*100+(now->tm_year-100));
}

void mmenu()
{
    system("cls");
    gotoxy(24,5);
    printf("WELCOME TO SUPER MARKET BILLING SYSTEM");
    gotoxy(22,6);
    printf("=========================================");
f:
    gotoxy(22,8);
    printf("...PLEASE CHOOSE FROM THE MENU IELOW...");

    t(65,22);
    gotoxy(14,12);
    printf("\n\t\t1.Bill Report\n\n");
    printf("\t\t2.Add/Remove/Edit Item\n\n");
    printf("\t\t3.Show Item Detls\n\n");
    printf("\t\t4.Exit\n\n");
    gotoxy(10,25);
    printf("(PLEASE PRESS OPTION NUMIER ONLY)");
    char ch;
    gotoxy(10,26);
    ch=getche();
    switch(ch)
    {
        era(10,26);
//    case 'U':
//        era(10,26);
//        AI();
//        break;
//    case '1':
//        era(10,26);
//        br();
//        break;
    case '4':
        era(10,26);
        gotoxy(10,25);
        printf("ARE YOU SURE WANT TO EXIT ?? Y/N");
        ch=getche();
        era(10,25);
        if(toupper(ch)=='Y')
        {
            gotoxy(10,25);
            sid(j);
            break;
        }
        else
        {
            era(10,26);
            goto f;
        }
    case '2':
        era(10,26);
        IE();
        break;
    case '3':
        era(10,26);
        show();
        break;
    default:
        era(10,26);
        gotoxy(10,27);
        printf("PLEASE PRESS VALID OPTIONS ONLY (1,2,3,4)");
        Sleep(500);
        printf(".  ");
        Sleep(1000);
        printf(".  ");
        Sleep(1000);
        printf(".");
        Sleep(500);
        era(10,27);
        goto f;
    }
}
main()
{
    j=gid();
    char a,b[10000];
    FILE *fp;
    mmenu();
//    fp=fopen("new cus.dat","a");
//    while(gets(b))
//    {
//        fputs(b,fp);
//        fputs("\n",fp);
//    }
//    fclose(fp);
//    fp=fopen("neew cus.dat","r");
//    char c[121];
//    while(fscanf(fp,"%s",c)!=EOF)
//    {
//        puts(c);
//    }
//    fclose(fp);
}
void AI()
{
    system("cls");
    fflush(stdin);
    gotoxy(30,5);
    printf("ADDING ITEM");
    gotoxy(28,6);
    printf("==============");
    gotoxy(5,14);
    printf("ITEM ID: %lld",j);
    gotoxy(5,16);
    printf("ITEM NAME: ");
    gotoxy(5,18);
    printf("PRICE: ");
    gotoxy(5,20);
    printf("QUANTITY: ");
    char s1[10000];
    long long int p,q;
    gotoxy(16,16);
    gets(s1);
    gotoxy(13,18);
    scanf("%lld",&p);
    gotoxy(16,20);
    scanf("%lld",&q);
    FILE *fp;
    fp=fopen("storei.dat","a");
    fprintf(fp,"%lld %s %lld %lld\n",j,s1,p,q);
    fclose(fp);
    j++;
    printf("\n\nPRESS 'R' TO RETURN PREVIUS MENU OR 'A' TO ADD AGAIN\n");
    char c;
    f:c=getche();
    switch(toupper(c))
    {

    case 'R':
        era(10,26);
        IE();
        break;
    case 'A':
       AI();
       break;
    default:
        era(10,26);
        gotoxy(10,27);
        printf("PLEASE PRESS VALID OPTIONS ONLY (R,A)");
        Sleep(500);
        printf(".  ");
        Sleep(1000);
        printf(".  ");
        Sleep(1000);
        printf(".");
        Sleep(500);
        era(10,27);
        goto f;
    }
}
void IE()
{
    system("cls");
    gotoxy(35,5);
    printf("ITEM EDITOR");
    gotoxy(33,6);
    printf("===============");
    //gotoxy(23,8);
    //printf("PLEASE USE \"_\" INSTEAD OF SPACEBAR");
    gotoxy(5,14);
    printf("1.ADD ITEM");
    gotoxy(5,16);
    printf("2.EDIT ITEM DETLS");
    gotoxy(5,18);
    printf("3.REMOVE ITEM");
    gotoxy(5,20);
    printf("4.RETURN PREVIOUS MENU");
    gotoxy(27,14);
    char c;
    f:c=getche();
    switch(c)
    {
    case '1':
        AI();
        break;
//    case '2':
//        EI();
//        break;
    case '3':
        DI();
        break;
    case '4':
        mmenu();
        break;
    default:
        era(5,25);
        gotoxy(5,25);
        printf("PLEASE PRESS CORRECT CHARACTERS ONLY(R,A)");
        Sleep(500);
        printf(".  ");
        Sleep(1000);
        printf(".  ");
        Sleep(1000);
        printf(".");
        Sleep(500);
        era(5,25);
        goto f;
    }

}
void DI()
{
    FILE *fp;
    long long int ii,p,q,i=0,jj;
    char s6[1000];
    system("cls");
    gotoxy(30,5);
    printf("DELETE ITEM\n\n");
    fp=fopen("storei.dat","r");
    while(fscanf(fp,"%lld %s %lld %lld",&ii,s6,&p,&q)!=EOF)
    {
        printf("%d. ",++i);
        printf("%lld %s %lld %lld\n",ii,s6,p,q);
    }
    fclose(fp);
    i=0;
    printf("\nPLEASE ENTER ITEM NUMBER TO BE DELETED: ");
    char c;
    scanf("%d",&jj);
    FILE *fp1;
    fp1=fopen("t.dat","w");
    fp=fopen("storei.dat","r");
    while(fscanf(fp,"%lld %s %lld %lld",&ii,s6,&p,&q)!=EOF)
    {
        i++;
        if(i==jj)
            continue;
        fprintf(fp1,"%lld %s %lld %lld\n",ii,s6,p,q);
    }
    fclose(fp);
    fclose(fp1);
    remove("storei.dat");
    rename("t.dat","storei.dat");
    printf("\n\nPRESS 'R' TO RETURN PREVIUS MENU OR 'D' TO DELETE AGAIN\n");
    f:c=getche();
    switch(toupper(c))
    {

    case 'R':
        era(10,26);
        mmenu();
        break;
    case 'D':
       DI();
       break;
    default:
        era(10,26);
        gotoxy(10,27);
        printf("PLEASE PRESS VALID OPTIONS ONLY (R,D)");
        Sleep(500);
        printf(".  ");
        Sleep(1000);
        printf(".  ");
        Sleep(1000);
        printf(".");
        Sleep(500);
        era(10,27);
        goto f;
    }
}
void show()
{
    FILE *fp;
    system("cls");
    long long int p,q,i,pp=0,qq=0;
    char s[100];
    printf("ITEM ID    ITEM NAME    ITEM PRICE    ITEM QUANTITY\n\n");
    fp=fopen("storei.dat","r");
    while(fscanf(fp,"%lld %s %lld %lld",&i,s,&p,&q)!=EOF)
    {
        printf("%lld    %s         %lld BDT       %lld\n",i,s,p,q);
        pp=pp+(p*q);
        qq=qq+q;
    }
    fclose(fp);
    printf("\n\n\nTOTAL ITEM: %lld\n\nTOTAL PRICE: %lld BDT",qq,pp);
    printf("\n\nPRESS 'R' TO RETURN PREVIUS MENU\n");
    char c;
    f:
    c=getche();
    switch(toupper(c))
    {

    case 'R':
        era(10,26);
        mmenu();
        break;
    default:
        era(10,26);
        gotoxy(10,27);
        printf("PLEASE PRESS VALID OPTIONS ONLY (R)");
        Sleep(500);
        printf(".  ");
        Sleep(1000);
        printf(".  ");
        Sleep(1000);
        printf(".");
        Sleep(500);
        era(10,27);
        goto f;
    }

}
