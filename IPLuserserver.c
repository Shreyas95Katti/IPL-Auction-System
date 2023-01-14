#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "IPLheaderfile.h"
void bidding()
{
    char cha;
    printf("Welcome to the ipl auctions!\n");
    printf("This program needs three representatives of the three teams participating in the ipl.\n");
    printf("Get ready to bid.............\n");
    printf("Press any key to continue:\n");
    cha=getch();
    auct p1;
    char *p;
    FILE *fp=fopen("PlayersList.csv","r");
    FILE *fp1=fopen("Team1.csv","w");
    FILE *fp2=fopen("Team2.csv","w");
    FILE *fp3=fopen("Team3.csv","w");
    if(fp==NULL||fp1==NULL||fp2==NULL||fp3==NULL)
    {
        printf("File did not successfully open\n");
        //return 0;
    }
    else
    {
        rewind(fp);
        int i,j,m=0,x=0,y=0,z=0,prev,t1=0,t2=0,t3=0;//t1,t2,t3=no of players in respective teams
        char line[500];
        char c1;

        /*char team1[10][30];
        char team2[10][30];
        char team3[10][30];*/
        char buffer[10];

        printf("\nGet ready to bid\n");
        fgets(line,1000,fp);
        
        while(fgets(line,1000,fp) != NULL)
        {
            fflush(stdin);
            int a,b,c=0,d=5;
            //c=no of rounds of bidding
            p=strtok(line,",");
            p1.pno=atoi(p);
            p=strtok(NULL,",");
            strcpy(p1.pname,p);
            p=strtok(NULL,",");
            strcpy(p1.ptype,p);
            p=strtok(NULL,",");
            strcpy(p1.pnational,p);
            p=strtok(NULL,",");
            p1.b_price=atoi(p);
            p=strtok(NULL,",");
            strcpy(p1.s.matches,p);
            p=strtok(NULL,",");
            strcpy(p1.s.innings,p);
            p=strtok(NULL,",");
            strcpy(p1.s.bavg,p);
            p=strtok(NULL,",");
            strcpy(p1.s.runs,p);
            p=strtok(NULL,",");
            strcpy(p1.s.fifties,p);
            p=strtok(NULL,",");
            strcpy(p1.s.hundreds,p);
            p=strtok(NULL,",");
            strcpy(p1.s.sr,p);
            p=strtok(NULL,",");
            strcpy(p1.s.wickets,p);
            p=strtok(NULL,",");
            strcpy(p1.s.eco,p);
            p=strtok(NULL,",");
            strcpy(p1.s.fourwic,p);
            p=strtok(NULL,"/n");
            strcpy(p1.s.fivewick,p);
            printf("\nPlayer %d : %s\t Type:%s\nNationality:%s \t Base price(in Lakh): %d\n", p1.pno, p1.pname,p1.ptype,p1.pnational,p1.b_price);
            printf("Matches: %s\t Innings:%s\nBatting average:%s \t Runs: %s\n", p1.s.matches, p1.s.innings,p1.s.bavg,p1.s.runs);
            printf("Fifties: %s\t Hundreds:%s\nStrike rate:%s\n", p1.s.fifties, p1.s.hundreds,p1.s.sr);
            printf("Wickets: %s\t Economy:%s\n 4W:%s \t 5W: %s\n", p1.s.wickets, p1.s.eco,p1.s.fourwic,p1.s.fivewick);
            printf("\nWant to bid for above player (all teams decide) (y or n): ");
            scanf("%c", &c1);
            fflush(stdin);
            if(c1=='y')
            { 
                //loop to keep asking teams for amount for bidding until all teams wish to stop
                
                a=p1.b_price;
                    if(c==0)
                    {
                        printf("\nEnter the team number that wants to bid: ");
                        scanf("%d", &d);
                        if(d==1)
                        {
                            printf("Team 1 bidding for %d\n", a);
                            c++;
                            b=1;
                        }
                        else if(d==2)
                        {
                            printf("Team 2 bidding for %d\n", a);
                            c++;
                            b=2;
                        }
                        else if(d==3)
                        {
                            printf("Team 3 bidding for %d\n", a);
                            c++;
                            b=3;
                        }
                        else
                        {
                            printf("\nPlease enter correct team number\n");
                        }
                    }
        
                prev=d;

                while(c<=5 && d!=0)
                {
                    
                        printf("\nEnter the team number that wants to bid (0 if no one wants to): ");
                        scanf("%d", &d);
                        if(d==prev)
                        {
                            printf("You've already bidded.");
                        }
                        else
                        {
                            
                                if(d==1)
                                {
                                    a=a+10;
                                    printf("Team 1 bidding for: %d\n", a);
                                    c++;
                                    b=1;					
                                }
                                else if(d==2)
                                {
                                    a=a+10;
                                    printf("Team 2 bidding for: %d\n", a);
                                    c++;
                                    b=2;
                                }
                                
                                else if(d==3)
                                {
                                    a=a+10;
                                    printf("Team 3 bidding for: %d\n", a);
                                    c++;
                                    b=3;
                                }
                                else if(d<0 || d>3)
                                {
                                    printf("\n Please enter correct team number\n");
                                }
                                else
                                {
                                    printf("All teams stop bidding\n");
                                }
                        }
                        
                
                    prev=d;
                }
                while(c>5 && c<=10 && d!=0)
                {
                       printf("\nEnter the team number that wants to bid (0 if no one wants to): ");
                        scanf("%d", &d);
                        if(prev==d)
                        {
                            printf("You've already bidded.");
                        }
                        else
                        {
                            if(d==1)
                            {
                                a=a+20;
                                printf("Team 1 bidding for: %d\n", a);
                                c++;
                                b=1;					
                            }

                            else if(d==2)
                            {
                                a=a+20;
                                printf("Team 2 bidding for: %d\n", a);
                                c++;
                                b=2;
                            }
                    
                            else if(d==3)
                            {
                                a=a+20;
                                printf("Team 3 bidding for: %d\n", a);
                                c++;
                                b=3;
                            }
                            else if (d<0 || d>3)
                            {
                                printf("\n Please enter correct team number\n");
                            }
                            else
                            {
                                printf("All teams stop bidding\n");
                            }
                        }
                    
                    prev=d;
        
                }
                while(c>10 && c<=20 && d!=0)
                {
                  
                        printf("\nEnter the team number that wants to bid (0 if no one wants to): ");
                        scanf("%d", &d);
                        if(prev==d)
                        {
                            printf("You've already bidded.");
                        }
                        else
                        {
                            if(d==1)
                            {
                                a=a+30;
                                printf("Team 1 bidding for: %d\n", a);
                                c++;
                                b=1;					
                            }
                            else if(d==2)
                            {
                                a=a+30;
                                printf("Team 2 bidding for: %d\n", a);
                                c++;
                                b=2;
                            }
                        
                            else if(d==3)
                            {
                                a=a+30;
                                printf("Team 3 bidding for: %d\n", a);
                                c++;
                                b=3;
                            }
                            else if (d<0 || d>3)
                            {
                                printf("\n Please enter correct team number\n");
                            }
                            else
                            {
                                printf("All teams stop bidding\n");
                            }
                        }

                    
                    prev=d;
                }
                while(c>20 && d!=0)
                {
 
                        printf("\nEnter the team number that wants to bid (0 if no one wants to): ");
                        scanf("%d", &d);
                        if(prev==d)
                        {
                            printf("You've already bidded.");
                        }
                        else
                        {
                            if(d==1)
                            {
                                a=a+100;
                                printf("Team 1 bidding for: %d\n", a);
                                c++;
                                b=1;					
                            }
                            else if(d==2)
                            {
                                a=a+100;
                                printf("Team 2 bidding for: %d\n", a);
                                c++;
                                b=2;
                            }
                            else if(d==3)
                            {
                                a=a+100;
                                printf("Team 3 bidding for: %d\n", a);
                                c++;
                                b=3;
                            }
                            else if (d<0 || d>3)
                            {
                                printf("\n Please enter correct team number\n");
                            }
                            else
                            {
                                printf("All teams stop bidding\n");
                            }
                        }
 
                    
                    prev=d;	
                
                    
                }
                printf("%s has been sold to Team %d for %d\n", p1.pname, b, a); 
                
                if(b==1)
                {
                    ++t1;
                    fprintf(fp1,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", t1,p1.pname,p1.ptype,p1.pnational,p1.s.matches,p1.s.innings,p1.s.bavg,p1.s.runs,p1.s.fifties,p1.s.hundreds,p1.s.sr,p1.s.wickets,p1.s.eco,p1.s.fourwic,p1.s.fivewick);
                   /* fprintf(fp1,"%d,t1,buffer,10));
                    fprintf(fp1,",");
                    fprintf(fp1,p1.pname);
                    fprintf(fp1,",");
                    fprintf(fp1,p1.ptype);
                    fprintf(fp1,",");
                    fprintf(fp1,p1.pnational);
                    fprintf(fp1,",");
                    fprintf(fp1,itoa(a,buffer,10));//base price is converted to string here because the team owners do not have to perform any base price related calculations
                    fprintf(fp1,"\n");*/
                }
    //note:baseprice is in string form in team list but in integer form in player list
                if(b==2)
                {
                    ++t2;
                    fprintf(fp2,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", t2,p1.pname,p1.ptype,p1.pnational,p1.s.matches,p1.s.innings,p1.s.bavg,p1.s.runs,p1.s.fifties,p1.s.hundreds,p1.s.sr,p1.s.wickets,p1.s.eco,p1.s.fourwic,p1.s.fivewick);
                    /*fprintf(fp2,itoa(t2,buffer,10));
                    fprintf(fp2,",");
                    fprintf(fp2,p1.pname);
                    fprintf(fp2,",");
                    fprintf(fp2,p1.ptype);
                    fprintf(fp2,",");
                    fprintf(fp2,p1.pnational);
                    fprintf(fp2,",");
                    fprintf(fp2,itoa(a,buffer,10));//base price is converted to string here because the team owners do not have to perform any base price related calculations
                    fprintf(fp2,"\n");*/
                }

                if(b==3)
                {
                    ++t3;
                    fprintf(fp3,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", t3,p1.pname,p1.ptype,p1.pnational,p1.s.matches,p1.s.innings,p1.s.bavg,p1.s.runs,p1.s.fifties,p1.s.hundreds,p1.s.sr,p1.s.wickets,p1.s.eco,p1.s.fourwic,p1.s.fivewick);
                    /*fprintf(fp3,itoa(t3,buffer,10));
                    fprintf(fp3,",");
                    fprintf(fp3,p1.pname);
                    fprintf(fp3,",");
                    fprintf(fp3,p1.ptype);
                    fprintf(fp3,",");
                    fprintf(fp3,p1.pnational);
                    fprintf(fp3,",");
                    fprintf(fp3,itoa(a,buffer,10));//base price is converted to string here because the team owners do not have to perform any base price related calculations
                    fprintf(fp3,"\n");*/
                }			
            }
        }
        
        fclose(fp);
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
    }
   
    
}
void display()
{
        int t;
        char line[1000];
        char *p;
        auct p1;
        printf("Enter which team you would like to view(1=team1,2=team2,3=team3):\n");
        scanf("%d",&t);
           if(t==1)
            {
                FILE *fp=fopen("Team1.csv","r");
                if(fp==NULL)
                {
                    printf("File cant be opened.\n");
                }
                fflush(stdin);
                while(fgets(line,1000,fp)!= NULL)
                {
                    p=strtok(line,",");        
                    p1.pno=atoi(p);
                    p=strtok(NULL,",");
                    strcpy(p1.pname,p);
                    p=strtok(NULL,",");
                    strcpy(p1.ptype,p);
                    p=strtok(NULL,",");
                    strcpy(p1.pnational,p);
                    p=strtok(NULL,",");
                    p1.b_price=atoi(p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.matches,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.innings,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.bavg,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.runs,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.fifties,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.hundreds,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.sr,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.wickets,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.eco,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.fourwic,p);
                    p=strtok(NULL,"/n");
                    strcpy(p1.s.fivewick,p);
                    printf("\nPlayer %s : %s\t Type:%s\nNationality:%s \t Base price: %d\n", p1.pno, p1.pname,p1.ptype,p1.pnational,p1.b_price);
                    printf("Matches: %s\t Innings:%s\nBatting average:%s \t Runs: %s\n", p1.s.matches, p1.s.innings,p1.s.bavg,p1.s.runs);
                    printf("Fifties: %s\t Hundreds:%s\nStrike rate:%s\n", p1.s.fifties, p1.s.hundreds,p1.s.sr);
                    printf("Wickets: %s\t Economy:%s\n 4W:%s \t 5W: %s\n", p1.s.wickets, p1.s.eco,p1.s.fourwic,p1.s.fivewick);
                }
                fclose(fp);
            }
            else if(t==2)
            {
                fflush(stdin);
                FILE *fp=fopen("Team2.csv","r");
                if(fp==NULL)
                {
                    printf("The team has not been made.\n");
                }
                while(fgets(line,1000,fp)!= NULL)
                {
                    p=strtok(line,",");        
                    p1.pno=atoi(p);
                    p=strtok(NULL,",");
                    strcpy(p1.pname,p);
                    p=strtok(NULL,",");
                    strcpy(p1.ptype,p);
                    p=strtok(NULL,",");
                    strcpy(p1.pnational,p);
                    p=strtok(NULL,",");
                    p1.b_price=atoi(p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.matches,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.innings,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.bavg,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.runs,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.fifties,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.hundreds,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.sr,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.wickets,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.eco,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.fourwic,p);
                    p=strtok(NULL,"/n");
                    strcpy(p1.s.fivewick,p);
                    printf("\nPlayer %s : %s\t Type:%s\nNationality:%s \t Base price: %d\n", p1.pno, p1.pname,p1.ptype,p1.pnational,p1.b_price);
                    printf("Matches: %s\t Innings:%s\nBatting average:%s \t Runs: %s\n", p1.s.matches, p1.s.innings,p1.s.bavg,p1.s.runs);
                    printf("Fifties: %s\t Hundreds:%s\nStrike rate:%s\n", p1.s.fifties, p1.s.hundreds,p1.s.sr);
                    printf("Wickets: %s\t Economy:%s\n 4W:%s \t 5W: %s\n", p1.s.wickets, p1.s.eco,p1.s.fourwic,p1.s.fivewick);
                }
                fclose(fp);
            }
            else if(t==3)
            {
                fflush(stdin);
                FILE *fp=fopen("Team3.csv","r");
                if(fp==NULL)
                {
                    printf("The team has not been made.\n");
                }
                while(fgets(line,1000,fp)!= NULL)
                {
                    p=strtok(line,",");        
                    p1.pno=atoi(p);
                    p=strtok(NULL,",");
                    strcpy(p1.pname,p);
                    p=strtok(NULL,",");
                    strcpy(p1.ptype,p);
                    p=strtok(NULL,",");
                    strcpy(p1.pnational,p);
                    p=strtok(NULL,",");
                    p1.b_price=atoi(p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.matches,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.innings,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.bavg,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.runs,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.fifties,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.hundreds,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.sr,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.wickets,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.eco,p);
                    p=strtok(NULL,",");
                    strcpy(p1.s.fourwic,p);
                    p=strtok(NULL,"/n");
                    strcpy(p1.s.fivewick,p);
                    printf("\nPlayer %s : %s\t Type:%s\nNationality:%s \t Base price: %d\n", p1.pno, p1.pname,p1.ptype,p1.pnational,p1.b_price);
                    printf("Matches: %s\t Innings:%s\nBatting average:%s \t Runs: %s\n", p1.s.matches, p1.s.innings,p1.s.bavg,p1.s.runs);
                    printf("Fifties: %s\t Hundreds:%s\nStrike rate:%s\n", p1.s.fifties, p1.s.hundreds,p1.s.sr);
                    printf("Wickets: %s\t Economy:%s\n 4W:%s \t 5W: %s\n", p1.s.wickets, p1.s.eco,p1.s.fourwic,p1.s.fivewick);
                }
                fclose(fp);
            }
            else
            {
                printf("Enter a valid team number\n");
            }
        
        
}
void user()
{
    char ch,cha;
    do
    {
        printf("Enter your choice:\n1.Initiate the bidding process\n2.Display team members \n3.Display Player list for auction\n4.exit\n");
        scanf("%d",&ch);
        fflush(stdin);
        switch(ch)
        {
            case 1:
            bidding();
            break;
            case 2:
            display();
            break;
            case 3:
            disp();
            break;
            case 4:
            break;
            default:
            printf("Please enter another option\n");
        }
        printf("Press any key to continue:\n");
        cha=getch();
   }while(ch!=4);
}

