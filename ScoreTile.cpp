#include "ScoreTile.h"
#include <iostream>

ScoreTile::ScoreTile() : totalScore(0), tagCount(0) {}

int ScoreTile::getTotalScore() {
    return totalScore;
}

int ScoreTile::getTagCount() {
    return tagCount;
}

void ScoreTile::addTag(const int& location) {

    //Based on the int location from the file, add appropriate points
    switch (location) {
    case 1:
        totalScore += PointValue::Back;
        break;
    case 2:
        totalScore += PointValue::Chest;
        break;
    case 3:
        totalScore += PointValue::Shoulder;
        break;
    case 4:
        totalScore += PointValue::LaserGun;
        break;
    default:
        std::cout << "Invalid tag location: " << location << std::endl;
        return;
    }

    ++tagCount;
}
