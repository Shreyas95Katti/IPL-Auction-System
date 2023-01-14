#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct player
{
    int srno;
    char p_name[30];
    char p_type[20];
    int p_runs;
    int p_wickets;
    char p_team[20];
    struct player *next;
};

struct player *head=NULL;

struct player *newNode()
{
    return((struct player *)malloc(sizeof(struct player)));
}


void writeFile(FILE *fptr, struct player *head)    //shreyas
{
    struct player *start;
    start = head;
    if (start->next != NULL)
    {
        fprintf(fptr, "Serial Number: %d\nPlayer Name: %s\nPlayer Type: %s\nPlayer Runs: %d\nPlayer Wickets: %d\nPlayer Team: %s\n\n", start->srno, start->p_name, start->p_type, start->p_runs, start-> p_wickets, start->p_team);
        writeFile(fptr, start->next);
    }
    else
    {
        fprintf(fptr, "Serial Number: %d\nPlayer Name: %s\nPlayer Type: %s\nPlayer Runs: %d\nPlayer Wickets: %d\nPlayer Team: %s\n\n", start->srno, start->p_name, start->p_type, start->p_runs, start-> p_wickets, start->p_team);
        fclose(fptr);
    }
}

void readFile()     //shreyas
{
    FILE *fptr;

    char x[2000];
    int y = 0;

    fptr = fopen("data.txt", "r");

    if (fptr == NULL)
    {
        printf("Error: The File Is Not Opening!!\n");
    }
    printf("\n\n***************READING FROM data.txt FILE***************\n");
    while (fgets(x, 2000, fptr) != NULL)
    {
        y = strlen(x);
        x[y - 1] = x[y - 1] == '\n' ? '\0' : x[y - 1];
        printf("%s\n", x);
    }
    fclose(fptr);
}

void displayData(struct player *head)     //sai sanjana
{
    struct player *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d --> %s --> %s --> %d runs --> %d wickets --> %s Team\n", temp->srno, temp->p_name, temp->p_type, temp->p_runs, temp->p_wickets, temp->p_team);

        temp=temp->next;
    }
}


void addPlayer()    //sanjana prasad
{
    struct player *temp,*new;
    new=newNode();
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    printf("Enter Serial Number:\n");
    scanf("%d", &new->srno);
    printf("Enter the player's name:\n");
    scanf("%s", &new->p_name);
    printf("Enter player type:\n");
    scanf("%s", &new->p_type);
    printf("Enter the total runs scored by the new player:\n");
    scanf("%d", &new->p_runs);
    printf("Enter the total number of wickets taken by the new player:\n");
    scanf("%d", &new->p_wickets);
    printf("Enter team name of the player:\n");
    scanf("%s", &new->p_team);

    temp->next=new;
    new->next=NULL;

    FILE *fp = fopen("data.txt", "a");
    writeFile(fp, new);
}

struct player *newData()
{
    struct player *temp, *new;
    if (head != NULL)
        addPlayer();
    else
    {
        new = newNode();
        head = new;
        temp = head;
        printf("Enter Serial Number:\n");
        scanf("%d", &new->srno);
        printf("Enter player name:\n");
        scanf("%s", &new->p_name);
        printf("Enter player type:\n");
        scanf("%s", &new->p_type);
        printf("Enter the total runs scored by the new player:\n");
        scanf("%d", &new->p_runs);
        printf("Enter the total number of wickets taken by the new player:\n");
        scanf("%d", &new->p_wickets);
        printf("Enter team name of the player:\n");
        scanf("%s", &new->p_team);
        new->next = NULL;

        FILE *fp = fopen("data.txt", "a");
        writeFile(fp, new);
    }
}

void search()    //sai sanjana
{
    struct player *temp;
    int no;
    temp = head;
    printf("Enter player serial number to be searched: ");
    scanf("%d", &no);
    while ((temp->srno < no))
    {
        temp = temp->next;
    }
    printf("%d --> %s --> %s --> %d runs --> %d wickets --> %s Team\n", temp->srno, temp->p_name, temp->p_type, temp->p_runs, temp->p_wickets, temp->p_team);
}

void removePlayer()     //sanjitha
{
    struct player *temp;
    int no;
    temp = head;
    printf("Enter player serial number to be removed: ");
    scanf("%d", &no);
    while (temp != NULL)
    {
        if ((temp->next->srno == no))
        {
            printf("%d --> %s --> %s --> %d runs --> %d wickets --> %s Team\n", temp->srno, temp->p_name, temp->p_type, temp->p_runs, temp->p_wickets, temp->p_team);
            temp->next = temp->next->next;
            free(temp->next);
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
}

void editData()    //shivani
{
    struct player *temp, *temp2;
    int no;
    temp = head;
    printf("Enter the player serial number of the player whose data is to be edited: ");
    int x=0;
    scanf("%d", &no);
    while(temp != NULL)
    {
        if(temp->srno == no)
        {
            printf("Enter the player data with edited data:\n");
            printf("Enter Serial Number:\n");
            scanf("%d", &temp->srno);
            printf("Enter player name:\n");
            scanf("%s", &temp->p_name);
            printf("Enter player type:\n");
            scanf("%s", &temp->p_type);
            printf("Enter the total runs scored by the new player:\n");
            scanf("%d", &temp->p_runs);
            printf("Enter the total number of wickets taken by the new player:\n");
            scanf("%d", &temp->p_wickets);
            printf("Enter team name of the player:\n");
            scanf("%s", temp->p_team);
            x=1;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (x==0)
    {
        printf("This player doesn't exist. Please try again");
    }

    temp2 = head;
    while(temp2->next!= NULL)
    {
        FILE *fptr = fopen("data.txt", "w");
        writeFile(fptr, temp2);
        temp2 = temp2->next;
    }
}

int main()
{
    int op, ch;
    do
    {
        printf("**********Welcome to Player DataBase**********\n ");
        printf("1.Create a List\n2.Add a New Player\n3.Remove an Existing Player\n4.Display Data\n5.Edit Player Data\n6.Search for a Player\n7.Read Data File\n8.Quit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            newData();
            break;
        case 2:
            addPlayer();
            break;
        case 3:
            removePlayer();
            break;
        case 4:
            displayData(head);
            break;
        case 5:
            editData();
            break;
        case 6:
            search();
            break;
        case 7:
            readFile();
            break;
        case 8: 
            exit(1);
            break;
        default:
            printf("Wrong choice. Please Try Again!\n");
            main();
            break;
        }
        printf("Do you want to quit? Enter 0 for No & 1 for Yes:");
        scanf("%d", &op);
        if(op!=1 && op!=0)
        {main();}
    } while (op != 1);
    return 0;
}