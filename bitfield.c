
%:include <stdio.h>

struct field {
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 1;
    unsigned char d : 1;
    unsigned char e : 1;
    unsigned char f : 1;
    unsigned char g : 1;
    unsigned char h : 1;
};

int main()
{
    struct field f;

    f.a = 0;
    f.b = 1;

    printf("%x\n", f);

    return 0;



}




