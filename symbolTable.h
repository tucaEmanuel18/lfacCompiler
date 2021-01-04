#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

extern int yylineno;
char DataType[50];
char AuxBuffer[50];
char Scope[50] = "global";

// variabile predefinite
typedef struct var {
    char *type;
    char *name;
    char value[50];
    char scope[50];

    bool constant;
    bool set;
    bool used;

	struct var *next;
} var;

// lista de variabile
var *firstVar = NULL, *lastVar = NULL, *currentVar; 


void printVarList()
{
	currentVar = firstVar;
	printf("Printare lista:\n");
	while(currentVar != NULL)
	{
		printf("type = %s | name = %s | value = %s | scope = %s| set = %d | used = %d | constant = %d\n" ,
						currentVar->type, currentVar->name, currentVar->value, currentVar->scope, currentVar->set, currentVar->used, currentVar->constant);
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


void insertVar(char* dataType, char* symbolName, char* value, char* scope, bool set, bool constant)
{

	var *nod = (var *) malloc(sizeof(var));
	
	nod->type = dataType;
	nod->name = symbolName;
	nod->constant = constant;
	strcpy(nod->value, value);
	strcpy(nod->scope, scope);
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


// arrys
typedef struct array {
    char *type;
    char *name;
    int maxSize;
    int actualSize;

    char* values[50];
    char scope[50];


    bool used;
    bool constant;

	struct array *next;
} array;

// lista de arrayuri
array *firstArray = NULL, *lastArray = NULL, *currentArray;

void printArrayList()
{
	currentArray = firstArray;
	printf("Printare lista:\n");
	while(currentArray != NULL)
	{
		printf("type = %s | name = %s | maxSize = %d | actualSize = %d | scope = %s| used = %d | constant = %d\n" ,
						currentArray->type, currentArray->name, currentArray->maxSize, currentArray->actualSize, currentArray->scope, currentVar->used, currentVar->constant);
		
		currentVar = currentVar->next;
	}
}

bool lookupArray(char *name) {
	currentArray = firstArray;
	while (currentArray != NULL) {
		if (strcmp(currentArray->name, name) == 0) break;
		currentArray = currentArray->next;
	}

	if(currentArray == NULL)
		return false;
	return true;
}

void insertArray(char* dataType, char* arrayName, int maxSize, char* scope, bool constant)
{

	array *nod = (array *) malloc(sizeof(array));
	
	nod->type = dataType;
	nod->name = arrayName;
	nod->maxSize = maxSize;
	nod->actualSize = 0;
	//strcpy(nod->values, values);
	strcpy(nod->scope, scope);

	nod->constant = constant;
	nod->used = false;

	nod->next = NULL;
	if (firstArray == NULL) 
		firstArray = lastArray = nod;
	else 
	{
		lastArray->next = nod;
		lastArray = nod;
	}
}

char* extractName(char* arrayIdentifier)
{
	
    char extractedName[50];
    static char copied[50];

    int i=0;
    while(arrayIdentifier[i] != '['){
        extractedName[i] = arrayIdentifier[i];
        i++;
    }
    extractedName[i] = '\0';

    i=0;
    while(extractedName[i] != '\0'){
        copied[i] = extractedName[i];
        i++;
    }
    copied[i] = '\0';
    return copied;  
}
int extractMaxSize(char* arrayIdentifier)
{
	char extractedNumber[20];
	int i=0;
    while(arrayIdentifier[i] != '['){
        i++;
    }

    int j = ++i;
    while(arrayIdentifier[i] != ']')
    {
    	extractedNumber[i-j] = arrayIdentifier[i];
    	i++;
    }
    extractedNumber[i] = '\0';
    int maxSize = atoi(extractedNumber);
    return maxSize;
}





// utilsFunctions

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

void charToString(char charVal)
{
	bzero(AuxBuffer, 50);
	sprintf(AuxBuffer, "%c", charVal);
}



//Raportari Erori

void DuplicateIdentifierError(char* identifier){
    printf("ERROR ON LINE %d : Duplicate identifier '%s' found.\n",yylineno,identifier);
    exit(0);
}

void AssignementError(char* identifier, char* type, char* assignementType){
    printf("\nERROR ON LINE %d : The identifier '%s' has type '%s', but you try to assign type %s.\n",yylineno, identifier, type, assignementType);
    exit(0);
}