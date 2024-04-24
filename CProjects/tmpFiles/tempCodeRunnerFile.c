void merge(int r[], int tmpArray[], 
	int leftPos, /*第一部分序列的开头;(结尾尾rightPos-1)*/
	int rightPos, /*第二部分序列的开头*/
	int rightEnd)/*第而部分序列的结尾*/
{
	/*数组A存放在r[leftPos ~ rightPos-1]，     
		 数组B存放在r[rightPos ~ rightEnd]。*/
	int i = leftPos,
		j = rightPos,
		k;/*指示写在tmpArray[]索引k处*/
		//l;/*可用于将有剩余部分的序列循环复制到tmpArray[]里*/

	k = leftPos;
	for (; i <= rightPos-1/*j-1 和 辅助遍历混淆就糟糕了*/ && j <= rightEnd;)/*j只是被初始化为rightPos,但难以保持不变,要写实参*/
	{
		if (r[i] < r[j])
		{
			tmpArray[k] = r[i++];
		}
		else
		{
			tmpArray[k] = r[j++];
		}
		k++;
	}
}