/*3) Заданий одновимірний числовий масив розмірності n. 
//Замінити у ньому усі елементи, які передують найбільшому від'ємному,
//на значення їх квадратів
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "enter the size of the array" << endl;
    cin >> n;
    vector <int> arr(n);
    cout << "Enter array elements" << endl;
    for (int i = 0; i < n; i++)
    { cin >> arr[i];}

    int min = -1000000, m=0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 && arr[i] > min) { min = arr[i]; m = i; }
    }
    for (int j = 0; j < m; j++) {
        arr[j] = arr[j] * arr[j];
        cout << arr[j]<< " ";
    }
    for (int i = m; i < n; i++) {
        cout << arr[i]<<" ";
    }
    return 0;
} */




/*2
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "enter n " << endl;
    cin >> n;
    double result1=1, result2=cos(1), result=result1/result2;
    for (int i = 1; i < n; i++) {
        result1 = result1 * n;
        result2 = result2 + cos(n);
        result = result1 / result2;
    }
    cout << result << endl;
    return 0;
} */


/*3
#include <iostream>
using namespace std;
int main() {
    double x, e, kpop=1, sum=0, p=0, pop;
    cout << "enter x and e" << endl;
    cin >> x >> e;
    int k = 1;
    p = (pow(sin(x), k)) / kpop * k;
     do {
        sum += p;
        pop = p;
        if (k!=1) kpop = k+1;
        k++;
        p = (pow(sin(x), k)) / kpop * k;
     } while (abs(p - pop) > e);

     cout << sum;
    return 0;
}
*/