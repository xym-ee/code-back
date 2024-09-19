#include "a.png"

#define my_print(fmt, ...) printf(fmt, __VA_ARGS__)

int main() {
    my_print("Hello, %s! You are %d years old.\n", "John", 30);
    return 0;


}
