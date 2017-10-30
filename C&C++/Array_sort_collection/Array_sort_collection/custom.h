//Copyright 2016 Fyf and Xjw. All Rights Reserved.
/*Array_sort_collection*/

//常数宏定义
#define MAX_NUM 10000000  //数组每个元素值最大值
#define MAX_BIT 10000000  //数组元素个数上限

//变量标识符定义
typedef int Number;//声明数组元素值变量的标识符
typedef int BitNum;//声明数组元素个数变量的标识符
typedef int Counter;


//Bubble_sort.c
void Bubble_sort(Number *array, BitNum n);

void Bubble_sort_dual_1(Number *array, BitNum n);

void Bubble_sort_dual_2(Number *array, BitNum n);


//Count_sort.c
void Count_sort(Number *array, BitNum n);


//Heap_sort.c
void Heap_sort(Number *array, BitNum n);


//Insert_sort.c
void Insert_sort_1(Number *array, BitNum n);

void Insert_sort_2(Number *array, BitNum n);


//Merge_sort.c
void Merge_sort_iteration(Number *array, BitNum n);

void Merge_sort_recursion(Number *array, BitNum n);


//Quick_sort.c
void Quick_sort_1(Number *array, BitNum n);

void Quick_sort_2(Number *array, BitNum n);


//Select_sort.c
void Select_sort_1(Number *array, BitNum n);

void Select_sort_2(Number *array, BitNum n);


//Shell_sort.c
void Shell_sort_1(Number *array, BitNum n);

void Shell_sort_2(Number *array, BitNum n);


//tool.c
void PrintArray(Number *array, BitNum n, int flag);

Number* getRandomArray(BitNum n, Number maximun);

BitNum verify(Number *array, BitNum n);