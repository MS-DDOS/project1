#ifndef MATCH_H
#define MATCH_H

#include "Team.h"

/**
 * Represents the match between two teams. Loads all of the teams
 * into two separate team instances, loads the match file, and then
 * prints the results.
 */
class Match
{
private:

    /** Team corresponding to the first team file given */
    Team teamA;

    /** Team corresponding to the second team file given*/
    Team teamB;

    /**
     * Prints low verbosity output to an output stream
     * @param out The output stream to write to
     * @param firstTeam The first team to print scores for
     * @param secondTeam The second team to print scores for
     */
    void printLowVerbosity(std::ostream& out, Team& firstTeam, Team& secondTeam);

    /**
     * Prints medium verbosity output to an output stream
     * @param out The output stream to write to
     * @param firstTeam The first team to print scores for
     * @param secondTeam The second team to print scores for
     */
    void printMedVerbosity(std::ostream& out, Team& firstTeam, Team& secondTeam);

    /**
     * Prints high verbosity output to an output stream
     * @param out The output stream to write to
     * @param firstTeam The first team to print scores for
     * @param secondTeam The second team to print scores for
     */
    void printHighVerbosity(std::ostream& out, Team& firstTeam, Team& secondTeam);

    /**
     * Prints the overall winners to an output stream, based on
     * the final team scores
     * @param out The output stream to write to
     */
    void printOverallWinners(std::ostream& out);

    /**
     * Reads a line of text from the tag file, and parses it
     * @param fin The input stream to read from
     */
    void readTagLine(std::istream& in);

public:

    /**
     * Enum to represent either Team A file or Team B file.
     */
    enum TeamNumber {
        TEAM_A, TEAM_B
    };

    /**
     * Loads a team file and saves it to be used in the match.
     * @param filePath The path to the input file
     * @param team A TeamNumber value that represents which team
     * we are loading. Can either be TEAM_A or TEAM_B
     */
    void loadTeamFile(const char* filePath, TeamNumber team);

    /**
     * Loads and processes a match file. When this function is finished,
     * then technically the match has finished, and all scores have been
     * tabulated
     * @param filePath The path to the input match file
     */
    void loadMatchFile(const char* filePath);

    /**
     * Prints the match results to an output file. The level of detail
     * is specified by the verbosity variable
     * @param outputFilePath The path to the output file (created if it
     * doesn't exist
     * @param verbosity One of vlow, vmed, or vhigh. An invalid value
     * exits the program
     */
    void printResults(const char* outputFilePath, const char* verbosity);
};

#endif // MATCH_H
