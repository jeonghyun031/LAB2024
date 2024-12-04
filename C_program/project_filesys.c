#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define BLOCK_SIZE 512

typedef struct Block {
    char data[BLOCK_SIZE];
    struct Block *next;
} Block;

typedef struct Node {
    char name[MAX_NAME];
    int is_file;
    Block *blocks;
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
    node->blocks = NULL;

    if (!is_file) {
        node->children = (Node**)malloc(sizeof(Node*) * node->max_children);
        if (!node->children) {
            printf("Error: Memory allocation failed for children.\n");
            free(node);
            exit(1);
        }
    } else {
        node->children = NULL;
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

void add_child_to_directory(Node *dir, Node *child) {
    expand_children(dir);
    dir->children[dir->child_count] = child;
    dir->child_count++;
}

void add_block_to_file(Node *file_node, const char *content) {
    Block *new_block = (Block*)malloc(sizeof(Block));
    if (!new_block) {
        printf("Error: Memory allocation failed for block.\n");
        exit(1);
    }
    
    strncpy(new_block->data, content, BLOCK_SIZE);
    new_block->next = NULL;

    if (file_node->blocks == NULL) {
        file_node->blocks = new_block;
    } else {
        Block *last_block = file_node->blocks;
        while (last_block->next != NULL) {
            last_block = last_block->next;
        }
        last_block->next = new_block;
    }
}

void write_file(Node *current, const char *name, const char *content) {
    for (int i = 0; i < current->child_count; i++) {
        if (!strcmp(current->children[i]->name, name) && current->children[i]->is_file) {
            add_block_to_file(current->children[i], content);
            
            FILE *fp = fopen(name, "a");
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
            printf("Content of '%s':\n", name);
            Block *block = current->children[i]->blocks;
            while (block != NULL) {
                printf("%s", block->data);
                block = block->next;
            }
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
        Block *block = node->blocks;
        while (block != NULL) {
            Block *temp = block;
            block = block->next;
            free(temp);
        }
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

    Node *file = create_node("test.txt", 1, root);
    add_child_to_directory(root, file);

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

            Node *new_node = create_node(name, is_file, current_dir);
            add_child_to_directory(current_dir, new_node);
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