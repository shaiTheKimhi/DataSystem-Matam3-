#include<stdlib>
#include"vote.h"
using namespace std;

Vote createVote(Voter voter, Participant getter)
{
    Vote v = new Vote;
    v->voter = voter;
    v->to_vote = getter;
    return Vote;
}

void destroyVote(Vote v)
{
    delete v;
}