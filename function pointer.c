#define _CRT_SECURE_NO_WARING
#include <stdio.h>



//函数指针 - 是指向函数的指针
//数组指针 - 是指向数组的指针
//数组包含的元素类型
//指针指向对象的类型 
//函数返回的类型

/*
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int main()
{
	int a = 10;
	int b = 20;
	//int arr[10] = { 0 };
	//int(*p)[10] = &arr;
	//printf("%d\n", Add(a, b));
	
	//  &函数名 和 函数名都是函数的地址
//	printf("%p\n", &Add);
//	printf("%p\n", Add);
	int (*pa)(int, int) = Add;
	printf("%d\n", (*pa)(2, 3));
	return 0;
}
*/

/*
void Print(char* str)
{
	printf("%s\n", str);
}

int main()
{
	int a;
	int* pa;
	void(*p)(char*) = Print;
	(*p)("hello bit");
	p("hello bit");//一样的
}
*/


//当计算机启动时，硬件将调用首地址为0位置的子例程，为了模拟开机启动时的情形，设计一个C语句，以显示调用该子例程。
//(*(void(*) ())0) (); 把0强制类型转换成：void(*)()函数指针类型 - 0就是一个函数的地址；调用0地址处的该函数

//void(*signal(int, void(*)(int)))(int);
//void(*)(int):函数指针类型
// signal是一个函数声明
// signal函数的参数有2个，第一个是int，第二个是函数指针，该函数指针指向的函数的参数是int，返回类型是void
// signal函数的返回类型也是一个函数指针：该函数指针指向的函数的参数是int，返回类型void
// typedef unsigned int uint;
// 简化
// typedef void (*pfun_t)(int);
// pfun_t signal(int, pfun_t);
// 

/*
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int main()
{
	int a = 10;
	int b = 20;
	
	int (*pa)(int, int) = Add;
	printf("%d\n", Add(2, 3));
	printf("%d\n", pa(2, 3));
	printf("%d\n", (*pa)(2, 3));
	printf("%d\n", (**pa)(2, 3));
	printf("%d\n", (***pa)(2, 3));
	return 0;
}//输出结果都是：5
*/


/*
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int Sub(int x, int y)
{
	int z = 0;
	z = x - y;
	return z;
}
int Mul(int x, int y)
{
	int z = 0;
	z = x * y;
	return z;
}
int Div(int x, int y)
{
	int z = 0;
	z = x / y;
	return z;
}

int main()
{
	//指针数组
	//int*arr[5]
	//需要一个数组，这个数组可以存放4个函数的地址 - 函数指针的数组
	//
	int (*pa)(int, int) = Add; //Sub/Mul/Div
	int(*parr[4])(int, int) = { Add,Sub,Mul,Div }; //函数指针的数组

	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", parr[i](2, 3)); 
	}
	return 0;
}
*/


//函数指针数组： int(*parr1[10])();
//函数指针数组的用途：转移表

char* my_strcpy(char* dest, const char* src);
//1.写一个函数指针pf，能够指向my_strcpy
// char* (*pf)(char*, const char*);
// 2.写一个函数指针数组 pfArr，能够存放4个my_strcpy函数的地址
//char*(*pfArr[4])(char*, const char*);



/*
//计算器
void menu()
{
	printf("*******************************\n");
	printf("****   1. add      2.sub   ****\n");
	printf("****   3. mul      4.div   ****\n");
	printf("****         0.exit        ****\n");
	printf("*******************************\n");
}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf_s("%d", &input);
		
		switch (input)
		{
		case 1:
			printf("请输入两个操作数：>");
			scanf_s("%d%d", &x, &y);
			printf("%d\n", Add(x, y));
			break;
		case 2:
			printf("请输入两个操作数：>");
			scanf_s("%d%d", &x, &y);
			printf("%d\n", Sub(x, y));
			break;
		case 3:
			printf("请输入两个操作数：>");
			scanf_s("%d%d", &x, &y);
			printf("%d\n", Mul(x, y));
			break;
		case 4:
			printf("请输入两个操作数：>");
			scanf_s("%d%d", &x, &y);
			printf("%d\n", Div(x, y));
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
*/



//回调函数
//是一个通过函数指针调用的函数
//简写上面的代码

/*
void menu()
{
	printf("*******************************\n");
	printf("****   1. add      2.sub   ****\n");
	printf("****   3. mul      4.div   ****\n");
	printf("****         0.exit        ****\n");
	printf("*******************************\n");
}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

void Calc(int(*pf)(int, int))
{
	int x = 0;
	int y = 0;
	printf("请输入两个操作数：>");
	scanf_s("%d%d", &x, &y);
	printf("%d\n", pf(x, y));
}

int main()
{
	int input = 0;
	
	do
	{
		menu();
		printf("请选择：>");
		scanf_s("%d", &input);

		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
*/


/*
//简便方法
void menu()
{
	printf("*******************************\n");
	printf("****   1. add      2.sub   ****\n");
	printf("****   3. mul      4.div   ****\n");
	printf("****         0.exit        ****\n");
	printf("*******************************\n");
}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	//pfArr是一个函数指针数组
	int(*pfArr[5])(int,int) = { 0,Add,Sub,Mul,Div };
	do
	{
		menu();
		printf("请选择：>");
		scanf_s("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入两个操作数：>");
			scanf_s("%d%d", &x, &y);
			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出\n");
		}
		else
		{
			printf("选择错误\n");
		}
	} while (input);
	return 0;
}
*/



//指向函数指针数组的指针： 指向函数指针数组的指针是一个指针， 指针指向一个数组，数组的元素都是函数指针；
//
//
//

int main()
{
	int arr[10] = { 0 };
	int(*p)[10] = &arr; //取出数组的地址

	int (*pfArr[4])(int, int); //pfArr是一个数组——函数指针的数组
	//ppfArr是一个指向【函数指针数组】的指针
	int(*(*ppfArr)[4])(int, int) = &pfArr; 
	//
	//ppfArr是一个数组指针，指针指向的数组有4个元素
	//指向的数组的每个元素的类型是一个函数指针int(*)(int,int)

	return 0;
}





//回调函数
//是一个通过函数指针调用的函数
//如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。 
// 回调函数不是由该函数的是现房直接调用，而是在特定的时间或条件发生时由另外的一方调用的，用于对该事件或条件进行相应
/*
void print(char* str)
{
	printf("hehe:%s", str);
}

void test(void(*p)(char*))
{
	print("test\n");
	p("bit");
}

int main()
{
	test(print);
	return 0;
}*/

void BubbleSort(int arr[], int sz)
{
	//...
}

//qsort - 可以排序任意类型的数据

int main()
{
	//冒泡排序函数
	//冒泡排序函数只能排序整形数组
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);

	return 0;
}