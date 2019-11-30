#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

FILE *astFile;                          // AST file
FILE *sourceFile;                       // miniC source program
FILE *ucodeFile;                        // ucode file

#include "src\Scanner.c"
#include "src\Parser.c"
#include "src\PrintTree.c"
//#include "src\EmitCode.c"
//#include "src\SymTab.c"



// void codeGen(Node *ptr);
// void processDeclaration(Node *ptr);
// void processFuncHeader(Node *ptr);
// void processFunction(Node *ptr);
// void icg_error(int n);
// void processSimpleVariable(Node *ptr, int typeSpecifier, int typeQualifier);
// void processArrayVariable(Node *ptr, int typeSpecifier, int typeQualifier);
// void processStatement(Node *ptr);
// void processOperator(Node *ptr);
// void processCondition(Node *ptr);
// void rv_emit(Node *ptr);
// void genLabel(char *label);
// int checkPredefined(Node *ptr);

// int labelCount = 0;
// int returnWithValue, lvalue;

void icg_error(int n);

void main(int argc, char *argv[])
{
	char fileName[30];
	Node *root;

	printf(" *** start of Mini C Compiler\n");
	if (argc != 2) {
		icg_error(1);
		exit(1);
	}
	strcpy(fileName, argv[1]);
	printf("   * source file name: %s\n", fileName);

	if ((sourceFile = fopen(fileName, "r")) == NULL) {
		icg_error(2);
		exit(1);
	}
	astFile = fopen(strcat(strtok(fileName, "."), ".ast"), "w");
	// ucodeFile = fopen(strcat(strtok(fileName, "."), ".uco"), "w");

	printf(" === start of Parser\n");
    root = parser();
	printTree(root, 0);
	// printf(" === start of ICG\n");
	// codeGen(root);
	printf(" *** end   of Mini C Compiler\n");

	system("pause");
} // end of main

void icg_error(int n)
{
	printf("icg_error: %d\n", n);
	//3:printf("A Mini C Source file must be specified.!!!\n");
	//"error in DCL_SPEC"
	//"error in DCL_ITEM"
}