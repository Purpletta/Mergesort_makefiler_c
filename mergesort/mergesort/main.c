#include <stdio.h>
#include <stdlib.h>

int compar(int *firstitem, int *seconditem) {
    if (*firstitem < *seconditem) {
        return 1;
    } else if (*firstitem > *seconditem){
        return 0;
    } else{
        return 2;
    }
}

void merge(int *a, size_t num, size_t size, int (*compar)(int *, int *)) {
    {
        int mid = num / 2;
        if (num % 2 == 1)
            mid++;
        int h = 1;
        int *c = (int *) malloc(num * size);
        int step;
        while (compar(&h, (int *) &num) == 1) {
            step = h;
            int i = 0;
            int* j = malloc(size);
            *j = mid;
            int k = 0;
            while (compar(&step, &mid) != 0) {
                int mid_and_step = mid + step;
                while (compar(&i, &step) == 1 && compar(j, (int *) &num) == 1 && compar(j, &mid_and_step) == 1) {
                    if (compar(a+i, a+(*j)) == 1) {
                        c[k] = *(a+i);
                        i++;
                        k++;
                    } else {
                        c[k] = *(a+(*j));
                        (*j)++;
                        k++;
                    }
                }
                while (compar(&i, &step) == 1) {
                    c[k] = a[i];
                    i++;
                    k++;
                }
                while (compar(j , &mid_and_step) == 1 && compar(j, (int *) &num) == 1) {
                    c[k] = a[*j];
                    (*j)++;
                    k++;
                }
                step = step + h;
            }
            h = h * 2;
            for (i = 0; i < num; i++)
                a[i] = *(c+i);
        }
    }
}
void some_tests() {
   
    int a[5];
    int b[8];
    int c[15];
    printf("unsorted array:\n");
    for (int i = 0; i < 5; i++)
        a[i] = rand() % 20 - 10;
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("sorted array:\n");
    merge(a, 5, sizeof(int), (int (*)(int *, int *)) compar);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("unsorted array:\n");
    for (int j = 0; j < 8; j++)
        b[j] = rand() % 20 - 10;
    for (int j = 0; j < 8; j++)
        printf("%d ", b[j]);
    printf("\n");
    printf("sorted array:\n");
    merge(b, 8, sizeof(int), (int (*)(int *, int *)) compar);
    for (int j = 0; j < 8; j++)
        printf("%d ", b[j]);
    printf("\n");
     printf("unsorted array:\n");
    for (int k = 0; k < 15; k++)
        c[k] = rand() % 20 - 10;
    for (int k = 0; k < 15; k++)
        printf("%d ", c[k]);
    printf("\n");
    printf("sorted array:\n");
    merge(c, 15, sizeof(int), (int (*)(int *, int *)) compar);
    for (int k = 0; k < 15; k++)
        printf("%d ", c[k]);
    printf("\n");
    getchar();}

int main() {
   
    some_tests();

    return 0; }
