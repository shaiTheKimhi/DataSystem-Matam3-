#include "eurovision.h"
#include<stdlib>



Vote* createVote(Voter voter, Participant part)
{
    Vote* vote = new Vote;
    vote->vote_to = part;
    vote->voter = voter;
}

void destroyVote(Vote vote)
{
    delete vote;
}