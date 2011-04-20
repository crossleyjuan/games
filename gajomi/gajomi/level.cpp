#include "level.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Level::Level()
{
    _currentLevel = 0;
}

Level::~Level() {
    for (std::vector<char*>::iterator iter = _levels.begin(); iter != _levels.end(); iter++) {
        char* level = *iter;
        free(level);
    }
    _levels.clear();
}

bool Level::OnInit()
{
    FILE* FileHandle = fopen("./Levels.txt", "r");

    if(FileHandle == NULL) {
        return false;
    }

    fscanf(FileHandle, "%d", &_maxLevel);

    char* level = NULL;
    for (int x = 0; x < _maxLevel; x++) {
        level = (char*)malloc(255);
        memset(level, 0, 255);
        fscanf(FileHandle, "%s", level);
        _levels.push_back(level);
        fscanf(FileHandle, "\n");
    }

    _maxLevel--;// Level is 0 based
    fclose(FileHandle);
    CreateLaunchCode();
    return true;
}

char Level::GetLaunchCode() {
    return _launchCode;
}

void Level::NextLevel() {
    _currentLevel++;
    if (_currentLevel > _maxLevel) {
        _currentLevel = _maxLevel;
    }
    CreateLaunchCode();
}


void Level::CreateLaunchCode() {
    char* launchCodes = _levels.at(_currentLevel);
    int pos = -1;
    int len = strlen(launchCodes);
    while ((pos < 0) || (pos >= len)) {
        pos = rand();
    }
    _launchCode = launchCodes[pos];
    printf("LaunchCode: %c", _launchCode);
}
