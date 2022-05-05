#pragma once

#include <stdint.h>
#include <string>
#include <queue>

#include "GameObject.h"

class LevelGUI : public GameObject {
public:

    LevelGUI() : bombsNumber(0), score(0), passedTime(0), fps(0), height(0), currentMessage("Boom"){ }

    void __fastcall SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew);
    
    void __fastcall SetHeight(uint16_t heightN) { height = heightN; };
    
    inline uint16_t GetFinishX() const { return finishX; }
    inline void SetFinishX(uint16_t finishXN) { finishX = finishXN; }

    void Draw() const override;

    void NextMessage();

    friend class Mediator;

private:

    uint16_t height;
    uint16_t finishX = 109;

    uint64_t passedTime, fps;
    uint16_t bombsNumber;
    int16_t score;

    std::queue<std::string>messageQueue;
    std::string currentMessage;
    int delay = 3;

};

class Mediator
{
public:
    virtual ~Mediator(){}

    void addToQueue(const std::string& message)
    {
        gui->messageQueue.push(message);
    }
private:
    LevelGUI* gui;
};





