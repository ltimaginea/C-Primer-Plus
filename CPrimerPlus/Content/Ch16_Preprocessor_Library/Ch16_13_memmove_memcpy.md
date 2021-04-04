# ***memmove 和 memcpy***

`memcpy` 和 `memmove` 的函数原型：

```c
void* memcpy( void *restrict dest, const void *restrict src, size_t count );
void* memmove( void* dest, const void* src, size_t count );
```

这两个函数都从 src 指向的位置拷贝 count 字节到 dest 指向的位置。所不同的是，`memcpy` 的参数带关键字 `restrict` ，即 `memcpy` 假设两个内存区域之间没有重叠；而 `memmove` 不作这样的假设，所以拷贝过程类似于先把所有字节拷贝到一个临时缓冲区，然后再拷贝到最终目的地。如果使用 `memcpy` 时，两区域出现重叠会怎样？其行为是未定义的，这意味着该函数可能正常工作，也可能失败。编译器不会在本不该使用 `memcpy` 时禁止你使用，作为程序员，在使用该函数时有责任确保两个区域不重叠。 

由于这两个函数设计用于处理任何数据类型，所以它们的参数都是两个 `void *` 的指针。C允许把任何类型的指针赋给 `void *` 类型的指针。如此宽容导致函数无法知道待拷贝数据的类型。因此，这两个函数使用第3个参数指明待拷贝的字节数。注意，对数组而言，字节数一般与元素个数不同。如果要拷贝数组中10个double类型的元素，要使用10*sizeof(double)，而不是10。

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum { kSize = 10 };

int main()
{
    int values[kSize] = { 1,2,3,4,5,6,7,8,9,10 };
    int target[kSize] = { 1,2,3,4,5,6,7,8,9,10 };
    
    memmove(values + 2, values, 5 * sizeof(int));       // 含有重叠区域，应使用 memmove
    memcpy(target + 2, target, 5 * sizeof(int));        // 危险！含有重叠区域，memcpy 行为未定义

    return 0;
}
```

