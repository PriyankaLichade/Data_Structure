#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

// Trie node structure
struct TrieNode {
    struct TrieNode *child[ALPHABET];
    int wordEnd;   // marks end of a word
};

// Create new node
struct TrieNode* newNode() {
    struct TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    int i;

    node->wordEnd = 0;
    for (i = 0; i < ALPHABET; i++)
        node->child[i] = NULL;

    return node;
}

// Insert word into trie
void insertWord(struct TrieNode *root, char word[]) {
    int i, index;
    struct TrieNode *curr = root;

    for (i = 0; word[i] != '\0'; i++) {
        index = word[i] - 'a';

        if (curr->child[index] == NULL) {
            curr->child[index] = newNode();
        }
        curr = curr->child[index];
    }
    curr->wordEnd = 1;
    printf("Word inserted successfully.\n");
}

// Search word in trie
int searchWord(struct TrieNode *root, char word[]) {
    int i, index;
    struct TrieNode *curr = root;

    for (i = 0; word[i] != '\0'; i++) {
        index = word[i] - 'a';

        if (curr->child[index] == NULL)
            return 0;

        curr = curr->child[index];
    }
    return curr->wordEnd;
}

// Menu-driven program
int main() {
    struct TrieNode *root = newNode();
    int choice;
    char key[50];

    while (1) {
        printf("\n--- TRIE MENU ---\n");
        printf("1. Insert Word\n");
        printf("2. Search Word\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter word to insert (lowercase): ");
                scanf("%s", key);
                insertWord(root, key);
                break;

            case 2:
                printf("Enter word to search: ");
                scanf("%s", key);

                if (searchWord(root, key))
                    printf("Word FOUND in Trie.\n");
                else
                    printf("Word NOT FOUND.\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
