#ifndef MONTY
#define MONTY

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s {
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s {
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s: structure of the arg from int main
 * @av: name of the file
 * @ac: number of arg
 * @line_number; num of arg
 *
 * Description: arg passed to main from the commanline
 *
 */
typedef struct args_s {
  char *av;
  int ac;
  unsigned int line_number;
} args_s;

/**
 * struct data_s - extern data to access inside functions
 * @line; line from the file
 * @word: parsed line
 * @stack: pointer of the stack
 * @filep: file pointer
 * @flagq: flag for queue or stack
 */
typedef struct data_s {
  char *line;
  char **word;
  stack_t *stack;
  FILE *filep;
  int flagq;
} data_s;

typedef stack_t dlistint_t;

#endif
