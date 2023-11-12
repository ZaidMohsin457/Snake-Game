#include <iostream>
#include <conio.h>   //getch() and kbhit()
#include <time.h>    //including time
#include <windows.h> //sleep functions
#include <fstream>   //file handling
#include <string>

#define Max 30

// Color Escape Sequences
#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

using namespace std;
int BoardX = 30;
int BoardY = 30;
void save_game();
void set_screen();
template <class T>
void show(T a)
{
    if (a == 1)
    {
        cout << "GAME WON.......:)" << endl;
        exit(0);
    }
    else
    {
        cout << "GAME Lost.....:(" << endl;
        exit(0);
    }
}
class User
{
    // Class User Added For Multiplayer Features

    string name;
    string winner;
    int high_score, scores;

public:
    // constructor called

    User()
    {
        winner = '\0';
        name = "\0";
        high_score = 0;
        scores == 0;
    }
    void get()
    {
        cout << "Who's playing: ";
        cin >> name;
    }
    void set_score(int s)
    {
        scores = s;
    }

    // Saving User name and scores

    void save()
    {
        ofstream user("userdata.txt", ios::app);
        try
        {
            if (user.is_open())
            {
                user << name << endl
                     << scores << endl;
                user.close();
            }
            else
                throw 0;
        }
        catch (int a)
        {
            cout << "user file not opened..." << endl;
            exit(0);
        }
    }

    string return_name()
    {
        return name;
    }

    // Function to calculate high score and save it in the file

    void get_highscore()
    {
        ifstream read("userdata.txt");
        try
        {
            if (read.is_open())
            {
                string a;
                int s = 0;
                while (!read.eof())
                {
                    read >> a;
                    read >> s;
                    if (high_score < s)
                    {
                        winner = a;
                        high_score = s;
                    }
                    read.peek();
                }
                read.close();
            }
            else
                throw 0;
        }
        catch (int a)
        {
            cout << "read file not opened.." << endl;
            exit(0);
        }
    }

    // function used to Show the list of the Users present in the file ;

    void show_list()
    {
        ifstream read1("userdata.txt");
        try
        {
            if (read1.is_open())
            {
                string user, scor;
                while (!read1.eof())
                {
                    getline(read1, user);
                    cout << "Name: " << user;
                    getline(read1, scor);
                    cout << "\tscore: " << scor << endl;
                    read1.peek();
                }
                read1.close();
            }
            else
                throw 0;
        }
        catch (int a)
        {
            cout << "read1 file not opened.." << endl;
            exit(0);
        }
    }

    int return_highscore()
    {
        get_highscore();
        return high_score;
    }

    string return_winner()
    {
        return winner;
    }
} U;

class Snake : public User
{
public:
    int headX;
    int headY;
    int size;
    int *tailX;
    int *tailY;     // snake position, pointers for tail
    char direction; // for controlling the direction
    virtual void polymorphism()
    {
        cout << "Polymorphism used..." << endl;
    }
    Snake(int s = 1)
    {
        headX = BoardX / 2;
        headY = BoardY / 2; // snake initial position
        direction = '\0';
        size = s;
        tailX = new int[size];
        tailY = new int[size]; // allocating dynamic arrays for the tail
        for (int i = 0; i < size; i++)
        {
            tailX[i] = tailY[i] = 0; // initiallizing tail
        }
    }
    void get_move()
    {
        char input;
        if (kbhit()) // checking for key press
        {
            input = getch(); // if key pressed, key passed

            // Exception Handling used !!

            try // Try Block Body !!
            {
                if ((input == 'a' && direction == 'd') || (input == 's' && direction == 'w') || (input == 'd' && direction == 'a') || (input == 'w' && direction == 's'))
                {
                    move_snake();
                }
                else if (input == 'a' || input == 's' || input == 'd' || input == 'w')
                {
                    direction = input;
                    move_snake();
                }
                else if (input == 'x')
                {
                    save_game();
                }
                else
                    throw input; // throw Function Used !!
            }
            catch (char in)
            {
                cout << "Entered key is " << in << " which is invalid...."; // Catch Block Used !!
                exit(0);
            }
        }
        else
            move_snake();
    }
    void move_snake()
    {
        switch (direction)
        {
        case 'a':
        {
            headX--;
            break;
        }
        case 's':
        {
            headY++;
            break;
        }
        case 'd':
        {
            headX++;
            break;
        }
        case 'w':
        {
            headY--;
            break;
        }
        }
    }
    void tail_movement()
    {
        int prevX = tailX[0]; // initial conditions for the tail
        int prevY = tailY[0]; // store the initial position of = 0
        int prev2X, prev2Y;
        tailX[0] = headX;
        tailY[0] = headY; // when snake moves, its previous position is stored in the array
        for (int i = 1; i < size; i++)
        {
            prev2X = tailX[i]; // for loop for growing the tail
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
    }

    // Operator Overloading Used !!

    void operator=(Snake &s)
    {
        headX = s.headX; // OPERATOR OVERLOADING USED FOR COPYING VALUES !
        headY = s.headY;
        for (int i = 0; i < size; i++)
        {
            tailX[i] = s.tailX[i];
            tailY[i] = s.tailY[i];
        }
        direction = s.direction;
    }
} S;
class Fruit : public Snake
{
public:
    int fruitX;
    int fruitY;
    int score;
    int max_score;
    Fruit()
    {
        score = 0;
        max_score = 40;
        fruit_random_pos();
    }
    void fruit_random_pos()
    {
        srand(time(0));
        fruitX = 1 + (rand() % (BoardX - 2));
        fruitY = 1 + (rand() % (BoardY - 2));
    }
    void fruit_eat()
    {
        if (S.headX == fruitX && S.headY == fruitY)
        {
            Snake temp(S.size);
            fruit_random_pos();
            score += 10;
            temp = S; // Operator overloading  used !
            delete S.tailX;
            delete S.tailY;
            S.size++;
            S.tailX = new int[S.size];
            S.tailY = new int[S.size];
            S = temp;
        }
        S.tail_movement();
    }
} F;
class level : public Fruit
{
public:
    int lev;
    int max_level;
    char mode;
    level() : lev(1), max_level(10) {}
    void incr_level()
    {
        if (lev < max_level)
            if (F.score == F.max_score)
            {
                system("cls");
                cout << YELLOW << "\n\n\n\t\tLevel " << lev << " Completed......" << endl;
                cout << "\n\t\tNext Level....." << RESET << endl;
                Sleep(1300);
                lev++;
                F.max_score += 50;
                BoardX -= 3;
                BoardY -= 3;
                S.size = 1;
                S.headX = BoardX / 2;
                S.headY = BoardY / 2;
                S.direction = '\0';
                delete S.tailX;
                delete S.tailY;
                S.tailX = new int[S.size];
                S.tailY = new int[S.size];
                F.fruit_random_pos();

                system("cls");

                system("color 8A");
            }

            else if (lev > max_level)
            {
                show(1);
            }
    }
} L;

class Game : public level{
    public :
        void show_board(){
            for (int i = 0; i < BoardY; i++){
                cout << "\t\t\t\t\t";
for (int j = 0; j < BoardX; j++)
{
    if (i == 0 || i == BoardY - 1 || j == 0 || j == BoardX - 1)
    {
        cout << BLUE << "|" << RESET;
    }
    else if (i == F.fruitY && j == F.fruitX)
        cout << GREEN << "$" << RESET;
    else if (i == S.headY && j == S.headX)
        cout << RED << "0" << RESET;
    else
    {
        bool tail_print = false;
        for (int k = 0; k < S.size; k++)
        {
            if (S.tailX[k] == j && S.tailY[k] == i)
            {
                cout << RED << "o" << RESET;
                tail_print = true;
            }
        }
        if (tail_print == false)
            cout << " ";
    }
}
cout << endl;
}
}
void game_flow()
{
    if (game_over() == 0)
    {
        L.incr_level();
        F.fruit_eat();
        set_screen();
        cout << YELLOW << "\n\n\t\t\t\t\t\tYour Name: " << U.return_name() << RESET;
        cout << "\n\t\t\t\tPrevios Winner: " << U.return_winner() << "\tPrevious High Score: " << U.return_highscore();
        cout << "\n\t\t\t\tMode: " << L.mode << "\t\tLevel: " << L.lev << "\tScore: " << F.score << endl;
        show_board();
    }
    else
    {
        if (U.return_highscore() < F.score)
        {
            system("cls");
            system("color 8A");

            cout << YELLOW << "\n\n\n\t\tGAME OVER.....:(" << endl;
            cout << "\n\tBut " << U.return_name() << " is a NEW HIGH SCORER....:)\n"
                 << RESET;
            Sleep(1500);
        }
        else
            cout << "\t\tGAME OVER......";

        flow_after_gameover();
    }
}
bool game_over()
{
    for (int i = 5; i < S.size; i++)
        if (S.tailX[i] == S.headX && S.tailY[i] == S.headY)
            return 1;
    if (L.mode == 'G')
    {
        if (S.headX >= BoardX)
            S.headX = 0;
        else if (S.headX < 0)
            S.headX = BoardX - 1;
        if (S.headY >= BoardY)
            S.headY = 0;
        else if (S.headY < 0)
            S.headY = BoardY - 1;
        else
            return 0;
    }
    else if (L.mode == 'A')
    {
        if (S.headX == 0 || S.headX == BoardX - 1 || S.headY == 0 || S.headY == BoardY)
            return 1;
    }
}
void flow_after_gameover()
{
    int flow;
    cout << "\n\n\n\t\t1.Wanna Play again?\n ";
    cout << "\t\t2.Exit Game\n";
    cin >> flow;
    try
    {
        if (flow == 1)
        {
            S.headX = BoardX / 2;
            S.headY = BoardY / 2;
            S.direction = '\0';
            S.size = 1;
            F.score = 0;
            delete S.tailX;
            delete S.tailY;
            S.tailX = new int[S.size];
            S.tailY = new int[S.size];
            system("cls");
        }
        else if (flow == 2)
        {
            U.set_score(F.score);
            U.save();
            exit(0);
        }
        else
            throw flow;
    }
    catch (int a)
    {
        cout << "You entered " << a << " which is invalid" << endl;
        exit(0);
    }
}
}
*G;

// FILE HANDLIND USED FOR SAVING AND RESUMING GAME !!

void save_game() // Save Game ftn for storing data in the file .
{
    ofstream out("Game.txt"); //  OFSTREAM Class used !
    try
    {
        if (out.is_open())
        {
            out << BoardX << endl;
            out << BoardY << endl;
            out << S.headX << endl; //  All the data written in the file
            out << S.headY << endl;
            out << S.size << endl;
            out << S.direction << endl;
            for (int i = 0; i < S.size; i++)
            {
                out << S.tailX[i] << endl;
                out << S.tailY[i] << endl;
            }
            out << F.fruitX << endl;
            out << F.fruitY << endl;
            out << F.max_score << endl;
            out << F.score << endl;
            out << L.lev << endl;
            out << G->mode;
            out.close();
            cout << "Game Saved...";
            exit(0);
        }
        else
            throw 0;
    }
    catch (int a)

    {
        cout << "File is not opened..." << endl;
        exit(0);
    }
}

void resume_game() // Resume Game ftn for reading data from the file .
{
    ifstream in("Game.txt"); // IFSTREAM Class Used !
    try
    {
        if (in.is_open())
        {
            in >> BoardX;
            in >> BoardY;
            in >> S.headX; // All the data read from the file
            in >> S.headY;
            in >> S.size;
            in >> S.direction;
            delete[] S.tailX;
            delete[] S.tailY;
            S.tailX = new int[S.size];
            S.tailY = new int[S.size];
            for (int i = 0; i < S.size; i++)
            {
                in >> S.tailX[i];
                in >> S.tailY[i];
            }
            in >> F.fruitX;
            in >> F.fruitY;
            in >> F.max_score;
            in >> F.score;
            in >> L.lev;
            in >> G->mode;
            S.direction = '\0';
            in.close();
        }
        else
            throw 0;
    }
    catch (int a)
    {
        cout << "File is not opened..." << endl;
        exit(0);
    }
}

void set_screen()
{
    COORD a;
    a.X = 0;
    a.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

int main()
{
    int flow;
    system("color 8A");
    system("cls");
    // String Function : Strcpy Used !!!

    char s1[Max];
    char s2[Max];
    char s3[Max];
    char s4[Max];

    strcpy(s1, "1.New Game"); // Copying Text to str 1 !!!
    strcpy(s2, "2.Resume Previous Game");
    strcpy(s3, "3.Show the User list.");
    strcpy(s4, "4.Exit Game");

    // Printing All the strings  Step by Step !!!

    cout << "\n\t" << s1;
    cout << "\n\t" << s2;
    cout << "\n\t" << s3;
    cout << "\n\t" << s4 << "\n\t";
    cin >> flow;
    try
    {
        if (flow == 1 || flow == 2 || flow == 3)
        {
            switch (flow)
            {
            case 1:
            {
                U.get();
                Game G1;
                G = &G1;
                system("cls");
                cout << "\n\tSelect One Mode:\n";
                cout << "\t1.General Mode\n";
                cout << "\t2.Advanced Mode\n\t";
                cin >> flow;
                if (flow == 1)
                    L.mode = 'G';
                else if (flow == 2)
                    L.mode = 'A';
                system("cls");
                do
                {
                    G->game_flow();
                    S.get_move();
                } while (1);
                break;
            }
            case 2:
            {
                Game G2;
                G = &G2;
                system("cls");
                resume_game();
                do
                {
                    G->game_flow();
                    S.get_move();
                } while (1);
                break;
            }
            case 3:
            {
                U.show_list();
            }
            case 4:
            {
                exit(0);
                break;
            }
            }
        }
        else
            throw flow;
    }
    catch (int f)
    {
        cout << "Entered number is invalid...";
        exit(0);
    }
}