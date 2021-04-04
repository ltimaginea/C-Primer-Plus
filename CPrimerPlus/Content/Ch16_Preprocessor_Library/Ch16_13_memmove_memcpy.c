#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum { kSize = 10 };

void ShowArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int values[kSize] = { 1,2,3,4,5,6,7,8,9,10 };
    int target[kSize];

    puts("values (original data): ");
    ShowArray(values, kSize);
    memcpy(target, values, kSize * sizeof(int));
    puts("target (copy of values): ");
    ShowArray(target, kSize);

    puts("\nUsing memmove() with overlapping ranges: ");
    memmove(values + 2, values, 5 * sizeof(int));       // 含有重叠区域，应使用 memmove
    ShowArray(values, kSize);

    puts("\nUsing memcpy() with overlapping ranges: ");
    memcpy(target + 2, target, 5 * sizeof(int));        // 错误！含有重叠区域，memcpy 行为未定义
    ShowArray(target, kSize);

    return 0;
}
