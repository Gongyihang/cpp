class Solution {
public:
    vector<vector<int>> dp;
    void KMP(string pat)
    {
        int M = pat.size();
        // dp[状态][字符] = 下个状态
        dp.resize(M, vector<int>(256));
        // base case
        dp[0][pat[0]] = 1;
        // 影子状态 X 初始为 0
        int X = 0;
        // 构建状态转移图（稍改的更紧凑了）
        for (int j = 1; j < M; j++) {
            for (int c = 0; c < 256; c++) {
                dp[j][c] = dp[X][c];
            }
            dp[j][pat[j]] = j + 1;
            // 更新影子状态
            X = dp[X][pat[j]];
        }
    }

    int search(string txt, string pat)
    {
        int M = pat.size();
        int N = txt.size();
        // pat 的初始态为 0
        int j = 0;
        for (int i = 0; i < N; i++) {
            // 计算 pat 的下一个状态
            j = dp[j][txt[i]];
            // 到达终止态，返回结果
            if (j == M)
                return i - M + 1;
        }
        // 没到达终止态，匹配失败
        return -1;
    }
    int strStr(string txt, string pat)
    {
        if (!pat.size())
            return 0;
        if (!txt.size())
            return -1;
        KMP(pat); //状态机解KMP
        int index = search(txt, pat);
        if (index != -1) { //匹配成功返回文本串下标
            return index;
        } else { //否则返回-1
            return -1;
        }
    }
};