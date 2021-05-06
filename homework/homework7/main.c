/*
How to compile?
¡¡KEEP IN MIND THAT USING GDB AND THE TIME.h LIBRARY GIVES US A DIFFERENT TIME from MEXICO!!
It is recommended to use the online gdb compiler
This file goes in the main.c, the file registers.h is created using Ctrl m or clicking in the new file button
and put what is in the repository with that name
With ctrl m or clicking in the file button you need to create system.txt // entries.txt // exits.txt // report.txt // schedule.txt
¡¡IMPORTANT!!
In system.txt there are 10
lines (9 lines and 1 blank)
In entries.txt there are 12 lines (11 lines and 1 blank)
In exits.txt there are 12 lines (11 lines 1 blank)
In report.txt there are 16 lines (15 lines and 1 blank)
In schedule.txt there are 27 lines (26 lines and 1 blank)
When saying a blank, an enter must be given
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "registers.h"

int main()
{
    header();
    int i;
    int j;
    int temporarypin;
    matrix = (int**)malloc(sizeof(int*) * USERS);
    for (i = 0; i < USERS; i ++)
    {
            matrix[i] = (int*)malloc(sizeof(int) * 6);
            for (j=0; j<6; j++)
            {
            matrix[i][j]=-1;
     }
    }
    int exit=0;
    int option=0;
    while(exit==0)
    {
        int limit;
        limit=count();
        printf("\nIn this moment there are %d registered workers\n", limit);
        printf("This program use the function scanf, please check that your input is correct before you click enter\n");
        printf("Welcome!!!\nWrite\n1 To register a entry\n2 To registrer a exit\n3 To register a worker\n4 To close the program\n");
        scanf("%d", &option);
        if (option==1)
        {
        printf("What is your pin?\n");
        scanf("%d", &temporarypin);
        
        if (temporarypin<=0)
        {
            printf("Invalid entry\n");
        }
            else if (temporarypin<=limit){
               
                if (matrix[temporarypin-1][1]==-1){ 
                    entryorexit(temporarypin, 0);
                }
                else
                {
                    printf("Your entry has already been registered\n");
             }
            }
            else
            {
                printf("In this moment there are %d workers you cant use this pin\n", limit);
         }
        }
        else if (option==2)
        {
        printf("What is your pin?\n");
        scanf("%d", &temporarypin);
        
        if (temporarypin<=0){
            printf("Invalid entry\n");
        }
            else if (temporarypin<=limit)
            {
                if (matrix[temporarypin-1][1]!=-1)
                {  
                    entryorexit(temporarypin, 1);
                }
                else
                {
                    printf("To register an exit, an entry had to be registered\n");
             }
            }
            else
            {
                printf("In This moment there are %d workers you cant use this pin\n", limit);
         }
        }
        else if (option==3)
        {
            registrar();
        }
        else if (option==4)
        {
            int flag=0;
            for (i=0; i<MAX; i++)
            {
                if(matrix[i][0]*matrix[i][1]*matrix[i][2]>0&&matrix[i][3]*matrix[i][4]*matrix[i][5]<0)
                {
                    flag=-1; 
                    printf("Error: The user with the pin <%d> registered a entry but not a exit\n\n", i+1);
             }
            }
            if (flag==0)
            {
            schedule();
            printf("Have a nice day!!\n");
            exit=1;
         }
        }
        else
        {
            printf("Option not available\n\n");
     }
    }
    return 0;
}

int count()
{
    FILE* system = fopen("system.txt", "r");
    char c;
    int count=0;
    while ((c = fgetc(system)) != EOF)
    {
    if (c == '\n') 
    {
      count++; 
     }
    }
    
    return count;
}
void registrar()
{
    int pin;
    pin=count()+1;
    char user[MAX];
    int sunday;
    int monday;
    int tuesday;
    int wednesday;
    int thursday;
    int friday;
    int saturday;
    int hour;
    int min;
    int work;
    printf("The pin for this user will be <%d>\n", pin);
    registrados++;
    printf("What will the username be?\n");
    scanf("%s", user);
    
     do
     {
        printf("\nWrite 0 (False) and 1 (True) in the days that the user will work\nExample: 1 0 0 1 0 1 0\nThere will be at least a 1\n");
        printf("Make sure to write 7 numbers\n");
        printf("Sun Mon Tue Wed Thu Fri Sat\n");
        scanf("%d %d %d %d %d %d %d", &sunday, &monday, &tuesday, &wednesday, &thursday, &friday, &saturday);
    } while(sunday+monday+tuesday+wednesday+thursday+friday+saturday==0||sunday!=0&&sunday!=1||monday!=0&&monday!=1||tuesday!=0&&tuesday!=1||wednesday!=0&&wednesday!=1||thursday!=0&&thursday!=1||friday!=0&&friday!=1||saturday!=0&&saturday!=1);
    
    do 
    {
        printf("\nWrite at what hour and minute you will work (write it separated by a space)\n");
        printf("Example: 10 26\n");
        scanf("%d %d", &hour, &min);
    } while(hour<0||hour>23||min<0||min>60);
        
    do 
    {
        printf("\nHow many second you will work? (write a number between 1 and 60)\n");
        scanf("%d", &work);
    }
    while(work<=0||work>60);
    printf("Successful registration\n\n");
    
    FILE* writesystem = fopen("system.txt", "a");
    fprintf(writesystem, "%d %s %d %d %d %d %d %d %d %d %d %d\n",pin, user, sunday, monday,tuesday,wednesday,thursday,friday,saturday, hour, min, work);
    fclose(writesystem);
}

void entryorexit(int pin, int status)
{
    int difference=0; 
    time_t timenow;
    time(&timenow);
    struct tm *mytime = localtime(&timenow);
    int actualsec=mytime->tm_sec;
    int actualmin=mytime->tm_min;
    int actualhour=mytime->tm_hour;
    int actualyear=mytime->tm_year+1900;
    int actualmonth=mytime->tm_mon+1;
    int actualday=mytime->tm_mday;
    int actualwday=mytime->tm_wday;
    if (status==0)
    { 
    FILE* entry = fopen("entries.txt", "a");
    fprintf(entry, "%d %d %d/%d/%d %d:%d:%d\n", pin, actualwday, actualday, actualmonth, actualyear, actualhour, actualmin, actualsec);
    fclose(entry);
    matrix[pin-1][0]=actualhour;
    matrix[pin-1][1]=actualmin;
    matrix[pin-1][2]=actualsec;
    printf("Registered entry\n");
    }
    if (status==1)
    {
    FILE* exit = fopen("exits.txt", "a"); 
    fprintf(exit, "%d %d %d/%d/%d %d:%d:%d\n", pin, actualwday, actualday, actualmonth, actualyear, actualhour, actualmin, actualsec);
    fclose(exit);
    printf("Registered exit\n");
    matrix[pin-1][3]=actualhour;
    matrix[pin-1][4]=actualmin;
    matrix[pin-1][5]=actualsec;
    FILE* report = fopen("report.txt", "a");
    if (totalofexits==0)
    {
        fprintf(report, "Report generated in "); 
            switch(actualwday)
            {
                case 0:
                fprintf(report, "Sunday");
                break;
                case 1:
                fprintf(report, "Monday");
                break;
                case 2:
                fprintf(report, "Tuesday");
                break;
                case 3:
                fprintf(report, "Wednesday");
                break;
                case 4:
                fprintf(report, "Thursday");
                break;
                case 5:
                fprintf(report, "Friday");
                break;
                case 6:
                fprintf (report, "Saturday");
                break;
            }
        fprintf(report, " %d/%d/%d\n", actualday, actualmonth, actualyear);
    } 
    
    difference=(matrix[pin-1][3]*3600+matrix[pin-1][4]*60+matrix[pin-1][5])-(matrix[pin-1][0]*3600+matrix[pin-1][1]*60+matrix[pin-1][2]);
    int hourpin=matrix[pin-1][0];
    int minpin=matrix[pin-1][1];
    int secondpin=matrix[pin-1][2];                                                                             
    fprintf(report, "The worker with the pin <%d> enter at the hour: <%d:%d:%d> on the day: <%d/%d/%d> work %d seconds\n", pin, hourpin, minpin, secondpin, actualday, actualmonth, actualyear, difference);
    fclose(report);
    matrix[pin-1][0]=-1;
    matrix[pin-1][1]=-1;
    matrix[pin-1][2]=-1;
    matrix[pin-1][3]=-1;
    matrix[pin-1][4]=-1;
    matrix[pin-1][5]=-1;
    
    totalofexits=9; 
 }
}

void header()
{
    time_t timenow;
    time(&timenow);
    struct tm *mytime = localtime(&timenow);
    switch(mytime->tm_wday)
    {
        case 0:
        printf("Today is Sunday\n");
        break;
        case 1:
        printf("Today is Monday\n");
        break;
        case 2:
        printf("Today is Tuesday\n");
        break;
        case 3:
        printf("Today is Wednesday\n");
        break;
        case 4:
        printf("Today is Thursday\n");
        break;
        case 5:
        printf("Today is Friday\n");
        break;
        case 6:
        printf ("Today is Saturday\n");
        break;
    }
    printf("Day: %d/%d/%d\n", mytime->tm_mday, mytime->tm_mon+1, mytime->tm_year+1900); 
    printf("Hour: %d:%d\n", mytime->tm_hour, mytime->tm_min);
    printf("The maximum number of users that can be in the system are %d\n", USERS);
}

void schedule()
{
    time_t timenow;
    time(&timenow);
    int pinread;
    char userread[MAX];
    int sundayschedule;
    int mondayschedule;
    int tuesdayschedule;
    int wednesdayschedule;
    int thursdayschedule;
    int fridayschedule;
    int saturdayschedule;
    int hourread;
    int minuteread;
    int work;
    int i;
    struct tm *mitiempo = localtime(&timenow);
    FILE* readsystem = fopen("systema.txt", "r");
    FILE* writeschedule = fopen("schedule.txt", "w");
    char c;
    int count;
    while (fscanf(readsystem, "%d %s %d %d %d %d %d %d %d %d %d %d\n", &pinread, userread, &sundayschedule, &mondayschedule, &tuesdayschedule, &wednesdayschedule, &thursdayschedule, &fridayschedule, &saturdayschedule, &hourread, &minuteread, &work) == 12) 
    {
    fprintf(writeschedule, "The user <%s> with the pin <%d> will enter at: %d:%d will work for <%d segundos> the days:\n", userread, pinread,hourread, minuteread, work);
    if (sundayschedule==1)
    fprintf(writeschedule, "sunday ");
    if (mondayschedule==1)
    fprintf(writeschedule, "monday ");
    if (tuesdayschedule==1)
    fprintf(writeschedule, "tuesday ");
    if (wednesdayschedule==1)
    fprintf(writeschedule, "wednesday ");
    if (thursdayschedule==1)
    fprintf(writeschedule, "thursday ");
    if (fridayschedule==1)
    fprintf(writeschedule, "friday ");
    if (saturdayschedule==1)
    fprintf(writeschedule, "saturday ");
    fprintf(writeschedule, "\n\n");    
    }
    fclose(readsystem);
    fclose(writeschedule);
}
