#include <iostream>
using namespace std;
char markers[10]={0};
char players[2]={'X','O'};
int isdraw()
{
    int flag=1;
    for(int i=1;i<=9;++i)
    {
        if(markers[i]!=0)
        {
            flag=1;
        }
        else
        {
            flag=0;
            break;
        }
    }
    return flag;
}
int isgameOver(char pl)
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
void restart()
{
    for(int i=0;i<10;++i)
        markers[i]=0;
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
    int pturn=0;
    char ch='y';
    cout<<"\tWelcome to TIC TAC TOE!!\n\n";
    cout<<"\tPlayer 1 :X\n";
    cout<<"\tPlayer 2 :O\n";
    print_board();
    do
    {
        cout<<"\tMake your Move Player "<<pturn+1<<": ";
        cin>>i;
        if(markers[i]!=0)
        {
            cout<<"\tAlready Marked Spot\n";
        }
        else{
            Move(i,players[pturn]);
            print_board();
            if(isgameOver(players[pturn]))
            {
                cout<<"\tCongrats!! Player "<<pturn+1<<" Won!!!\n";
                matchstatus=1;
                cout<<"\tWant a Rematch?? (Y/N) ";
                cin>>ch;
                if(ch=='y' || ch=='Y')
                {
                    restart();
                    matchstatus=0;
                    continue;
                }
            }
            if(isdraw())
            {
                cout<<"\tGame Draw!!\n";
                matchstatus=1;
                cout<<"\tWant a Rematch?? (Y/N) ";
                cin>>ch;
                if(ch=='y' || ch=='Y')
                {
                    restart();
                    matchstatus=0;
                    continue;
                }
            }
            if(pturn==1)
                pturn=0;
            else
                pturn=1;
        }
    }while(!matchstatus && (ch=='Y' || ch=='y'));
    return 0;
}
