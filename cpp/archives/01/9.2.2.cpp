//program 9.2.2.cpp �ǵݹ�⺺ŵ������
#include <iostream>
using namespace std;
struct Problem 
{
	int n;
	char src,mid,dest;
}; //һ��Problem��������һ�������⣬��src�ϵ�n�����ӣ���midΪ�н飬�ƶ���dest
Problem stack[200]; //����ģ���ŷ�ѵ�ջ��һ��Ԫ�ش���һ���ŷ�
                    //����n�����ӣ���ջ�ĸ߶Ȳ����� n * 3 
int main()
{
	cin >> stack[1].n;
	stack[1].src = 'A';
	stack[1].mid = 'B';
	stack[1].dest = 'C'; //�����ʼ���˵�һ���ŷ�
	int problemNum = 1;  //�൱�������ŷ���Ŀ
	while( problemNum > 0) { //ֻҪ�����ŷ⣬�ͼ�������
		Problem curProblem = stack[problemNum--]; //ȡ��������ŷ⣬����ǰ����
                                                    //problemNum-- �൱�ڶ���һ���ŷ�
		if( curProblem.n == 1 ) 
			cout << curProblem.src << "->" << curProblem.dest << endl ;
		else { //�ֽ�������
			//�Ȱѷֽ�õ��ĵ�3�����������ջ��
			stack[++problemNum].n = curProblem.n - 1;
			stack[problemNum].src = curProblem.mid;
			stack[problemNum].mid = curProblem.src;
			stack[problemNum].dest = curProblem.dest;
			//�ٰѵ�2�����������ջ��
			stack[++problemNum].n = 1;
			stack[problemNum].src = curProblem.src;
			stack[problemNum].mid = curProblem.mid;
			stack[problemNum].dest = curProblem.dest;
			//���ŵ�1�������⣬�����ջ���������ȱ�����
			stack[++problemNum].n = curProblem.n - 1; 					
			stack[problemNum].src = curProblem.src;
			stack[problemNum].mid = curProblem.dest;
			stack[problemNum].dest = curProblem.mid;
		}
	}
	return 0;
}

