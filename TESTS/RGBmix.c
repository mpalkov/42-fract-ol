#include <stdio.h>
#include <math.h>

#define MAX_RGB_VALUE 255
#define MAX_X_VALUE 800
#define MAX_Y_VALUE 600

typedef struct {
    int red;
    int green;
    int blue;
} RGBColor;

RGBColor mixColors(int x, int y) {
    double normalizedX = (double)x / MAX_X_VALUE;
    double normalizedY = (double)y / MAX_Y_VALUE;

    double angle = atan2(normalizedY, normalizedX);
    if (angle < 0) {
        angle = 2 * M_PI + angle;
    }

    double hue = angle / (2 * M_PI);

    int sector = (int)(hue * 6);
    double fraction = hue * 6 - sector;
    int p = (int)(MAX_RGB_VALUE * (1 - fraction));
    int q = (int)(MAX_RGB_VALUE * fraction);
    int t = MAX_RGB_VALUE / 2;

    RGBColor color;

    switch (sector) {
        case 0:
            color.red = MAX_RGB_VALUE;
            color.green = t + q;
            color.blue = t - p;
            break;
        case 1:
            color.red = t - q;
            color.green = MAX_RGB_VALUE;
            color.blue = t - p;
            break;
        case 2:
            color.red = t - p;
            color.green = MAX_RGB_VALUE;
            color.blue = t + q;
            break;
        case 3:
            color.red = t - p;
            color.green = t - q;
            color.blue = MAX_RGB_VALUE;
            break;
        case 4:
            color.red = t + p;
            color.green = t - q;
            color.blue = MAX_RGB_VALUE;
            break;
        case 5:
            color.red = MAX_RGB_VALUE;
            color.green = t + p;
            color.blue = t - q;
            break;
    }

    return color;
}

int main() {
    int x, y;
    x = 400;
    y = 300;

    // Restrict input values to the maximum values
    if (x > MAX_X_VALUE) {
        x = MAX_X_VALUE;
    }
    if (y > MAX_Y_VALUE) {
        y = MAX_Y_VALUE;
    }

    RGBColor mixedColor = mixColors(x, y);
    printf("Mixed RGB color values: (%d, %d, %d)\n", mixedColor.red, mixedColor.green, mixedColor.blue);

    return 0;
}
