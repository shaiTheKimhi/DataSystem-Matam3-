#include"voter.h"
#include"participant.h"

typedef struct _sVote{
    Voter voter;
    Participant to_vote;
} *Vote;