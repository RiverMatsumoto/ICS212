#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
        int num1, num2 = 10;
        char c1 = 'A';
        char c2 = 'B';
        float score1 = 20.5;
        char ca[3] = "Hi";

        printf("argc address: %p\n", (void *) &argc);
        printf("argv address: %p\n", (void *) &argv);
        printf("num1 address: %p\n", (void *) &num1);
        printf("num2 address: %p\n", (void *) &num2);
        printf("c1 address: %p\n", (void *) &c1);
        printf("c2 address: %p\n", (void *) &c2);
        printf("score1 address: %p\n", (void *) &score1);
        printf("ca[0] address: %p\n", (void *) &ca[0]);
        printf("ca[1] address: %p\n", (void *) &ca[1]);
        printf("ca[2] address: %p\n", (void *) &ca[2]);
        printf("argc value: %d\n", argc);
        printf("argv value: %p\n", (void *) argv);
        printf("num1 value: %d\n", num1);
        printf("num2 value: %d\n", num2);
        printf("c1 value: %c\n", c1);
        printf("c2 value: %c\n", c2);
        printf("score1 value: %f\n", score1);
        printf("ca[0] value: %c\n", ca[0]);
        printf("ca[1] value: %c\n", ca[1]);
        printf("ca[2] value: %d\n", ca[2]);
        printf("size of int: %lu\n", sizeof(argc));
        printf("size of pointer: %lu\n", sizeof(argv));
        printf("size of char: %lu\n", sizeof(c1));
        printf("size of float: %lu\n", sizeof(score1));

        dummy(num2, c1, ca, score1);

        return 0;
}

void dummy(int x, char y, char* z, float w)
{
        x++;
        y++;
        w = w + 2.1;

        printf("x address: %p\n", (void *) &x);
        printf("y address: %p\n", (void *) &y);
        printf("z address: %p\n", (void *) &z);
        printf("w address: %p\n", (void *) &w);
        printf("x value: %d\n", x);
        printf("y value: %c\n", y);
        printf("z value: %p\n", z);
        printf("w value: %f\n", w);
        /* pause here */
}
