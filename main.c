#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define W 10
#define H 10

typedef enum Ships {
    carrier = 5,
    battleship = 4,
    destroyer = 3,
    submarine = 3,
    patrolBoat = 2
} Ship;
typedef struct Players {
    char oceanGrid[W*H];
    char targetGrid[W*H];
} Player;

void initPlayer(Player *plyr);
void display(Player plyr);

void addShip(Ship ship, Player *plyr);

int convertCoords(int i, int j);

void main(){
    srand( time(NULL) );
    
    Player player = { 0 };
    initPlayer(&player);
    addShip(battleship, &player);
    
    display(player);
}

void initPlayer(Player *plyr){
	for(int i = 0; i < W*H; i++){
    	plyr->oceanGrid[i] = ' ';
    	plyr->targetGrid[i] = ' ';
    }
    
    addShip(battleship, plyr);
	addShip(destroyer, plyr);
 	addShip(carrier, plyr);
  	addShip(submarine, plyr);
  	addShip(patrolBoat, plyr);
}

void display(Player plyr){
	printf("`        Target Grid                    Ocean Grid\n");
	printf("`   ");
	for(int i = 0; i < W; i++){
    	if(i < 9) printf("%d ", i + 1);
        else printf("%d", i + 1);
    }
    printf("          ");
    for(int i = 0; i < W; i++){
    	if(i < 9) printf("%d ", i + 1);
        else printf("%d", i + 1);
    }
    printf("\n\n");    
    
    for (int i = 0; i < H; i++) {
    	printf("%c | ", 'a'+i);
    	for (int j = 0; j < W; j++)
            printf("%c ", plyr.oceanGrid[i * H + j]);
        printf("      ");
    	printf("%c | ", 'a'+i);
        for (int j = 0; j < W; j++)
            printf("%c ", plyr.targetGrid[i * H + j]);
        printf("\n");
    }
}

void addShip(Ship ship, Player *plyr){
        int x = rand()%(11-ship);
        int y = rand()%(11-ship);
        int dir = rand()&1 ? 1 : 0;
        bool avail = true;

        for(int i = 0; i < ship; i++){
            avail = plyr->oceanGrid[convertCoords(x +(i*dir), y +i*((1-dir)))] == ' ' && avail;
        }
        if(avail){
            for(int i = 0; i < ship; i++){
                char c = '0';
                if(i == 0 && dir == 0) c = '<';
                else if(i == ship - 1 && dir == 0) c = '>';
                else if(i == 0 && dir == 1) c= '^';
                else if(i == ship-1 && dir == 1) c= 'v';
                plyr->oceanGrid[convertCoords(x +(i*dir), y+(i*(1-dir)))] = c;
            }
        } else {
            addShip(ship, plyr);
        }
}

int convertCoords(int i, int j){
    return i*W + j;
}
