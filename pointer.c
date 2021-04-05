
//字符指针
//指针就是个变量，用来存放地址，地址唯一标识一块内存空间
//指针的大小是固定的4/8个字节（32位平台/64位平台）
//指针是有类型，指针的类型决定了指针的+-整数的步长，指针解引用操作的时候的权限
//指针的运算
//字符指针 ：char*


#define _CRT_SECURE_NO_WARING
#include <stdio.h>

/*
void test(int arr[])
{
	int sz = sizeof(arr) / sizeof(arr[0]);//32位平台4个字节/整形数组的大小也是4 = 1
	printf("%d\n", sz);
}

int main()
{
	int arr[10] = { 0 };
	test(arr);
	return 0;
}
*/




//字符指针
//
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch; //字符指针是一个指针变量，用来存放指针的地址
//	return 0;
//}

//另一种使用方法：
//int main()
//{
//	char* p = "hello bit.";//"hello bit."是一个常量字符串
//	printf("%c\n",*p); //存的是首字母的地址
//	printf("%s\n", p);
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	char* pc = arr;
//	printf("%s\n", arr);
//	printf("%s\n", pc);
//	return 0;
//}

//int main()
//{
//	// char* p = "abcdef"; //"abcdef"是一个常量字符串
//	//*p = 'W';
//	const char* p = "abcdef";
//	printf("%s\n", p);
//	return 0;
//}




//面试题
int main()
{
	char str1[] = "helo bit."; //指的是首地址； 字符串常量池只能存在一个，地址一样
	char str2[] = "helo bit.";
	const char *str3 = "helo bit.";   //加上const更加规范
	const char *str4 = "helo bit."; 

	//char* str3 = "helo bit.";  //常量字符串； 常量字符串存放在某个区域是不允许修改的
	//char* str4 = "helo bit."; //只存了一份

	if (str1 == str2)  //
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	
	if (str3 == str4)  //
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");

	return 0;
}