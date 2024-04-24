///*实验五 数组及其应用
//数组的特点是每个数据元素可以又是一个线性表结构。数组的特点是每个数据元素可以又是一个线性表结构；
//若一维数组中的数据元素又是一维数组结构，则称为二维数组；依次类推。
//
//本实验实现用一维数组模拟矩阵的存储，以及一些特殊矩阵的的相关应用。
//（1）实验目的
//（2）理解矩阵的存储与访问方式；
//（3）实现特殊矩阵的压缩存储；
//（4）实现稀疏矩阵的压缩存储；
//（5）针对特殊矩阵和稀疏矩阵，掌握常见矩阵操作的实现方式。
//（6）实验内容
//（7） 矩阵的实现
//目标：用一维数组模拟一个存放整型数据的矩阵，并实现其常用算法。
//（8）算法填空：根据功能提示，完善下划线处的代码。
//（9）矩阵数据类型的定义
//
//数学上的矩阵可用C语言中的二维数组表示，但为了更深入地理解二维数组的存取，
//本实验用顺序表来模拟矩阵。*/
#define _CRT_SECURE_NO_WARNINGS
#define   EMPTY_QUEUE_ERROR   -999999
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 100
typedef int ElemType;
//typedef struct {
//    int* elem; // 用来存储矩阵元素的动态数组空间：按照行优先存储
//    int row, col;
//}intMatrix;//矩阵Matrix
///*
//（10）初始化矩阵
//给定矩阵的行数和列数，对矩阵进行初始化。*/
//void  InitMatrix(intMatrix* pMat, int row, int col)
//{
//    /**********************************************************
//    设定pMat所指向矩阵的行数，列数并为之开辟元素的动态存储空间
//    *********************************************************/
//    pMat->row = row ; // 行数..
//    pMat->col = col; // 列数
//    pMat->elem = (ElemType*)malloc(sizeof(ElemType)*row*col) ; // 存储空间
//}
///*（11）矩阵赋值
//对矩阵的第i行第j列位置的元素赋值为x。
//赋值成功返回1，否则0。
//
//*/
//int  Assign(intMatrix* pMat, int i, int j, int x)
//{
//    // 判断i, j是否合法(从1计数)
//    if ((i<1 || i> pMat->row) || (j<1 || j> pMat->col))
//    {
//        printf("行或列位置非法，赋值失败\n"); return 0;
//    }
//    // 若合法，赋值。 i,j从1开始，数组存数据 从0位置开始
//    pMat->elem[pMat->col*(i - 1)+(j -1)] = x;/*elem时一维数组,这样就需要定位转换*/
//    return 1;
//}
///*（12）读取矩阵中元素值
//将矩阵的第i行第j列位置的元素赋值到x带回。成功返回1，否则0*/
//int  Get(intMatrix* pMat, int i, int j, int* x)
//{
//    // 判断i ,j是否合法
//    if ((i<1 || i> pMat->row) || (j<1 || j> pMat->col))
//    {
//        printf("行或列索引非法，赋值失败\n"); return 0;
//    }
//    // 给x赋值
//    *x = pMat->elem[pMat->col * (i - 1) + (j - 1)];
//    return 1;
//}
////（13）算法练习：根据功能提示，实现算法。
///*（14）打印输出此矩阵
//将矩阵按照 行×列 的形式输出到屏幕上。函数原型如下：
//*/
//void  PrintMatrix(intMatrix* pMat)
//{
//    for (int i = 0; i < pMat->row; i++)
//    {
//        for (int j = 0; j < pMat->col; j++)
//        {
//            printf("%d\t",pMat->elem[pMat->col * i + j]);
//        }
//        printf("\n");
//    }
//}
///*
//（15）调试
//根据上述矩阵的定义，完成下面代码，运行并调试程序。
//*/
//int main()
//{
//    // 定义一个4*5矩阵mat和一个5*4矩阵matT
//       
//    // 初始化mat矩阵，并为其每个元素赋值
//	intMatrix mat; 
//    intMatrix matT;
//    int x = 0;
//	InitMatrix(&mat, 4, 5);
//	InitMatrix(&matT, 5, 4);
//    printf("初始化mat矩阵,并测试Assign()函数:\n");
//    for (int i = 1; i <= mat.row; i++)
//    {
//        for (int j = 1; j <= mat.col; j++)
//        {
//            scanf("%d", &x);
//            Assign(&mat, i, j,x);
//        }
//        
//    }
//
//    // 打印该mat
//    printf("打印该mat,并测试PrintMatrix()函数:\n");
//    PrintMatrix(&mat);
//    // 将mat矩阵转置到matT，直接赋值填充法转置矩阵(在没有压缩原矩阵时)，
//    int temp = 0;
//    for (int i = 1; i <= matT.row; i++)
//    {
//        for (int j = 1; j <= matT.col; j++)
//        {
//            
//            Get(&mat, j, i, &temp);/*行优先读取mat的元素,将值存到temp*/
//            /*将temp赋值到matT矩阵的相应位置(行优先存放)*/
//            Assign(&matT, i, j, temp);
//        }
//
//    }
//    //并打印matT
//    printf("打印该matT:\n");
//    PrintMatrix(&matT);
//}

//（16）特殊矩阵的压缩存储
//形如对称矩阵、三角矩阵等特殊形式的矩阵，只需保存其中的部分元素即可，称为“压缩存储”。关键是建立矩阵中元素的 行列 索引与 一维数组 存储空间 索引之间的关联关系。
//（17）对称矩阵
//（18）矩阵结构体的定义
//定义一个压缩矩阵的结构体类型，用一维数组来存储矩阵中的元素。为了简单起见，令矩阵为DIM* DIM的方阵。其中，DIM为一确定的整数大小。
#define MAXLEN 100
#define DIM 4
typedef struct {
    int elem[MAXLEN];    // 用来存 特殊矩阵 里的元素的 一维数组
}intCompressedMatrix;/*压缩矩阵就是由一个矩阵压缩成一维数组,而非一般意义的矩阵*//*matrix /'meɪtrɪks/n.矩阵*/

/*（19）对称矩阵的初始化与读取
用一个对称矩阵(定义为m[DIM][DIM]) 来初始化(填充) 该压缩矩阵
压缩:*/
void  InitSMatrix(intCompressedMatrix* pMat, int m[DIM][DIM])
{
    /**********************************************************
    将存放于二维数组m中的对称矩阵下三角元素存放到pMat中
    *********************************************************/
    int index = 0;
    for (int i = 1; i <= DIM; i++) // 对每一行
        for (int j = 1; j <= i; j++) // 对每一列中的部分元素(下三角,包括对角线上的元素)
            pMat->elem[index++] = m[i - 1][j - 1];/*注意,指示行和列的视情况而定,一定要转化为从0开始计数的来访问数组元素*/
}//该函数正确.

// 读取(对称矩阵的压缩矩阵中解压出来(一次一个元素),将值保存到x中.)
//int  Get(intCompressedMatrix* pMat, int i, int j, int* x)
//{
//    // 判断i, j是否合法
//    if ((i<1 || i> DIM) || (j<1 || j> DIM))
//    {
//        printf("行或列索引非法，赋值失败\n");
//        return 0;
//    }
//
//   /*  给x赋值
//     由于只保存了i>=j的下三角，如果欲读取j>i的上三角元素，怎么读取？*/
//    if (i >= j)
//       *x = pMat->elem[(i-1) * ((i-1) + 1) / 2 + j - 1];
//    else
//       *x = pMat->elem[(j - 1) * ((j - 1) + 1) / 2 + i - 1];
//    return 1;
//}//函数已修正.

/*（20）三角矩阵的存取(重复元素集中在某一侧)("三角"分为上三角和下三角)
对三角矩阵进行压缩存储，写出与上述对称矩阵类似的 结构体和操作函数。*/
int InitSMatrix_triangle_down(intCompressedMatrix* pMat, int(*m)[DIM])
{
    int index = 1;/*index = 0 的位置保留用于存储重复的元素,一般时三角矩阵的某个顶点)*/
    for (int i = 1; i <= DIM; i++)
    {
        for (int j = 1; j <= i; j++)/*这个二重循环扫描下三角矩阵.((三角遍历)*/
        {
            pMat->elem[index++] = m[i - 1][j - 1];
            printf("%d ", pMat->elem[index-1]);
        }
        printf("\n");
    }
    pMat->elem[0] = m[0][DIM - 1];

}
/*传入原始矩阵的任意位置(i,j)*/
int Get_triangle_down(intCompressedMatrix* pMat,int i,int j,int *x)
{
    /*编写前先设计好算法:而框架则可以编码搭建*/
    /*判断要解压的元素位置是否合法*/
    if ((i<1 || i> DIM) || (j<1 || j> DIM))
    {
        printf("行或列索引非法，赋值失败\n");
        return 0;
    }
    int subscript_row = i - 1,
        subscript_col = j - 1;

    if (i >= j)
    {
        *x = pMat->elem[subscript_row * (subscript_row + 1) / 2 + subscript_col + 1];

    }
    else
    {
        *x = pMat->elem[0];
    }
    return 1;/*读取成功*/
}

/*分析上三角:(内存循环收缩左边界)*/
/*将上三角矩阵压缩到pMat矩阵(或者说一维数组)中*/
int InitSMatrix_triangle_up(intCompressedMatrix* pMat, int m2_2[][DIM])
{
    int index = 1;/*保留elem[0]*/
    /*上三角遍历*/
    for (int i = 1; i <= DIM; i++)
    {
        for (int j = i; j <= DIM; j++)
        {
            pMat->elem[index++] = m2_2[i - 1][j - 1];
            printf("%d ", pMat->elem[index-1]);
        }
        printf("\n");
    }
    pMat->elem[0] = m2_2[DIM-1][0];
}
/*解压公式:F(i,j) = (i-1)*row+j -(i-1)*((i-1) + 1) / 2;*/
/*参数变量x是原矩阵中的元素,映射F(i,j)求得的是原矩阵中(i,j)位置的元素在压缩矩阵中的下标值.*/
int Get_triangle_up(intCompressedMatrix* pMat, int i, int j, int* x)
{
    /*请求解压的位置合法性(分为行与列)*/
    if ((i<1 || i>DIM) || (j<1 || j>DIM))
    {
        printf("行或列索引非法，赋值失败\n");
        return 0;
    }
    if(i<=j)
    {
        *x = pMat->elem[(i - 1) * DIM + j - (i - 1) * i / 2];
        
    }
	else
	{
		*x = pMat->elem[0];
	}
    return 1;
}
/*
（21）对角矩阵的存取(重复元素分布在对角线两侧)(一般说明是n对角矩阵) 
对 对角矩阵进行压缩存储，写出与上述对称矩阵类似的结构体和操作函数。*/
    //对角矩阵的重复元素保存在数组的第[0]位置上.
/*对角矩阵的压缩没有涉及公式*/
int InitSMatrix_tri_diagonal(intCompressedMatrix* pMat, int(*m3)[DIM])/*diagonal /daɪ'æɡənl/ adj.对角线的, 斜的,*/
{
    /*对角遍历*/
    int index = 1;
    for (int i = 1; i <= DIM; i++)
    {
        for (int j = i - 1; j <= i+1; j++)//默认每行读取三个元素
        {
            if (j<1 || j > DIM)
            {
                continue;
            }
            pMat->elem[index++] = m3[i - 1][j - 1];/*i,j的取值控制由两重循环实现控制,到访问数组元素前,位置参量i,j都是从1开始,在访问时均减去1再访问.*/
            printf("%d ", pMat->elem[index -1]);
        }//for
        printf("\n");
    }//for
    pMat->elem[0] = m3[0][DIM - 1];
}
/*解压对三角矩阵,从elem[]数组中解压出来.(访问指定的原矩阵中的第i行,第j列位置上的元素.)
涉及两个基础公式,合并成第三个公式.:
前i-1行的元素个数:3(i-1)-1 (其中因子3是n对角矩阵n=3时的特例)
a(i,j)是第i行对角线区域的第 (j-i)+2 个元素(2是n对角矩阵n=3下的线性关系的修正因子)*/
int Get_tri_diagonal(intCompressedMatrix* pMat, int i, int j, int* x)
{
   if ((i<1 || i > DIM) || (j<1 || j > DIM))
   {
       printf("行或列索引非法，赋值失败\n");
       return 0;
   }
   if (j >= i - 1 && j <= i + 1)/*只访问对角线和他相邻的两条平行线上的元素,其余元素由else统一处理.*/
   {
       *x = pMat->elem[2*(i) + (j) - 2];//这里的公式已经时按i,j从1计数的方式计算的
   }
   else
   {
       *x = pMat->elem[0];/*重复部分的矩阵填充*/
   }
   return 1;
}

/*（22）调试
根据上述压缩矩阵定义，完成下面代码，运行并调试程序。
*/
/*填充二维数组函数fill_two_dimenssion_array(int (*arr_2)[DIM])*/
void fill_two_dimenssion_array(int(*arr_2)[DIM])
{
    printf("创建并填充二维数组:\n");
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            scanf("%d", &arr_2[i][j]);
        }
    }
}
//int main()
//{
//    int x = 0;
//	// 定义一个二维数组m1并初始化为对称矩阵形式
//    int m1[DIM][DIM] /*= {
//{1,0,0,6},
//{0,2,7,0},
//{0,7,3,8},
//{6,0,8,4}
//    }*/;//初始化而非赋值,如果不直接初始化的话,第一个乃至每个维数都不可省略;
//    int m2[DIM][DIM] /*= {
//{1,0,0,0},
//{0,2,0,0},
//{0,7,3,0},
//{6,0,8,4}
//    }*/;
//    int m2_2[DIM][DIM] /*= {
//{1,4,5,7},
//{0,2,0,3},
//{0,0,3,5},
//{0,0,0,4}
//    }*/;
//    int m3[DIM][DIM] /*= {
//{1,4,0,0},
//{4,2,9,0},
//{0,6,3,5},
//{0,0,1,4}
//    }*/;
//  
//		// 定义一个 压缩矩阵mat，并用m1初始化mat
//    intCompressedMatrix mat;/*压缩处理后的数组保存于此*/
//    printf("执行压缩处理:\n");
//   /* */
//    fill_two_dimenssion_array(m1);
//    printf("压缩对称矩阵:\n");
//    InitSMatrix(&mat, m1);
//
//    /* fill_two_dimenssion_array(m2);
//    printf("压缩三角矩阵:\n");
//    InitSMatrix_triangle_down(&mat, m2);*/
//
//    /*fill_two_dimenssion_array(m2_2);
//    printf("压缩上三角矩阵:\n");
//    InitSMatrix_triangle_up(&mat, m2_2);*/
//
//   /* fill_two_dimenssion_array(m3);
//    printf("压缩对三角矩阵:\n");
//    InitSMatrix_tri_diagonal(&mat, m3);*/
//
//    // 打印该mat
//    printf("解压并打印mat矩阵\n");
//    /*解压并打印:(全遍例)*/
//    for (int i = 1; i <= DIM; i++)
//    {
//        for (int j = 1; j <= DIM; j++)
//        {
//            /*根据mat压缩矩阵 解压*/
//            Get(&mat, i, j, &x);//对称矩阵
//           // Get_triangle_down(&mat, i, j, &x);//下三角矩阵
//            //Get_triangle_up(&mat, i,j,&x);
//            //Get_tri_diagonal(&mat, i, j, &x);
//            printf("%d ", x);
//        }
//        printf("\n");
//    }
//
//}
//（23）稀疏矩阵压缩存储
//稀疏矩阵是非零元素远少于零元素个数的矩阵，因此可用三元组形式来保存非零元素信息，即可实现压缩存储。

//（24）稀疏矩阵结构体的定义
/*定义一个三元组，用来  存储  非零元素的行、列 和 数据值。
再定义一个稀疏矩阵结构体，用来表示稀疏矩阵。*/
#define MAXNUM 40   // 假定非零元素个数不超过20个
/*矩阵中的单个元素(非零元素)的数据结构*/
typedef struct {
    int r, c, e;   // 非零元素的行、列和数据值/*从行和列1开始计数*/
}Triple;
/*稀疏矩阵整体(zheng'ti)的数据结构*/
typedef struct {
    //非零元素信息数组
   Triple elem[MAXNUM];
    //分别保存稀疏矩阵的总行数、总列数和非零元素个数
    int nrow, ncol, num;
}SparseMatrix;/*sparse /spɑːrs/ adj.稀少的, 稀疏的*/
/*（25）根据 二维数组   初始化一个稀疏矩阵结构体
二维数组中包含  少量非零元素，通过  遍历该二维数组，
将非零元素信息填入稀疏矩阵 结构体中。为简化起见，假定二维数组为 六行七列。
*/
#define ROWS 6
#define COLS 7
void BuildSparseMatrix(int m[ROWS][COLS], SparseMatrix* pSM)
{
    int i, j, n = 0;  // 用于统计非零元素个数

    // 遍历该二维数组
    for (i = 0;i<ROWS;i++)
        for (j = 0;j<COLS;j++)
        {
            // 如果找到非零元素
            if (m[i][j])
            {
                // 保存非零元素信息到相应位置的三元组中
                pSM->elem[n].r = i+1;
                pSM->elem[n].c = j+1;
                pSM->elem[n].e = m[i][j];
                ++n;
            }
        }

    // 分别保存稀疏矩阵的总行数、总列数和非零元素个数	  
    pSM->nrow = ROWS;
    pSM->ncol = COLS;
    pSM->num = n;
}
/*（26）输出稀疏矩阵(
(根据(gen'ju)稀疏矩阵压缩结构体,解压出原矩阵中(r,c)位置的元素)将三元组形式的稀疏矩阵按照二维数组的形式输出。*/
int Get(SparseMatrix* pSM, int r, int c)
{
    /**********************************************************
     从稀疏矩阵中得到第r行c列元素的值
 *********************************************************/
    int i = 0;
    /*遍历查找的过程:*/
    // 遍历该稀疏矩阵的三元组数组
    for (; i < pSM->num; i++)
    {
        // 若找到第r行第c列的非零值，则返回该值
        if (pSM->elem[i].r == r && pSM->elem[i].c == c)
            return pSM->elem[i].e;
    }

    // 若没有找到第r行第c列的数据，则必然是0
    return 0;
}

void PrintSMatrix(SparseMatrix* pSM)
{
    int  i, j;
    /*全遍历*/
    for (i = 1; i <= pSM->nrow; i++)
    {
        for (j = 1; j <= pSM->ncol; j++)
            printf("%d\t",Get(pSM,i,j)); // 输出第i行第j列元素的值(在主函数之外调用 &参数是愚蠢的.(定以复合函数时,内部函数的指针参数不要&比如:错误的Get(&pSM,i,j))
        printf("\n");
    }
}
/*（27）稀疏矩阵的转置
(快速转置)：
引入了两个辅助的存储空间starting_pos和row_terms将A转置为B。

其中 数组row_terms中存放的是  各行 非零元素的 个数，
数组starting_pos用来存储  转置后的矩阵 每行非零元素的 起始地址。*/
void Translate3(SparseMatrix* pMatA, SparseMatrix* pMatB)
{
    int i;
    // 定义两个辅助数组;从0开始计数.
    int row_terms[COLS], /*数组row_terms中存放的是  各行 非零元素的 个数*/
        starting_pos[COLS];/*用来存储  转置后的矩阵 每行非零元素的 起始地址(在三元组数组中)
                           同时该数组的每个元素都可视作一个计数器*/

    // 转置后，行列值交换，但非零元素个数不变
    pMatB->ncol = pMatA->nrow;
    pMatB->nrow = pMatA->ncol;
    pMatB->num = pMatA->num;

    // 统计转置后每行元素个数

    // 首先将每行元素  个数置零
    for (i = 0; i < pMatB->nrow; i++)
        row_terms[i] = 0;

    //遍历 一遍矩阵A中的 非零值信息，计算转置之后每行非零元素个数
    /*核心步骤1(用数组row_terms[]巧妙地统计矩阵A中各列非零元素的个数(同时也是矩阵B各行的非0元素的个数.)
    这种根据元素的信息填充/增加计数到对应列(对矩阵B来说是行)的方式
    比根据位置判断其上的元素(是否为0)一般都要要来的高效.*/
    for (i = 0; i < pMatA->num; i++)/*从三元组列表中无空洞查找(遍历非0元素)*/
        row_terms[pMatA->elem[i].c - 1]++;
    /*其中:  pMatA->elem[i].c (是矩阵A的非零元素信息数组中第i个元素的所在列号,随着i的增长,这个表达式(记为k)的值的取值将落在 1,2,...pMatA->ncol 以内(且可以重复);*/
  
     /*核心步骤2*/
    /* 计算转置之后 每一行(各行在非零元素数组中)起始写入位置
     第1行的写入位置也在数组的0号位置  */
    starting_pos[0] = 0;
    /* 从第2行开始， 第i行的写入位置是 (第i-1行的起始写入位置+第i-1 行的非零元素个数)
    迭代过程:(初始化/准备起点+迭代公式)*/
    for (i = 1; i < pMatA->ncol; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

    
    /*核心步骤3*/// 有了两个辅助数组，再次扫描A
    for (i = 0; i < pMatA->num; i++)
    {
        // A中的第i个非零值转置之后为B的第几行？从starting_pos 中找到第几行的起始写入位置
        pMatB->elem[starting_pos[pMatA->elem[i].c - 1]].r = pMatA->elem[i].c;/*pMatA->elem[i].c,(不妨将该表达式记为k)即A中的第i个非零元素的所在列号,也是该元素(pMatA->elem[i])要填充在矩阵B的所在行的行号
                                           再找到矩阵B中第k行的 起始位置:starting_pos[k],每填充一个,位置后移一也就是说,起始位置starting_pos[k]是要不断迭代的
                                           注意k没有变,变的是整体(starting_pos[k])这一变量*/
        pMatB->elem[starting_pos[pMatA->elem[i].c - 1]].c = pMatA->elem[i].r;
         
        pMatB->elem[starting_pos[pMatA->elem[i].c - 1]].e = pMatA->elem[i].e;

        // B中的第几行写入数据后， starting_pos中相应行的写入位置 后移一位
        starting_pos[pMatA->elem[i].c - 1]  ++;/*rting_pos[pMatA->elem[i].c - 1] 是一个整数,用以指示数组下标(引导填充位置)*/
    }
}
/*（28）稀疏矩阵相加
试根据函数原型，写出稀疏矩阵C = A + B的函数。*/
void Add(SparseMatrix* pMatA, SparseMatrix* pMatB, SparseMatrix* pMatC)
{
    int index = 0;
    int x1 = 0,
        x2 = 0;
    for (int i = 1; i <= pMatA->nrow; i++)
    {
        for (int j = 1; j <= pMatB->ncol; j++)
        {
            x1 = Get(pMatA, i, j);
            x2 = Get(pMatB, i, j);
            if (x1 || x2)//这里的Get(又多写了&);注意短路问题呀:(x1 = Get(pMatA, i, j)) || (x2 = Get(pMatB, i, j))一旦前部非0,后部x2就无法获得更新/计算
            {
                /*三元组必须同时更改*/
                pMatC->elem[index].e = x1 + x2;/*重新压缩的策略*/
                pMatC->elem[index].r = i;/*i,j,r,c,均是从1开始计数*/
                pMatC->elem[index].c = j;
                index++;
            }
           /* if(pMatA->)
            pMatC->elem[index++] += pMatB->elem[j];*/
        }
           
    }
    /*勿忘修改矩阵总体信息(规格,方便打印)建议放在函数头部:*/
    pMatC->ncol = pMatA->ncol;
    pMatC->nrow = pMatA->nrow;
    pMatC->num = index -1;
    //index = 0;
    
}
/*（29）稀疏矩阵相乘
注意先明确操作函数的参数对象要求:矩阵规格必须分别是:a*k以及k*b,结果矩阵规格为a*b(计算每个C中的元素,都是一个k项式之和)
    矩阵先后顺序不可掉换.
试根据函数原型，写出稀疏矩阵C = A * B的函数。*/
void Mul(SparseMatrix* pMatA, SparseMatrix* pMatB, SparseMatrix* pMatC)
{
    /*处理矩阵C的统计信息*/
    pMatC->nrow = pMatA->nrow;
    pMatC->ncol = pMatB->ncol;
    int x1,
        x2;
    int index = 0;
    int temp_s = 0;
    /*根据位置填值*/
    for (int i = 0; i < pMatA->nrow; i++)
    {
        for (int j = 0; j < pMatB->ncol; j++)
		{
            /*填充单个元素(求矩阵C的(i,j)位置上的元素值,并将非零元素的行列信息一并保存到三元组表中*/
            temp_s = 0;
			for (int k = 1; k <= pMatA->ncol; k++)
			{
                temp_s += (Get(pMatA, i, k) * Get(pMatB, k, j));
                if (temp_s)
                {
                    pMatC->elem[index].e = temp_s;
                    pMatC->elem[index].r = i;
                    pMatC->elem[index].c = j;
                    index++;

                }
				

			}
			
		}
    }

    pMatC->num = index - 1;

}
/*（30）调试
根据上述稀疏矩阵定义，，完成下面代码，运行并调试程序。*/
void fill_two_dimenssion_array_2(int(*arr_2)[COLS])
{
    printf("创建并填充二维数组:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            scanf("%d", &arr_2[i][j]);
        }
    }
}
int main()
{
    // 定义两个二维数组a和b，用少量 非零值 初始化a和b
    int a[ROWS][COLS],
        b[ROWS][COLS];
    fill_two_dimenssion_array_2(a);
    fill_two_dimenssion_array_2(b);
    //定义两个三元组形式稀疏矩阵mat1和mat2，分别用a和b初始化
    SparseMatrix
        mat1,
        mat2,
        mat3,
        mat4;
    /*一般的,矩阵mat1,mat2本身不受二维数组a,b规格的影响
    但矩阵mat_i中元素对以矩阵mat_i为参数的函数来说有影响*/
    BuildSparseMatrix(a, &mat1);
    BuildSparseMatrix(b, &mat2);
    //输出mat1和mat2
    /**/
    printf("输出mat1:\n");
    PrintSMatrix(&mat1);
    printf("输出mat2:\n");
    PrintSMatrix(&mat2);


    /**/
    // 定义三元组形式稀疏矩阵mat3， 计算mat3=mat1+mat2
       //输出mat3
    printf("测试Add(&mat1, &mat2, &mat3),并输出mat3:\n");
    Add(&mat1, &mat2, &mat3);
   /* */
    PrintSMatrix(&mat3);
    // 将mat3转置到mat2
    printf("测试Translate3(&mat3, &mat2):将mat3转置到mat2:\n");
    Translate3(&mat3, &mat2);
    //输出mat2
   /* */printf("输出矩阵转置结果(新)mat2:\n");
    PrintSMatrix(&mat2);
    
   // 定义三元组形式稀疏矩阵mat4， 计算mat4=mat1 * mat2
    printf("测试Mul(&mat1, &mat2, &mat4);并输出矩阵mat4:\n");
    Mul(&mat1, &mat2, &mat4);
       //输出mat4
   
    PrintSMatrix(&mat4);

}

