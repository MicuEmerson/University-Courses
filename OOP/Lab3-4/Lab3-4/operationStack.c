#include "operationStack.h"


Operation *create_operation(Offer *x, int type) {

	Operation *op = (Operation*)malloc(sizeof(Operation));
	op->opType = type;
	op->x = copy_offer(x);

	return op;
}

void free_operation(Operation *op) {

	free_offer(op->x);
	free(op);
}

Operation *copy_operation(Operation *op) {

	return create_operation(op->x, op->opType);
}

//------------------------------------------------------------------------------------------------------------


OperationsStack *create_stack() {

	OperationsStack *stack = (OperationsStack*)malloc(sizeof(OperationsStack));
	stack->n = 0;
	return stack;
}

void free_stack(OperationsStack *stack) {

	int i;
	
	for (i = 0; i < stack->n; i++) 
		free_operation(stack->operations[i]);
	
	free(stack);
}


void push_stack(OperationsStack* stack, Operation* op) {

	
	stack->operations[stack->n++] = copy_operation(op);

}

Operation* pop_stack(OperationsStack* stack) {

	return stack->operations[--stack->n];
}

int isEmpty_stack(OperationsStack* stack)
{
	return stack->n == 0;
}

int isFull_stack(OperationsStack* stack)
{
	return stack->n == 100;
}