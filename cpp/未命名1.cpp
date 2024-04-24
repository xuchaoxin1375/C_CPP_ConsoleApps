#include <stdio.h>

/* ���ְ�ָ��swap() */
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
			//ƽ��/���
			if (j == n && hasEqual > 0) {
				printf("%d", draw);
				draw++;//ƽ��
				n1[j] = -1;
			}
			//continue;
		}

		//����ƽ�ֵ��������:
		//Ȼ��,���������Ǹ�ʵ���øô��Ե��㷨��ʾһ�·���,ƽ�ֵ������������ȷ��,
		//�������б���������������,�Ǿ���һ������������:
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
	/*ð�ݷ�����Ҫ������ֵflag. */
	for (int i = 0; i < n - 1; i++) {
		/*����ѭ����LHS��[0,n-2]ѡ��һ��Ԫ��;
		RHS = LHS+1 �� [1,n-1]
		���˱Ƚ���:*/
		for (int j = 0; j <= n - 2 - i;
		        j++) { /*����ѭ�����Ƹ��������һϵ�бȽ���:����LHS��[0,n-2-i]��0ȡ��n-2-i(i������ѭ�������ı�ʾ�����ǵ�i������) */
			/*ͨ���ı�'<'Ϊ'>',���Դӽ���תΪ����; ͨ������*(p+j)��*(p+j+1)����֪����ǰ(��j��)��������ֵ����� */
			if (*(p + j) > * (p + j + 1)) { /*����д��if(p[j] < p[j+1])Ҳ����*/
				swap_int_pointer(p + j, p + j + 1);
			}
		}
	}
}
