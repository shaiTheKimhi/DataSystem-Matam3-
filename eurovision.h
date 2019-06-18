#ifndef EUROVISION_H_
#define EUROVISION_H_

#include <iostream>
#include<string>
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
    string country_name;
    string song_name;
    string singer_name;
    int song_length;
    bool _registered;

public:
    Participant(string, string, int, string)
    ~Participant();
    Participant operator=(Participant) = delete;

    void update(string, int, string);

    string state();
    string song();
    int timeLength();
    string singer();
    
    bool isRegistered();
    void updateRegistered(bool);//name might be changed if needed by test



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
    int votes_amount;
    string country;
    VoterType type;//default type is regular
public:
    Voter(string);
    Voter(string, VoterType);
    string state();
    VoterType voterType();
    int timesOfVotes();
    void setVotes(int);
// need to define here possibly c'tr and d'tr and ONLY methods that
// are mentioned and demonstrated in the test example that has been published.
// NO OTHER METHODS SHOULD APPEAR HERE.

// NO friend is allowed here.

};


// -----------------------------------------------------------

struct Vote
{
Voter& voter;
string vote_to;
// ALL is public here.
// need to define ONLY data members and c'tr and d'tr.
// NO NEED to define anything else.

};

// -----------------------------------------------------------


class MainControl
{
// relevant private members can be defined here, if necessary.
private:
    vector<Participant&> _participants;
    vector<Vote&> _rvotes;
    vector<Vote&> _jvotes
    Phase _phase;
    int _max_participants;
    int _max_time;
    int _max_votes;
public:
    MainControl();//should create option to set the default values
    ~MainControl();
    MainControl operator +=(Participant&);//register participant
    MainControl operator -=(Participant&);//unregister participant
    MainControl operator +=(Vote&);//save vote to votes list at contest

    void setPhase(Phase);
    bool leagalParticipant(Participant);
    bool participate(string);

    int votesCountRegular(string);
    int votesCountJudge(string);

    friend std::ostream& operator<<(std::ostream& os, MainControl& eur);
// need to define here possibly c'tr and d'tr and ONLY methods that
// are mentioned and demonstrated in the test example that has been published.
// NO OTHER METHODS SHOULD APPEAR HERE.

// Also it's allowed here to define friend.

};

// -----------------------------------------------------------

#endif
