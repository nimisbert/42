#include <stdio.h> 
#include <portaudio.h>

int main(int argc, char* argv[])
{
    const char* version;
    PaHostApiIndex hostApiIndex;
    PaStream *stream;
    const PaStreamInfo *streamInfo;
    double cpuLoad;

    PaError err = Pa_Initialize();
    if(err != paNoError)
    {
        printf("Port Audio Error: %s \n",Pa_GetErrorText(err));
    }

    version = Pa_GetVersionText();
    printf("%s\r\n",version);
    err = Pa_IsStreamStopped(&stream);
    if(err != paNoError)
    {
        printf("Port Audio Error: %s \n",Pa_GetErrorText(err));
    }
    err = Pa_IsStreamActive(&stream);
    if(err != paNoError)
    {
        printf("Port Audio Error: %s \n",Pa_GetErrorText(err));
    }
    streamInfo = Pa_GetStreamInfo(&stream);
    cpuLoad = Pa_GetStreamCpuLoad(&stream);
    printf("Cpu Load: %f \n",cpuLoad);

    err = Pa_Terminate();
    if(err != paNoError)
    {
        printf("Port Audio Error: %s \n",Pa_GetErrorText(err));
    }
    return 0;
}