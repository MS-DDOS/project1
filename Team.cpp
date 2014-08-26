#include "Team.h"

Team::Team() : teamSize(0), teamName("") {}

void Team::setTeamName(const std::string& name) {
    teamName = name;
}

void Team::printTeamScore(std::ostream &out) {
    out << teamName << ": " << getTeamScore() << " points" << std::endl;
}

std::string Team::getTeamName() {
    return teamName;
}

void Team::addPlayer(const int& playerID, const std::string& playerName) {
    Player p(playerID, playerName);
    teamPlayers[teamSize++] = p;
}

void Team::recordTag(const int &taggerLocation, const int &targetLocation, const int &location) {
    scoreGrid[taggerLocation][targetLocation].addTag(location);
}

int Team::findPlayerLocationByID(const int &playerID) {
    //Find player with matching ID
    for (int i = 0; i < teamSize; ++i) {
        if (teamPlayers[i].getPlayerID() == playerID) {
            return i;
        }
    }
    return -1;
}

int Team::getTeamScore() {
    int score = 0;
    //Iterate over grid, summing scores
    for (int i = 0; i < teamSize; ++i) {
        for (int j = 0; j < MAX_TEAM_SIZE; ++j) {
            score += scoreGrid[i][j].getTotalScore();
        }
    }
    return score;
}

void Team::printTeamResults(std::ostream &out, Team &otherTeam, bool useHighVerbosity) {
    out << teamName << "\n";
    calcTotalPlayerScore();

    //We do a sort of selection sort, so we need to keep track of which players
    //we've already visited
    bool visited[MAX_TEAM_SIZE];
    for (int i = 0; i < teamSize; ++i) {
        visited[i] = false;
    }

    //Iterate until all players have been printed
    for (int i = 0; i < teamSize; ++i) {
        int mostPlayerTagLocation = -1, maxTags = -1;

        //Find player with the most tags that hasn't been visited
        for (int j = 0; j < teamSize; ++j) {
            if (visited[j] == true) {
                continue;
            }
            if (teamPlayers[j].getTotalPlayerTags() > maxTags) {
                maxTags = teamPlayers[j].getTotalPlayerTags();
                mostPlayerTagLocation = j;
            }
        }

        //If using vhigh, then print detailed tag information
        if (useHighVerbosity) {
            printAllPlayerTags(out, mostPlayerTagLocation, otherTeam);
        }
        //Print the total number of tags for that player, mark as visited
        printPlayerTagCount(out, mostPlayerTagLocation);
        visited[mostPlayerTagLocation] = true;
    }
}

void Team::printPlayerTagCount(std::ostream &out, int playerLocation) {
    out << "\t";
    out << teamPlayers[playerLocation].getPlayerName() << " had a total of ";
    out << teamPlayers[playerLocation].getTotalPlayerTags() << " tags";
    out << std::endl;
}

void Team::printAllPlayerTags(std::ostream &out, int playerLocation, Team& otherTeam) {
    for (int j = 0; j < otherTeam.teamSize; ++j) {
        out << "\t";
        out << teamPlayers[playerLocation].getPlayerName();
        out << " tagged ";
        out << otherTeam.teamPlayers[j].getPlayerName();
        out << " " << scoreGrid[playerLocation][j].getTagCount();
        out << " times\n";
    }
}

void Team::calcTotalPlayerScore() {
    //Iterate over each player
    for (int i = 0; i < teamSize; ++i) {
        int sumTags = 0, sumScore = 0;

        //Sum the number of tags and score based on each score tile
        for (int j = 0; j < MAX_TEAM_SIZE; ++j) {
            sumTags += scoreGrid[i][j].getTagCount();
            sumScore += scoreGrid[i][j].getTotalScore();
        }
        teamPlayers[i].setTotalPlayerTags(sumTags);
        teamPlayers[i].setTotalPlayerScore(sumScore);
    }
}

void Team::printHighestScoringPlayer(std::ostream &out) {
    //Find the score with the highest overall score
    int maxScore = -1, bestPlayerLocation = -1;
    for (int i = 0; i < teamSize; ++i) {
        if (teamPlayers[i].getTotalPlayerScore() > maxScore) {
            maxScore = teamPlayers[i].getTotalPlayerScore();
            bestPlayerLocation = i;
        }
    }

    //Print results
    out << "Best score from " << teamName << ": ";
    out << teamPlayers[bestPlayerLocation].getPlayerName();
    out << " (" << teamPlayers[bestPlayerLocation].getTotalPlayerScore() << " points)";
    out << std::endl;
}
