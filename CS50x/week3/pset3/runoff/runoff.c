#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// DONE
// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // 2D Array Pref ultimately stores candidates and their rank for each voter...
    // ...so as user gives a votename in their order of preference...
    // kinda switch that, and store the pref in place of that name in the array
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(name, candidates[i].name))
        {
            preferences[voter][i] = rank;
            return true;
        }
    }
    return false;
}


// Tabulate votes for non-eliminated candidates
void tabulate(void)
    // ******  Where we left off **** ///////////
    /* Method For making sure each voter only gets one vote:
        - Create a variable called ballots_drawn
        - Whenever someone's highest preference vote gets cast, int ballots is incremented
        - Then, when looping through rank in each voter's choice, check int ballot
        - If it is not less than their voter number, break from that loop
        - Check next voter
    */
    // Loop through voters

    // Clear all candidates' votes

    {
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].votes = 0;
    }

    int ballots_drawn = 0;
    int highest_pref;
    int pref_cand;
    for (int i = 0; i < voter_count; i++)
    {
        highest_pref = candidate_count;
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] <  highest_pref && candidates[j].eliminated == false)
            {
                highest_pref = preferences[i][j];
                pref_cand = j;
            }
        }
        candidates[pref_cand].votes += 1;
    }

    // Debugging
    for (int i = 0; i < candidate_count; i++)
    {
        printf("Candidate %s has %i votes\n", candidates[i].name, candidates[i].votes);
    }
}

// DONE
// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Hopefully 0.5 is made into a float as well, I'll assign it just in case
        if ((float) candidates[i].votes / (float) voter_count > (float) 0.5)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// DONE
// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // MAX_CANDIDATES is the maximum number of votes a candidate can have. It can only be lower
    int min_votes = MAX_CANDIDATES;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min_votes && candidates[i].eliminated == false)
        {
            min_votes = candidates[i].votes;
        }
    }
    printf("min_votes is  %i\n", min_votes);
    return min_votes;
}

// DONE
// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}


// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}