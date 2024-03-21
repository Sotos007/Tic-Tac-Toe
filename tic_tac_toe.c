#include <stdio.h>
#include <stdlib.h>

void board();
void menu();
void guide();
void marking_board(int, char);
int scan_for_winner();
int winner_is();
int computer_move();
void PVP();
void PVE();
void board_clear();


char grid[3][3]={'1','2','3','4','5','6','7','8','9'};

int main()
{
    int mode = 0;
    int first = 1;

    while( mode != 4)
    {
        menu();
        scanf("%d",&mode);
        printf("\n\n");
        // elegxei gia emfanisi tou katharismenou pinaka otan den einai i proti epanalipsi
        if(first == 0 )
        {
            printf("    O pinakas katharise, mporeis na sinexeiseis to paixnidi sou!");
            printf("\n\n");
            board_clear();
        }
        // elegxei an i epilogi pou edose o xristis einai to PVP
        if( mode == 1 )
        {
            printf("    Epelekses to mode: Xritis vs Xristi\n");
            printf("\n\n");

            PVP();

        }
        // elegxei an i epilogi pou edose o xristis einai to PVE
        else if( mode == 2 )
        {
            printf("   Epelekses to mode: Xritis vs Ypologisti\n");
            printf("\n");

            PVE();


        }
        // elegxei an i epilogi pou edose o xristis einai h eksodos tou programmatos
        else if (mode == 4 )
        {
            printf("    Exit...\n");
        }
        // elegxei an i epilogi pou edose o xristis einai to menu odigion
        else if(mode == 3)
        {
            guide();
        }
        first = 0;
    }
}

void menu( void )
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    printf("          !!! T I C    T A C    T O E !!!  \n ");
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    printf("                   ---MAIN MENU---          \n\n   ");
    printf("    Geia sou, kalosilthes sto paixnidi!!! \n");
    printf("\n");
    printf("    Dialekse ena apo ta akoloutha mode pou epithimeis:\n ");
    printf("    1. Xritis VS Xristi - PVP\n");
    printf("     2. Xristis VS Ypologisti - PVE\n");
    printf("     3. Odigies paixnidiou\n");
    printf("     4. Exit game\n");
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    printf("    Dose tin epilogi sou, ");

    return ;
}

void guide ()
{
    printf ("                                      --GUIDE--    \n");
    printf(" +----------------------------------------------------------------------------------+\n");
    printf(" | * To paixnidi paizetai me diadoxikes kiniseis duo paixton se enan pinaka 3x3.    |\n");
    printf(" | * Oi paixtes simplironoun enallaks mia thesi tou pinaka topothetontas o protos   |\n");
    printf(" |   to to symbolo 'X' kai o deuteros to symbolo 'O'.                               |\n");
    printf(" | * Nikitis einai o paixtis pou tha symplirosei protos mia triada omoion symbolon  |\n");
    printf(" |   se kapoia grammi, stili h diagonio tou pinaka.                                 |\n");
    printf(" | * An o pinakas siblirothei xoris nikith to paixnidi theorite isopalo.            |\n");
    printf(" +----------------------------------------------------------------------------------+\n");
    printf("\n\n");
}

void board()
{

    printf("        |   |    \n");
    printf("     %c  | %c | %c \n", grid[0][0], grid[0][1], grid[0][2]);
    printf("    ----+---+----\n");
    printf("     %c  | %c | %c \n", grid[1][0], grid[1][1], grid[1][2]);
    printf("    ----+---+----\n");
    printf("     %c  | %c | %c \n", grid[2][0], grid[2][1], grid[2][2]);
    printf("        |   |    \n");
    printf("\n\n");

    return ;
}

void board_clear()
{
    printf("        |   |    \n");
    printf("     %c  | %c | %c \n", grid[0][0]='1', grid[0][1]='2', grid[0][2]='3');
    printf("    ----+---+----\n");
    printf("     %c  | %c | %c \n", grid[1][0]='4', grid[1][1]='5', grid[1][2]='6');
    printf("    ----+---+----\n");
    printf("     %c  | %c | %c \n", grid[2][0]='7', grid[2][1]='8', grid[2][2]='9');
    printf("        |   |    \n");
    printf("\n\n");

    return ;
}

void PVP()
{

    int flag=1;
    int choice, winner, j, t, win;
    char mark;
    char player[2]={'X','O'};
    do{

        board();
        // elegxei an einai h seira tou protou paixti gia na paiksei
        if(player[0]== 'X' && flag== 1)
        {
            printf("    Player 1, dose enan arithmo: ");
            scanf("%d",&choice);
            printf("\n");
            mark = 'X' ;
            marking_board(choice, mark);

        }
        // elegxei an einai h seira tou deuterou paixti gia na paiksei
        if( player[1]=='O'&& flag == 0)
        {
            printf("    Player 2, dose enan arithmo: ");
            scanf("%d",&choice);
            printf("\n");
            mark = 'O';
            marking_board(choice, mark);
        }
        // enallasei tis seires tou kathe paixti
        if(flag==1)
        {
            flag=0;
        }
        else
        {
            flag=1;
        }
        // elegxei an yparxei kapoios nikitis
        winner=scan_for_winner();

    }while(winner == -1);
    // vriskei ton nikiti tou paixnidiou
     win=winner_is();
    // elegxei an o nikithis einai o player 1
     if(win == 1)
     {
         board();
         printf("    Player 1 eisai o nikitis!!!\n");
         printf("\n\n");
     }
     // elegxei an o nikithis einai o player 2
     if(win == 2)
     {
         board();
         printf("    Player 2 eisai o nikitis!!!\n");
         printf("\n\n");
     }
     // elegxei an to paixnidi irthe isopalo
     if(win == 0)
     {
         board();
         printf("    To paixnidi elikse isopalo\n");
         printf("    Prospathiste ksana...\n");
         printf("\n\n");
     }


}

void PVE()
{
    int flag=1;
    int choice, winner, j, t, win;
    char mark;
    char player[2]={'X','O'};

     do{
        board();
        // elegxei an einai seira tou protou paixth na paiksei
          if(player[0]== 'X' && flag== 1)
          {
                printf("    Player 1, dose enan arithmo: ");
                scanf("%d",&choice);
                printf("\n");
                mark = 'X' ;
                marking_board(choice, mark);
          }
          // elegxei an einai seira tou deuterou paixth na paiksei
          if( player[1]=='O' && flag == 0)
          {
                printf("    O Ypologistis epekse seira sou... ");
                printf("\n\n");

                choice=computer_move();
                mark = 'O';
                marking_board(choice, mark);
          }
          //enallazei tin seira ton paixton
          if(flag==1)
          {
                flag=0;
          }
          else
          {
          flag=1;
          }
        // elegxei an yparxei kapoios nikitis
          winner=scan_for_winner();

        }while(winner == -1);
        // vriskei ton nikiti tou paixnidiou
        win=winner_is();
    // elegxei an o player 1 einai o nikitis
     if(win == 1)
     {
         board();
         printf("    Player 1 eisai o nikitis!!!\n");
         printf("\n\n");
     }
     // elegxei an o ypologistis einai o nikitis
     if(win == 2)
     {
         board();
         printf("    O Ypologistis nikise\n");
         printf("    Prospathise ksana...\n");
         printf("\n\n");
     }
     //elegxei an to paixnidi elikse isopalo
     if(win == 0)
     {
         board();
         printf("    To paixnidi elikse isopalo\n");
         printf("    Prospathise ksana...\n");
         printf("\n\n");
     }
}

void marking_board( int choice, char mark)
{
    // gemizei ton pinaka me 'X' kai 'O' analoga ton player
    int flag=0;

     while(flag==0)
     {
        if(choice==1 && grid[0][0]=='1')
        {
            grid[0][0]=mark;
            flag=1;
        }
        else if(choice==2 && grid[0][1]=='2')
        {
            grid[0][1]=mark;
            flag=1;
        }
        else if(choice==3 && grid[0][2]=='3')
        {
            grid[0][2]=mark;
            flag=1;
        }
        else if(choice==4 && grid[1][0]=='4')
        {
            grid[1][0]=mark;
            flag=1;
        }
        else if (choice==5 && grid[1][1]=='5')
        {
            grid[1][1]=mark;
            flag=1;
        }
        else if (choice==6 && grid[1][2]=='6')
        {
            grid[1][2]=mark;
            flag=1;
        }
        else if (choice==7 && grid[2][0]=='7')
        {
            grid[2][0]=mark;
            flag=1;
        }
        else if (choice==8 && grid[2][1]=='8')
        {
            grid[2][1]=mark;
            flag=1;
        }
        else if (choice==9 && grid[2][2]=='9')
        {
            grid[2][2]=mark;
            flag=1;
        }
        // elegxei ean exei dothei apo ton player ena idi xrisimopoihmeno keli tou pinaka
        else
        {
            printf("    Mi apodekth kinisi.");
            printf(" Prospathise ksana:");
            scanf("%d",&choice);

        }
     }
}

int scan_for_winner()
{
    //orizontia
    if(grid[0][0]==grid[0][1] && grid[0][1]==grid[0][2])
    {
        return 1;
    }
    else if(grid[1][0]==grid[1][1] && grid[1][1]==grid[1][2])
    {
        return 1;
    }
    else if (grid[2][0]==grid[2][1] && grid[2][1]==grid[2][2])
    {
        return 1;
    }
    //katheta
    else if (grid[0][0]==grid[1][0] && grid[1][0]==grid[2][0])
    {
        return 1;
    }
    else if(grid[0][1]==grid[1][1] && grid[1][1]==grid[2][1])
    {
        return 1;
    }
    else if(grid[0][2]==grid[1][2] && grid[1][2]==grid[2][2])
    {
        return 1;
    }
    //diagonia
    else if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])
    {
        return 1;
    }
    else if(grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])
    {
        return 1;
    }
    // adios - xoris stoixeia pinakas
    else if(grid[0][0]!= '1' && grid[0][1]!= '2' && grid[0][2]!= '3' && grid[1][0]!= '4'&& grid[1][1]!= '5' && grid[1][2]!= '6'&& grid[2][0]!= '7' && grid[2][1]!= '8' && grid[2][2]!='9')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int winner_is()
{

    if(grid[0][0]=='X'&& grid[0][1]=='X' && grid[0][2]=='X')
    {
        return 1;
    }
    if(grid[1][0]=='X'&& grid[1][1]=='X' && grid[1][2]=='X')
    {
        return 1;
    }
    if(grid[2][0]=='X'&& grid[2][1]=='X' && grid[2][2]=='X')
    {
        return 1;
    }
    if(grid[0][0]=='O'&& grid[0][1]=='O' && grid[0][2]=='O')
    {
        return 2;
    }
    if(grid[1][0]=='O'&& grid[1][1]=='O' && grid[1][2]=='O')
    {
        return 2;
    }
    if(grid[2][0]=='O'&& grid[2][1]=='O' && grid[2][2]=='O')
    {
        return 2;
    }
    if(grid[0][0]=='X'&& grid[1][0]=='X' && grid[2][0]=='X')
    {
        return 1;
    }
    if(grid[0][1]=='X'&& grid[1][1]=='X' && grid[2][1]=='X')
    {
        return 1;
    }
    if(grid[0][2]=='X'&& grid[1][2]=='X' && grid[2][2]=='X')
    {
        return 1;
    }
    if(grid[0][0]=='O'&& grid[1][0]=='O' && grid[2][0]=='O')
    {
        return 2;
    }
    if(grid[0][1]=='O'&& grid[1][1]=='O' && grid[2][1]=='O')
    {
        return 2;
    }
    if(grid[0][2]=='O'&& grid[1][2]=='O' && grid[2][2]=='O')
    {
        return 2;
    }
    if(grid[0][0]=='X'&& grid[1][1]=='X' && grid[2][2]=='X')
    {
        return 1;
    }
    if(grid[0][2]=='X'&& grid[1][1]=='X' && grid[2][0]=='X')
    {
        return 1;
    }
    if(grid[0][0]=='O'&& grid[1][1]=='O' && grid[2][2]=='O')
    {
        return 2;
    }
    if(grid[0][2]=='O'&& grid[1][1]=='O' && grid[2][0]=='O')
    {
        return 2;
    }
    if (grid[0][0]!= '1' && grid[0][1]!= '2' && grid[0][2]!= '3' && grid[1][0]!= '4'&& grid[1][1]!= '5' && grid[1][2]!= '6'&& grid[2][0]!= '7' && grid[2][1]!= '8' && grid[2][2]!='9')
    {
        return 0;
    }

}

int computer_move(void)
{
    // ena normal mode tis kinisis tou ipologisti kai oxi ena hard (eksipno)
    if(grid[0][0]== 'O' && grid[2][0]=='O' && grid[1][0]== '4')
    {
        return 4;
    }
    if(grid[0][2]== 'O' && grid[2][2]=='O' && grid[1][2]== '6')
    {
        return 6;
    }
    if(grid[2][0]=='O' && grid[2][2]=='O' && grid[2][1]=='8')
    {
        return 8;
    }
    if(grid[0][0]=='O' && grid[0][2]=='O' && grid[0][1]=='2')
    {
        return 2;
    }
    if(grid[0][1]=='O' && grid[1][1]=='O' && grid[2][1]=='8')
    {
        return 8;
    }
    if(grid[1][0]=='O' && grid[1][1]=='O' && grid[1][2]=='6')
    {
        return 6;
    }
    if(grid[0][0]=='O' && grid[1][1]=='O' && grid[2][2]=='9')
    {
        return 9;
    }
    if(grid[0][2]=='O' && grid[1][1]=='O' && grid[2][0]=='7')
    {
        return 7;
    }
    if(grid[0][0]=='X' && grid[2][0]=='X' && grid[1][0]=='4')
    {
        return 4;
    }
    if(grid[0][2]=='X' && grid[2][2]=='X' && grid[1][2]=='6')
    {
        return 6;
    }
    if(grid[2][0]=='X' && grid[2][2]=='X' && grid[2][1]=='8')
    {
        return 8;
    }
    if(grid[0][1]=='X' && grid[1][1]=='X' && grid[2][1]=='8')
    {
        return 8;
    }
    if(grid[0][0]=='X' && grid[0][2]=='X' && grid[0][1]=='2')
    {
        return 2;
    }
    if(grid[0][2]=='X' && grid[1][1]=='X' && grid[2][0]=='7')
    {
        return 7;
    }
    if(grid[0][0]=='X' && grid[1][1]=='X' && grid[2][2]=='9')
    {
        return 9;
    }
    if(grid[1][1]== '5')
    {
        return 5;
    }
    if(grid[0][0]== '1')
    {
        return 1;
    }
    if(grid[2][2]== '9')
    {
        return 9;
    }
    if(grid[0][2]== '3')
    {
        return 3;
    }
    if(grid[2][0]== '7')
    {
        return 7;
    }
    if(grid[1][2]== '6')
    {
        return 6;
    }
    if(grid[0][1]== '2')
    {
        return 2;
    }
    if(grid[2][1]== '8')
    {
        return 8;
    }
    if(grid[1][0]== '4')
    {
        return 4;
    }
}
