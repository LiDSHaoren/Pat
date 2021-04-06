#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

// 使用数组，输出时倒序输出并且添加，0 

int main() {
    int a, b, ans, k = 0, symbol = 1;
    // a,b的上限是1e6,所以和的范围是[-1e7, 1e7], 数组开3个足够
    int group[3];
    cin >> a >> b;
    ans = a + b;
    // 每三个数作为一组存在数组中
    // 将结果转换为绝对值，用symbol记录转换前的符号
    if (ans < 0) {
        ans = -ans;
        symbol = -1;
    }

    // 通过%1000 将结果分别存储在group[0], group[1] ... group[k - 1]中
    do {
        group[k++] = ans % 1000;
        ans /= 1000;
    } while (ans);

    // 小于0则先输出一个负号
    if (symbol == -1) cout << "-";
    // 输出头部
    if (k > 0) {
        cout << group[--k];

        // 输出余下部分
        while (k > 0) {
            // 注意输出格式
            cout << ",";
            cout << setw(3) << setfill('0') << group[--k];
        }
    }
    else { cout << "请重新输入数据"; }
    return 0;
}
