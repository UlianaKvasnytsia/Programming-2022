//6. ������ ���� ����� �1, �2,...� �-1, p, ���������� ����� k ( , k<n). 
//�������� � ������  ������� � ������� k  (�����  ) � �������� �������, 
//�� ������� p, ���, ��� �� �������� ��������������

#include <iostream>
using namespace std;
int main() {
	int n, k;
	double p;
	cout << "enter n: " << endl;
	cin >> n;
	cout << "enter the array: " << endl;
	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "enter k (which element will be deleted): "<<endl;
	cin >> k;
	cout << "enter p (element to be added): " << endl;
	cin >> p;
	int u = 0;
	while(u<n&&p>arr[u])
	{
		u++;
	}
	if (u > k) {
		for (int i = k; i<n&&i < u; i++)
			arr[i] = arr[i + 1];
	 
	}
	else {
		for (int i = k; i>0&&i > u; i--)
			arr[i] = arr[i - 1];
	}
	if (u == n) arr[n - 1] = p;
	else arr[u] = p;
	for (int i = 0; i < n; i++)
		cout << arr[i]<<" ";
	return 0;
}