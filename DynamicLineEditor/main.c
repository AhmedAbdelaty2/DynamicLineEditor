#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

void gotoxy1(int x, int y);


int main()
{
    char *ptr;
    int s,l;
    int x=0,y=0;
    char in;
    int i,len;

    printf("Please, Enter the number of characters: ");
    scanf("%d",&s);
    system("cls");
    l = s + 1;

    ptr = (char*)malloc(l*sizeof(char));

    if(ptr != NULL)
    {
        for(i=0;i<l;i++)
        {
            ptr[i] = '\0';
        }

        while(in != 13) //Press Enter to End The Program
        {
            gotoxy1(x,y);
            in=getch();

            if(in==-32)
            {
                in=getch();

                if(in==77) //Right Arrow
                {
                    len = strlen(ptr);

                    if(x>len-1)
                        x=0;

                    else
                        x++;
                }

                else if(in==75) //Left Arrow
                {
                    len = strlen(ptr);

                    if(x<1)
                        x=len;

                    else
                        x--;
                }

                else if(in == 79) //End key
                {
                    len = strlen(ptr);
                    x = len;
                }

                else if(in == 71) //Home key
                    x = 0;

                 else if(in == 82) //Insert Key
                {
                    len = strlen(ptr);

                    if(len==s)
                        ptr[len-1] = '\0';

                    for(i=len;i>x;i--)
                    {
                        ptr[i]=ptr[i-1];
                    }

                    ptr[x]=' ';

                    system("cls");
                    printf("%s",ptr);

                    gotoxy1(x,y);
                    in = getch();

                    ptr[x] = in;

                    system("cls");
                    printf("%s",ptr);
                }

                else if(in == 83) //Delete Key
                {
                    ptr[x]=' ';

                    system("cls");
                    printf("%s",ptr);

                    gotoxy1(x,y);
                    in = getch();

                    ptr[x] = in;

                    system("cls");
                    printf("%s",ptr);
                }
            }

            else if(in == 8) //BackSpace Key
            {
                len = strlen(ptr);

                if (x>0)
                {
                    for(i=x;i<len;i++)
                    {
                        ptr[i-1]=ptr[i];
                    }

                    ptr[len-1]='\0';
                    x--;

                    system("cls");
                    printf("%s",ptr);
                }
            }

            else if(in>=32 && in<=127) //Normal Insert
            {
                len = strlen(ptr);

                if (len < s)
                {
                    for(i=len;i>x;i--)
                    {
                        ptr[i]=ptr[i-1];
                    }

                    ptr[x] = in;

                    system("cls");
                    printf("%s",ptr);

                    if(x==s-1)
                        x=0;

                    else
                        x++;
                }
            }
        }

        gotoxy1(20,20);
        printf("%s",ptr);

        free(ptr);
    }

    return 0;
}

void gotoxy1(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
