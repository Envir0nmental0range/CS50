#include <cs50.h>
#include <stdio.h>
int main() {
    int i, j, rows;
    rows = 0;
    do
        {
    rows = get_int("Enter number of rows: ");

    }while((rows > 8) || (rows < 1));
           
    for (i=1; i<=rows; ++i) {
        for (j=rows - i; j>=1; --j)
        { printf(" "); }
        for (j=1; j<=i; ++j)
        { printf("#"); }
        printf("\n");
    }
    return 0;
}

