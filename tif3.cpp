#include <stdio.h>
#include <string.h>

// �Լ� ����
void longestCommonSubsequence(char *s1, char *s2);

int main() {
    char s1[] = "abcbdab";
    char s2[] = "bdcab";

    longestCommonSubsequence(s1, s2);

    return 0;
}

void longestCommonSubsequence(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // ���� ���α׷��� ���̺� �ʱ�ȭ
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    // ���̺� ä���
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    // LCS ���� ���
    printf("Length of Longest Common Subsequence: %d\n", dp[m][n]);

    // LCS ���ڿ��� ������ �����Ͽ� ���
    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0'; // LCS ���ڿ� ���� ����

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // LCS ���ڿ� ���
    printf("Longest Common Subsequence: %s\n", lcs);
}
