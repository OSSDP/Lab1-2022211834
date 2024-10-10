
#include<iostream>
#include<algorithm>
#define INF 0x3F3F3F3F
//first change
using namespace std;
const int N = 1000;
int f[N], d[N], t[N], q[N][N];
int m[N][N];
int n, h,a=0, z, sum = 0, sum2 = 0;
int main()
{
	int ans = 0;
	int num1 = 1;
	cin >> n;
	cin >> z;
	h = z * 60;
	for (int i = 1; i <= n; i++)cin >> f[i];
	//q[i][j]表示第i个池塘第j次钓到的鱼
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
		if (d[i] > 0) {
			num1 = 0;
			while (num1 * d[i] < f[i])
			{
				q[i][0] = 0;//数组没初始化的话，值也不是默认为零
				q[i][num1+1] = f[i] - num1 * d[i];
				num1++;
			}
			
		}
		else for (int j = 1; j <= N; j++)q[i][j] = f[i];
	};
	for (int i = 1; i < n; i++)  cin >> t[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			m[i][j] = -INF;
	m[1][0] = 0;
	for (int i = 1; i <= n; i++) {
		sum += t[i - 1]*5;
		for (int j = h; j >= sum; j--) {
			m[i][j] = m[i - 1][j - 5 * t[i - 1]];
			for (int k = 0; k+sum <= j; k=k+5)
			{
				sum2 = 0;
				for (int l = 0; l <= k / 5; l++) sum2 += q[i][l];
				m[i][j] = max(m[i ][j], m[i - 1][j - 5 * t[i-1] - k] + sum2);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= h; j++)

			ans = max(ans, m[i][j]);
	cout << ans;
/*	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= h; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}*/
}
