#ifndef SCORETILE_H
#define SCORETILE_H

/**
 * Class used to represent a tag count between two players. A match
 * consists of a 2D grid of ScoreTiles, where the rows are the taggers,
 * and the columns are the targets. A particular tile in the grid
 * represents the total number of tags the tagger has on the target,
 * as well as the total score for the tagger against the target.
 */
class ScoreTile {
private:

    /**
     * Enum that is used to aggregate points based on tag location.
     */
    enum PointValue {
        Back = 5,
        Chest = 8,
        Shoulder = 10,
        LaserGun = 15
    };

    /** The total score for the particular player-player combo */
    int totalScore;

    /** The total tag count for the particular player-player combo */
    int tagCount;

public:

    /** Initializes score and tag count to 0 */
    ScoreTile();

    /**
     * Records a tag. Also adds points based on the value of location
     * @param location An int that is one of 1, 2, 3, or 4. An invalid
     * location results in no points being added.
     */
    void addTag(const int& location);

    /**
     * Gets the total score for this tile
     * @return The total score for this tile
     */
    int getTotalScore();

    /**
     * Gets the number of tags for this tile
     * @return The total number of tags for this tile
     */
    int getTagCount();
};

#endif // SCORETILE_H
