#include "Match.h"
#include <iostream>
#include <cstdlib>

/**
 * This is the main function for Project 1: Laser Tag. This is called
 * when the main project is run with the -p1 flag.
 */

int main(int argc, char *argv[]) {

    if (argc != 6) {
        std::cout << "Incorrect number of arguments.\n";
        std::cout << "Usage:\n";
        std::cout << "\t./p1.out <TeamAFile> <TeamBFile> <MatchFile> <OutputFile> <Verbosity>\n";
        std::cout << "where Verbosity is one of vlow, vmed, or vhigh" << std::endl;
        return 1;
    }

    //Load team files first, process match file, then print results
    Match m;
    m.loadTeamFile(argv[1], Match::TeamNumber::TEAM_A);
    m.loadTeamFile(argv[2], Match::TeamNumber::TEAM_B);
    m.loadMatchFile(argv[3]);
    m.printResults(argv[4], argv[5]);
    return 0;
}
