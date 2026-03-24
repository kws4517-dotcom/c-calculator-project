#include <stdio.h>
#include "calc.h"

int main(void) {
    int a, b;

    printf("Ã¹ ¹øÂ° Á¤¼ö ÀÔ·Â: ");
    scanf("%d", &a);

    printf("µÎ ¹øÂ° Á¤¼ö ÀÔ·Â: ");
    scanf("%d", &b);

    printf("µ¡¼À °á°ú: %d\n", add(a, b));
    printf("»¬¼À °á°ú: %d\n", sub(a, b));
    printf("°ö¼À °á°ú: %d\n", mul(a, b));

    if (b != 0)
        printf("³ª´°¼À °á°ú: %.2f\n", (double)a / b);
    else
        printf("³ª´°¼À °á°ú: 0À¸·Î ³ª´­ ¼ö ¾ø½À´Ï´Ù.\n");

    return 0;
}

