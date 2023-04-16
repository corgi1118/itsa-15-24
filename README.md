# itsa-15-24
## 題目16. 子字串出現次數
### 問題描述 ：
給予兩個英文字串，請計算出第一個字串出現在第二個字串中的次數。
### 輸入說明 ：
輸入分為兩行，第一行是由英文大小寫字母與數字所組成的字串，長度不超過 128 個字母。
第二行也是由英文大小寫字母與數字所組成的字串，長度不超過 512 個字母。
### 輸出說明：
第一個字串出現在第二個字串中的次數。
### 範例 :
![image](https://user-images.githubusercontent.com/126050259/232307021-e84dd591-bd37-462a-88c7-2b39657ced70.png)

### 程式:
```
#include<iostream>
#include<string>
using namespace std;
int appearNum(string& s, int p, string& l);
int main()
{
	string inputa, inputb, save;

	cin >> inputa >> inputb;
	cout << appearNum(inputa, 0, inputb) << endl;
	return 0;
}
int appearNum(string& s, int p, string& l)
{
	int a = 0;
	if (p > l.length()) {
		return a = 0;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (l[i + p] == s[i])continue;
		else return a += appearNum(s, p + 1, l);
	}
	a++; return a += appearNum(s, p + 1, l);
}

```
### 程式說明:
先讀取使用者輸入的兩個字串 inputS 和 inputL，分別代表要搜尋的字串和目標字串。
呼叫 appearNum ，並將 inputS、起始位置 0、以及 inputL 作為參數傳入。
appearNum 開始執行，接收三個參數：s 代表要搜尋的字串，p 代表搜尋的起始位置，l 代表目標字串。
函式中先初始化一個整數變數 a 並設為 0，用來記錄字串 s 在字串 l 中出現的次數。
判斷如果起始位置 p 大於目標字串 l 的長度，則直接返回 a 的值，表示搜尋結束，次數為 0。
接下來使用迴圈依序比對字串 s 和 l 中的字元，如果相同則繼續比對下一個字元，如果不同則進入遞迴。
遞迴呼叫 appearNum 函式，將起始位置 p 加一，繼續比對下一個位置。
遞迴終止條件是當 s 中所有字元都比對完畢，即 i 達到 s.length()，此時將 a 加一，表示找到一個出現次數。
最後再次遞迴呼叫 appearNum 函式，將起始位置 p 加一，繼續搜尋下一個位置。
當遞迴終止時，函式會返回計算得到的出現次數 a。
主程式輸出 appearNum 函式的回傳值，即字串 s 在字串 l 中出現的次數。



## 題目 17. 英文斷詞
### 問題描述 ：
斷詞在自然語言的研究上是個很重要的步驟，主要就是將關鍵字從句子中斷出，英文的斷詞較為簡單，就根據句子中的空格將英文字隔開。
### 輸入說明 ：
輸入一句英文敘述句。 字元數≤1000。
### 輸出說明 ：
將輸入的句子進行斷詞，將斷出的關鍵字依照句子中的出現排序列印出。全部轉成小寫，列印出的關鍵字不得重複，關鍵字間以一個空格隔開，最後一個關鍵字後面進行換行。例如輸入 How do you do ，則輸出 how do you 。
### 範例 ：
![image](https://user-images.githubusercontent.com/126050259/232306815-586dadd4-c66f-4510-bd5d-8319f05c116a.png)
### 程式:
```
#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

int main() {
    char enter[10000];
    cin.getline(enter, 9999);
    int len = strlen(enter);
    for (int i = 0; i < len; i++) {
        enter[i] = tolower(enter[i]);
    }
    char ans[1000][1000];
    int nowAns = 0;
    char* pch = strtok(enter, " \r\n");
    while (pch != NULL) {
        int judge = 1;
        for (int i = 0; i < nowAns; i++) {
            if (strcmp(ans[i], pch) == 0) {
                judge = 0;
                break;
            }
        }
        if (judge) {
            strcpy(ans[nowAns], pch);
            nowAns++;
        }
        pch = strtok(NULL, " \r\n");
    }
    for (int i = 0; i < nowAns; i++) {
        if (i)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
```
### 程式說明:
這段程式功能是將輸入的字串轉換為小寫，並且去除重複的單字，然後輸出結果。
宣告了一個大小為 10000 的 char 陣列 enter 來儲存輸入的字串。
使用 cin.getline() 讀取一行字串到 enter 陣列中。
使用 strlen() 計算 enter 陣列中的字串長度，並儲存到 len 變數中。
使用 tolower() 將 enter 陣列中的字元轉換為小寫。
宣告了一個二維 char 陣列 ans 來儲存去重後的結果，以及一個整數變數 nowAns 來紀錄目前 ans 陣列中的單字數量。
使用 strtok() 來將 enter 陣列中的字串以空白、換行或斷行符號為分隔符號進行切割，並將切割後的字串指標儲存在 pch 變數中。
使用 strcmp() 來比較 ans 陣列中的單字是否與 pch 相同，如果相同則將 judge 變數設為 0，表示已存在於 ans 陣列中。
如果 judge 變數為 1，表示 pch 為一個新的單字，將其複製到 ans 陣列中，並將 nowAns 變數加一。
繼續使用 strtok() 切割下一個字串，直到 pch 變數為 NULL，表示已經沒有更多的字串可供切割。
使用迴圈輸出 ans 陣列中的單字，並以空白隔開。
最後輸出換行符號，並返回 0 表示程式結束。


## 題目19. 最少派車數
### 問題描述 ：
某遊覽車派遣公司共收到n筆任務訂單，訂單中詳細記載發車時間s和返回時間d。每一輛遊覽車只要任務時間不衝突，可立即更換司機繼續上路執行任務。請問該公司至少需要調遣多少車輛才足以應付需求？
### 輸入說明 ：
程式的輸入包含兩行數字，第一行包含一個正整數n，1 ≤ n ≤ 30，代表第二行有n筆訂單的出發時間和返回時間s1, d1, s2, d2, ..., sn, dn，0 < si < di ≤ 24，而此2n個正整數間以空格隔開。
### 輸出說明 ：
輸出最少車輛需求數。
### 範例 
![image](https://user-images.githubusercontent.com/126050259/232314490-277be49e-aac6-4467-afa6-47d47ec755e1.png)

### 程式:
```
#include<iostream>
using namespace std;
int main()
{
	int input = 0, t[24] = { 0 };
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		for (int j = a - 1; j < b - 1; j++) { t[j]++; }
	}
	input = t[0];
	for (int i = 0; i < 24; i++) { if (input < t[i])input = t[i]; }
	cout << input << endl;
	return 0;
}
```
### 程式說明:
宣告一個大小為24的整數陣列t並初始化為0，用來記錄每個小時內事件發生的次數。
通過cin從標準輸入讀取一個整數值並存入input變數，表示要計算的事件數量。
使用for迴圈從0到input-1，依次讀取每個事件的起始時間a和結束時間b。
在內層的for迴圈中，使用a-1和b-1作為索引，將t陣列中對應的元素加1，表示在這個時間為遊覽車任務時間。
完成對所有事件的計數後，使用for迴圈遍歷t陣列，找到最大的計數值，並存入input變數。
最後，使用cout將最大的事件數量輸出到標準輸出，並加上換行符。
程式結束，返回0表示正常運行結束

## 20. 大整數加法
### 問題描述 ：
有時候我們有些很大的值，大到即使大型的計算機也無法幫我們作一些很基本的運算。請你寫一個程式來解決兩個大整數的加法問題。
### 輸入說明 ：
第一行有一個正整數 N ，表示共有 N 筆測試資料。接下來有 N 行，每行為一筆測試資料，內含兩個整數，其值不超過 30 位數，兩個整數間有一個空格。
### 輸出說明 ：
每筆測試資料輸出兩個整數的和於一行。
### 範例 ：
![image](https://user-images.githubusercontent.com/126050259/232324427-741b0585-92e1-4efd-9bb4-c02426c6565b.png)

### 程式:
```
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
```
### 程式說明:
包含iostream和cstring標頭檔，以便使用cin、cout和strlen等輸入輸出和字串處理功能。
宣告一個整數變數ncase，用來接收輸入。
cin從標準輸入讀取一個整數值並存入ncase變數，表示要處理的測試案例數量。
while迴圈，迴圈次數為ncase，用來處理每個測試案例。
在迴圈內部，宣告兩個字串變數n1和n2，分別用來接收要相加的兩個大數。
宣告三個整數陣列num1、num2和ans，用來分別儲存n1、n2和相加的結果，並初始化為0。
cin從標準輸入讀取兩個大數n1和n2。
strlen函數計算n1和n2的長度，並分別存入len1和len2變數。
自定義的rev函數，將n1和n2反轉，方便後續相加操作。
for迴圈，將n1和n2轉換成整數陣列num1和num2，並將每一位的數字字符轉換成對應的數字。
for迴圈，對num1和num2進行相加操作，結果存入ans陣列。
在相加過程中，如果相加的結果超過10，則將進位加到下一位。
for迴圈，從ans陣列的最高位開始輸出相加結果，注意處理前綴零的情況。
程式結束

## 21. 最大值與最小值
### 問題描述 ：
寫一個程式來找出輸入的十個數字的最大值和最小值，數值不限定為整數，且值可存放於 float 型態數值內。
### 輸入說明 ：
輸入十個數字，以空白間隔。
### 輸出說明 ：
輸出數列中的最大值與最小值，輸出時需附上小數點後兩位數字。
### 範例 ：
![image](https://user-images.githubusercontent.com/126050259/232324510-212f6ec7-8588-4bb0-b88c-5f1eddef4f62.png)

### 程式:
```
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    double a[10], b, c;
    int x;
    for (x = 0; x < 10; x++) {
        cin >> a[x];
        if (x == 0) {
            b = a[x];
            c = a[x];
        }
        else {
            if (a[x] > b) {
                b = a[x];
            }
            if (a[x] < c) {
                c = a[x];
            }
        }
    }
    cout << fixed << setprecision(2) << "maximum:" << b << endl;
    cout << fixed << setprecision(2) << "minimum:" << c << endl;
    return 0;
}
```
### 程式說明:
把第一次輸入的數值帶入變數內，當作最大值最小值好做比較




## 題目 22. 圈圈叉叉
### 問題描述 ：
OX 遊戲是大家小時候的童年記憶，甚至在長大後，無聊時還是會玩一下呢 ! 但當你一個人時，是否也能讓電腦跟你玩呢 ?
### 輸入說明 ：
輸入一個 3*3 的 2 維矩陣，矩陣內容， 0 代表 O ， 1 代表 X 。註：每列數字之間均有空格隔開。
### 輸出說明 ：
輸出這場 OX 遊戲是否有勝負之分。註：輸出結尾需換行。
### 範例 ：
![image](https://user-images.githubusercontent.com/126050259/232279019-5dff86a0-c76e-469e-8e31-998f2d7924c7.png)
### 程式:
```
#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];
    bool win = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) {
            win = true;
        }
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) {
            win = true;
        }
    }

    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
        win = true;
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
        win = true;
    }

    if (win) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}
```
### 程式說明:
這段程式是一個井字遊戲，用於檢查輸入的井字遊戲矩陣是否有贏家。

程式中定義了一個 3x3 的整數矩陣 matrix 和一個布林變數 win，用於儲存是否有贏家。接下來使用兩層 for 迴圈讓使用者輸入矩陣的值，並將其存儲在 matrix 中。

程式中使用四個 if 條件語句檢查矩陣中的所有行、列和對角線是否有相同的值。如果有相同的值，將 win 設置為 true，表示有贏家。最後，根據 win 的值輸出 "True" 或 "False"。

## 題目23. 找零錢問題
### 問題描述 ：
假設銅板有1元、5元、50元共三種，媽媽請小明去菜市場買水果，給了小明N元，且媽媽交待，要老闆找小明的零錢的數目要最少，而小明到了水果攤買了a1顆蘋果，a2顆柳丁，及a3顆桃子，1顆蘋果15元，1顆柳丁20元，1顆桃子30元，請問老問需找多少個1元、5元、50元，其銅板數目最少。
### 輸入說明 ：
先輸入媽媽給小明多少錢，N，接著輸入a1, a2, a3 ， 在此n, a1, a2, a3為整數，且a1*15+ a2*20+ a3*30小於或等於N。
### 輸出說明 ：
列出共找小明多少個1元，5元及50元，若帶的錢不夠買水果，則顯示”0”。
### 範例 ：
![image](https://user-images.githubusercontent.com/126050259/232315544-1a8aabd7-a029-4b9e-9407-904080ee638b.png)
### 程式
```
#include <iostream>
#include<string>
#include<sstream>
using namespace std;

void replaceD(string &str)
{
 int i = 0;
 while (i < str.length())
 {
  if (str[i] == ',')
  str[i] = ' ';
  i++;
 }
}

int main()
{
 string str;
 int N, a1, a2, a3, x, y, z, a, b, c ;
 N = a1 = a2 = a3 = x = 0;
 getline(cin,str);
 replaceD(str);
 stringstream ss(str);
 ss >> N >> a1 >> a2 >> a3;
 x = (a1 * 15) + (a2 * 20) + (a3 * 30);
  if (x <= N) {
    y = N - x;
    c = y / 50;
    b = (y - c * 50) / 5;
    a = (y - c * 50) - b * 5;
    cout << a << "," << b << "," << c << endl;
  } 
  else {
    cout << "0" << endl;
  } 
 return 0;
}
```
### 程式說明:



## 24. 計算複利
### 問題描述 ：
Problem Description
你每個月存 10000 元到銀行中，銀行的每月利率為 0.1% ，以複利計算，請問 3 個月後，你的帳戶為多少錢？
底下的表格示範了如何得到第 3 個月時，帳戶中的本利和（本金 + 利率總合）。
![image](https://user-images.githubusercontent.com/126050259/232324696-dcfe7db2-6f61-4e2f-b0cd-af8ece4a74b4.png)
我們定義底下幾個符號：

r: 每期利率。以前例而言， r = 0.1%

n: 期數。以前例而言， n = 3

p: 每期投入金額。以前例而言 p = 10000

現在，給你前述的三個值（即 r, n 及 p ），請計算期末的本利和。以前例而言，期未的本利合為 30060.04001 元。

Input File Format
輸入有 3 行。第一行為 r ，為浮點數值。第二行為 n ，為一整數。第三行為 p ，為一整數。

Output Format
輸出本利和，請將數值以「整數」表示（無條件捨去）
### 範例:
![image](https://user-images.githubusercontent.com/126050259/232324722-e49d7031-8631-4ef2-a84e-a580be0e29ea.png)
### 程式:
```
#include<iostream>  
using namespace std;
long double r, x;
long int n, p;
int main() {
	cin >> r >> n >> p;
	x = 0;

	while (n > 0) {
		x += p;
		x *= (1 + r);
		n--;
	}

	cout << (long long)x << endl;
	return 0;
}
```
### 程式說明:





