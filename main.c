#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct player {
	char* oceanGrid;
	char* targetGrid;
};

enum Boats {
    carrier = 5,
    battleship = 4,
    destroyer = 3,
    submarine = 3,
    patrolBoat = 2
};


const int W = 10, H = 10;

void addShip(enum Boats ship, struct player plyr);
void initPlayer(struct player plyr);
void display(struct player plyr);

int convertCoords(int i, int j);

int main() {
    srand (time(NULL));  
    
    struct player plyr = {malloc((W*H)*sizeof(char)), malloc((W*H)*sizeof(char))};
    struct player comp = {malloc((W*H)*sizeof(char)), malloc((W*H)*sizeof(char))};
    
	initPlayer(plyr);
	initPlayer(comp);
	
 	addShip(battleship, plyr);
	addShip(destroyer, plyr);
 	addShip(carrier, plyr);
  	addShip(submarine, plyr);
  	addShip(patrolBoat, plyr);
	
    display(plyr);
}

//Initializes a player's oceanGrids
void initPlayer(struct player plyr){
    //Initilaze blank grids
	for(int i = 0; i < W*H; i++){
    	plyr.oceanGrid[i] = ' ';
    	plyr.targetGrid[i] = ' ';
    }
}

//Displays the turn screen for a player
void display(struct player plyr){
	//Header
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
    
    //Displays Both oceanGrids
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

void addShip(enum Boats ship, struct player plyr){
        int x = rand()%(11-ship);
        int y = rand()%(11-ship);
        int dir = rand()&1 ? 1 : 0;
        bool avail = true;

        for(int i = 0; i < ship; i++){
            avail = plyr.oceanGrid[convertCoords(x +(i*dir), y +i*((1-dir)))] == ' ' && avail;
        }
        if(avail){
            for(int i = 0; i < ship; i++){
                char c = '0';
                if(i == 0 && dir == 0) c = '<';
                else if(i == ship - 1 && dir == 0) c = '>';
                else if(i == 0 && dir == 1) c= '^';
                else if(i == ship-1 && dir == 1) c= 'v';
                plyr.oceanGrid[convertCoords(x +(i*dir), y+(i*(1-dir)))] = c;
            }
        } else {
            addShip(ship, plyr);
        }
}

int convertCoords(int i, int j){
    return i*W + j;
}
