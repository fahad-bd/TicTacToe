/*
Fahad Ahammed
ID:2020-2-60-174
*/

#include<stdio.h>
char board[20][20],turn;
int count11=0,count22=0;
int n,i,j;

//board print
void print_board()
{

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int count1, count2;
    printf("what is the size of the board you want to play in?\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            board[i][j]='.';
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }

    //game

    int l,a,b;
    for(l=1;l<=(n*n);l++){
            int p_n;
        if(l%2==1){
            p_n=1;
            turn='X';
        }
        else{
            p_n=2;
            turn='O';
        }

        while(1){
            printf("Player %d's turn\n",p_n);
            scanf("%d %d",&a,&b);


        //if turn is already filled up or not

        if(board[a-1][b-1]=='X' || board[a-1][b-1]=='O'){
                printf("%d %d is already filled up\nPlease try again\n",a,b);

        print_board();
        }

        //if turn is outside of board or not

        else if(a<=0 || a>n || b<=0 || b>n)
        {
        printf("%d %d is outside the board\nPlease try again\n",a,b);

        print_board();
        }

    else
        {
            board[a-1][b-1]=turn;

            break; //infinity for loop break
        }

    }

    //turn input

    print_board();

     //who win

     for(i=0;i<n;i++){
         count1=0,count2=0;
         count11=0,count22=0;
        for(j=0;j<n;j++){
            if(board[i][j]=='X') count1++;
            if(board[j][i]=='X') count11++;
            if(board[i][j]=='O') count2++;
            if(board[j][i]=='O') count22++;
        }
        if(count1==n || count11==n){
            printf("Player 1 win\n");
            break;
        }
        else if(count2==n || count22==n){
            printf("Player 2 win\n");
            break;
        }
     }
     if(count1==n || count11==n || count2==n || count22==n) break; //l loop break

     // win check diagonally
     //right diagonal

     count1=0, count2=0;
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                if(board[i][j]=='X') count1++;
                if(board[i][j]=='O') count2++;
            }
        }
     }

        if(count1==n){
        printf("Player 1 win\n");
        break;
       }
       else if(count2==n){
        printf("Player 2 win\n");
        break;
       }

       //left diagonal

       count1=0,count2=0;
       j=n-1;
       for(i=0;i<n;i++)
       {
           if(board[i][j]=='X') count1++;
           else if(board[i][j]=='O') count2++;
           j-=1;
       }

     if(count1==n){
        printf("Player 1 win\n");
        break;
       }
       else if(count2==n){
        printf("Player 2 win\n");
        break;
       }


    if(count1==n || count2==n)break;


    }

     if(count1!=n && count2!=n && count11!=n && count22!=n) printf("Draw\n");

    return 0;
}
