
#include <stdio.h>
#include <stdlib.h>

struct flex
{
    size_t count;
    double average;
    double scores [];   /* 伸缩型数组成员 */
};

struct person {
    int id;
    struct {
        char first[20];
        char last[20];
    };
};

int main(int argc, char const *argv[])
{
    struct flex * pf = NULL;

    struct person p = {
        .first = "sdf"
    };

    pf = malloc(sizeof(struct flex) + 5 * sizeof(double));

    pf->count = 5;
    pf->scores[4] = 20.0;
    return 0;
}







