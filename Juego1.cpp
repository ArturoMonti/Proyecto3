#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
 
using namespace std;
 
void gotoxy(int x, int y){
        HANDLE hCon;
        hCon=GetStdHandle(STD_OUTPUT_HANDLE);
        
        COORD dwPos;
        dwPos.X=x;
        dwPos.Y=y;
        SetConsoleCursorPosition(hCon,dwPos);
}
 
class Snake{
        public:
                int x,y;
                int dx,dy;
                char cuerpo;
};
 
class Fruta{
        public:
                int x,y;
                char cuerpo=254;
};
 
class Juego{
        public:
                void main();
        private:
                int score,nivel,velocidad;
                Snake snake[100];
                Fruta fruta;
                int tam=4;
                int c=21,f=64;
                bool gameover=false;
                void tablero();
                //void inicio();
                void genFruta();
                void genSnake();
                void loop();
                void tecla();
                void actualizar();
                void imprimir();
                void cfruta();
                void muerte();
                void puntos();
                //void menu();
                void portada();
                void muerte2();
        
};
 
void Juego::muerte2(){
        system("cls");
        int c=24,f=79,r;
        char key;
        char t=178;
        for(int i=0 ; i<f ; i++){
                gotoxy(i,0);
                cout<<t;
                gotoxy(i,c);
                cout<<t;
        }
        for(int i=0 ; i<=c ; i++){
                gotoxy(0,i);
                cout<<t;
                gotoxy(f,i);
                cout<<t;
        }
        
        string g4meover[]={"  ____                       ___"," / ___| __ _ _ __ ___   ___ / _ \\__   _____ _ __ ",
        "| |  _ / _` | '_ ` _ \\ / _ \\ | | \\ \\ / / _ \\ '__|","| |_| | (_| | | | | | |  __/ |_| |\\ V /  __/ | ",
        " \\____|\\__,_|_| |_| |_|\\___|\\___/  \\_/ \\___|_|"};
        r=2;
        for(int i=0;i<5;i++){
                gotoxy(15,r);
                r++;
                cout<<g4meover[i]<<endl;
        }
        
        string g4meover2[]={"   _________         _________","  /         \\       /         \\",
        " /  /~~~~~\\  \\     /  /~~~~~\\  \\"," |  |     |  |     |  |     |  |"," |  |     |  |     |  |     |  |",
        " |  |     |  |     |  |     |  |         /"," |  |     |  |     |  |     |  |       //","(X  X)    \\  \\_____/  /     \\  \\_____/ /",
        " \\__/      \\         /       \\        /","  |         ~~~~~~~~~         ~~~~~~~~","  ^"};
        for(int i=0;i<11;i++){
                gotoxy(20,r);
                cout<<g4meover2[i]<<endl;
                r++;
                
        }
        gotoxy(33,r);
        cout<<"Score: "<<score;
        r++;
        gotoxy(33,r);
        cout<<"Level: "<<nivel;
        gotoxy(8,23);
        cout<<"Presione ESC para salir o cualquier otra tecla para seguir jugando";
        key=getch();
        if(key==27)
                exit(1);
}
 
 
void Juego::portada(){
        system("cls");
        int c=24,f=79,r;
        char t=178;
        for(int i=0 ; i<f ; i++){
                gotoxy(i,0);
                cout<<t;
                gotoxy(i,c);
                cout<<t;
        }
        for(int i=0 ; i<=c ; i++){
                gotoxy(0,i);
                cout<<t;
                gotoxy(f,i);
                cout<<t;
        }
        string snkd[]={"       ---_ ......._-_--.","      (|\\ /      / /| \\  \\","      /  /     .'  -=-'   `.",
                "     /  /    .'             )","   _/  /   .'        _.)   /","  / o   o        _.-' /  .'",
                "  \\          _.-'    / .'*|","   \\______.-'//    .'.' \\*|","    \\|  \\ | //   .'.' _ |*|",
                "     `   \\|//  .'.'_ _ _|*|","      .  .// .'.' | _ _ \\*|","      \\`-|\\_/ /    \\ _ _ \\*\\",
                "                     \\ _ _ \\*","                      \\ _ _ \\ ","                       \\_"};
                
        r=2;
        for(int i=0;i<14;i++){
                gotoxy(20,r);
                r++;
                cout<<snkd[i]<<endl;
        }
        
        string snkl[]={"                     __     ","   _________  ____ _/ /_____","  / ___/ __ \\/ __ `/ //_/ _ \\",
        " (__  ) / / / /_/ / ,< /  __/","/____/_/ /_/\\__,_/_/|_|\\___/"};
        for(int i=0;i<5;i++){
                gotoxy(22,r);
                r++;
                cout<<snkl[i]<<endl;
        }
        gotoxy(23,23);
        cout<<"Precione ENTER para empezar";
        system("pause>dsdsd");
}
 
 
void Juego::puntos(){
        gotoxy(f+2,2);
        cout<<"Score: "<<(score-1)*10;
        gotoxy(f+2,4);
