#ifndef compiler_H
#define compiler_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "vector.h"
#include "hashmap.h"

#define SPACE_CHAR " "
#define OPEN_BRACKET "("
#define CLOSE_BRACKET ")"
#define OPEN_BRACE "{"
#define CLOSE_BRACE "}"
#define CONST_KEYWORD "const"
#define ASTERISKS "*"
#define NEWLINE "\n"
#define TAB "\t"
#define EQUAL_SYM "="
#define SEMICOLON ";"
#define COMMA_SYM ","

typedef enum {
	WRITE_HEADER_STATE,
	WRITE_SOURCE_STATE
} WriteState;

typedef struct {
	Vector *abstractSyntaxTree;
	Vector *sourceFiles;
	SourceFile *currentSourceFile;
	map_t functions;
	map_t structures;
	map_t variables;
	WriteState writeState;

	int currentNode;
} Compiler;

typedef struct {
	// a list of the initial values IN ORDER!!
	Vector *initialValues;
} StructInitializer;

Compiler *createCompiler(Vector *sourceFiles);

void emitExpression(Compiler *self, ExpressionAstNode *expr);

void emitVariableDefine(Compiler *self, VariableDefinitionAstNode *def);

void emitVariableDeclaration(Compiler *self, VariableDeclarationAstNode *var);

void emitReturnStatement(Compiler *self, FunctionReturnAstNode *ret);

void emitForLoop(Compiler *self, ForLoopAstNode *forLoop);

void emitFunctionCall(Compiler *self, FunctionCallAstNode *call);

void emitIfStatement(Compiler *self, IfStatementAstNode *stmt);

void emitBlock(Compiler *self, BlockAstNode *block);

void emitArguments(Compiler *self, Vector *args);

void emitInfiniteLoop(Compiler *self, InfiniteLoopAstNode *infinite);

void emitWhileLoop(Compiler *self, WhileLoopAstNode *whileLoop);

void emitEnumeration(Compiler *self, EnumAstNode *enumeration);

void emitUseStatement(Compiler *self, UseStatementAstNode *use);

void emitFunction(Compiler *self, FunctionAstNode *func);

void consumeAstNode(Compiler *self);

void consumeAstNodeBy(Compiler *self, int amount);

void startCompiler(Compiler *self);

void compileAST(Compiler *self);

void destroyCompiler(Compiler *self);

#endif // compiler_H
