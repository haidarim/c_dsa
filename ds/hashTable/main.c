#include <stdio.h>
#include "hash_map.h"

int main(void)
{
    printf("---------> [START] <---------\n");

    hm_t *hm = createHashMap();
    if (hm == NULL)
    {
        printf("Failed to create hash map.\n");
        return 1;
    }

    printf("Hash map created successfully.\n");

    put(hm, "fjant", "är");
    printf("Added key 'fjant' with value 'är'.\n");

    put(hm, "chaq", "bad boy");
    printf("Added key 'chaq' with value 'bad boy'.\n");

    put(hm, "1", "1");
    printf("Added key '1' with value '1'.\n");

    put(hm, "2", "2");
    printf("Added key '2' with value '2'.\n");

    put(hm, "3", "3");
    printf("Added key '3' with value '3'.\n");

    put(hm, "4", "4");
    printf("Added key '4' with value '4'.\n");

    put(hm, "5", "5");
    printf("Added key '5' with value '5'.\n");

    printf("---------------> before loop <---------\n");

    for (unsigned int i = 0; i < hm->mapSize; i++)
    {
        const char *val = getVal(hm, "fjant");
        if (val != NULL)
        {
            printf("the value: %s of the key: fjant\n", val);
        }
        else
        {
            printf("Key 'fjant' not found.\n");
        }
    }

    free_hm(hm);
    printf("Hash map freed.\n");

    return 0;
}
