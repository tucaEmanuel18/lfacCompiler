#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

extern int yylineno;
char DataType[50];
char AuxBuffer[50];
char Scope[50] = "global";
void ArrayDimensionError();
void FunctionNoOfParametersError();

typedef struct parameter
    {
    	char type[10];
    	char identifier[10];
    }para;

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
	printf("\nPrintare lista variabile:\n");
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

var* getVar(char *name) {
	currentVar = firstVar;
	while (currentVar != NULL) {
		if (strcmp(currentVar->name, name) == 0) break;
		currentVar = currentVar->next;
	}
	return currentVar;
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
    char name[50];
    int maxSize;
    int actualSize;

    char values[20][20];
    char scope[50];


    bool used;

	struct array *next;
} array;

// lista de arrayuri
array *firstArray = NULL, *lastArray = NULL, *currentArray;


void printArrayList()
{
	currentArray = firstArray;
	printf("\nPrintare lista array:\n");
	while(currentArray != NULL)
	{
		printf("type = %s | name = %s | maxSize = %d | actualSize = %d | scope = %s | used = %d\n" ,
						currentArray->type, currentArray->name, currentArray->maxSize, currentArray->actualSize, currentArray->scope, currentArray->used);
		

		if(currentArray->actualSize != 0)
		{
			printf("Values: ");
			for(int i = 0; i < currentArray->actualSize; i++)
			{
				printf("%s, ", currentArray->values[i]);
			}
			printf("\n");
		}

		currentArray = currentArray->next;
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

array* getArray(char *name) {
	currentArray = firstArray;
	while (currentArray != NULL) {
		if (strcmp(currentArray->name, name) == 0) break;
		currentArray = currentArray->next;
	}
	return currentArray;
}

void insertArray(char* dataType, char* arrayName, int maxSize, int actualSize, char arrayValues[20][20], char* scope, bool constant)
{

	array *nod = (array *) malloc(sizeof(array));
	
	nod->type = dataType;
	strcpy(nod->name, arrayName);
	if(maxSize <= 20)
	{
		nod->maxSize = maxSize;
	}
	else
	{
		ArrayDimensionError();
	}
	
	nod->actualSize = actualSize;
	if(actualSize != 0)
	{
		for(int i = 0; i < actualSize; i++)
		{
			strcpy(nod->values[i], arrayValues[i]);
		}
	}
	strcpy(nod->scope, scope);
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
    extractedNumber[i-j] = '\0';
    int maxSize = atoi(extractedNumber);
    return maxSize;
}



// functions
typedef struct function {
    char *returnType;
    char name[50];
    int nrOfParameters;
    
 	struct parameter parameters[10];
    char scope[50];
    bool signature;

	struct function *next;
} function;

// lista de arrayuri
function *firstFunction = NULL, *lastFunction = NULL, *currentFunction;

void printFunctionList()
{
	currentFunction = firstFunction;
	printf("Printare lista Functii:\n");
	while(currentFunction != NULL)
	{
		printf("return_type = %s | name = %s | nrOfParameters = %d | scope = %s| signature = %d\n" ,
						currentFunction->returnType, currentFunction->name, currentFunction->nrOfParameters, currentFunction->scope, currentFunction->signature);

		printf("List of parameters: ");
		for(int i = 0 ; i < currentFunction->nrOfParameters; i++)
		{
			printf("%s %s, ", currentFunction->parameters[i].type, currentFunction->parameters[i].identifier);
		}
		printf("\n");

		currentFunction = currentFunction->next;
	}
}


bool lookupFunction(char *name, bool newSignature) {
	currentFunction = firstFunction;
	while (currentFunction != NULL) 
	{
		if (strcmp(currentFunction->name, name) == 0)
		 	{
		 		if(currentFunction->signature != true)
		 		    break;
		 		else
		 		{
		 			if(newSignature == true)
		 				break;
		 		}
		 	}
		currentFunction = currentFunction->next;
	}

	if(currentFunction == NULL)
		return false;
	return true;
}

function* getFunction(char* name, bool signatures)
{

	currentFunction = firstFunction;
	while (currentFunction != NULL) 
	{
		if (strcmp(currentFunction->name, name) == 0)
		 	{
		 		if(currentFunction->signature != true)
		 		    break;
		 		else
		 		{
		 			if(signatures == true)
		 				break;
		 		}
		 	}
		currentFunction = currentFunction->next;
	}
	return currentFunction;
}


void insertFunction(char* returnType, char* functionName, int nrOfParameters, struct parameter parameters[5], char* scope, bool signature)
{

	function *nod = (function *) malloc(sizeof(function));
	
	nod->returnType = returnType;
	strcpy(nod->name, functionName);
	if(nrOfParameters <= 5)
	{
		nod->nrOfParameters = nrOfParameters;
	}
	else
	{
		FunctionNoOfParametersError();
	}
	if(nrOfParameters != 0)
	{
		for(int i = 0; i < nrOfParameters; i++)
		{
			strcpy(nod->parameters[i].type, parameters[i].type);
			strcpy(nod->parameters[i].identifier, parameters[i].identifier);
		}
	}
	strcpy(nod->scope, scope);
	nod->signature = signature;

	nod->next = NULL;
	if (firstFunction == NULL) 
		firstFunction = lastFunction = nod;
	else 
	{
		lastFunction->next = nod;
		lastFunction = nod;
	}
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
    printf("\nERROR ON LINE %d : The identifier '%s' has type '%s', but you try to assign type '%s'.\n",yylineno, identifier, type, assignementType);
    exit(0);
}

void ListTypesError()
{
	printf("\nERROR ON LINE %d : The values of list are diffrent types!\n", yylineno);
    exit(0);
}

void ArrayDimensionError()
{
	printf("\nERROR ON LINE %d : The array dimension can't not be greater than 20!\n", yylineno);
    exit(0);
}

void FunctionNoOfParametersError()
{
	printf("\nERROR ON LINE %d : The maximum number of parameters is 5!\n", yylineno);
    exit(0);
}

void ConstAsignementError(char* identifier)
{
	printf("\nERROR ON LINE %d : %s is declared as constant!\n", yylineno, identifier);
    exit(0);
}

void UndeclaredVariableError(char* identifier)
{	
	printf("\nERROR ON LINE %d : The variable %s is not declared!\n", yylineno, identifier);
    exit(0);
}

void OperationError()
{
	printf("\nERROR ON LINE %d : Can't do operations with different types!!\n", yylineno);
    exit(0);
}

void OperatorError(char* type)
{
	printf("\nERROR ON LINE %d : Can't use this operator on '%s' type!!\n", yylineno, type);
    exit(0);
}

void DivideZeroError()
{
	printf("\nERROR ON LINE %d : Can't divide by Zero!\n", yylineno);
    exit(0);	
}

void OutOfBoundError()
{
	printf("\nERROR ON LINE %d : Index out of bound!\n", yylineno);
    exit(0);
}

void UndefinedFunction(char* identifier)
{
	printf("\nERROR ON LINE %d : The function '%s' is not defined!\n", yylineno, identifier);
    exit(0);
}

void ParameterWrongTypeError(char* identifier, int nrOfParameter, char* calledType, char* definedType)
{
	printf("\nERROR ON LINE %d : In function '%s' call the %d th parameter is called with type '%s', but it is defined with type '%s' !\n", yylineno, identifier, nrOfParameter, calledType, definedType);
    exit(0);
}

void ParameterNumberError(char* identifier)
{
	printf("\nERROR ON LINE %d : The function %s, is called with wrong number of parameters!\n", yylineno, identifier);
    exit(0);
}

void UsedButNotSetError(char* identifier)
{
	printf("\nERROR ON LINE %d : The variable '%s' is used but not set!\n", yylineno, identifier);
    exit(0);
}