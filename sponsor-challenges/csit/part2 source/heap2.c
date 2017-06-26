#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>

void check(void) __attribute__((constructor));
 
void
check(void)
{
   /*if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1) {
	printf("YOU ARE TRYING TO DEBUG... Bye Bye\n");
       exit(-1);
   }*/
}

typedef struct {
  unsigned int size;
  char* entry;
} log_item;

typedef int (*print_function_t)(log_item*);

typedef struct {
  print_function_t pf;
} function_table;

log_item* build_log_item(const char* entry_text) {
  log_item* temp = NULL;

  temp = malloc(sizeof(log_item));

  if (temp) {
    temp->size = strlen(entry_text);
    temp->entry = strdup(entry_text);
  }

  return temp;
}


int destroy_log_item(log_item* l) {
  free(l->entry);
  free(l);

  return 0;
}

int copy_log_item(log_item* dst, log_item* src) {
  dst->size = src->size;
  memcpy(dst->entry, src->entry, src->size);

  return 0;
}

int print_log_item(log_item* l) {
  unsigned int size = l->size;
  int i = 0;

  for (i = 0; i < size; i++) {
    printf("%c", l->entry[i]);
  }

  return 0;
}

#ifndef PRODUCTION

void getFlag(){
	printf("{CSIT:W3LLD0N3:PrIz3M1GhTB30ur$}");

}

#endif

#define NUM_LOG_ITEMS 512

int count_spaces(char* string) {
  int len = strlen(string);
  int i = 0;
  int num_spaces = 0;

  for (i = 0; i < len; i++) {
    if (string[i] == ' ') {
      num_spaces++;
    }
  }
      
  return num_spaces;
}

int handler(int argc, char** argv) {
  function_table* ftable = NULL;
  log_item* log_items[NUM_LOG_ITEMS] = {0};
  unsigned int num_log_items = 0;
  char line[1024] = {0};

  // Populate function table
  ftable = (function_table*) malloc(sizeof(function_table));
  ftable->pf = print_log_item;

  printf("\n");
  printf("  Welcome to logger!\n");
  printf("\n");
  printf("  Your available commands are:\n");
  printf("   + add log_entry\n");
  printf("   + show index\n");
  printf("   + copy from_index to_index\n");
  printf("   + exit\n");
  printf("\n");

  // Take commands
  while (1) {
    printf(" > ");

    if (fgets(line, sizeof(line), stdin) == NULL) break;
      
    if (strncmp(line, "add", 3) == 0) {
      if (num_log_items == NUM_LOG_ITEMS) {
        printf("No more space.\n");
      } else {
        log_items[num_log_items] = build_log_item(line + 4);
        num_log_items++;
      }
    } else if(strncmp(line, "show", 4) == 0) {
      int index = atoi(line + 5);
      if (index >= num_log_items) {
        printf("That item doesn't exist\n");
      } else {
        ftable->pf(log_items[index]);
      }
    } else if(strncmp(line, "copy", 4) == 0) {
      if (count_spaces(line) != 2) {
        printf("Invalid command\n");
      } else {
        char* first = line+5;
        char* second = strchr(first, ' ');
        int first_index = atoi(first);
        int second_index = atoi(second+1);

        if (first_index >= num_log_items) {
          printf("The first item does not exist\n");
        } else if (second_index >= num_log_items) {
          printf("The second item does not exist\n");
        } else {
          copy_log_item(log_items[second_index], log_items[first_index]);
        }
      }
    } else if(strncmp(line, "exit", 4) == 0) {
      printf("KThxBye!\n");
      return 0;
    } else {
      printf("Invalid command\n");
    }
  }

  return 0;
}

int main(int argc, char** argv) {
  
if (argc != 2) {
    printf("%s <port>\n", argv[0]);
    return 1;
  }
	
  //handler(argc, argv);
  serve_forever((unsigned short)atoi(argv[1]), handler);

  return 0;
}
