#include <iostream>
using namespace std;
char markers[10]={0};
int isgameOver(char pl,int index)
{
    if(markers[1]==pl && markers[2]==pl && markers[3]==pl)
        return 1;
    if(markers[4]==pl && markers[5]==pl && markers[6]==pl)
        return 1;
    if(markers[7]==pl && markers[8]==pl && markers[9]==pl)
        return 1;
    if(markers[1]==pl && markers[5]==pl && markers[9]==pl)
        return 1;
    if(markers[3]==pl && markers[5]==pl && markers[7]==pl)
        return 1;
    if(markers[1]==pl && markers[4]==pl && markers[7]==pl)
        return 1;
    if(markers[2]==pl && markers[5]==pl && markers[8]==pl)
        return 1;
    if(markers[3]==pl && markers[6]==pl && markers[9]==pl)
        return 1;
    return 0;
}
void Move(int index,char player)
{
    markers[index]=player;
}
void print_board()
{
    cout<<"\n";
    cout<<"\t"<<" "<<markers[1]<<" | "<<markers[2]<<" | "<<markers[3]<<" "<<"\n";
    cout<<"\t"<<"_"<<"_"<<"_|_"<<"_"<<"_|_"<<"_"<<"_"<<"\n";
    cout<<"\t"<<" "<<markers[4]<<" | "<<markers[5]<<" | "<<markers[6]<<" "<<"\n";
    cout<<"\t"<<"_"<<"_"<<"_|_"<<"_"<<"_|_"<<"_"<<"_"<<"\n";
    cout<<"\t"<<" "<<markers[7]<<" | "<<markers[8]<<" | "<<markers[9]<<" "<<"\n";
    cout<<"\t"<<" "<<" "<<" | "<<" "<<" | "<<" "<<" "<<"\n";
}
int main()
{
    int matchstatus=0,i;
    int playerturn=1;
    char player1,player2;
    cout<<"\tWelcome to TIC TAC TOE!!\n\n";
    cout<<"\tPlayer 1 choose your symbol X or O: ";
    cin>>player1;
    cout<<"\tPlayer 2 choose your symbol X or O: ";
    cin>>player2;
    print_board();
    if(player1==player2)
        cout<<"\tFOUL!! Both players are using same symbol!!";
    do
    {
        if(playerturn==1)
        {
            cout<<"\tPlayer 1's turn..Make your Move: ";
            cin>>i;
            Move(i,player1);
            print_board();
            if(!isgameOver(player1,i))
                playerturn++;
            else
            {
                cout<<"\tCongrats!! Player 1 Won!!!";
                matchstatus=1;
                break;
            }
        }
        if(playerturn==2)
        {
            cout<<"\tPlayer 2's turn..make your Move: ";
            cin>>i;
            Move(i,player2);
            print_board();
            if(!isgameOver(player2,i))
                playerturn--;
            else
            {
                cout<<"\tCongrats!! Player 2 Won!!!";
                matchstatus=1;
                break;
            }
        }
    }while(!matchstatus);
    return 0;
}
