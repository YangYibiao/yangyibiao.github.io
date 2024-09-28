
int *f(void)
{
    int i;
    i = 8;
    return &i;
}

int *max(int *a, int *b)
{
    if (*a > *b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int *p, i, j;
    scanf("%d%d", &i, &j);
    p = max(&i, &j);
    printf("p: %p,\n&a: %p\n&b:\n", p, &a, &b);
    printf("%d", *p);
    return 0;
}