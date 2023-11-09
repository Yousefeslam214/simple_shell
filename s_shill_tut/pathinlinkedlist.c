#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

typedef struct node {
  char *path;
  struct node *next;
} Node;

Node *build_path_list() {
	char *path_env = getenv("PATH");
	if (!path_env) {
		return NULL;
	}
	Node *head = NULL;
	char *token = strtok(path_env, ":");
	while (token) {
		Node *new_node = malloc(sizeof(Node));
		new_node->path = strdup(token);
		new_node->next = head;
		head = new_node;
		token = strtok(NULL, ":");
	}
	return head;
}

void free_path_list(Node *head) {
  while (head) {
	free(head->path);
	Node *next = head->next;
	free(head);
	head = next;
  }
}
int main ()
{
	Node *path_list = build_path_list();
if (path_list) {
  Node *node = path_list;
  while (node) {
	printf("%s\n", node->path);
	node = node->next;
  }
  free_path_list(path_list);
}
	return(0);
}
