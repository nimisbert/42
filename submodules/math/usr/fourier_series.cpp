//INCLUDES
#include <SDL2/SDL.h> 
#include <fstream>
#include <cstring>
#include <iostream>
#include <numeric>
#include <complex> 
#include <vector>
//DEFINE
#define WL 720
#define WH 480
#define FS_LOW_LIM -50
#define FS_UP_LIM   50
#define DELTA_t     0.0001
//CONST 
const std::complex<double> j(0,1);
const double pi = std::acos(-1);
//STRUCTS
struct svgData{
    char identifier;
    std::vector<std::complex<double>> data;
};

//FUNC
std::complex<double> svg_line(void);
std::complex<double> svg_cubicBezier(void);

std::complex<double> fourier_complexExponential(double cn, double n, double t);
std::complex<double> fourier_complexLerp(std::complex<double> a, std::complex<double> b);

void unitTest_renderSineWave(SDL_Renderer renderer);


int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_CreateWindowAndRenderer(WL,WH,0,&window,&renderer);
    SDL_RenderSetScale(renderer,1.0,1.0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

//    unitTest_disaplySineWave(renderer);

    //set Bezier curve data
    svgData curve;
    curve.identifier = 'c';
    std::complex<double> a(0.0,0.0);
    curve.data.push_back(a);
    a = (0.5,0.5); curve.data.push_back(a);
    a = (1.0,0.0); curve.data.push_back(a);
    for(double l=0.0; l<1.0; l+=DELTA_t)
    {
        double point_lr = std::lerp(curve.data[0].real,curve.data[1].real,l);
        double point_li = std::lerp(curve.data[0].imag,curve.data[1].imag,l);
    }


    for(double t=0.0; t<1.0; t+=DELTA_t)
    {
        double point_t = std::lerp(0.0, 3.14, t);
        std::complex<double>wave = fourier_complexExponential(0.5,1.0,t);
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderDrawPointF(renderer, wave.real()*WH/2+WL/2, wave.imag()*WH/2+WH/2);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(10000);

    return 0;
}

std::complex<double> fourier_complexExponential(double cn, double n, double t)
{
    std::complex<double> ans = cn * std::exp(n * 2.0 * pi * j * t);
    return ans;
}

void unitTest_displaySineWave(SDL_Renderer* renderer)
{
    for(double t=0.0; t<1.0; t+=DELTA_t)
    {
        double point_t = std::lerp(0.0, 3.14, t);
        std::complex<double>wave = fourier_complexExponential(0.5,1.0,point_t);
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderDrawPointF(renderer, t*WL, (wave.real() + wave.imag()*WH/2)+WH/2);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
}