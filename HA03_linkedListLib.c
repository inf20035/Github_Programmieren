#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HA03_linkedListLib.h"

void addListElem(listElement *start){
    
    listElement * new;
    new = (listElement *)malloc(sizeof(listElement));
    if (new == NULL) {
        printf("can't reserve storage.\n"); 
        return;
        }

    listElement * currElem = start;
    while (currElem->nextElem != NULL) currElem = currElem->nextElem;// get last elem in list
    currElem->nextElem = new; // add new to the end of list
    new->nextElem = NULL;
    
    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s",new->lastName);
    printf("Please enter first name: \n");
    scanf("%s",new->firstName);
    printf("Please enter age: \n");
    scanf("%d",&(new->age));
    printf("end of function\n");
}

int printList(listElement *start){
   
    int i = 1; /*die Position des derzeitigen Elements in der Liste*/
    listElement * currElem = start; /*Man springt an den Anfang der Liste*/

    if(currElem->nextElem == NULL)/*überprüfen ob die Liste leer ist*/
    {
        printf("List is empty!\n");
        return 0;
    }
    while(currElem->nextElem != NULL)/*Durch die Liste iterieren*/
    {
        currElem = currElem->nextElem;/*Zum nächsten Element springen*/
        printf("%d. element:\n{\nlast name: %s\nfirst name: %s\nage: %d\n}\n",
        i, currElem->lastName, currElem->firstName, currElem->age);/*ausgeben des Listenelements*/
        i++;  
    }

    return 1;

}

int delListElem(listElement *start){

    listElement * delElem;
    delElem = (listElement *)malloc(sizeof(listElement));/*Variable in der das zu löschende Element gespeichert wird*/
    int delete = 0;/*Variable zum entscheiden ob man ein Element löschen will oder nicht*/

    int i = 1; /*die Position des derzeitigen Elements in der Liste*/
    listElement * currElem = start; /*Man springt an den Anfang der Liste*/

    if(currElem->nextElem == NULL)/*überprüfen ob die Liste leer ist*/
    {
        printf("List is empty!\n");
        return 0;
    }
    while(currElem->nextElem != NULL)/*Durch die Liste iterieren*/
    {
        /*Abfrage ob dieses Element gelöscht werden soll*/
        printf("Do you want to delete %d. entry? No(0) or Yes(1)\n{\nlast name: %s\nfirst name: %s\nage: %d\n}\n",
        i, currElem->nextElem->lastName, currElem->nextElem->firstName, currElem->nextElem->age);
        i++;
        scanf("%d",&delete);

        /*Löschen des Elements*/
        if(delete == 1)
        {
            delElem = currElem->nextElem;
            currElem->nextElem = currElem->nextElem->nextElem;
            free(delElem);
            printf("element was deleted\n"); // missing int argument: -1Pkt    
            return 1;
        }else/*Zum nächsten Element übergehen*/
        {
            currElem = currElem->nextElem;
        }
    }

    printf("nothing was deleted.\n");
    return 0;

}

int delList(listElement *start){

    listElement * delElem;
    delElem = (listElement *)malloc(sizeof(listElement));/*Variable in der das zu löschende Element gespeichert wird*/

    listElement * currElem = start; /*Man springt an den Anfang der Liste*/

    if(currElem->nextElem == NULL)/*überprüfen ob die Liste leer ist*/
    {
        printf("List is empty!\n");
        return 0;
    }
    while(currElem->nextElem != NULL)/*Durch die Liste iterieren und die Elemente löschen*/
    {
        delElem = currElem->nextElem;
        currElem->nextElem = currElem->nextElem->nextElem;
        free(delElem);
        printf("element was deleted\n"); // missing int argument                    

        currElem = currElem->nextElem;
    }
    delElem = currElem;/*Auch noch das erste Element löschen*/
    free(delElem);

    printf("\n>> getLenOfList fcn is tbd.\n\n");
    return 1;

}

int getLenOfList(listElement *start){ // we use this for save list fcn

    int counter = 0;
    listElement * currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list
        currElem = currElem->nextElem; counter++;
        }
    return counter;
}

int saveList(listElement *start){

    char filename[50];
    printf("filename?\n");
    scanf("%s", filename);/*Name für die Datei wird festgelegt*/

    FILE *openFile;

    openFile = fopen(filename, "w");/*file wird geöffnet um hineinzuschreiben*/

    if (openFile == NULL) // no semicolon here !!! /*überprüfen ob file geöffnet wurde*/
    {
        printf("cant open file\n");
        return 0;
    }
    listElement * currElem  = start;/*An den Anfang der Liste spirngen*/

    while(currElem->nextElem != NULL)/*Durch die Liste iterieren und Inhalte Zeile für Zeile in die <liste übertragen*/
    {
        currElem = currElem->nextElem;
        fprintf(openFile, "%s\n%s\n%d\n\n", currElem->lastName, currElem->firstName, currElem->age);
    }
    
    printf("save complete.\n");
    printf("\n>> saveList fcn is tbd.\n\n");
}

int loadList(listElement *start){

   listElement * currElem = start;/*Zum Anfang der Liste springen*/
   while(currElem->nextElem != NULL)/*Ende der Liste ermitteln*/
   {
       currElem = currElem->nextElem;
   }

   listElement * new;
   new = (listElement *)malloc(sizeof(listElement));/*Variable um die neuen Elemente zu erstellen*/

   int line = 0;/*Variable zum ermitteln ob die Informaiton der lastName, firstName oder das age ist*/
   char temp; // char here ? /*Zeile*/ 

   FILE *fileprt;
   char filename[50];

   system("dir *.txt");
   printf("filename of the file you want to open?\n");
   scanf("%s", filename);// array is already pointer: -1Pkt /*filename abfragen*/

   fileprt = fopen(filename, "r");/*file öffnen*/

   if(fileprt == NULL)/*überprüfen ob file leer ist*/
   {
       printf("file cant be opened.\n");
       return 0;
   }

   while(fscanf(fileprt,"%c", &temp) != EOF) // type ! /*File auslesen*/
   {
       currElem->nextElem = new;
       new->nextElem = NULL; // no == here simple = is needed !

       /*Informationen der richtigen Zeile in die neu erstellten Listenelemente eintragen*/
       if(line==0)
       {
           strcpy(new->lastName, &temp); // i think you need a char pointer here? -1Pkt
       }
       if(line==1)
       {
           strcpy(new->firstName, &temp);
       }
       if(line==2)
       {
           strcpy(new->age, temp);
           line = line - 3;/*zurücksetzen der Varibale*/
       }
       line++;
   }
 
	printf("loading data will be append to current list...\n");
	printList(start); // show loaded list
}

void exitFcn(listElement *start){

    printf("\n>> exitFcn fcn is tbd.\n\n");

}

void sortList(listElement *start){
	
	printf("\n>>sortList fcn is tbd.\n\n");
    
}

void stringToLower(char *string) {
	
    printf("\n>>stringToLower fcn is tbd.\n\n");

}
// 7/10 you have many data type mismatches. Be careful !




