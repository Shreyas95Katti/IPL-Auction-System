#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "IPLheaderfile.h"
void newlist()
{
        auct a;
        //make a fresh list of players
        FILE *fpa=fopen("PlayersList1.csv","w");//change this to PlayersList.csv
        if(fpa==NULL)
        {
            printf("File did not successfully open\n");
        }
        else
        {
        int c=1;
        int i=0;
        while(c)
        {
            i++;
            fprintf(fpa,"Player number,Player number,Player name,Player type,Nationality,Matches,Innings,Batting average,Runs,Fifties	Hundreds,Strike rate,Wickets,Economy,4W,5W\n");
            printf("Enter player name:\n");
            scanf("%[^\n]s",a.pname);
            fflush(stdin);
            printf("Enter player type:\n");
            scanf("%[^\n]s",a.ptype);
            fflush(stdin);
            printf("Enter player nationality:\n");
            scanf("%[^\n]s",a.pnational);
            fflush(stdin);
            printf("Enter number of matches:\n");
            scanf("%[^\n]s",a.s.matches);
            fflush(stdin);
            printf("Enter number of innings:\n");
            scanf("%[^\n]s",a.s.innings);
            fflush(stdin);
            printf("Enter batting average:\n");
            scanf("%[^\n]s",a.s.bavg);
            fflush(stdin);
            printf("Enter player runs:\n");
            scanf("%[^\n]s",a.s.runs);
            fflush(stdin);           
            printf("Enter player fifties:\n");
            scanf("%[^\n]s",a.s.fifties);
            fflush(stdin);
            printf("Enter player hundreds:\n");
            scanf("%[^\n]s",a.s.hundreds);
            fflush(stdin);
            printf("Enter player strike rate:\n");
            scanf("%[^\n]s",a.s.sr);
            fflush(stdin); 
            printf("Enter player wickets:\n");
            scanf("%[^\n]s",a.s.wickets);
            fflush(stdin);
            printf("Enter player economy:\n");
            scanf("%[^\n]s",a.s.eco);
            fflush(stdin);
            printf("Enter number of 4W:\n");
            scanf("%[^\n]s",a.s.fourwic);
            fflush(stdin);
            printf("Enter number of 5W:\n");
            scanf("%[^\n]s",a.s.fivewick);
            fflush(stdin); 
            fprintf(fpa,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",i,a.pname,a.ptype,a.pnational,a.s.matches,a.s.innings,a.s.bavg,a.s.runs,a.s.fifties,a.s.hundreds,a.s.sr,a.s.wickets,a.s.eco,a.s.fourwic,a.s.fivewick); 
            printf("Enter any value to add one more player,0 to stop.\n");
            scanf("%d",&c);
        }
        fclose(fpa);
    }
}
void disp()
{
      char line[1000];
        char *p;
        auct p1;
        FILE *fp=fopen("PlayersList.csv","r");
        if(fp==NULL)
        {
            printf("File did not successfully open\n");
            
        }
        fgets(line,1000,fp);
        while(fgets(line,1000,fp))
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
		printf("\nPlayer %s : %s\t Type:%s\nNationality:%s \t Base price(in Lakh): %d\n", p1.pno, p1.pname,p1.ptype,p1.pnational,p1.b_price);
        printf("Matches: %s\t Innings:%s\nBatting average:%s \t Runs: %s\n", p1.s.matches, p1.s.innings,p1.s.bavg,p1.s.runs);
        printf("Fifties: %s\t Hundreds:%s\nStrike rate:%s\n", p1.s.fifties, p1.s.hundreds,p1.s.sr);
        printf("Wickets: %s\t Economy:%s\n 4W:%s \t 5W: %s\n", p1.s.wickets, p1.s.eco,p1.s.fourwic,p1.s.fivewick);
        }
        fclose(fp);
}

void addpl()
{
	auct a;
    int n=0;
        FILE *fpa=fopen("PlayersList.csv","r");
        if(fpa==NULL)
        {
		printf("File did not successfully open\n");
        }
        for(char c=getc(fpa);c!=EOF;c=getc(fpa))
        {
            if(c=='\n')
            {
                n++;
            }
        }
    printf("%d\n",n);
    fclose(fpa);
    fpa=fopen("PlayersList.csv","a");
    if(fpa==NULL)
    {
	  printf("File did not successfully open\n");
    }
	else
	{
         
         char line[100];
         char buffer[100];
            while(fgets(line,1000,fpa))
            {
                n++;
            }
            a.pno=n;
	        printf("Enter new player name:\n");
            scanf("%[^\n]s",a.pname);
            fflush(stdin);
            printf("Enter new player type:\n");
            scanf("%[^\n]s",a.ptype);
            fflush(stdin);
            printf("Enter new player nationality:\n");
            scanf("%[^\n]s",a.pnational);
            fflush(stdin);
            printf("Enter number of matches played by new player:\n");
            scanf("%[^\n]s",a.s.matches);
            fflush(stdin);
            printf("Enter number of innings played by new player:\n");
            scanf("%[^\n]s",a.s.innings);
            fflush(stdin);
            printf("Enter batting average of new player:\n");
            scanf("%[^\n]s",a.s.bavg);
            fflush(stdin);
            printf("Enter player runs of new player:\n");
            scanf("%[^\n]s",a.s.runs);
            fflush(stdin);           
            printf("Enter player fifties of new player:\n");
            scanf("%[^\n]s",a.s.fifties);
            fflush(stdin);
            printf("Enter player hundreds by new player:\n");
            scanf("%[^\n]s",a.s.hundreds);
            fflush(stdin);
            printf("Enter player strike rate of new player:\n");
            scanf("%[^\n]s",a.s.sr);
            fflush(stdin); 
            printf("Enter player wickets taken by new player:\n");
            scanf("%[^\n]s",a.s.wickets);
            fflush(stdin);
            printf("Enter player economy of new player:\n");
            scanf("%[^\n]s",a.s.eco);
            fflush(stdin);
            printf("Enter number of 4W taken by new player:\n");
            scanf("%[^\n]s",a.s.fourwic);
            fflush(stdin);
            printf("Enter number of 5W taken by new player:\n");
            scanf("%[^\n]s",a.s.fivewick);
            fflush(stdin); 
            fprintf(fpa,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", a.pno,a.pname,a.ptype,a.pnational,a.s.matches,a.s.innings,a.s.bavg,a.s.runs,a.s.fifties,a.s.hundreds,a.s.sr,a.s.wickets,a.s.eco,a.s.fourwic,a.s.fivewick);
            fprintf(fpa,"\n");
	}
}
void delpl()
{
    auct p1;
    int n=0;
	char name[50];
    char line[1000];
    char buffer[100];
    int chk=0;
    char *p;
	FILE *fpa = fopen("PlayersList.csv","r");
	FILE *fpab = fopen("PlayerListTemp.csv","w");
	if(fpa == NULL || fpab == NULL)
    {
       	printf("Could not open data file\n");
   	}
	else
	{
		printf("Please enter player name to delete:");
		scanf("%[^\n]s",name);
		fflush(stdin);
		while(fgets(line, sizeof(line), fpa) != NULL)
		{
                p=strtok(line,",");
                n++;
                p1.pno=n;
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
                if(!(strcmpi(name,p1.pname)))
                {
                    chk=1;
                }
                if (strcmpi(name,p1.pname))//if it is 0 then it will not enter the if block and hence it wont add the player to the file
    		    {   
                    fprintf(fpab,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", p1.pno,p1.pname,p1.ptype,p1.pnational,p1.s.matches,p1.s.innings,p1.s.bavg,p1.s.runs,p1.s.fifties,p1.s.hundreds,p1.s.sr,p1.s.wickets,p1.s.eco,p1.s.fourwic,p1.s.fivewick);
			
                }
        //we use a temp file to add the players 
		}
		fclose(fpa);
		fclose(fpab);
        if(chk==0)
        {
            printf("The player does not exist\n");
        }
        else
        {
            FILE *fpa = fopen("PlayersList.csv","w");
            FILE *fpab = fopen("PlayerListTemp.csv","r");
            if(fpa == NULL || fpab == NULL)
            {
                printf("Could not open data file\n");
            }
            else
            {
                while(fgets(line, sizeof(line), fpab) != NULL)
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
                    fprintf(fpa,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", p1.pno,p1.pname,p1.ptype,p1.pnational,p1.s.matches,p1.s.innings,p1.s.bavg,p1.s.runs,p1.s.fifties,p1.s.hundreds,p1.s.sr,p1.s.wickets,p1.s.eco,p1.s.fourwic,p1.s.fivewick); 
                }
                fclose(fpa);
                fclose(fpab);
            }
 
        }
    }
}
void changebp()
{
    auct p1;
    int n=0;
	char name[50];
    char line[1000];
    char *p;
	FILE *fpa = fopen("PlayersList.csv","r");
	FILE *fpab = fopen("PlayerListTemp.csv","w");
	if(fpa == NULL || fpab == NULL)
    {
       	printf("Could not open data file\n");
   	}
	else
	{
		int chk=0;
        printf("Please enter player name to change base price:");
		scanf("%[^\n]s",name);
		fflush(stdin);
		while(fgets(line, sizeof(line), fpa) != NULL)
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
                if (!(strcmpi(name,p1.pname)))//if it is not then it will enter the if block and change base price
    		    {
                    chk=1;
                    printf("Enter new base price(In lakh):");
                    scanf("%d",&p1.b_price);
                }
                fprintf(fpab,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", p1.pno,p1.pname,p1.ptype,p1.pnational,p1.s.matches,p1.s.innings,p1.s.bavg,p1.s.runs,p1.s.fifties,p1.s.hundreds,p1.s.sr,p1.s.wickets,p1.s.eco,p1.s.fourwic,p1.s.fivewick);
        //we use a temp file to add the players 
		}
        fclose(fpa);
		fclose(fpab);
        if(chk==0)
        {
            printf("Player not found\n");
        }
        else
        {
            FILE *fpa = fopen("PlayersList.csv","w");
            FILE *fpab = fopen("PlayerListTemp.csv","r");
            if(fpa == NULL || fpab == NULL)
            {
                printf("Could not open data file\n");
            }
            else
            {
                while(fgets(line, sizeof(line), fpab) != NULL)
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
                        fprintf(fpa,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", p1.pno,p1.pname,p1.ptype,p1.pnational,p1.s.matches,p1.s.innings,p1.s.bavg,p1.s.runs,p1.s.fifties,p1.s.hundreds,p1.s.sr,p1.s.wickets,p1.s.eco,p1.s.fourwic,p1.s.fivewick);
                    }
                    fclose(fpa);
                    fclose(fpab);
            }
        }
    }

}
void admin()
{
    char ch,cha;
    do
    {
        printf("Enter your choice:\n 1.Make a new list of players\n2.Display the player list \n3.Add players to the list \n4.Delete players from the list \n5.Change base price of players\n 6.exit\n");
        scanf("%d",&ch);
        fflush(stdin);
        switch(ch)
        {
            case 1:
            newlist();
            break;
            case 2:
            disp();
            break;
            case 3:
            addpl();
            break;
            case 4:
            delpl();
            break;
            case 5:
            changebp();
            break;
            case 6:
            break;
            default:
            printf("Please enter another option\n");
        }
        printf("Press any key to continue:\n");
        cha=getch();
   }while(ch!=6);
}