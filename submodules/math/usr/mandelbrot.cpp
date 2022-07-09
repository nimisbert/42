#include <SDL2/SDL.h>
#include <numeric>
#include <complex>


#define WL 720
#define WH 480

#define MANDELBROT_X_LOW_LIM -2.0
#define MANDELBROT_X_UP_LIM   1.0
#define MANDELBROT_Y_LOW_LIM -1.0
#define MANDELBROT_Y_UP_LIM   1.0


int mandelbrot_isInSet(std::complex<double> c)
{
    std::complex<double> z(0,0);
    for(int i=0; i<250; i++)
    {
        z = std::pow(z,2) + c;
        if(std::norm(z) > 20)
        {
            return i;
        }
    }
    return 0;
}


int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;


    SDL_CreateWindowAndRenderer(WL,WH,0,&window,&renderer);
    SDL_RenderSetScale(renderer,1.0,1.0);

    for(double x=0.0; x<1.0; x+=0.001)
    {
        for(double y=0.0; y<1.0; y+=0.001)
        {
            double point_x = std::lerp(MANDELBROT_X_LOW_LIM, MANDELBROT_X_UP_LIM, x);
            double point_y = std::lerp(MANDELBROT_Y_LOW_LIM, MANDELBROT_Y_UP_LIM, y);

            int niters = mandelbrot_isInSet(std::complex<double>(point_x,point_y));
            if(niters==0)
            {
                SDL_SetRenderDrawColor(renderer,0,0,0,255);
                SDL_RenderDrawPointF(renderer, x*WL, y*WH);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 3*niters%255, 2*niters%255, 1*niters%255 ,255);
                SDL_RenderDrawPointF(renderer, x*WL, y*WH);
            }
        }
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(10000);

    return 0;
}