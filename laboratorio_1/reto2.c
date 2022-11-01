#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void Game(){
    srand(time(0));

    int randomIndex = rand() % 5;

    char movies[][25] = {
            "dune",
            "the notebook",
            "interstellar",
            "the theory of everything",
            "el robo del siglo"
    };


    /* Randomness test --------------------------------------------
       int looprandom = 0;
       int fullrand = 0;

       for (looprandom = 0; looprandom < 5; looprandom++) {
           fullrand = rand();
           randomIndex = fullrand % 5;
           printf("%d -> %d\n", fullrand, randomIndex);
       }
   ----------------------------------------------------------------*/
    int numlives = 6;
    int numCorrect = 0;
    int oldCorrect = 0;
    int i=0;
    int lengthofWord = strlen(movies[randomIndex]);

//                  T  h  e     T  h  e  o  r  y     o  f     e  v  e  r  y  t  h  i  n  g
//  int letterGuessed[27] = {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
    int letterGuessed[27] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char UnknownWord[lengthofWord];

    for (i = 0; i < lengthofWord; i++){
        UnknownWord[i]= '_';
    }

    int quit = 0;
    int loopIndex = 0;
    char guess[27];

    printf("Película:%s, Índice: %d, Tamaño-letras: %d\n", movies[randomIndex], randomIndex, lengthofWord);

    while (numCorrect < lengthofWord){

        printf("Letras adivinadas: %d\n", numCorrect);
        printf("\nAdivina una letra:");
        fgets(guess, 27, stdin);
        fflush(stdin);

        if( strncmp(guess, "salir", 4) == 0){
            quit = 1;
            break;
        }

        char letterEntered;
        letterEntered = guess[0];

        printf("Letra: %c\n", letterEntered);

        oldCorrect = numCorrect;

        for (loopIndex = 0; loopIndex < lengthofWord; loopIndex++){

            if (  letterGuessed[loopIndex] == 1){
                continue;
            }

            if (tolower(letterEntered) == movies[randomIndex][loopIndex]){
                letterGuessed[loopIndex] = 1;
                numCorrect++;
            }
        } // end for

        if ( oldCorrect == numCorrect){
            numlives--;
            printf("Equivocación :( \n");

            if ( numlives == 0)
                break;

        } else{
            printf("¡Es correcto! :) \n");
        }

        printf ("Vidas: %d\n", numlives);

        for(i=0;i<lengthofWord;i++){
            if(tolower(letterEntered) == movies[randomIndex][i]){
                printf("%c", tolower(letterEntered));
            }
            else{
                printf("_ ");
            }
        }

        for(i=0;i<lengthofWord;i++){
            if(tolower(letterEntered) == movies[randomIndex][i])
                UnknownWord[i] = tolower(letterEntered);
        }

        for(i=0;i<lengthofWord;i++){
            printf("%c ", UnknownWord[i]);
        }


        printf ("\n");

        switch (numlives)
        {
            case 6:
                // No error
                printf(" _ _ _ _\n|\t|\n|\t\n|\n|\n|\n");
                break;

            case 5:
                // 1st miss
                printf(" _ _ _ _\n|\t|\n|\tO\n|\n|\n|\n");
                break;

            case 4:
                // 2nd miss
                printf(" _ _ _ _\n|\t|\n|\tO\n|\t|\n|\n|\n");
                break;

            case 3:
                // 3rd miss, 6 spacebars
                printf(" _ _ _ _\n|\t|\n|\tO\n|      /|\n|\n|\n");
                break;

            case 2:
                // 4 miss, 6 spacebars
                printf(" _ _ _ _\n|\t|\n|\tO\n|      /|\\\n|\n|\n");
                break;

            case 1:
                // 5 miss, 6 spacebars + 6
                printf(" _ _ _ _\n|\t|\n|\tO\n|      /|\\\n|      /\n|\n");
                break;

            default:
                printf(" _ _ _ _\n|\t|\n|\tO\n|      /|\\\n|      / \\\n|\n");
                break;
        }


    } // end while

    //printf("rand: %d \n rand with Mod: %d", rand(), randomIndex);
    if ( quit == 1){
        printf("\nUsuario abandonó reto\n");
    } else if (numlives == 0){
        printf(" _ _ _ _\n|\t|\n|\tO\n|      /|\\\n|      / \\\n|\n");
        printf("\n Lo siento, perdiste. La palabra era: %s\n", movies[randomIndex]);
    } else {
        printf("¡Ganaste!");
    }


}

int main()
{
    char Option[1];

    do{
        Game();
        printf("\n¿Quieres jugar? [Y/n]: \t");
        fgets(Option, 2, stdin);
        fflush(stdin);
        Option[0]=tolower(Option[0]);

    }
    while(Option[0] == 'y');

    //printf("%s", Option);
}




