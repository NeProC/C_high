#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct list
{
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t findMaxBlock(list *head)
{
    // if (head == NULL)
    // {
    //     return 0;
    // }
    size_t max = 0;
    uint64_t maxSizeAdress = 0;
    // do
    // {
    //     if (max < head->size)
    //     {
    //         max = head->size;
    //         maxSizeAdress = head->address;
    //     }
    //     head = head->next;
    // } while (head != NULL);
    for (list *p = head; p != NULL; p = p->next)
    {
        if (max < p->size)
        {
            max = p->size;
            maxSizeAdress = p->address;
        }
        
    }
    

    //    printf("%llu", maxSizeAdress);
    return maxSizeAdress;
}