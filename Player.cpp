#include "Player.h"

Player::Player() : playerID(-1), totalPlayerTags(-1), totalPlayerScore(-1), playerName("") {}

Player::Player(const int& playerID, const std::string& playerName) : playerID(playerID), totalPlayerTags(-1), totalPlayerScore(-1), playerName(playerName) {}

int Player::getPlayerID() {
    return playerID;
}

void Player::setTotalPlayerTags(int numTags) {
    totalPlayerTags = numTags;
}

int Player::getTotalPlayerTags() {
    return totalPlayerTags;
}

void Player::setTotalPlayerScore(int score) {
    totalPlayerScore = score;
}

int Player::getTotalPlayerScore() {
    return totalPlayerScore;
}

std::string Player::getPlayerName() {
    return playerName;
}
