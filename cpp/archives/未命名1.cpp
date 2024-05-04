#include <stdio.h>

/* 数字版指针swap() */
void swap_int_pointer(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void bubble_int_sort(int *p, int n);

int main() {
	int n;
	while (1) {

		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		int n1[1001], n2[1002];
		for (int i = 0; i < n; i++) {
			scanf("%d", &n1[i]);
		}
		for (int i = 0; i < n; i++) {
			/* code */
			scanf("%d", &n2[i]);
		}
		int count = 0;
		int draw = 0;

		bubble_int_sort(n1, n);
		bubble_int_sort(n2, n);

//		for (int i = 0; i < n; i++) {
//			printf("%d", n1[i]);
//
//		}
//		printf("\n");
		for (int i = 0; i < n; i++) {//king
			int hasEqual = 0;
			int indexOfEqual1 = 0;
			int j = 0;
			for (j; j < n; j++) {//Yuanzi
				int delta = n1[j] - n2[i];

				if (delta > 0) {
					count++;
					n1[j] = -1;
					break;
				} else if (delta == 0) {
					hasEqual++;
					if (indexOfEqual1 == 0)
						indexOfEqual1 = j;
				}
			}
			//平局/输掉
			if (j == n && hasEqual > 0) {
				printf("%d", draw);
				draw++;//平局
				n1[j] = -1;
			}
			//continue;
		}

		//考虑平局的情况才行:
		//然而,我们亲手那个实例用该粗略的算法演示一下发现,平局的情况不能轻易确定,
		//由于所有比赛情况不外乎三种,那就退一步看输掉的情况:
		if (count > (n - draw) / 2) {
			//printf("%d", count);
			printf("%s", "YES");

			/* code */
		} else {
			printf("%s", "NO");
		}
	}
}

void bubble_int_sort(int *p, int n) {
	void swap_int_pointer(int *a, int *b);
	/*冒泡法不需要设立最值flag. */
	for (int i = 0; i < n - 1; i++) {
		/*外重循环从LHS∈[0,n-2]选出一个元素;
		RHS = LHS+1 ∈ [1,n-1]
		单趟比较中:*/
		for (int j = 0; j <= n - 2 - i;
		        j++) { /*内重循环控制各趟排序的一系列比较中:控制LHS从[0,n-2-i]从0取遍n-2-i(i由外重循环弹出的表示现在是第i趟排序) */
			/*通过改变'<'为'>',可以从降序转为升序; 通过监视*(p+j)和*(p+j+1)可以知道当前(第j组)相邻量的值的情况 */
			if (*(p + j) > * (p + j + 1)) { /*或者写作if(p[j] < p[j+1])也可以*/
				swap_int_pointer(p + j, p + j + 1);
			}
		}
	}
}
