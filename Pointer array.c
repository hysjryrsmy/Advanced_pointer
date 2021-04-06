#define _CRT_SECURE_NO_WARING
#include <stdio.h>

//指针数组:是一个存放指针的数组


//int main()
//{
//	int arr[10] = { 0 };  //整形数组
//	char ch[5] = { 0 };   //字符数组
//	int* parr[4]; //存放整形指针的数组 - 指针数组
//	char* pch[5]; //存放字符指针的数组 - 指针数组
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	int* arr[4] = { &a, &b, &c, &d };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", *(arr[i]));
//	}
//	return 0;
//}




//常用的用法
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };  //数组名就是首元素地址
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}




//数组指针 -> 指针    ：能够指向数组的指针

/*
int main()
{
	//int* p = NULL;   //p数整形指针 - 指向整形的指针 - 可以存放整形的地址
	//char* pc = NULL; //pc是字符指针 - 指向字符的指针 - 可以存放字符的地址
	//				 //数组指针 - 指向数组的指针 - 存放数组的地址
	//int arr[10] = { 0 };
	//arr - 首元素地址
	//&arr[0] - 首元素的地址
	//&arr - 数组的地址
	
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*p)[10] = &arr;  //数组的地址要存起来
	//上面的p就是数组指针

	return 0;
}
*/
/*
int main()
{
	char* arr[5];
	char*(*pa)[5] = &arr;
	//pa指向的数组是5个元素的
	//pa指向的数组的元素类型是char*

	int arr2[10] = { 0 };
	int(*pa2)[10] = &arr;
	return 0;
}
*/


//&数组名 和数组名的比较
// int arr[10];  arr是数组名：表示数组首元素的地址
//&arr表示的是数组的地址，而不是数组首元素的地址
//数组的地址+1,跳过整个数组的大小； &arr+1相当于&arr的差值是40



/*
//参数是数组的形式
void print1(int arr[3][5], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//参数是指针的形式
void print2(int(*p)[5], int x, int y)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			printf("%d ", p[i][j]);
			//printf("%d ", *(p[i] + j));
			//printf("%d ", *(*(p + i) + j));
			//printf("%d ", (*(p + i))[j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	//print1(arr, 3, 5); //arr - 数组名 - 数组名就是首元素地址 但是二维数组的首元素是二维数组的第一行
	print2(arr, 3, 5);   //这里传递的arr，其实相当于第一行的地址，以一维数组的地址； 可以数组指针来接受

	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int i = 0;
	//int* p = arr;
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", p[i]);
		//printf("%d ", *(p + i));
		//printf("%d ", *(arr + i));
		//printf("%d ", arr[i]);  //arr[i] == *(arr+i) == *(p+i) == p[i]
	//}

	return 0;
}
*/



int arr[5];            //arr是一个5个元素的整形数组
int* parr1[10];       //parr1是一个数组，数组有10个元素，每个元素的类型是int* ， parr1是指针数组
int(*parr2)[10];      //parr2是一个指针，该指针指向了一个数组，数组10个元素，每个元素类型是int， parr2是数组指针
int(*parr3[10])[5];   //parr3是一个数组，该数组有10个元素，每个元素是一个数组指针，该数组指针指向的数组有5个元素，每个元素是int
