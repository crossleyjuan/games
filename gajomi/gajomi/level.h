#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

class Level
{
private:
    int _currentLevel;
    int _maxLevel;
    std::vector<char*> _levels;
    char _launchCode;

public:
    Level();
    virtual ~Level();

    void NextLevel();
    void CreateLaunchCode();
    char GetLaunchCode();
    bool OnInit();
};

#endif // LEVEL_H
