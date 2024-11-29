#include <stdio.h>

struct Data
{
    int d_int;
    float d_float;
};

#define GET_MEMBER(structure, member) structure.d_##member

int main()
{
    struct Data data1 = {42, 3.14};

    printf("Integer member: %d\n", GET_MEMBER(data1, int)); // 生成 data.data_int
    printf("Float member: %f\n", GET_MEMBER(data1, float)); // 生成 data.data_float

    return 0;
}
