    //读入不确定数目的整数:(以0为结尾)
//     int i = 0;
//     /* 初始化s[0] */
//     scanf("%d",&s[i]);
//如果用循环内部用break当然很简单.
//     for(;s[i++] != 0;)
//     {
//         scanf("%d",&s[i]);
//     }
    /* 利用指针读入二维数据 */
    while (1)
    {
        int *pq;
        int n ;
        scanf("%d",&n);
        int size_int = sizeof(int);
        pq = (int *)malloc(n * n * size_int);/* 申请二维空间 */
        /* 有需要监测结束符的读入要求,应该先考虑对结束符进行判断. */
        /* 判断是否需要停止测试/读入新数据 */
        if (scanf("%d", pq) != EOF)
        {
            /* 继续读入后续的值 */
            for (int i = 1; i < n * n; i++)
            {
                scanf("%d", pq + i);
            }
        }

        else
        {
            break;
        }
    }

   /*读入含有结束标志符的输入的方法*/
    for (i = 0;; i++)
    {
        scanf("%d", &input[i]);
        if (!input[i])
        {
            break;
        }

    }/*i-1当前数组的元素数目.*/
    num = i - 1;
    /*	第二中读入含有结束标志符的输入的方法;
        int i = 0;
        while (scanf("%d", &input[i++]) && input[i - 1]);*/