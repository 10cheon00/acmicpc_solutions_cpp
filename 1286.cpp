/*
ABCDE
FGHIJ
KLMNO
1x1 A B C D E F G H I J K L M N O
2x1 AB BC CD DE FG GH HI IJ KL LM MN NO
3x1 ABC BCD CDE FGH GHI HIJ KLM LMN MNO
4x1 ABCD BCDE FGHI GHIJ KLMN LMNO
5x1 ABCDE FGHIJ KLMNO
1x2 AF BG CH DI EJ FK GL HM IN JO
2x2 ABFG BCGH CDHI DIEJ FGKL GHLM HIMN IJNO
3x2 ABCFGH BCDGHI CDEHIJ FGHKLM GHILMN HIJMNO
4x2 ABCDFGHI BCDEGHIJ FGHIKLMN GHIJLMNO
5x2 ABCDEFGHIJ FGHIJKLMNO
1x3 AFK BGL CHM DIN EJO
2x3 ABFGKL BCGHLM CDHIMN DEIJNO
3x3 ABCFGHKLM BCDGHILMN CDEHIJMNO
4x3 ABCDFGHIKLMN BCDEGHIJLMNO
5x3 ABCDEFGHIJKLMNO
A = (1+1+1+1+1)*3 = 15
B = (1+2+2+2+1)*3 = 24
C = (1+2+3+2+1)*3 = 27
D = (1+2+2+2+1)*3
..
F = (1+1+1+1+1) + (2+2+2+2+2) + (1+1+1+1+1) 1 5
G = (1+2+2+2+1) + (2+4+4+4+2) + (1+2+2+2+1) 2 8
H = (1+2+3+2+1) + (2+4+6+4+2) + (1+2+3+2+1) 3 10
ABCDEFG
A B C D E F G
AB BC CD DE EF FG
ABC BCD CDE DEF EFG
ABCD BCDE CDEF DEFG
ABCDE BCDEF CDEFG
ABCDEF BCDEFG

1 2 3 4 5 6 7 8
1 2 3 3 3 3 2 1
x = 3
*/

#include <iostream>
#define MIN(A, B) ((A)>(B)?(B):(A))
typedef long long LL;
using namespace std;
int N, M, NN, MM;
LL f(int x, int y) {
    LL sum = 0;
    int thx = MIN(x, MM - x + 1), thy = MIN(y, NN - y + 1);
    for (int i = 1; i <= MM; i++) {
        int xx = MIN(i, MM - i + 1); // 1 2 3 4 4 3 2 1
        if (xx < thx) {
            sum += xx;
        } else {
            sum += thx;
        }
    }
    LL ssum = 0;
    for (int i=1; i<=NN; i++) {
        int yy = MIN(i, NN - i + 1);
        if (yy < thy) {
            ssum += sum * yy;
        } else {
            ssum += sum * thy;
        }
    }
    return ssum;
}

int main() {
    char map[100][100];
    LL cnt[26] = {0};
    cin >> N >> M;
    NN = N * 2;
    MM = M * 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            map[i + N][j + M] = map[i + N][j] = map[i][j + M] = map[i][j];
        }
    }

    for (int i = 1; i <= NN; i++) {
        for (int j = 1; j <= MM; j++) {
            cnt[map[i - 1][j - 1] - 'A'] += f(j, i);
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << cnt[i] << '\n';
    }
}
