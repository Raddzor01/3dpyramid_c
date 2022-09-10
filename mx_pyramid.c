void mx_printchar(char c);

void mx_pyramid(int n) {
    char pyramid[n][n * 2];
    int count_sl = 1;
    int count_bsl_back = 1;
    int count_bsl = 1;
    int print_count = n + 1;
    if (n % 2 == 1 || n <= 1)
        return;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n * 2; j++) {
            if (j == n - count_sl) {
                pyramid[i][j] = '/';
                count_sl++;
            } else if (j == n + count_bsl_back - 1) {
                pyramid[i][j] = '\\';
                count_bsl_back += 2;
                break;
            } else
                pyramid[i][j] = ' ';
        }      
    for (int i = 1; i < n * 2 - 2; i++)
        pyramid[n - 1][i] = '_';
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n * 2; j++)
            if (j == n + count_bsl - 1 && i > 0) {
                pyramid[i][j] = '\\';
                count_bsl++;
                break;
            }
    for (int i = n / 2; i < n; i++)
        pyramid[i][n * 2 - 1] = '|';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < print_count; j++)
            mx_printchar(pyramid[i][j]);
        if (print_count < n * 2)
            print_count += 2;
        if (print_count > n * 2)
            print_count = n * 2;
        mx_printchar('\n');
    }
}

int main(void) {
    mx_pyramid(42);
    return 0;
}
