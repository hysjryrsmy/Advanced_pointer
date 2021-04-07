#define _CRT_SECURE_NO_WARING
#include <stdio.h>


//数组参数



/*
// 一维数组传参
void test(int arr[])  //没有问题
{}
void test(int arr[10]) //没有问题
{}
void test(int *arr)  //没有问题
{}
void test2(int *arr[20]) //没有问题，里面的20也可以省略
{}
void test2(int **arr)  //没有问题
{}
int main()
{
	int arr[10] = { 0 };
	int* arr2[20] = { 0 };
	test(arr);
	test2(arr2);
}
*/




//二维数组传参
/*
void test(int arr[3][5])
{}
void test1(int arr[][5]) //行可以省略，列不能省略
{}
//void test2(int arr[3][]) //错的


int main()
{
	int arr[3][5] = { 0 };
	test(arr); //二维数组传参
	return 0;
}
*/

void test(int *arr) //err
{}
void test1(int **arr) //err
{}
void test2(int* arr[5]) //err
{}
void test3(int (*arr)[5]) //正确
{}

int main()
{
	int arr[3][5] = { 0 };

	test(arr);  //二维数组传参
	test1(arr);
	test2(arr);
	test3(arr);

	return 0;
}