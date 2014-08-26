#include "Match.h"

#include <cstdlib>
#include <iostream>
#include <cstring>

void Match::loadTeamFile(const char* filePath, TeamNumber team) {
    //Try to open file
    std::ifstream fin(filePath);
    if (!fin) {
        std::cout << "Invalid team file path: " << filePath << std::endl;
        exit(1);
    }

    std::string teamName, playerName;
    int numTeamMembers, playerID;

    //Make a reference to the current team
    Team& currentTeam = (team == TEAM_A) ? teamA : teamB;

    //Get team name and team size
    getline(fin, teamName);
    fin >> numTeamMembers;
    currentTeam.setTeamName(teamName);

    //Now read each pair of ID's and names
    for (int i = 0; i < numTeamMembers; ++i) {
        fin >> playerID;
        fin.ignore(80, ' ');
        getline(fin, playerName, '\n');

        currentTeam.addPlayer(playerID, playerName);
    }

    fin.close();
}

void Match::loadMatchFile(const char *filePath) {
    //Try to open file
    std::ifstream fin(filePath);
    if (!fin) {
        std::cout << "Invalid match file path: " << filePath << std::endl;
        exit(1);
    }

    int numTags;
    //Start reading tags
    fin >> numTags;
    for (int i = 0; i < numTags; ++i) {
        readTagLine(fin);
    }
}

void Match::readTagLine(std::istream &in) {
    int targetID, taggerID, timestamp, tagLocationID;

    //Read all fields
    in >> taggerID;
    in >> targetID;
    in >> timestamp;
    in >> tagLocationID;

    //Find out which team tagger is on, and add points to that team/player
    int taggerLocation, targetLocation;
    taggerLocation = teamA.findPlayerLocationByID(taggerID);
    if (taggerLocation == -1) {
        taggerLocation = teamB.findPlayerLocationByID(taggerID);
        targetLocation = teamA.findPlayerLocationByID(targetID);
        teamB.recordTag(taggerLocation, targetLocation, tagLocationID);
    } else {
        targetLocation = teamB.findPlayerLocationByID(targetID);
        teamA.recordTag(taggerLocation, targetLocation, tagLocationID);
    }
}

void Match::printResults(const char *outputFilePath, const char *verbosity) {
    std::ofstream fout(outputFilePath);

    //Determine which team goes first
    bool teamAFirst = teamA.getTeamName() < teamB.getTeamName();
    Team& firstTeam = (teamAFirst) ? teamA : teamB;
    Team& secondTeam = (teamAFirst) ? teamB : teamA;

    //Call appropriate verbosity function
    if (strcmp(verbosity, "vlow") == 0) {
        printLowVerbosity(fout, firstTeam, secondTeam);
    } else if (strcmp(verbosity, "vmed") == 0) {
        printMedVerbosity(fout, firstTeam, secondTeam);
    } else if (strcmp(verbosity, "vhigh") == 0) {
        printHighVerbosity(fout, firstTeam, secondTeam);
    } else {
        std::cout << "Invalid verbosity: " << verbosity << "\n";
        std::cout << "Verbosity can be one of vlow, vmed, or vhigh" << std::endl;
        fout.close();
        exit(1);
    }
    fout.close();
}

void Match::printLowVerbosity(std::ostream& out, Team& firstTeam, Team& secondTeam) {
    //We print the score for each team, then the winner
    firstTeam.printTeamScore(out);
    secondTeam.printTeamScore(out);

    printOverallWinners(out);
}

void Match::printMedVerbosity(std::ostream& out, Team& firstTeam, Team& secondTeam) {
    //We print the number of tags for each player on each team, the highest
    //scoring player, and then the winner
    firstTeam.printTeamResults(out, secondTeam, false);
    secondTeam.printTeamResults(out, firstTeam, false);
    firstTeam.printHighestScoringPlayer(out);
    secondTeam.printHighestScoringPlayer(out);

    printLowVerbosity(out, firstTeam, secondTeam);
}

void Match::printHighVerbosity(std::ostream& out, Team& firstTeam, Team& secondTeam) {
    //We print detailed tag info for each player on each team, the score
    //of each team, and then the winner
    firstTeam.printTeamResults(out, secondTeam, true);
    firstTeam.printTeamScore(out);
    secondTeam.printTeamResults(out, firstTeam, true);
    secondTeam.printTeamScore(out);

    printOverallWinners(out);
}

void Match::printOverallWinners(std::ostream& out) {
    out << "Overall winners: ";
    out << ((teamA.getTeamScore() > teamB.getTeamScore()) ? teamA.getTeamName() : teamB.getTeamName());
    out << std::endl;
}
