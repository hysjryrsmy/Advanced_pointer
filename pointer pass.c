#define _CRT_SECURE_NO_WARING
#include <stdio.h>


//指针传参


/*
//一级指针传参
void print(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d\n", *(p + i));
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//一级指针p， 传给函数
	print(p, sz);

	return 0;
}
*/

/*
void test1(int* p)
{}
void test2(char* p)
{}

int mian()
{
	int a = 10;
	int* p1 = &a;
	test1(&a);  //ok
	test1(p1);  //ok

	char ch = 'w';
	char* pc = &ch;
	test2(&ch); //ok
	test2(pc);  //ok
	return 0;
}
*/


//二级指针传参
/*
void test(int** ptr)
{
	printf("%num = %d\n", **ptr);
}

int main()
{
	int n = 10;
	int* p = &n;
	int** pp = *&p;
	test(pp);
	test(&p);

	int*arr[10];
	test(arr);  //指针数组也可以
	return 0;
}
*/
