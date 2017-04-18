#include <iostream>
void Josephproblem(int *arr, int pNum, int outNum)
{

	int tNum = pNum;
	int outFlag = 0;
	int i= 0;
	while(tNum >1)
	{
		if(arr[i] == 0)
			++outFlag;
		if(outFlag == outNum)
		{
			printf("out peple is : %d\n", i+1);
			arr[i] = 1;
			tNum--;
			outFlag= 0;
		}
		i++;
		if(i == pNum)
			i= 0;	
	}
	for(i = 0; i< pNum;i++)
		if(arr[i] == 0)
		{
			printf("service peple is %d", i+1);
			break;
		}
}

int main(void)
{
	
	return o;
}

