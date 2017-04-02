#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> 
#include <mcheck.h> 

int main()
{  
	setenv("MALLOC_TRACE", "output", 1);  /* 环境变量MALLOC_TRACE为记录文件路径,存放内存分配信息 */
	mtrace();  
   
	char * text = (char *)malloc(sizeof(char)*100);  
	memset(text, 0, 100);  
	memcpy(text, "hello,world!", 12);  
   
	printf("%s/n",text);  
	
	unsetenv("MALLOC_TRACE");
	
	return 0;  
} 

/*
mtrace的原理是记录每一对malloc-free的执行，若每一个malloc都有相应的free，则代表没有内存泄露；
对于任何非malloc/free情況下所发生的内存泄露问题，mtrace并不能找出来。
使用方式：mtrace app(可执行文件名称) output(记录文件)
*/
 
