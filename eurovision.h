#ifndef EUROVISION_H_
#define EUROVISION_H_

#include <iostream>
#include<String>
#include<vector>
using namespace std;
// it's allowed to define here any using statements, according to needs.
// do NOT define here : using namespace std;

//---------------------------------------------------

enum VoterType { All, Regular, Judge };
enum Phase { Registration, Contest, Voting };

//---------------------------------------------------

class Participant
{
// relevant private members can be defined here, if necessary.
private:
    String country_name;
    String song_name;
    String songer_name;
    int song_length;


public:

// need to define here possibly c'tr and d'tr and ONLY methods that
// are mentioned and demonstrated in the test example that has been published.
// NO OTHER METHODS SHOULD APPEAR HERE.

// NO friend is allowed here.

};

//---------------------------------------------------


class Voter
{
// relevant private members can be defined here, if necessary.
private: 
    Participant country;
    VoterType type;
public:
    
// need to define here possibly c'tr and d'tr and ONLY methods that
// are mentioned and demonstrated in the test example that has been published.
// NO OTHER METHODS SHOULD APPEAR HERE.

// NO friend is allowed here.

};


// -----------------------------------------------------------

struct Vote
{
Voter voter;
Participant vote_to;
// ALL is public here.
// need to define ONLY data members and c'tr and d'tr.
// NO NEED to define anything else.

};

// -----------------------------------------------------------


class MainControl
{
// relevant private members can be defined here, if necessary.
private:
    vector<Participant> _participants;
    vector<Vote> _votes;
public:

    void operator +=(Participant p)
    {
        //save participant to list
    }
    void operator +=(Vote v)
    {
        //save vote to votes list at contest
    }

// need to define here possibly c'tr and d'tr and ONLY methods that
// are mentioned and demonstrated in the test example that has been published.
// NO OTHER METHODS SHOULD APPEAR HERE.

// Also it's allowed here to define friend.

};

// -----------------------------------------------------------

#endif
