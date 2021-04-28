#define MAX 80
typedef struct binarytreenode
{
  char* user;
  char* password;
  struct binarytreenode* rightchild;
  struct binarytreenode* leftchild;
  unsigned int depth;
}


node;
char line[MAX], password[MAX], user[MAX];
int getout();
void get (char l[MAX],char p[MAX],char u[MAX]);
node* insert(char* u, char* p, node* pos, int d);
void delete(node* position, char* a, char* p, int* n);
void alpha(node* position);

/* This program was made with the help of https://github.com/satuelisa/C/tree/main/Ch6, Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988) and
with the help of rulgamer07 */
