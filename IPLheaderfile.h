typedef struct statistics
{
    //Matches	Innings	B avg   Runs    Fifties	Hundreds  Strike rate	Wickets	Economy	4W	5W
    char matches[5];
    char innings[5];
    char bavg[5];
    char runs[5];
    char fifties[5];
    char hundreds[5];
    char sr[5];
    char wickets[5];
    char eco[5];
    char fourwic[5];
    char fivewick[5];
}stat;
typedef struct auct_pl
{
    int pno;
    char pname[50];
    char ptype[10];
    char pnational[20];
    stat s;
    int b_price;
} auct;
void admin();
void user();
void newlist();
void disp();
void addpl();
void delpl();
void bidding();
void display();
void changebp();