#pragma once
#include "domain.h"

typedef struct
{
	Offer* x;
	int opType;
	
} Operation;

Operation *create_operation(Offer *x, int type);
void free_operation(Operation *op);
Operation *copy_operation(Operation *op);

//------------------------------------------------------------------------------------------------------------

typedef struct
{
	Operation* operations[100];
	int n;
} OperationsStack;

OperationsStack *create_stack();
void free_stack(OperationsStack *stack);
void push_stack(OperationsStack* stack, Operation* o);
Operation* pop_stack(OperationsStack* stack);
int isEmpty_stack(OperationsStack* stack);
int isFull_stack(OperationsStack* stack);

