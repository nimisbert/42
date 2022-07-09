#include <stdio.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define NUM_SECS 1

typedef struct{
    float leftPhase;
    float rightPhase;
}paTestData;

static int patestCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    (void)inputBuffer; //prevent unused variable warning;

    for(int i=0; i<framesPerBuffer; i++)
    {
        *(out+i) = data->leftPhase;
        *(out+i) = data->rightPhase;

        data->leftPhase += 0.01;       
        data->leftPhase = (data->leftPhase >= 1.0) ? -1.0 : data->leftPhase;

        data->rightPhase += 0.03;
        data->rightPhase = (data->rightPhase >= 1.0) ? -1.0 : data->rightPhase;
    }
    return 0;
}


int main(void)
{
    //Variables 
    static paTestData data;
    PaError err = Pa_Initialize();
    PaStream *stream;
    //Initialize
    if(err != paNoError)
    {
        printf("Port Audio Error: %s \n",Pa_GetErrorText(err));
    }

    err = Pa_OpenDefaultStream(&stream,0,2,paFloat32,SAMPLE_RATE,256,patestCallback,&data);
    if(err != paNoError)
    {
        printf("Port Audio Error: %s \n",Pa_GetErrorText(err));
    }
    err = Pa_StartStream(stream);
    if(err != paNoError)
    {
        printf("Port Audio Error: %s \n",Pa_GetErrorText(err));
    }
    Pa_Sleep(NUM_SECS*1000);
    err = Pa_StopStream(stream);
    if(err != paNoError)
    {
        printf("Port Audio Error: %s \n",Pa_GetErrorText(err));
    }


    //Terminate
    err = Pa_Terminate();
    if(err != paNoError)
    {
        printf("Port Audio Error: %s \n",Pa_GetErrorText(err));
    }
    return 0;
}