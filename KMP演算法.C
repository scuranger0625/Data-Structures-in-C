int KMP(char *string, char *pat) {
    int i = 0, j = 0;
    int lens = strlen(string);  // 文本字串的長度
    int lenp = strlen(pat);     // 模式字串的長度

    // 預處理：構建失敗函數
    int f[lenp];
    f[0] = -1;
    for (int j = 1; j < lenp; j++) {
        int k = f[j-1];
        while (k >= 0 && pat[k] != pat[j-1])
            k = f[k];
        f[j] = k + 1;
    }

    // 進行匹配
    while (i < lens && j < lenp) {
        if (string[i] == pat[j]) {
            i++;
            j++;
        } else if (j == 0) {
            i++;
        } else {
            j = f[j-1] + 1;
        }
    }

    // 如果找到了整個模式串，返回匹配開始的索引
    if (j == lenp) {
        return i - lenp;
    } else {
        return -1;  // 未找到
    }
}
