/****************找缺失整数算法*************************/
/*场景一:
	有一无序整数数组N(本场景假设为99), 数值在[1,99],缺失一个正整数，
	找出该数，使得算法最优
*/

/*方法:
	求sum(1,100)，然后依次减数组元素，最后值为缺失整数
*/

int findLostInteger(int *arr, int N)
{
	int sum = N<<1 + (N+1)<<1;
	for(int i=0; i<N; ++i)
	{
		sum -= arr[i];
	}
	return sum;
}

int findLostInteger(vector<int> &v)
{
	size_t len = v.size();
	int ret=0;
	for(int i=0; i<len; ++i)
	{
		ret ^= i;
		ret ^= n[i]-1;
	}
	return (ret^len)+1;
}

/*场景二:
	有一长度为N的数组，范围[1,100]，其中99个整数出现偶次数，1个整数出现奇次数，
	找出该整数
*/

/*方法：
	将该数组所有值进行异或运算(0^1 = 1, 0^0 = 0, 1^1 = 0)，最后值为求取值
*/

int findOddInteger(int *arr, int N)
{
	int result = 0;
	for(int i=0; i<N; ++i)
		result ^= arr[i];
	return result;
}

/*场景三：
	一个无序数组里有若干个正整数,范围从1到100， 其中98个整数都出现了偶数次，只有两个整数出现奇数次，
	找到出现奇数次的整数
*/
/*方法:
	两个整数出现奇数次，则数组异或结果必然至少有一个二进制位是1，按照其中一个二进制为1的位对数组分组，
	两个奇数次整数必然出现在不同分组
*/
void findOddInteger(int *arr, int N)
{
	int result1 = 0, result2 = 0, res=0;
	//两个出现奇数次整数异或结果
	for(int i=0; i<N; ++i)
		result1 ^= arr[i];
	
	res = 0x01;
	while(!result1&res)
		res << 1;
	
	result1=0;
	for(int i=0; i<N; ++i)
	{
		if(arr[i] & res)
			result1 ^= arr[i];
		else
			result2 ^= arr[i];
	}
	cout << result1 << ' ' << result2;
}