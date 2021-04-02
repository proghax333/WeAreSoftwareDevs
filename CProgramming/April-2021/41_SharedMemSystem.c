
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MemoryBlock MemoryBlock;
struct MemoryBlock
{
  void *memory;
  size_t counter;
  MemoryBlock *self_pointer;
};

typedef struct MemoryNode MemoryNode;
struct MemoryNode
{
  MemoryNode *prev, *next;
  MemoryBlock block;
};

typedef struct BlockStack
{
  MemoryNode *bottom, *top;
} BlockStack;

typedef struct AlignmentInfo
{
  size_t context_node_count;
} AlignmentInfo;

typedef struct AlignmentInfoNode AlignmentInfoNode;
struct AlignmentInfoNode
{
  AlignmentInfoNode *prev, *next;
  AlignmentInfo info;
};

typedef struct AlignmentStack
{
  AlignmentInfoNode *bottom, *top;
} AlignmentStack;

typedef struct MemoryStack
{
  BlockStack block_stack;
  AlignmentStack alignment_stack;
} MemoryStack;

void push_current_context()
{
}
void pop_current_context()
{
}

#define PUSH push_current_context();
#define POP pop_current_context();

#define get(x, type) (*((type *)x))
#define set(x, expr, type) get(x, type) = expr;

int main()
{
  PUSH;

  int a = 10;
  int *pA = &a;

  printf("%d\n", get(pA, int));

  set(pA, 20, int);

  printf("%d\n", get(pA, int));

  POP;

  return 0;
}
