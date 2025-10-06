#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <malloc.h>

#define WORD_SIZE 20
#define MAX_LINE_LENGTH 1000

typedef struct list
{
    char word [WORD_SIZE];
    struct list *next; 
} list_t;

list_t* add_to_list(char word[], list_t *head);
void swap_elements(list_t *list);
void print_list(list_t *list);
void delete_list(list_t *head);
list_t * create_list_from_string(char *str);
list_t* sort_list(list_t *head);

int main() {
    char inputStr[MAX_LINE_LENGTH];
    scanf("%[^.]", inputStr);

    list_t *head = create_list_from_string(inputStr);
//    print_list(head);

    head = sort_list(head);
    print_list(head);

    delete_list(head);

    return 0;
}

// Функция сортировки списка по алфавиту
list_t* sort_list(list_t *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    int swapped;
    list_t *ptr1;
    list_t *lptr = NULL;
    
    do {
        swapped = 0;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            // Сравниваем строки
            if (strcmp(ptr1->word, ptr1->next->word) > 0) {
                // Меняем местами слова
                char temp[WORD_SIZE];
                strncpy(temp, ptr1->word, sizeof(temp) - 1);
                temp[sizeof(temp) - 1] = '\0';
                strncpy(ptr1->word, ptr1->next->word, sizeof(ptr1->word) - 1);
                ptr1->word[sizeof(ptr1->word) - 1] = '\0';
                strncpy(ptr1->next->word, temp, sizeof(ptr1->next->word) - 1);
                ptr1->next->word[sizeof(ptr1->next->word) - 1] = '\0';
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    
    return head;
}

list_t * create_list_from_string(char *str)
{
    list_t *head = NULL;
    
    char *token = strtok(str, " ");
    while(token != NULL)
    {
        if (token[strlen(token) - 1] == '.') {
            token[strlen(token) - 1] = '\0';
        }

        head = add_to_list(token, head);
        token = strtok(NULL, " ");
    }
    return head;
}

list_t* add_to_list(char word[], list_t *head)
{
    list_t *new_node = calloc(1, sizeof(list_t));
    size_t len = strlen(word);
    if(len > WORD_SIZE-1)
        len = WORD_SIZE - 1;
    strncpy(new_node->word, word, len);
    new_node->word[WORD_SIZE] = '\0'; // null-terminate the string
    new_node->next = head;
    return new_node;
}

void print_list(list_t *list){
    while (list != NULL) {
        printf("%s ", list->word);
        list = list->next;
    }
    printf("\n");
}

void swap_elements(list_t *list){
    if(list == NULL || list->next == NULL)
        return;
    size_t len;
    char temp[WORD_SIZE];
    len = strlen(list->word);
    if(len > WORD_SIZE-1){
        len = WORD_SIZE-1;}
    strncpy(temp, list->word, len);
    temp[len] = '\0'; // null-terminate the string
    len = strlen(list->next->word);
    if(len > WORD_SIZE-1){
        len = WORD_SIZE-1;}
    strncpy(list->word, list->next->word, len);
    temp[len] = '\0'; // null-terminate the string
    len = strlen(temp);
    if(len > WORD_SIZE-1){
        len = WORD_SIZE-1;}
    strncpy(list->next->word, temp, len);
    temp[len] = '\0'; // null-terminate the string
}

void delete_list(list_t *head)
{
    list_t *currentList = head;
    while(currentList != NULL)
    {
        list_t *next = currentList->next;
        free(currentList);
        currentList = next;
    }
}
/*
list_t* add_to_list(char word[], list_t *head){
    list_t *new_node = calloc(1, sizeof(list_t));
    size_t len = strlen(word);
    if(len > 255)
        len = 255;
    strncpy(new_node->word, word, len); // copy the string into the node
    new_node->word[len] = '\0'; // null-terminate the string
    new_node->next = head;
    return new_node;
}



void delete_list(list_t *head)
{
    list_t *currentList = head;
    while(currentList != NULL)
    {
        list_t *next = currentList->next;
        free(currentList);
        currentList = next;
    }
}
*/
    
    