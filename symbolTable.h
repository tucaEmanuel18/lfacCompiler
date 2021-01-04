#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

extern int yylineno;
char DataType[50];
char AuxBuffer[50];
/*struct function
{
	char* functionName;
	char* returnType;
	char** listOfParametersType;
	int nrOfParameters;
}*/


typedef struct var {
    char* type;
    char *name;
    char value[250];

    bool set;
    bool used;

	struct var *next;
} var;

// lista de variabile
var *firstVar = NULL, *lastVar = NULL, *currentVar; 


void printList()
{
	currentVar = firstVar;
	printf("Printare lista\n:");
	while(currentVar != NULL)
	{
		printf("type = %s | name = %s | value = %s | set = %d\n" ,
						currentVar->type, currentVar->name, currentVar->value, currentVar->set);
		currentVar = currentVar->next;
	}
}

bool lookupVar(char *name) {
	currentVar = firstVar;
	while (currentVar != NULL) {
		if (strcmp(currentVar->name, name) == 0) break;
		currentVar = currentVar->next;
	}

	if(currentVar == NULL)
		return false;
	return true;
}

// void lookupFunction(char *name) {
// 	currVar = firstVar;
// 	while (currVar != NULL) {
// 		if (strcmp(currVar->name, name) == 0) break;
// 		currVar = currVar->next;
// 	}
// }



void insertVar(char* dataType, char* symbolName, char* value, bool set)
{

	var *nod = (var *) malloc(sizeof(var));

	printf("\nIn DataType  = %s\n", dataType);
	fflush(stdout);
	nod->type = dataType;
	nod->name = symbolName;

	strcpy(nod->value, value);

	nod->set = set;
	nod->used = false;

	nod->next = NULL;

	if (firstVar == NULL) 
		firstVar = lastVar = nod;
	else 
	{
		lastVar->next = nod;
		lastVar = nod;
	}
}


void storeDataType(char* data_type)
{
	int i=0;
	bzero(DataType, 50);
    while(data_type[i] != '\0')
    {
        DataType[i] = data_type[i];
        i++;
	}
	DataType[i] = '\0';
}


void intToString(int intVal)
{
	bzero(AuxBuffer, 50);
	sprintf(AuxBuffer, "%d", intVal);
}

void floatToString(float floatVal)
{
	bzero(AuxBuffer, 50);
	sprintf(AuxBuffer, "%f", floatVal);
}



//Raportari Erori

void DuplicateIdentifierError(char* identifier){
    printf("ERROR ON LINE %d : Duplicate identifier '%s' found.\n",yylineno,identifier);
    exit(0);
}