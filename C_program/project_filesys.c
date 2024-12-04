#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

typedef struct Node {
    char name[MAX_NAME];
    int is_file;
    char *content;
    struct Node **children;
    int child_count;
    int max_children;
    struct Node *parent;
} Node;

Node* create_node(const char *name, int is_file, Node *parent) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Error: Memory allocation failed for node.\n");
        exit(1);
    }
    strncpy(node->name, name, MAX_NAME);
    node->name[MAX_NAME - 1] = '\0';
    node->is_file = is_file;
    node->child_count = 0;
    node->max_children = 2;
    node->parent = parent;

    if (!is_file) {
        node->children = (Node**)malloc(sizeof(Node*) * node->max_children);
        if (!node->children) {
            printf("Error: Memory allocation failed for children.\n");
            free(node);
            exit(1);
        }
    } else {
        node->content = NULL;
    }
    return node;
}

void expand_children(Node *node) {
    if (node->child_count >= node->max_children) {
        node->max_children *= 2;
        node->children = realloc(node->children, sizeof(Node*) * node->max_children);
        if (!node->children) {
            printf("Error: Memory allocation failed while expanding children.\n");
            exit(1);
        }
    }
}

void create_node_in_dir(Node *current, const char *name, int is_file) {
    for (int i = 0; i < current->child_count; i++) {
        if (!strcmp(current->children[i]->name, name)) {
            printf("Error: File or directory '%s' already exists in '%s'.\n", name, current->name);
            return;
        }
    }

    expand_children(current);
    Node *new_node = create_node(name, is_file, current);
    current->children[current->child_count++] = new_node;

    if (is_file) {
        FILE *fp = fopen(name, "w");
        if (fp == NULL) {
            printf("Error: Could not create file '%s'.\n", name);
            return;
        }
        fclose(fp);
    }

    printf("%s '%s' created in '%s'.\n", is_file ? "File" : "Directory", name, current->name);
}

void write_file(Node *current, const char *name, const char *content) {
    for (int i = 0; i < current->child_count; i++) {
        if (!strcmp(current->children[i]->name, name) && current->children[i]->is_file) {
            free(current->children[i]->content);
            current->children[i]->content = strdup(content);

            FILE *fp = fopen(name, "w");
            if (fp == NULL) {
                printf("Error: Could not open file '%s'.\n", name);
                return;
            }
            fprintf(fp, "%s", content);
            fclose(fp);

            printf("Content written to file '%s' in '%s'.\n", name, current->name);
            return;
        }
    }
    printf("Error: File '%s' does not exist in '%s'.\n", name, current->name);
}

void read_file(Node *current, const char *name) {
    for (int i = 0; i < current->child_count; i++) {
        if (!strcmp(current->children[i]->name, name) && current->children[i]->is_file) {
            FILE *fp = fopen(name, "r");
            if (fp == NULL) {
                printf("Error: Could not open file '%s'.\n", name);
                return;
            }

            char buffer[1024];
            printf("Content of '%s':\n", name);
            while (fgets(buffer, sizeof(buffer), fp)) {
                printf("%s", buffer);
            }
            fclose(fp);
            return;
        }
    }
    printf("Error: File '%s' does not exist in '%s'.\n", name, current->name);
}

void delete_node_recursive(Node *node) {
    if (!node) return;
    if (!node->is_file) {
        for (int i = 0; i < node->child_count; i++) {
            delete_node_recursive(node->children[i]);
        }
        free(node->children);
    } else {
        free(node->content);
    }
    free(node);
}

void delete_file(Node *current, const char *name) {
    for (int i = 0; i < current->child_count; i++) {
        if (!strcmp(current->children[i]->name, name)) {
            if (current->children[i]->is_file) {
                if (remove(name) != 0) {
                    printf("Error: Could not delete file '%s'.\n", name);
                } else {
                    printf("File '%s' deleted from filesystem.\n", name);
                }
            }

            delete_node_recursive(current->children[i]);
            for (int j = i; j < current->child_count - 1; j++) {
                current->children[j] = current->children[j + 1];
            }
            current->child_count--;

            printf("File or directory '%s' deleted from '%s'.\n", name, current->name);
            return;
        }
    }
    printf("Error: File or directory '%s' does not exist in '%s'.\n", name, current->name);
}

void print_current_directory(Node *current) {
    if (current == NULL) return;
    if (current->parent != NULL) {
        print_current_directory(current->parent);
        printf("/");
    }
    printf("%s", current->name);
}

void free_filesystem(Node *root) {
    delete_node_recursive(root);
}

void background_operations(Node *root) {
    printf("Running background operations...\n");

    create_node_in_dir(root, "test.txt", 1);

    write_file(root, "test.txt", "Hello, this is a test file!");

    read_file(root, "test.txt");

    delete_file(root, "test.txt");

    printf("Background operations completed.\n");
}

int main() {
    Node *root = create_node("root", 0, NULL);
    Node *current_dir = root;

    background_operations(root);

    char command[256], name[256], content[1024];

    while (1) {
        printf("Current directory: ");
        print_current_directory(current_dir);
        printf("\n");

        printf("Enter command (create, delete, write, read, exit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Is it a file (1) or directory (0)? ");
            int is_file;
            scanf("%d", &is_file);
            create_node_in_dir(current_dir, name, is_file);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            delete_file(current_dir, name);
        } else if (strcmp(command, "write") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter content: ");
            getchar();
            fgets(content, sizeof(content), stdin);
            content[strcspn(content, "\n")] = '\0';
            write_file(current_dir, name, content);
        } else if (strcmp(command, "read") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            read_file(current_dir, name);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }
    }

    free_filesystem(root);
    return 0;
}