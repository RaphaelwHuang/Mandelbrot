#include "../Include/Mandelbrot.h"


// Mandelbrot set
int isInSetMandelbrot(long double x, long double y){
    int i;
//    complex<long double> z(0, 0);
//    complex<long double> c(x, y);

    complexNum z, c;    // Define complex number z and c
    z.real = 0;
    z.imag = 0;

    c.real = x;
    c.imag = y;

    for (i = 0; i < 255; i++) {
        z = z * z + c;

        if (z.real * z.real + z.imag * z.imag > 4) {
            break;
        }
    }
    return i;
}

// Julia set
int isInSetJulia(long double x, long double y){
    int i;
    complex<long double> z(x, y);
    //complex<long double> c(0.11,0.60);
    //complex<long double> c(-0.81,0.17);
    complex<long double> c(-0.31, -0.63);

    for (i = 0; i < 1024; i++) {
        z = z * z + c;

        if (z.real() * z.real() + z.imag() * z.imag() > 4) {
            break;
        }
    }
    return i;
}


int main() {
    ofstream img;
    //img.open("Mandelbrot.ppm");
    img.open("Julia.ppm");
    window content={-1.5, 1.5, -1.5, 1.5, 3000, 3000};
    img << "P3" << endl;
    img << content.width << " " << content.height << endl;
    img << "255" << endl;


    // Declare a 2d array
    int **array = new int*[content.width];
    for(int i = 0; i < content.height; ++i) {
        array[i] = new int[content.height];
    }

    int color = 0;

    long double scaleX = (content.xMax - content.xMin) / content.width;
    long double scaleY = (content.yMax - content.yMin) / content.height;
    for (int i = 0; i < content.height; i++) {
        for (int j = 0; j < content.width; j++) {
            long double CorX = scaleX * j + content.xMin;
            long double CorY = scaleY * i + content.yMin;
            //array[j][i] = isInSetMandelbrot(CorX, CorY);
            array[j][i] = isInSetJulia(CorX, CorY);

        }
    }

    for (long int i = 0; i < content.height; i++) {
        for (long int j = 0; j < content.width; j++) {
            color = array[j][i] % 255;
            int r = 60 + 3 * color;
            int g = 60 + 3 * color;
            int b = 90 +  3 * color;
            img << r << " " << g << " " << b << endl;
        }
    }

    //system("open Mandelbrot.ppm");
    system("open Julia.ppm");

    return 0;
}
