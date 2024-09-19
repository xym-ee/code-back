#include <stdio.h>

#define MAX 20

struct book
{
    char *name;
    char *auth;
    float price;
};

void print_book_by_ptr(struct book *b)
{
    printf("%s \n%s \n%f\n", b->name, b->auth, b->price);
}

int main(int argc, char const *argv[])
{
    struct book c_premier;
    c_premier = (struct book){"C Premier Plus", "unkonw", 88.0};
    print_book_by_ptr(&c_premier);

    (struct book){
        .name = "C Premier Plus",
        .auth = "unkonw",
        .price = 88.0,
    };
    
    return 0;
}


