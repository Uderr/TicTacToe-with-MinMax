#include<iostream>
using namespace std;
int indice;
char tavola[9] = {'*','*','*','*','*','*','*','*','*'};

int isFull(){
    for(int i =0;i<9;i++){
        if(tavola[i]!='X'){
            if(tavola[i]!='O'){
                 return 0;
               }
        }
    }
return 1;
}

int victoryCondition(){
    for(int i=0;i<9;i+=3){
        if((tavola[i]==tavola[i+1])&&(tavola[i+1]==tavola[i+2])&&(tavola[i]=='O'))
            return 1;
        else if((tavola[i]==tavola[i+1])&&(tavola[i+1]==tavola[i+2])&&(tavola[i]=='X'))
            return 2;
    }for(int i=0;i<3;i++){
        if((tavola[i]==tavola[i+3])&&(tavola[i+3]==tavola[i+6])&&(tavola[i]=='O'))
            return 1;
        else if((tavola[i]==tavola[i+3])&&(tavola[i+3]==tavola[i+6])&&(tavola[i]=='X'))
            return 2;
    }if((tavola[0]==tavola[4])&&(tavola[4]==tavola[8])&&(tavola[0]=='O')){
        return 1;
    }else if((tavola[0]==tavola[4])&&(tavola[4]==tavola[8])&&(tavola[0]=='O')){
        return 2;
    }if((tavola[2]==tavola[4])&&(tavola[4]==tavola[6])&&(tavola[2]=='O')){
        return 1;
    }else if((tavola[2]==tavola[4])&&(tavola[4]==tavola[6])&&(tavola[2]=='X')){
        return 2;
    }
    return 0;
}

void disegna_tavola()
{
    cout<<endl<<"             "<< tavola[0]<<"|"<<tavola[1]<<"|"<<tavola[2]<<endl<<"             -----"<<endl;
    cout<<"             "<<tavola[3]<<"|"<<tavola[4]<<"|"<<tavola[5]<<endl;
    cout<<"             -----"<<endl;
    cout<<"             "<<tavola[6]<<"|"<<tavola[7]<<"|"<<tavola[8]<<endl;
}

int minimax(bool flag){

    int max_val=-1000,min_val=1000;
    int i,j,value = 1;
    if(victoryCondition() == 2)
        {return 10;}
    else if(victoryCondition() == 1)
        {return -10;}
    else if(isFull()== 1)
        {return 0;}
    int score[9] = {1,1,1,1,1,1,1,1,1};//if score[i]=1 then it is empty

        for(i=0;i<9;i++)
            {
                 if(tavola[i] == '*')
                {
                    if(min_val>max_val) // reverse of pruning condition.....
                  {
                      if(flag == true)
                   {
                     tavola[i] = 'X';
                     value = minimax(false);
                   }
                    else
                    {
                      tavola[i] = 'O';
                      value = minimax(true);
                    }
                  tavola[i] = '*';
                  score[i] = value;
                 }
               }
            }

        if(flag == true)
        {
                 max_val = -1000;
                 for(j=0;j<9;j++)
                {
                    if(score[j] > max_val && score[j] != 1)
                    {
                        max_val = score[j];
                        indice = j;
                    }
                }
                return max_val;
        }
        if(flag == false)
        {
                min_val = 1000;
                for(j=0;j<9;j++)
                {
                    if(score[j] < min_val && score[j] != 1)
                    {
                        min_val = score[j];
                        indice = j;
                    }
                }
            return min_val;
        }
}

int main() //The main function
{
   int move,choice;
   cout << "Tris" << endl;
   cout<<endl<<"Il simbolo dell'utente è O, quello del computer invece X" << endl;
   cout<<endl<<"Chi inizia per primo?  1 per l'umano, 2 per il computer";
   cin>>choice;
   if(choice == 1)
   {
       disegna_tavola();
      up:cout<<endl<<"Enter the move:";
         cin>>move;
         if(tavola[move-1]=='*')
         {
           tavola[move-1] = 'O';
           disegna_tavola();
         }
         else
         {
             cout<<endl<<"Mossa non valida, prova un'altra volta";
             goto up;
         }
   }

    while(true)
    {

        cout<<endl<<"CPU MOVE....";
        minimax(true);
        tavola[indice] = 'X';
        disegna_tavola();
        if(victoryCondition()==2)
        {
            cout<<endl<<"CPU WON.....";
            break;
        }
        if(isFull()==1)
        {
            cout<<endl<<"Draw....";
            break;
        }
again:  cout<<endl<<"Enter the move:";
        cin>>move;
        if(tavola[move-1]=='*')
         {
           tavola[move-1] = 'O';
           disegna_tavola();
         }
         else
         {
             cout<<endl<<"Invalid Move......Try different move";
             goto again;
         }
         if(victoryCondition()==1)
         {
             cout<<endl<<"You Won......";
             break;
         }
         if(isFull() == 1)
        {
            cout<<endl<<"Draw....";
            break;
        }
    }

}
