#include <stdio.h>
#include <stdlib.h>

int *input(int *n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int *data;
    int n;
    data = input(&n);
    if (data != NULL) {
        sort(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }

    return 0;
}

int *input(int *n) {
    float v = 0;
    int *p, *q;
    char c;
    int b = scanf("%d%c", n, &c);
    if (!((b == 2) && (c == '\n')))
        return NULL;
    p = malloc(*n * sizeof(int));
    q = p;
    for (int i = 0; i < *n; i++) {
        b = scanf("%f", &v);
        if (((int)v == v) && (b == 1))
            *p++ = v;
        else
            return NULL;
    }
    return q;
}

void output(int *a, int n) {
    int *p;
    p = a;
    for (int i = 0; i < n; i++)
        printf("%d ", *p++);
    printf("\b");
}

void sort(int *a, int n) {
    int *p;
    int t;
    for (int i = 0; i < n - 1; i++) {
        p = a;
        for (int j = 0; j < n - 1 - i; j++) {
            if (p[j] > p[j + 1]) {
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
}
