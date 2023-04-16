# itsa-15-24
## 題目 
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

