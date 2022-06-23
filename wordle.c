#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



//funkcie ktora zmeni farbu textu na zltu,zelenu a bielu 
void yellow(){
    printf("\033[1;33m");
}
void green(){
    printf("\033[1;32m");
}
void white(){
    printf("\033[0m");
}


//naplni hraciu plochu kde sa budu zapisovat slova znakom '-'
void naplnenie_plochy(char plocha[6][6]){
    for(int i=0; i<5;i++){
        for(int j=0;j<5;j++){
            plocha[i][j] = '-';
        }
    }
}


//kazde kolo vypise celu hraciu plochu 
void vypis(char plocha[6][6],char *hladane_slovo){

    int zelene_pismena; //pocita zelene (spravne) pismena v slove, ked ich je 5 parameter ukoncit sa nastavi na 1 a program skonci 
    int ukoncit = 0;


    //cyklus pojde pismeno po pismene ked sa pozicia pismena nachdza na spravnom mieste vypise sa pismeno na zeleno, ked sa nachadza v slove tak na zlto, inak bielo
    printf("===============\n");
    for(int i=0; i<5;i++){
        printf("|| ");
        zelene_pismena = 0;

           
        for(int j=0;j<5;j++){   
            if(plocha[i][j]==hladane_slovo[j]){

                green();
                printf("%c ",plocha[i][j]);
                white();
                zelene_pismena++;
            }
            else if(plocha[i][j]==hladane_slovo[0] || plocha[i][j]==hladane_slovo[1]|| plocha[i][j]==hladane_slovo[2]|| plocha[i][j]==hladane_slovo[3]|| plocha[i][j]==hladane_slovo[4]){

                yellow();
                printf("%c ",plocha[i][j]);
                white();
            }
            else{
                printf("%c ",plocha[i][j]);
            }
        }

        printf("||\n");
        if (zelene_pismena == 5){
            ukoncit++;
        }
    }
    printf("===============\n");


    //ukonci program a vypise vyhernu spravu
    if(ukoncit == 1){
        printf("VYHRAL SI");
        exit(0);
    }

}

int main(){
    printf("len slovenske slova bez dikaritiky\n");

    char plocha[6][6];
    naplnenie_plochy(plocha);

    //nahodne vyberie slov ktore sa bude hadat z arrayu 

    char *slova[] = {"skola","blesk","peter","lampa","zebra","metro","ulica"};
    char hladane_slovo[6]; 
    srand(time(NULL));
    strcpy(hladane_slovo,slova[rand() % sizeof(slova)/sizeof(slova[0])]);


    vypis(plocha,hladane_slovo);


    //cyklus pojde 5x nacita stale slovo a vlozi ho do hracej plochy podla toho ktore kolo je, tak do takeho riadku ho vlozi, funkcia vypis potom riesi to vypisovanie farebne
    for(int i=0; i<5;i++){

        char pokus[6];
        scanf("%s", pokus);
        for(int j=0; j<5;j++){
            plocha[i][j] = pokus[j];
        }
        vypis(plocha,hladane_slovo);
        white();

    }

    //ak za 5 kol hra nevyhral vypise sa sprava o prehre a aj to ake bolo spraven slovo 
    printf("PREHRAL SI a pravne slovo bolo: %s",hladane_slovo);


    return 0;
}