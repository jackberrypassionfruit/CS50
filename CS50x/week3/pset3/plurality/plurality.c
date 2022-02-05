#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(name, candidates[i].name))
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Because there may be more than one winner, as you check the number of votes for each candidate, store the people who tie for the most in an array. If someone new has winning_votes, reset the array and winner_count
    string winners[candidate_count];
    int winning_votes = 0;
    int winner_count = 1;
    for (int i = 0; i < candidate_count; i++)
    {
        // Debugging Start
        for (int j = 0; j < candidate_count; j++)
        {
            printf("winners[j] is: %s, ", winners[j]);
        }
        // Debugging End
        if (candidates[i].votes > winning_votes)
        {
            //Clear array
            for (int j = 0; j < candidate_count; j++)
            {
                winners[j] = NULL;
            }
            winner_count = 1;
            winners[0] = candidates[i].name;
            winning_votes = candidates[i].votes;
        }
        else if (candidates[i].votes == winning_votes)
        {
            winner_count += 1;
            winners[i - 1] = candidates[i].name;
        }
        printf("\n");
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (winners[i] == NULL)
        {
            return;
        }
        else
        {
            printf("%s\n", winners[i]);
        }
    }
    return;
}