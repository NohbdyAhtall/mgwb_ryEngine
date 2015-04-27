#ifndef TIMING_H_INCLUDED
#define TIMING_H_INCLUDED

namespace ryEngine
{

class FpsLimiter
{
public:
    FpsLimiter();

    void init(float maxFPS);

    void setMaxFPS(float maxFPS);

    void begin();

    //end will return current FPS
    float end();

private:
    void            calculateFPS();

    float           _fps;
    float           _maxFPS;
    float           _frameTime;
    unsigned int    _startTicks;

};




}

#endif // TIMING_H_INCLUDED
