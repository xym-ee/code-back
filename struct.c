#include <stdio.h>

#define MAX 20

struct book
{
    char name[MAX];
    char auth[MAX];
    float price;
};

void print_book(struct book b)
{
    printf("%s \n%s \n%f\n", b.name, b.auth, b.price);
}

void print_book_by_ptr(struct book *b)
{
    printf("%s \n%s \n%f\n", b->name, b->auth, b->price);
}

void print_book_name(const char* name)
{
    printf("%s \n", name);
}

int main(int argc, char const *argv[])
{
    struct book c_premier = {
        .name = "C Premier Plus",
        .auth = "unkonw",
        .price = 88.0
    };

    struct book aa;
    
    struct book cc = c_premier;
    print_book(c_premier);
    printf("%s \n%s \n%f\n", cc.name, cc.auth, cc.price);
    printf("%s \n%s \n%f\n", (struct book){"C Premier Plus", "unkonw", 88.0}.name, (struct book){"C Premier Plus", "unkonw", 88.0}.auth, (struct book){"C Premier Plus", "unkonw", 88.0}.price);

    return 0;
}


