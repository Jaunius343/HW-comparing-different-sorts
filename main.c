#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_array(int data[], int size, int low, int high)
{
    srand(1/*time(0)*/);


    if(high < low)
        printf("\nincorrect interval\n");
    else{
        for(int i = 0; i < size; ++i){
            data[i] = low + rand()% (high - low + 1);
        }
    }
}

void print_array (int array[], int size)
{
    for (int i = 0; i < size; ++i){
        printf("%d ", array[i]);
    }
}

int is_array_sorted(int s[], int n)
{
    int a = 1, d = 1, i = 0;

    while ((a == 1 || d == 1) && i < n - 1) {
        if (s[i] < s[i+1])
            d = 0;
        else if (s[i] > s[i+1])
            a = 0;
        i++;
    }

    if (a == 1)
        return 1;
    else if (d == 1)
        return 2;
    else
        return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort (int array[], int size);
void quick_sort (int array[], int low, int high);
int partition (int array[], int low, int high);
void insertion_sort (int array[], int size);
void selection_sort (int array[], int size);
void merge (int array[], int l, int m, int r);
void merge_sort (int array[], int l, int r);
void compare_sorts(int array, int SIZE);

int comp, assign;

clock_t start, end;
double cpu_time_used;

int main()
{
    int array[2000];
    int *temp = (int *)malloc(1000 * sizeof(int));

    //printf("%-20s %d\n", "labas", 1);

    generate_array(array, 1000, 0, 1000);
//    print_array(array, 10);
//    printf("\n");
//    if (is_array_sorted(array, 10) == 0){
//        printf("array is not sorted\n");
//    } else {
//        printf("array is sorted\n");
//    }

    compare_sorts(array, 1000);
    printf("\n\n\n");
    generate_array(array, 2000, 0, 2000);
//    print_array(array, 20);
//    printf("\n");
    compare_sorts(array, 2000);

    return 0;
}

void compare_sorts(int array, int SIZE)
{
    int *temp = (int *)malloc(SIZE * sizeof(int));

    printf("\n");
    printf("%25s %10s %7s\n", "compare", "/ assign", "/ time");
    comp = 0;
    assign = 0;
    temp = array;
    printf("%-20s", "Bubble sort:");

    start = clock();
    bubble_sort(temp, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("%-7d / %7d / %f\n", comp, assign, cpu_time_used);
//    print_array(temp, SIZE);
//    printf("\n");
//    if (is_array_sorted(temp, SIZE) == 0){
//        printf("array is not sorted\n");
//    } else {
//        printf("array is sorted\n");
//    }
    printf("\n");

    comp = 0;
    assign = 0;
    temp = array;
    printf("%-20s", "Quick sort:");

    start = clock();
    quick_sort(temp, 0, SIZE - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("%-7d / %7d / %f\n", comp, assign, cpu_time_used);
//    print_array(temp, SIZE);
//    printf("\n");
//    if (is_array_sorted(temp, SIZE) == 0){
//        printf("array is not sorted\n");
//    } else {
//        printf("array is sorted\n");
//    }
    printf("\n");

    comp = 0;
    assign = 0;
    temp = array;
    printf("%-20s", "Insertion sort:");

    start = clock();
    insertion_sort(temp, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("%-7d / %7d / %f\n", comp, assign, cpu_time_used);
//    print_array(temp, SIZE);
//    printf("\n");
//    if (is_array_sorted(temp, SIZE) == 0){
//        printf("array is not sorted\n");
//    } else {
//        printf("array is sorted\n");
//    }
    printf("\n");

    comp = 0;
    assign = 0;
    temp = array;
    printf("%-20s", "Selection sort:");

    start = clock();
    selection_sort(temp, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("%-7d / %7d / %f\n", comp, assign, cpu_time_used);
//    print_array(temp, SIZE);
//    printf("\n");
//    if (is_array_sorted(temp, SIZE) == 0){
//        printf("array is not sorted\n");
//    } else {
//        printf("array is sorted\n");
//    }
    printf("\n");

    comp = 0;
    assign = 0;
    temp = array;
    printf("%-20s", "Merge sort:");

    start = clock();
    merge_sort(temp, 0, SIZE - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("%-7d / %7d / %f\n", comp, assign, cpu_time_used);
//    print_array(temp, SIZE);
//    printf("\n");
//    if (is_array_sorted(temp, SIZE) == 0){
//        printf("array is not sorted\n");
//    } else {
//        printf("array is sorted\n");
//    }
    printf("\n");
}

void merge (int array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for(i = 0; i < n1; ++i){
        L[i] = array[l + 1];
        ++assign;
    }
    for (j = 0; j < n2; ++j){
        R[j] = array[m + 1 + j];
        ++assign;
    }

    i = 0;
    j = 0;
    k = 1;
    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            array[k] = L[i];
            ++i;
            ++assign;
        } else {
            array[k] = R[j];
            ++j;
            ++assign;
        }
        ++k;
        ++comp;
    }

    while (i < n1){
        array[k] = L[i];
        ++i;
        ++k;
        ++assign;
    }

    while(i < n2){
        array[k] = R[j];
        ++j;
        ++k;
        ++assign;
    }
}

void merge_sort (int array[], int l, int r)
{
    if(l < r){
        int m = l + (r - l) / 2;

        merge_sort(array, l, m);
        merge_sort(array, m + 1, r);

        merge(array, l, m, r);
    }
}


void selection_sort (int array[], int size)
{
    int i, j, min_idx;

    for(i = 0; i < size - 1; ++i){
        min_idx = i;
        ++assign;
        for(j = i + 1; j < size; ++j){
            if(array[j] < array[min_idx]){
                min_idx = j;
                ++assign;
            }
            swap(&array[min_idx], &array[i]);
            ++comp;
            assign += 3;
        }
    }
}


void insertion_sort (int array[], int size)
{
    int i, key, j;
    for (i = 1; i < size; ++i){
        key = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j = j - 1;
            ++comp;
            assign += 2;
        }
        array[j + 1] = key;
        ++assign;
    }
}


int partition (int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++){
        if(array[j] < pivot){
            ++i;
            swap(&array[i], &array[j]);
            ++comp;
            assign += 3;
        }
    }
    swap(&array[i + 1], &array[high]);
    ++comp;
    assign += 3;
    return(i + 1);
}

void quick_sort (int array[], int low, int high)
{
    if (low < high){
        int pi = partition(array, low, high);

        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}


void bubble_sort (int array[], int size)
{
    for(int i = 0; i < size - 1; ++i){
        for(int j = 0; j < size - i - 1; ++j){
            if(array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
                ++comp;
                assign += 3;
            }
        }
    }
}
