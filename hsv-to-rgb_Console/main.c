#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

struct HSV{
    uint8_t RGB_Val[3];
};

struct HSV *Calc_HSV(void)
{
    static struct HSV *Calculation;
    Calculation = malloc(sizeof(struct HSV));

    float h;
    float s = 255;
    float v = 255;

    printf("H : ");
    scanf("%f", &h);


    h = h / 360;
    s = s / 255;
    v = v / 255;


    float i = floor(h * 6);

    float f = (h * 6) - i;

    float p = v * (1 - s);

    float q = v * (1 - (f * s));

    float t = v * (1 - (1 - f) * s);

    printf("\n%f %f %f %f %f \n", i, f, p, q, t);


    switch((int)i)
    {
        case 0: Calculation->RGB_Val[0] = v * 255; Calculation->RGB_Val[1] = t * 255; Calculation->RGB_Val[2] = p * 255; break;
        case 1: Calculation->RGB_Val[0] = q * 255; Calculation->RGB_Val[1] = v * 255; Calculation->RGB_Val[2] = p * 255; break;
        case 2: Calculation->RGB_Val[0] = p * 255; Calculation->RGB_Val[1] = v * 255; Calculation->RGB_Val[2] = t * 255; break;
        case 3: Calculation->RGB_Val[0] = p * 255; Calculation->RGB_Val[1] = q * 255; Calculation->RGB_Val[2] = v * 255; break;
        case 4: Calculation->RGB_Val[0] = t * 255; Calculation->RGB_Val[1] = p * 255; Calculation->RGB_Val[2] = v * 255; break;
        case 5: Calculation->RGB_Val[0] = v * 255; Calculation->RGB_Val[1] = p * 255; Calculation->RGB_Val[2] = q * 255; break;
        case 6: Calculation->RGB_Val[0] = v * 255; Calculation->RGB_Val[1] = t * 255; Calculation->RGB_Val[2] = p * 255; break;
    }



    return Calculation;
}

void Output(struct HSV *ptr)
{
    printf("%d %d %d", ptr->RGB_Val[0], ptr->RGB_Val[1], ptr->RGB_Val[2]);
}

int main()
{

    struct HSV *Instanz1;

    Instanz1 = Calc_HSV();

    Output(Instanz1);







    return 0;
}
