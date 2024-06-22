#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void start();
void kingsmoves(int*, int*, int game_board[][8], int);
void kingremove(int, int, int game_board[][8], int);
void kingprint(int , int , int game_board[][8], int size);
void kingsmovesplayers(int, int, int game_board[][8], int);


void rocksmoves(int*, int*, int game_board[][8], int);
void rockmovesplayers(int, int, int, int, int game_board[][8], int);
void rockremove(int, int,int, int game_board[][8], int);


void knightsmoves(int*, int*, int game_board[][8], int);
void knightmovesplayers(int, int, int, int, int game_board[][8], int);
void knightremove(int, int,  int, int game_board[][8], int);

void bishopsmoves(int*, int*, int game_board[][8], int);
void bishopmovesplayers(int, int, int, int, int game_board[][8], int);
void bishopremove(int, int,  int, int game_board[][8], int);

void queensmoves(int*, int*, int game_board[][8], int);
void queenmovesplayers(int, int, int,int game_board[][8], int);
void queenremove(int, int,  int, int game_board[][8], int);


void nextmove(int, int, int, int game_board[][8], char);
void savetheking(int, int, int, int game_board[][8], int);


int main()
{
    start();

    return 0;
}



void start() {
    srand(time(0));
    int your_player = 0;
    int pos1 = 0, pos2 = 0;
    int game_board[8][8] = {};
    char ch = 0;

    int option;
    cout << "Enter your choice :" << endl;
    cout << "[1] Your next move" << endl;
    cout << "[2] Save the King(2 player game)" << endl;
    cout << "YOUR CHOICE :";
    cin >> option;
    switch (option)
    {
    case 1:
    {

        nextmove(your_player, pos1, pos2, game_board, ch);
        break;
    }
    case 2:
    {
        int opponent_choice;




        cout << "\n\nOpponent player!Please choose your Player :" << endl;
        cout << "[1]Two Bishops " << endl;
        cout << "[2]Two Knights " << endl;
        cout << "[3]Two Rocks " << endl;
        cout << "[4] Queen" << endl;
        cout << "YOUR CHOICE :";
        cin >> opponent_choice;

        savetheking(opponent_choice, pos1, pos2, game_board, 8);
        break;
    }

    }


}


void nextmove(int pos1, int pos2, int your_player, int game_board[][8], char ch)
{

    do {

        //showing menu to select the player
        cout << "Enter your choice :" << endl;
        cout << "\n[1] King ";
        cout << "\n[2] Queen ";
        cout << "\n[3] Bishop ";
        cout << "\n[4] Rock ";
        cout << "\n[5] Knight " << endl;

        cout << "YOUR CHOICE :";
        cin >> your_player;

        switch (your_player)
        {
        case 1:
        {
            cout << "\nYou choose KING ";
            cout << "\nEnter the initial position";
            cout << "\nRow :";
            cin >> pos1;
            cout << "\nCol :";
            cin >> pos2;

            //function calling for KING moves
            kingsmoves(&pos1, &pos2, game_board, 8);
            break;
        }

        case 2:
        {
            cout << "\nYou choose QUEEN ";
            cout << "\nEnter the initial position";
            cout << "\nRow :";
            cin >> pos1;
            cout << "\nCol :";
            cin >> pos2;

            //function calling for QUEEN moves
            queensmoves(&pos1,&pos2, game_board, 8);

            break;
        }

        case 3:
        {
            cout << "\nYou choose BISHOP ";
            cout << "\nEnter the initial position";
            cout << "\nRow :";
            cin >> pos1;
            cout << "\nCol :";
            cin >> pos2;

            //function calling for BISHOP moves
            bishopsmoves(&pos1,&pos2, game_board, 8);
            break;
        }

        case 4:
        {
            cout << "\nYou choose ROCK ";
            cout << "\nEnter the initial position";
            cout << "\nRow :";
            cin >> pos1;
            cout << "\nCol :";
            cin >> pos2;

            //function calling for ROCK moves
            rocksmoves(&pos1,&pos2, game_board, 8);

            break;
        }

        case 5:
        {
            cout << "\nYou choose KNIGHT ";
            cout << "\nEnter the initial position";
            cout << "\nRow :";
            cin >> pos1;
            cout << "\nCol :";
            cin >> pos2;

            //function calling for KNIGHT moves
            knightsmoves(&pos1,&pos2, game_board, 8);

            break;
        }
        }

        game_board[pos1 - 1][pos2 - 1] = 1;


        cout << "Do you want to finish(Y or N):";
        cin >> ch;

    } while (ch == 'n' || ch == 'N');
}

void savetheking(int opponent_choice, int kingrow, int kingcolumn, int game_board[][8], int size)
{
    if (kingrow != 2) {
        switch (opponent_choice)
        {
        case 1:
        {
            cout << "\n\nYou have choose 2 Bishops ";
            break;

        }

        case 2:
        {
            cout << "\n\nYou have choose 2 Knights ";

            break;

        }

        case 3:
        {
            cout << "\n\nYou have choose 2 Rocks ";
            break;

        }

        case 4:
        {
            cout << "\n\nYou have choose a Queen ";
            break;

        }



        }
    }

   


   

   

    int bishop_row1 = rand()%8;
    int bishop_col1 = rand()%8;
    int bishop_row2 = rand()%8;
    int bishop_col2 = rand()%8;


    int rock_row1 = rand()%8;
    int rock_col1 = rand()%8;
    int rock_row2 = rand()%8;
    int rock_col2 = rand()%8;

    int knight_row1 =  rand()%8;
    int knight_col1 =  rand()%8;
    int knight_row2 =  rand()%8;
    int knight_col2 =  rand()%8;

    int queen_row = rand()%8;
    int queen_col = rand()%8;

  int time=0;
    switch (opponent_choice)
    {
    case 1:
    {
         kingrow = 1;
         kingcolumn = 3;
         kingsmovesplayers(kingrow, kingcolumn, game_board, 8);
         cout << "\n\n The BISHOP current position is represented by 7 and the next positions are represented by 8 " << endl;
       
         bishop_row1 = 5;
         bishop_col1 = 1;
         bishop_row2 = 4;
         bishop_col2 = 4;
         
       
          time=1;
            if (time == 1)
                bishopmovesplayers(opponent_choice, time, bishop_row1, bishop_col1, game_board, 8);
                time=2;
            if (time == 2)
                bishopmovesplayers(opponent_choice, time, bishop_row2, bishop_col2, game_board, 8);
       
        break;

    }

    case 2:
    {  
         kingrow = 2;
         kingcolumn = 1;
         kingsmovesplayers(kingrow, kingcolumn, game_board, 8);
        cout << "\n\n The Knight current position is represented by 5 and the next positions are represented by 6 " << endl;
       
        knight_row1 = 6;
        knight_col1 = 4;
        knight_row2 = 2;
        knight_col2 = 5;

        time = 1;
        if (time == 1)
            knightmovesplayers(opponent_choice, time, knight_row1, knight_col1, game_board, 8);
        time = 2;
        if (time == 2)
            knightmovesplayers(opponent_choice, time, knight_row2, knight_col2, game_board, 8);

        break;
    }

    case 3:
    {
         kingrow = 6;
         kingcolumn = 1;
         kingsmovesplayers(kingrow, kingcolumn, game_board, 8);
        cout << "\n\n The ROCK current position is represented by 3 and the next positions are represented by 4 " << endl;
       
        rock_row1 = 1;
        rock_col1 = 6;
        rock_row2 = 3;
        rock_col2 = 3;
       
           time=1;
            if (time == 1)
                rockmovesplayers(opponent_choice, time, rock_row1, rock_col1, game_board, 8);
           
            time=2;
            if (time == 2)
                rockmovesplayers(opponent_choice, time, rock_row2, rock_col2, game_board, 8);
       
        break;

    }

    case 4:
    {
         kingrow = 6;
         kingcolumn = 5;
         kingsmovesplayers(kingrow, kingcolumn, game_board, 8);
         
         queen_row = 3;
         queen_col = 4;
        queenmovesplayers(opponent_choice, queen_row, queen_col, game_board, 8);
        break;

    }



    }
   
   
    switch(opponent_choice)
    {
        case 1:
            {char ch;
              do{
                 int option;

                  cout << "OPPONENT TURN :" << endl;
                  cout << "Choose your option:" << endl;
                  cout << "[1] Bishop 1" << endl;
                  cout << "[2]  Bishop 2 " << endl;
                  cout<<"Your Choice :";
                  cin >> option;
                  switch (option)
                 {
                  case 1:
                     {
                     
                       int o=5,m=1;
                        cout << "\nEnter  position where you want to move :";
                        cout << "\nRow :";
                        cin >> bishop_row1;
                        cout << "\nCol :";
                        cin >> bishop_col1;
                   
                        bishopremove(option, o, m,  game_board, 8);
                     
                        time=2;
                        bishopmovesplayers(opponent_choice, time, bishop_row1, bishop_col1, game_board, 8);

                       cout << "Player Turn :" << endl;
                       cout << "\nEnter  position where you want to move King:";
                       cout << "\nRow :";
                       cin >> kingrow;
                       cout << "\nCol :";
                       cin >> kingcolumn;
                     
                       kingremove( o, m,  game_board, 8);
                       
                                kingsmovesplayers(kingrow, kingcolumn, game_board, 8);


                      kingprint(kingrow, kingcolumn, game_board, 8);
                      cout << endl;



                      break;
                  }
                 
                  case 2:
                     {
                        int o=4,m=4;
                        cout << "\nEnter  position where you want to move :";
                        cout << "\nRow :";
                        cin >> bishop_row2;
                        cout << "\nCol :";
                        cin >> bishop_col2;
                     
                     
                        bishopremove(option, o, m,  game_board, 8);

                        time=2;
                        bishopmovesplayers(opponent_choice, time, bishop_row2, bishop_col2, game_board, 8);

                        cout << "Player Turn :" << endl;
                        cout << "\nEnter  position where you want to move King:";
                        cout << "\nRow :";
                        cin >> kingrow;
                        cout << "\nCol :";
                        cin >> kingcolumn;
                     
                        kingremove( o, m,  game_board, 8);
                       
                                kingsmovesplayers(kingrow, kingcolumn, game_board, 8);


                        kingprint(kingrow, kingcolumn, game_board, 8);
                        cout << endl;



                   
                     }

                }
               
               
                cout << "Do you want to finish(Y or N):";
                cin >> ch;

            } while (ch=='n'||ch=='N');
            break;
         }
        case 2:
         {
            char ch;
           do{
               int option;

                cout << "OPPONENT TURN :" << endl;
                cout << "Choose your option:" << endl;
                cout << "[1] Knight 1" << endl;
                cout << "[2]  Knight 2 " << endl;
                cout<<"Your Choice :";
                cin >> option;
                switch (option)
                {
                  case 1:
                  {
                     
                     int o=6,m=4;
                      cout << "\nEnter  position where you want to move :";
                      cout << "\nRow :";
                      cin >> knight_row1;
                      cout << "\nCol :";
                      cin >> knight_col1;
                   
                     knightremove(option, o, m,  game_board, 8);
                     
                     time=2;
                     knightmovesplayers(opponent_choice, time, knight_row1, knight_col1, game_board, 8);

                      cout << "Player Turn :" << endl;
                      cout << "\nEnter  position where you want to move King:";
                      cout << "\nRow :";
                      cin >> kingrow;
                      cout << "\nCol :";
                      cin >> kingcolumn;
                     
                       kingremove( o, m,  game_board, 8);
                       
                                kingsmovesplayers(kingrow, kingcolumn, game_board, 8);


                      kingprint(kingrow, kingcolumn, game_board, 8);
                      cout << endl;



                      break;
                  }
                  case 2:
                  {
                      int o=2,m=5;
                       cout << "\nEnter  position where you want to move :";
                      cout << "\nRow :";
                      cin >> knight_row2;
                      cout << "\nCol :";
                      cin >> knight_col2;
                   
                     knightremove(option, o, m,  game_board, 8);
                     
                     time=2;
                     knightmovesplayers(opponent_choice, time, knight_row2, knight_col2, game_board, 8);

                      cout << "Player Turn :" << endl;
                      cout << "\nEnter  position where you want to move King:";
                      cout << "\nRow :";
                      cin >> kingrow;
                      cout << "\nCol :";
                      cin >> kingcolumn;
                     
                       kingremove( o, m,  game_board, 8);
                       
                                kingsmovesplayers(kingrow, kingcolumn, game_board, 8);


                      kingprint(kingrow, kingcolumn, game_board, 8);
                      cout << endl;



                      break;
                  }

                }
               
               
                cout << "Do you want to finish(Y or N):";
                cin >> ch;

            } while (ch=='n'||ch=='N');
            break;  
        }
       
       case 3:
        {
            char ch;
           do{
               int option;

                cout << "OPPONENT TURN :" << endl;
                cout << "Choose your option:" << endl;
                cout << "[1] ROCK 1" << endl;
                cout << "[2] ROCK 2 " << endl;
                cout<<"Your Choice :";
                cin >> option;
                switch (option)
                {
                  case 1:
                  {
                     
                     int o=1,m=6;
                      cout << "\nEnter  position where you want to move :";
                      cout << "\nRow :";
                      cin >> rock_row1;
                      cout << "\nCol :";
                      cin >> rock_col1;
                   
                     rockremove(option, o, m,  game_board, 8);
                     
                     time=2;
                     rockmovesplayers(opponent_choice, time, rock_row1, rock_col1, game_board, 8);

                      cout << "Player Turn :" << endl;
                      cout << "\nEnter  position where you want to move King:";
                      cout << "\nRow :";
                      cin >> kingrow;
                      cout << "\nCol :";
                      cin >> kingcolumn;
                     
                       kingremove( o, m,  game_board, 8);
                       
                                kingsmovesplayers(kingrow, kingcolumn, game_board, 8);


                      kingprint(kingrow, kingcolumn, game_board, 8);
                      cout << endl;



                      break;
                  }
                  case 2:
                  {
                      int o=3,m=3;
                       cout << "\nEnter  position where you want to move :";
                      cout << "\nRow :";
                      cin >> rock_row2;
                      cout << "\nCol :";
                      cin >> rock_col2;
                   
                     rockremove(option, o, m,  game_board, 8);
                     
                     time=2;
                     rockmovesplayers(opponent_choice, time, rock_row2, rock_col2, game_board, 8);

                      cout << "Player Turn :" << endl;
                      cout << "\nEnter  position where you want to move King:";
                      cout << "\nRow :";
                      cin >> kingrow;
                      cout << "\nCol :";
                      cin >> kingcolumn;
                     
                       kingremove( o, m,  game_board, 8);
                       
                                kingsmovesplayers(kingrow, kingcolumn, game_board, 8);


                      kingprint(kingrow, kingcolumn, game_board, 8);
                      cout << endl;



                      break;
                  }

                }
               
               
                cout << "Do you want to finish(Y or N):";
                cin >> ch;

            } while (ch=='n'||ch=='N');
            break;  
        }
       
        case 4:
         {
            char ch;
           do{
               int option;

                cout << "OPPONENT TURN :" << endl;
               
                 
                     
                     int o=3,m=4;
                      cout << "\nEnter  position where you want to move :";
                      cout << "\nRow :";
                      cin >> queen_row;
                      cout << "\nCol :";
                      cin >> queen_col;
                   
                     queenremove(option, o, m,  game_board, 8);
                     
                     time=2;
                     queenmovesplayers(opponent_choice, queen_row, queen_col, game_board, 8);

                      cout << "Player Turn :" << endl;
                      cout << "\nEnter  position where you want to move King:";
                      cout << "\nRow :";
                      cin >> kingrow;
                      cout << "\nCol :";
                      cin >> kingcolumn;
                     
                       kingremove( o, m,  game_board, 8);
                       
                                kingsmovesplayers(kingrow, kingcolumn, game_board, 8);


                      kingprint(kingrow, kingcolumn, game_board, 8);
                      cout << endl;



                   
                 
                 
               
               
               
                cout << "Do you want to finish(Y or N):";
                cin >> ch;

            } while (ch=='n'||ch=='N');
            break;  
        }
   
        }
       


}

void rockremove(int opponent_choice,int i, int j, int array[][8], int size)
{
    array[i][j] = 0;

        cout << "\n\nExisting position of ROCK " << time << " is [" << i << "][" << j << "]";
        cout << "\nThe next moves are:" << endl;
        for (int k = 0; k < size; k++)
        {
            if (k != i)
            {
               
                    array[k][j] = 0;
                cout << "[" << k << "][" << j << "]" << ", ";
            }
        }



        for (int l = 0; l < size; l++)
        {
           
                array[i][l] = 0;
                cout << "[" << i << "][" << l << "]" << ", ";
           

        }

}

void queenremove(int opponent_choice,int i, int j, int array[][8], int size)
{
    array[i][j] = 0;
        for (int k = 0; k < size; k++)
        {
            if (k != i)
            {
                array[k][j] =0;
                cout << "[" << k << "][" << j << "]" << ", ";
            }
        }

        for (int l = 0; l < size; l++)
        {
            if (l != j)
            {
                array[i][l] = 0;
                cout << "[" << i << "][" << l << "]" << ", ";
            }
        }


        for (int m = i - 1, n = j - 1; (m >= 0 && n >= 0); m--, n--)
        {
            array[m][n] = 0;
            cout << "[" << m << "][" << n << "]" << ", ";
        }


        for (int m = i + 1, n = j + 1; (m <= 7 && n <= 7); m++, n++)
        {
            array[m][n] = 0;
            cout << "[" << m << "][" << n << "]" << ", ";
        }


        for (int m = i - 1, n = j + 1; (m >= 0 && n <= 7); m--, n++)
        {
            array[m][n] = 0;
            cout << "[" << m << "][" << n << "]" << ", ";
        }


        for (int m = i + 1, n = j - 1; (m <= 7 && n >= 0); m++, n--)
        {
            array[m][n] = 0;
            cout << "[" << m << "][" << n << "]" << ", ";
        }

        cout << endl;

}

void knightremove(int opponent_choice,int i, int j, int array[][8], int size)
{
   
    array[i][j] = 0;

        if (i - 2 >= 0 && j - 1 >= 0)
        {
            cout << "[" << i - 2 << "][" << j - 1 << "]" << ", ";
            array[i - 2][j - 1] = 0;

        }


        if (i - 2 >= 0 && j + 1 <= 7)
        {
            cout << "[" << i - 2 << "][" << j + 1 << "]" << ", ";
            array[i - 2][j + 1] = 0;
        }


        if (i - 1 >= 0 && j - 2 >= 0)
        {
            cout << "[" << i - 1 << "][" << j - 2 << "]" << ", ";
            array[i - 1][j - 2] = 0;

        }


        if (i - 1 >= 0 && j + 2 <= 7)
        {
            cout << "[" << i - 1 << "][" << j + 2 << "]" << ", ";
            array[i - 1][j + 2] = 0;
        }


        if (i + 1 <= 7 && j - 2 >= 0)
        {
            cout << "[" << i + 1 << "][" << j - 2 << "]" << ", ";
            array[i + 1][j - 2] = 0;

        }



        if (i + 1 <= 7 && j + 2)
        {
            cout << "[" << i + 1 << "][" << j + 2 << "]" << ", ";
            array[i + 1][j + 2] = 0;
        }


        if (i + 2 <= 7 && j - 1 >= 0)
        {
            cout << "[" << i + 2 << "][" << j - 1 << "]" << ", ";
            array[i + 2][j - 1] = 0;

        }


        if (i + 2 <= 7 && j + 1 <= 7)
        {
            cout << "[" << i + 2 << "][" << j + 1 << "]" << ", ";
            array[i + 2][j + 1] = 0;

        }

   
}

void kingprint(int i, int j, int array[][8], int size)
{
    cout<<endl;
    for(int l=0;l<size;l++)
    {
        for(int a=0;a<size;a++)
      {
       
          cout<< array[l][a]<<"  ";
      }
      cout<<endl;
 }
}

void kingremove(int i, int j, int array[][8], int size)
{
    for(int l=0;l<size;l++)
    {
        for(int a=0;a<size;a++)
      {
        if(array[l][a]==2 || array[l][a]==1)
           array[l][a]=0;
      }
       
    }
   
   
   
}
void queenmovesplayers(int opponent_choice, int i, int j, int array[][8], int size)
{
   

    cout << "\nExisting position of QUEEN is [" << i << "][" << j << "]";
   

    cout << "\nThe next moves are:" << endl;


    int p = 0, z = 1;
    for (int k = 0; k < size; k++)
    {
        if (k != i)
        {
            z++;
            if (array[k][j] != 1)
                p++;
        }
    }

    for (int l = 0; l < size; l++)
    {
        if (l != j)
        {
            z++;
            if (array[i][l] != 1)
                p++;
        }
    }


    for (int m = i - 1, n = j - 1; (m >= 0 && n >= 0); m--, n--)
    {
        z++;
        if (array[m][n] != 1)
            p++;
    }


    for (int m = i + 1, n = j + 1; (m <= 7 && n <= 7); m++, n++)
    {
        z++;
        if (array[m][n] != 1)
            p++;
    }


    for (int m = i - 1, n = j + 1; (m >= 0 && n <= 7); m--, n++)
    {
        z++;
        if (array[m][n] != 1)
            p++;
    }


    for (int m = i + 1, n = j - 1; (m <= 7 && n >= 0); m++, n--)
    {
        z++;
        if (array[m][n] != 1)
            p++;
    }
    p++;

    if (p == z && array[i][j] != 1)
    {
        array[i][j] = 7;
        for (int k = 0; k < size; k++)
        {
            if (k != i)
            {
                array[k][j] =9;
                cout << "[" << k << "][" << j << "]" << ", ";
            }
        }

        for (int l = 0; l < size; l++)
        {
            if (l != j)
            {
                array[i][l] = 9;
                cout << "[" << i << "][" << l << "]" << ", ";
            }
        }


        for (int m = i - 1, n = j - 1; (m >= 0 && n >= 0); m--, n--)
        {
            array[m][n] = 9;
            cout << "[" << m << "][" << n << "]" << ", ";
        }


        for (int m = i + 1, n = j + 1; (m <= 7 && n <= 7); m++, n++)
        {
            array[m][n] = 9;
            cout << "[" << m << "][" << n << "]" << ", ";
        }


        for (int m = i - 1, n = j + 1; (m >= 0 && n <= 7); m--, n++)
        {
            array[m][n] = 9;
            cout << "[" << m << "][" << n << "]" << ", ";
        }


        for (int m = i + 1, n = j - 1; (m <= 7 && n >= 0); m++, n--)
        {
            array[m][n] = 9;
            cout << "[" << m << "][" << n << "]" << ", ";
        }

        cout << endl;


        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << array[i][j] << "  ";
            }
            cout << endl;
        }

    }
}


void bishopremove(int opponent_choice,int i, int j, int array[][8], int size)
{
          array[i][j] = 0;
       
        for (int m = i - 1, n = j - 1; (m >= 0 && n >= 0); m--, n--)
        {
           
             array[m][n] = 0;
           
            cout << "[" << m << "][" << n << "]" << ", ";
        }



        for (int m = i + 1, n = j + 1; (m <= 7 && n <= 7); m++, n++)
        {
             array[m][n] = 0;
            cout << "[" << m << "][" << n << "]" << ", ";
        }



        for (int m = i - 1, n = j + 1; (m >= 0 && n <= 7); m--, n++)
        {
             array[m][n] = 0;
            cout << "[" << m << "][" << n << "]" << ", ";
        }



        for (int m = i + 1, n = j - 1; (m <= 7 && n >= 0); m++, n--)
        {
             array[m][n] = 0;
            cout << "[" << m << "][" << n << "]" << ", ";
        }
       
       
}


void bishopmovesplayers(int opponent_choice, int time, int i, int j, int array[][8], int size)
{


    cout << "\nExisting position of BISHOP " << time << " is: [" << i << "][" << j << "]";


    cout << "\nThe next moves are:" << endl;

    int p = 0, k = 1;
    for (int m = i - 1, n = j - 1; (m >= 0 && n >= 0); m--, n--)
    {
        k++;
        if (array[m][n] != 1)
            p++;
    }



    for (int m = i + 1, n = j + 1; (m <= 7 && n <= 7); m++, n++)
    {
        k++;
        if (array[m][n] != 1)
            p++;
    }



    for (int m = i - 1, n = j + 1; (m >= 0 && n <= 7); m--, n++)
    {
        k++;
        if (array[m][n] != 1)
            p++;
    }



    for (int m = i + 1, n = j - 1; (m <= 7 && n >= 0); m++, n--)
    {
        k++;
        if (array[m][n] != 1)
            p++;
    }

    p++;

    if (p == k && array[i][j] != 1 && array[i][j] != 7)
    {
       
          array[i][j] = 7;
       
        for (int m = i - 1, n = j - 1; (m >= 0 && n >= 0); m--, n--)
        {
           
             array[m][n] = 8;
           
            cout << "[" << m << "][" << n << "]" << ", ";
        }



        for (int m = i + 1, n = j + 1; (m <= 7 && n <= 7); m++, n++)
        {
             array[m][n] = 8;
            cout << "[" << m << "][" << n << "]" << ", ";
        }



        for (int m = i - 1, n = j + 1; (m >= 0 && n <= 7); m--, n++)
        {
             array[m][n] = 8;
            cout << "[" << m << "][" << n << "]" << ", ";
        }



        for (int m = i + 1, n = j - 1; (m <= 7 && n >= 0); m++, n--)
        {
             array[m][n] = 8;
            cout << "[" << m << "][" << n << "]" << ", ";
        }


        cout << endl;
        if (time == 2) {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    cout << array[i][j] << "  ";
                }
                cout << endl;
            }
        }
    }

    else {
        for (int i = 0; i < 8; i++)
        {
            for (int k = 0; k < 8; k++)
            {
                array[i][k] = 0;
            }
        }
        savetheking(opponent_choice, 2, j, array, 8);
    }

}





//function definition for KING random  moves
void kingsmovesplayers(int i, int j, int array[][8], int size)
{



    cout << "\n\nExisting position of king is [" << i << "][" << j << "]";
    array[i][j] = 1;


    int k = i - 1, l = j - 1;


    cout << "\nThe next moves KINGS are:" << endl;
    for (int m = 0; m < 3; m++)
    {
        l = j - 1;
        for (int n = 0; n < 3; n++)
        {

            if (k == i && l == j) {}
            else {
                if ((l >= 0 && k >= 0) && (l <= 7 && k <= 7))
                {
                    array[k][l] = 2;
                    cout << "[" << k << "][" << l << "]" << "  ";

                }
            }
            l++;
        }
        k++;
    }


}


void knightmovesplayers(int opponent_choice, int time, int i, int j, int array[][8], int size)
{




    cout << "\nExisting position of KNIGHT " << time << " is :[" << i << "][" << j << "]";


    cout << "\nThe next moves are:" << endl;


    int p = 0, k = 1;


    if (i - 2 >= 0 && j - 1 >= 0)
    {
        k++;
        if (array[i - 2][j - 1] != 1)
            p++;

    }


    if (i - 2 >= 0 && j + 1 <= 7)
    {
        k++;
        if (array[i - 2][j + 1] != 2)
            p++;
    }


    if (i - 1 >= 0 && j - 2 >= 0)
    {
        k++;
        if (array[i - 1][j - 2] != 1)
            p++;

    }


    if (i - 1 >= 0 && j + 2 <= 7)
    {
        k++;
        if (array[i - 1][j + 2] != 1)
            p++;
    }


    if (i + 1 <= 7 && j - 2 >= 0)
    {
        k++;
        if (array[i + 1][j - 2] != 1)
            p++;

    }


    if (i + 1 <= 7 && j + 2)
    {
        k++;
        if (array[i + 1][j + 2] != 1)
            p++;
    }


    if (i + 2 <= 7 && j - 1 >= 0)
    {
        k++;
        if (array[i + 2][j - 1] != 1)
            p++;
    }


    if (i + 2 <= 7 && j + 1 <= 7)
    {
        k++;
        if (array[i + 2][j + 1] != 1)
            p++;
    }
    p++;

    if (p == k && array[i][j] != 1 && array[i][j] != 5)
    {
        array[i][j] = 5;

        if (i - 2 >= 0 && j - 1 >= 0)
        {
            cout << "[" << i - 2 << "][" << j - 1 << "]" << ", ";
            array[i - 2][j - 1] = 6;

        }


        if (i - 2 >= 0 && j + 1 <= 7)
        {
            cout << "[" << i - 2 << "][" << j + 1 << "]" << ", ";
            array[i - 2][j + 1] = 6;
        }


        if (i - 1 >= 0 && j - 2 >= 0)
        {
            cout << "[" << i - 1 << "][" << j - 2 << "]" << ", ";
            array[i - 1][j - 2] = 6;

        }


        if (i - 1 >= 0 && j + 2 <= 7)
        {
            cout << "[" << i - 1 << "][" << j + 2 << "]" << ", ";
            array[i - 1][j + 2] = 6;
        }


        if (i + 1 <= 7 && j - 2 >= 0)
        {
            cout << "[" << i + 1 << "][" << j - 2 << "]" << ", ";
            array[i + 1][j - 2] = 6;

        }



        if (i + 1 <= 7 && j + 2)
        {
            cout << "[" << i + 1 << "][" << j + 2 << "]" << ", ";
            array[i + 1][j + 2] = 6;
        }


        if (i + 2 <= 7 && j - 1 >= 0)
        {
            cout << "[" << i + 2 << "][" << j - 1 << "]" << ", ";
            array[i + 2][j - 1] = 6;

        }


        if (i + 2 <= 7 && j + 1 <= 7)
        {
            cout << "[" << i + 2 << "][" << j + 1 << "]" << ", ";
            array[i + 2][j + 1] = 6;

        }


        cout << endl;
        if (time == 2) {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    cout << array[i][j] << "  ";
                }
                cout << endl;

            }
        }
    }

    else {
        for (int i = 0; i < 8; i++)
        {
            for (int k = 0; k < 8; k++)
            {
                array[i][k] = 0;
            }
        }
        savetheking(opponent_choice, 2, j, array, 8);
    }


}



void rockmovesplayers(int opponent_choice, int time, int i, int j, int array[][8], int size)
{






    int p = 0;
    for (int k = 0; k < size; k++)
    {
        if (k != i)
        {
            if (array[k][j] != 1)
            {
                p++;
            }

        }
    }

    int q = 0;
    for (int l = 0; l < size; l++)
    {
        if (l != j)
        {
            if (array[i][l] != 1)
            {
                q++;
            }
        }

    }

    if (p == 7 && q == 7 && array[i][j] != 1 && array[i][j] != 3) {
        array[i][j] = 3;

        cout << "\n\nExisting position of ROCK  is [" << i << "][" << j << "]";
        cout << "\nThe next moves are:" << endl;
        for (int k = 0; k < size; k++)
        {
            if (k != i)
            {
                if (array[k][j] != 3)
                    array[k][j] = 4;
                cout << "[" << k << "][" << j << "]" << ", ";
            }
        }



        for (int l = 0; l < size; l++)
        {
            if (l != j && array[i][l] != 3)
            {
                array[i][l] = 4;
                cout << "[" << i << "][" << l << "]" << ", ";
            }

        }







        cout << endl;

        if (time == 2) {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    cout << array[i][j] << "  ";
                }
                cout << endl;
            }
        }
    }

    else {
        for (int i = 0; i < 8; i++)
        {
            for (int k = 0; k < 8; k++)
            {
                array[i][k] = 0;
            }
        }
        savetheking(opponent_choice, 2, j, array, 8);

    }

}







//function definition for KING moves
void kingsmoves(int *a, int *b, int array[][8], int size)
{

    //[i][j] will be the initial position ,that's why -1
    int i = *a - 1, j = *b - 1;

    cout << "Existing position of king is [" << i << "][" << j << "]";
    array[i][j] = 1;


    int k = i - 1, l = j - 1;


    cout << "\nThe next moves are:" << endl;
    for (int m = 0; m < 3; m++)
    {
        l = j - 1;
        for (int n = 0; n < 3; n++)
        {

            if (k == i && l == j) {}
            else {
                if ((l >= 0 && k >= 0) && (l <= 7 && k <= 7))
                {
                    array[k][l] = 2;
                    cout << "[" << k << "][" << l << "]" << "  ";

                }
            }
            l++;
        }
        k++;
    }

    cout << endl << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << "  ";
        }
        cout << endl;
    }
}


void bishopsmoves(int* a, int* b, int array[][8], int size)
{
    int i = *a - 1, j = *b - 1;

    cout << "Existing position of BISHOP is [" << i << "][" << j << "]";
    array[i][j] = 1;

    cout << "\nThe next moves are:" << endl;

    for (int m = i - 1, n = j - 1; (m >= 0 && n >= 0); m--, n--)
    {
        array[m][n] = 2;
        cout << "[" << m << "][" << n << "]" << ", ";
    }



    for (int m = i + 1, n = j + 1; (m <= 7 && n <= 7); m++, n++)
    {
        array[m][n] = 2;
        cout << "[" << m << "][" << n << "]" << ", ";
    }



    for (int m = i - 1, n = j + 1; (m >= 0 && n <= 7); m--, n++)
    {
        array[m][n] = 2;
        cout << "[" << m << "][" << n << "]" << ", ";
    }



    for (int m = i + 1, n = j - 1; (m <= 7 && n >= 0); m++, n--)
    {
        array[m][n] = 2;
        cout << "[" << m << "][" << n << "]" << ", ";
    }


    cout << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << "  ";
        }
        cout << endl;
    }

}



void rocksmoves(int* a, int* b, int array[][8], int size)
{


    int i = *a - 1, j = *b - 1;

    cout << "Existing position of ROCK is [" << i << "][" << j << "]";
    array[i][j] = 1;

    cout << "\nThe next moves are:" << endl;

    for (int k = 0; k < size; k++)
    {
        if (k != i)
        {
            array[k][j] = 2;
            cout << "[" << k << "][" << j << "]" << ", ";
        }
    }


    for (int l = 0; l < size; l++)
    {
        if (l != j)
        {
            array[i][l] = 2;
            cout << "[" << i << "][" << l << "]" << ", ";
        }

    }


    cout << endl;


    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << "  ";
        }
        cout << endl;
    }


}


void knightsmoves(int* a, int* b, int array[][8], int size)
{

    int i = *a - 1, j = *b - 1;

    cout << "Existing position of KNIGHT is [" << i << "][" << j << "]";
    array[i][j] = 1;

    cout << "\nThe next moves are:" << endl;

    if (i - 2 >= 0 && j - 1 >= 0)
    {
        cout << "[" << i - 2 << "][" << j - 1 << "]" << ", ";
        array[i - 2][j - 1] = 2;

    }


    if (i - 2 >= 0 && j + 1 <= 7)
    {
        cout << "[" << i - 2 << "][" << j + 1 << "]" << ", ";
        array[i - 2][j + 1] = 2;
    }


    if (i - 1 >= 0 && j - 2 >= 0)
    {
        cout << "[" << i - 1 << "][" << j - 2 << "]" << ", ";
        array[i - 1][j - 2] = 2;

    }


    if (i - 1 >= 0 && j + 2 <= 7)
    {
        cout << "[" << i - 1 << "][" << j + 2 << "]" << ", ";
        array[i - 1][j + 2] = 2;
    }


    if (i + 1 <= 7 && j - 2 >= 0)
    {
        cout << "[" << i + 1 << "][" << j - 2 << "]" << ", ";
        array[i + 1][j - 2] = 2;

    }



    if (i + 1 <= 7 && j + 2)
    {
        cout << "[" << i + 1 << "][" << j + 2 << "]" << ", ";
        array[i + 1][j + 2] = 2;
    }


    if (i + 2 <= 7 && j - 1 >= 0)
    {
        cout << "[" << i + 2 << "][" << j - 1 << "]" << ", ";
        array[i + 2][j - 1] = 2;

    }


    if (i + 2 <= 7 && j + 1 <= 7)
    {
        cout << "[" << i + 2 << "][" << j + 1 << "]" << ", ";
        array[i + 2][j + 1] = 2;
    }


    cout << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << "  ";
        }
        cout << endl;

    }

}



void queensmoves(int *a, int *b, int array[][8], int size)
{
    int i = *a - 1, j = *b - 1;

    cout << "Existing position of QUEEN is [" << i << "][" << j << "]";
    array[i][j] = 1;

    cout << "\nThe next moves are:" << endl;

    for (int k = 0; k < size; k++)
    {
        if (k != i)
        {
            array[k][j] = 2;
            cout << "[" << k << "][" << j << "]" << ", ";
        }
    }

    for (int l = 0; l < size; l++)
    {
        if (l != j)
        {
            array[i][l] = 2;
            cout << "[" << i << "][" << l << "]" << ", ";
        }
    }


    for (int m = i - 1, n = j - 1; (m >= 0 && n >= 0); m--, n--)
    {
        array[m][n] = 2;
        cout << "[" << m << "][" << n << "]" << ", ";
    }


    for (int m = i + 1, n = j + 1; (m <= 7 && n <= 7); m++, n++)
    {
        array[m][n] = 2;
        cout << "[" << m << "][" << n << "]" << ", ";
    }


    for (int m = i - 1, n = j + 1; (m >= 0 && n <= 7); m--, n++)
    {
        array[m][n] = 2;
        cout << "[" << m << "][" << n << "]" << ", ";
    }


    for (int m = i + 1, n = j - 1; (m <= 7 && n >= 0); m++, n--)
    {
        array[m][n] = 2;
        cout << "[" << m << "][" << n << "]" << ", ";
    }

    cout << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << "  ";
        }
        cout << endl;
    }


}
