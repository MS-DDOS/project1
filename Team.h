#ifndef TEAM_H
#define TEAM_H

#include "Player.h"
#include "ScoreTile.h"
#include <fstream>

#define MAX_TEAM_SIZE 10

/**
 * Class that contains a single set of players. It also
 * contains the grid of ScoreTile objects that is used
 * to maintain who on this team tagged who on the other team.
 */
class Team
{

private:

    /** The number of players on the team (1 <= teamSize <= 10) */
    int teamSize;

    /** The name of the team */
    std::string teamName;

    /** The set of players on this team */
    Player teamPlayers[MAX_TEAM_SIZE];

    /**
     * The grid of scores for the team. The rows are this
     * team's players, and the col's are the opponents
     */
    ScoreTile scoreGrid[MAX_TEAM_SIZE][MAX_TEAM_SIZE];

    /** Calculates the score and tag count for each player on the team */
    void calcTotalPlayerScore();

    /**
     * Prints the total number of tags the player had in the match
     * @param out The stream to write to
     * @param playerLocation The location in the teamPlayers array for the player
     */
    void printPlayerTagCount(std::ostream& out, int playerLocation);

    /**
     * Prints detaield tag information for a player (used with vhigh verbosity)
     * @param out The stream to write to
     * @param playerLocation The location in the teamPlayers array for the player
     * @param otherTeam The other team, used to print corresponding names
     */
    void printAllPlayerTags(std::ostream& out, int playerLocation, Team& otherTeam);

public:

    /** Initializes an empty team */
    Team();

    /**
     * Mutator for the team name
     * @param name The team name to set
     */
    void setTeamName(const std::string& name);

    /**
     * Accessor for the team name
     * @return The team name
     */
    std::string getTeamName();

    /**
     * Adds a player to the team
     * @param playerID The ID of the player
     * @param playerName The name of the player
     */
    void addPlayer(const int& playerID, const std::string& playerName);

    /**
     * Returns the player number in the team, based on the player's ID.
     * We need this so that another team can map to a score tile corresponding
     * to the correct location
     * @param playerID The ID of the player
     * @return A number 0 <= num < MAX_TEAM_SIZE
     */
    int findPlayerLocationByID(const int& playerID);

    /**
     * Records a tag for a player against a target
     * @param taggerLocation The location in the teamPlayers array for the tagger
     * @param targetLocation The location in the teamPlayers array for the target
     * @param location The tag location on the body
     */
    void recordTag(const int& taggerLocation, const int& targetLocation, const int& location);

    /**
     * Get's the overall team score. This is computed on the fly.
     * @return The overall team score
     */
    int getTeamScore();

    /**
     * Prints the team score to an output stream
     * @param out The stream to write to
     */
    void printTeamScore(std::ostream& out);

    /**
     * Prints the team results, either in medium or high verbosity.
     * @param out The stream to write to
     * @param otherTeam The other team, used when printing names
     * @param useHighVerbosity True to use high verbosity, false for medium
     */
    void printTeamResults(std::ostream& out, Team& otherTeam, bool useHighVerbosity);

    /**
     * Prints info for the highest scoring player on the team
     * @param out The stream to write to
     */
    void printHighestScoringPlayer(std::ostream& out);
};

#endif // TEAM_H
