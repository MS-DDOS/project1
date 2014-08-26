#ifndef PLAYER_H
#define PLAYER_H

#include <string>

/**
 * This class represents a single player in a match.
 * It records the players name and the total number
 * of tags and total score of the player. It does
 * not keep track of who the player tagged individually
 */
class Player
{

private:

    /** The player's ID */
    int playerID;

    /** The overall number of tags the player has gotten */
    int totalPlayerTags;

    /** The overall score the player has */
    int totalPlayerScore;

    /** The name of the player (may contain spaces) */
    std::string playerName;

public:

    /** Default constructor, initializes an empty player */
    Player();

    /**
     * Constructor that saves a player ID and name. Used when reading
     * from the input file
     * @param playerID The integer ID of the player
     * @param playerName The name of the player
     */
    Player(const int& playerID, const std::string& playerName);

    /**
     * Accessor for the player ID
     * @return The player's ID
     */
    int getPlayerID();

    /**
     * Mutator for the overall number of tags for the player
     * @param numTags The number of tags to record
     */
    void setTotalPlayerTags(int numTags);

    /**
     * Accessor for the number of tags for the player
     * @return The number of tags for the player
     */
    int getTotalPlayerTags();

    /**
     * Mutator for the overall score for the player
     * @param score The overall score to record
     */
    void setTotalPlayerScore(int score);

    /**
     * Accessor for the overall score for the player
     * @return The overall score for the player
     */
    int getTotalPlayerScore();

    /**
     * Accessor for the player's name
     * @return The player's name
     */
    std::string getPlayerName();
};

#endif // PLAYER_H
