#include <stdio.h>

int main() {
    float open, high, low, close;
    int ls, us;
    while (scanf("%f %f %f %f", &open, &high, &low, &close) != EOF) {
        printf("%s", close < open ? "BW-Solid" : (close == open ? "R-Cross" : "R-Hollow"));
        ls = low < open && low < close;
        us = high > open && high > close;
        printf("%s\n",
                us && ls ? " with Lower Shadow and Upper Shadow" : (us || ls ? (us ? " with Upper Shadow" : " with Lower Shadow") : ""));
    }

    return 0;
}
