// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++) // everytime a vote ticket enterered, do a linear search to match a candidate
    {
        if (strcmp(name, candidates[i].name) == 0) // if the vote ticket matchs any candidate's name, add one to that candidate's vote count
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // find the largest vote count
    int maxcount = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxcount)
        {
            maxcount = candidates[i].votes;
        }
    }
    
    // if any of the candidate's vote equals to the largest ticket count, print the candidate's name
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxcount)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
