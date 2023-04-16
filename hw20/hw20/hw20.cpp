// hw20.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <cstring>

void rev(char* s, int len) {
    int i;
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

int main() {
    int ncase;
    std::cin >> ncase;
    while (ncase--) {
        char n1[1000], n2[1000];
        int num1[1000] = { 0 }, num2[1000] = { 0 }, ans[1000] = { 0 }, len1, len2, len3, i;
        std::cin >> n1;
        len1 = strlen(n1);
        std::cin >> n2;
        len2 = strlen(n2);
        len3 = (len2 > len1) ? len2 : len1;
        rev(n1, len1);
        rev(n2, len2);
        for (i = 0; i < len1; i++)
            num1[i] = n1[i] - '0';
        for (i = 0; i < len2; i++)
            num2[i] = n2[i] - '0';
        for (i = 0; i < len3; i++) {
            ans[i] += num1[i] + num2[i];
            if (ans[i] / 10) {
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
            }
        }
        if (ans[len3])
            std::cout << ans[len3];
        for (i = len3 - 1; i >= 0; i--)
            std::cout << ans[i];
        std::cout << "\n";
    }
    return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
