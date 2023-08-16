// myfunctions.c
#include <windows.h>
#include <string.h>
#include <stdio.h>
//#include <cstdio>
//#include <cstddef>
#include "myheader.h"
//#include <cstring>
#include <windows.h>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
	#define MAX_PLAYERS 200
#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20
 // Example: Access individual player data by username and password
    char inputUsername[MAX_NAME_LENGTH];
    char inputPassword[MAX_PASSWORD_LENGTH];
struct Player {
    char username[MAX_NAME_LENGTH];
    
    char password[MAX_PASSWORD_LENGTH];
    int highScore;
};
int trial;


int auth(){
struct Player player;
gotoxy(40,5);
int choice;
printf("WELCOME TO DINO GAME");
gotoxy(25,8);
printf("\npress 1,to sign up: \npress 2,to login>> ");
scanf("%d",&choice);
 int i,numPlayers = 10;
 FILE *file1 = fopen("player_data.txt", "ab+");
struct Player players[MAX_PLAYERS];
FILE *file = fopen("player_data.txt", "r+");
 int checker =0;   
switch (choice){
	case(1):
		trial =0;
     printf("set username>> ");
     scanf("%s",inputUsername);
     strcpy(player.username,inputUsername);
     printf("set password>> ");
     scanf("%s",inputPassword);
     strcpy(player.password,inputPassword);
    // Write player data to a file
    if (file1 == NULL) {
        printf("Error opening file for writing.\n");
        return 0;
    }
    fwrite(&player, sizeof(struct Player), 1, file1);
	fclose(file1);
	return 1;
	break;
	case(2):
	trial = 1;
    printf("Enter username>> ");
    scanf("%s", inputUsername);

    printf("Enter password>> ");
    scanf("%s", inputPassword);
    // Read player data from the file    
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    fread(players, sizeof(struct Player), MAX_PLAYERS, file);
    fclose(file);
    for (i = 0; i<100; i++) {
        if (strcmp(players[i].username, inputUsername) == 0 &&
            strcmp(players[i].password, inputPassword) == 0) {
            printf("           Welcome to dino game, %s,get ready!\n", inputUsername);
            printf("Your high score: %d\n", players[i].highScore);
            Sleep(2000);
            checker = 1;
            return 1;
            //break;
        }  
    }
    if (checker ==1){
    //	printf("checker is 1 welcome");
    	Sleep(2000);
    	return 1;
	}
    if (checker ==0){
    
    //	printf("returned 0");
    	Sleep(2000);
    	return 0;
	}
//	printf("returned from here");
	Sleep(2000);
	return 1;
    break; 
    default:
    	return 0;
  }
}

int update_score(int scr) {
    struct Player players[MAX_PLAYERS];
    gotoxy(4,5);
	int Checker=0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
   	gotoxy(10,4);
        FILE *file = fopen("player_data.txt", "r+");
    if (file == NULL) {
        printf("Error opening file for reading and writing.\n");
        return 1000;
    }
    fread(players, sizeof(struct Player), MAX_PLAYERS, file);
    	 printf("%s",players[i].username);
        if (strcmp(players[i].username, inputUsername) == 0 &&
            strcmp(players[i].password, inputPassword) == 0) {
            //	printf("%s %s",players[i].username,inputUsername);
            	//printf("username inpu");
            	Checker =1;
            if (players[i].highScore < scr) {
            	printf("%d %d",players[i].highScore,scr);
            //	printf("playershis scr");
                players[i].highScore = scr;
                fseek(file, i * sizeof(struct Player), SEEK_SET);
                fwrite(&players[i], sizeof(struct Player), 1, file);
                fclose(file);
               // return scr;
              //  printf("%d",scr);
                return scr;
            } else {
                fclose(file);
                //printf("%d",players[i].highScore);
                return players[i].highScore;
            }
            
        }
//        	printf("players not matched");
		
    }
    if (Checker == 0){
    	        	printf("players not matched");

	}

 //   fclose(file);
    return scr;
}

