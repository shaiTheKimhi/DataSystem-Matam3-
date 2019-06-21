#ifndef EUROVISION_H_
#define EUROVISION_H_

#include <iostream>
#include<string>
#include<vector>
#include<cstdarg>
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
	Participant(string, string, int, string);
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
	string states[];//states voted for as judge
public:
	Voter(string);
	Voter(string, VoterType);
	string state();
	VoterType voterType();
	int timesOfVotes();
	void setVotes(int);

	Voter operator++();
		// need to define here possibly c'tr and d'tr and ONLY methods that
		// are mentioned and demonstrated in the test example that has been published.
		// NO OTHER METHODS SHOULD APPEAR HERE.

		// NO friend is allowed here.

};


// -----------------------------------------------------------

typedef struct _sVote
{
Voter* voter;
string* vote_to;
string* states_array;
// ALL is public here.
// need to define ONLY data members and c'tr and d'tr.
// NO NEED to define anything else.

} * _Vote;

// -----------------------------------------------------------


class MainControl
{
// relevant private members can be defined here, if necessary.
private:
    vector<Participant*> _participants;
    vector<_Vote> _rvotes;
	vector<_Vote> _jvotes;
    Phase _phase;
    int _max_participants;
    int _max_time;
    int _max_votes;
public:
    MainControl();//should create option to set the default values
    //MainControl(values);
	~MainControl();
    MainControl& operator +=(Participant&);//register participant
    MainControl& operator -=(Participant&);//unregister participant
    MainControl& operator +=(_Vote);//save vote to votes list at contest

    void setPhase(Phase);
    bool legalParticipant(Participant);
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

std::ostream& operator<<(std::ostream& os, Participant& p);
std::ostream& operator<<(std::ostream& os, Voter& v);
std::ostream& operator<<(std::ostream& os, MainControl& eur);

_Vote Vote(Voter& voter, string state1, string state2 = "", string state3 = "", string state4 = "", string state5 = "", string state6 = ""
	, string state7 = "", string state8 = "", string state9 = "", string state10 = "");
//_Vote Vote(Voter& voter, ... );
void destroyVote(_Vote vote);

#endif
