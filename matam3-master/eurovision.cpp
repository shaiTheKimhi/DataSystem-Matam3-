#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>

#include"eurovision.h"

using namespace std;

#define DEFAULT_MAX_PARTICIPANTS 26
#define DEFAULT_MAX_TIME 180    
#define DEFAULT_MAX_VOTES 5
#define DEFAULT_VOTER_TYPE Regular
////////////////////////////////////
//Participant class functions:
Participant::~Participant()
{
    
}
Participant::Participant(string country_name, string song_name, int time, string singer_name)
{
    this->country_name = (country_name);
    this->song_name = (song_name);
    this->singer_name = (singer_name);
    this->song_length = song_length;

    this->_registered = false;
}

void Participant::update(string song, int length, string singer)
{
    if(this->_registered)
        return;
    this->song_name = song;
    this->singer_name = singer;
    this->song_length = length;
}

string Participant::state()
{
    return this->country_name;
}
string Participant::song()
{
    return this->song_name;
}
int Participant::timeLength()
{
    return this->song_length;
}
string Participant::singer()
{
    return this->singer_name;
}
bool Participant::isRegistered()
{
    return this->_registered;
}
void Participant::updateRegistered(bool r)
{
    this->_registered = r;
}



//ofstream operator for Participant:
std::ostream& operator<<(std::ostream& os, Participant& p)
{
    os << "[" << p.state() << "/" << p.song() << "/"
    << p.timeLength << "/" << p.singer() << "]"; 
    return os;
}
//ofstream operator for Voter:
std::ostream& operator<<(std::ostream& os, Voter& v)
{
    string strs[] = {"All", "Regular", "Judge"};
    os << "[" << v.state() << "/" << strs[v.voterType()] << "]";
    return os;
}
//ofstream operator for Main Control
std::ostream& operator<<(std::ostream& os, MainControl& eur)
{
    os << eur._phase << endl;
    if(eur._phase == Registration)
    {
        for(int i = 0; i < eur._participants.size(); i++)
        {
            Participant& temp = eur._participants[i];
            os << "[" << temp.state() << "/" << temp.song() << "/"
            << temp.timeLength() << "/" << temp.singer() << "]";
            if(i != eur._participants.size() - 1)
                os << endl;
        }
    }
    else
    {
        //complete this to voting stage 
        for(int i = 0; i < eur._participants.size(); i++)
        {
            Participant& temp  = eur._participants[i];
            os << temp.state() << " : ";
            os << "Regular(" << eur.votesCountRegular(temp.state())
            << ") ";
            os << "Judge(" << eur.votesCountJudge(temp.state())
            << ")";
            if(i != eur._participants.size() - 1)
                os << endl;
        }
    }
    return os;
}

////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
//Voter class functions:
Voter::Voter(string state_name):Voter(state_name, DEFAULT_VOTER_TYPE)
{
    ////
}
Voter::Voter(string state_name, VoterType type)
{
    this->votes_amount = 0;
    this->type = type;
    this->country = state_name;
}
string Voter::state()
{
    return this->country;
}
VoterType Voter::voterType()
{
    return this->type;
}

int Voter::timesOfVotes()
{
    return this->votes_amount;
}

void Voter::setVotes(int v)
{
    this->votes_amount = v;
}

Voter Voter::operator ++()
{
    this->setVotes(this->timesOfVotes() + 1);
	return *this;
}



////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
//Vote struct functions:

_Vote Vote(Voter& voter, string vote_to)
{
    //_Vote vote = new struct _sVote;
	_Vote vote = (_Vote)malloc(sizeof(struct _sVote));
	vote->vote_to = vote_to;
    vote->voter = voter;
	return vote;
}
_Vote Vote(Voter& voter, ...)
{
	//should make this function work(save points for each state)
	va_list ap;
	return 0;
}

void destroyVote(_Vote vote)
{
    delete vote;
}

////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
//MainControl class functions:
MainControl::MainControl()
{
    this->_phase = Registration;
    this->_max_participants = DEFAULT_MAX_PARTICIPANTS;
    this->_max_time = DEFAULT_MAX_TIME;
    this->_max_votes = DEFAULT_MAX_VOTES;
}
MainControl::~MainControl()
{
    for(int i = 0; i < this->_jvotes.size(); i++)
        delete this->_jvotes[i];
    for(int i = 0; i < this->_rvotes.size(); i++)
        delete this->_rvotes[i];
}
//checks if the state already exists in the participants vector(friend)
bool checkStateExists(vector<Participant&> participants, string state_name)
{
    for(int i = 0; i < participants.size(); i++)
    {
        if(participants[i].state() == state_name)
            return true;
    }
    return false;
}
//return the index of the participant by the name of state, returns NULL if does not exist(friend)
int getStateIndexByName(vector<Participant&> participants, string state_name)
{
    for(int i = 0; i < participants.size(); i++)
    {
		if (participants[i].state() == state_name)
			return i;
    }
    return -1;
}


MainControl& MainControl::operator+=(Participant& p)
{
     if(this->_phase != Registration)
        return *this;
    if(!this->leagalParticipant(p))
        return *this;
    if(checkStateExists(this->_participants, p.state()))
        return *this;
    this->_participants.push_back(p);
    p.updateRegistered(true);

    return *this;
}

MainControl& MainControl::operator-=(Participant& p)
{
    if(this->_phase != Registration)
        return *this;
    if(!this->leagalParticipant(p))
        return *this;
    if(!checkStateExists(this->_participants, p.state()))
        return *this;
    this->_participants.erase(this->_participants.begin() +
    getStateIndexByName(this->_participants, p.state()));

    return *this;
}

void MainControl::setPhase(Phase p)
{
    this->_phase = p;
}

bool MainControl::leagalParticipant(Participant p)
{
    if(p.state() == "" || p.song() == "" || p.singer == "")
        return false;
    if(this->_participants.size() == this->_max_participants)
        return false;
    return true;

}

bool MainControl::participate(string state_name)
{
    return checkStateExists(this->_participants, state_name);
}



//counts the times a vote appears in the votes vector(friend)
// int voteCount(vector<Vote&> votes, Vote& vote)
// {
//     int count = 0;
//     for(int i = 0; i < votes.size(); i++)
//     {
//         if(votes[i] == vote)
//             count++;
//     }
//     return count;
// }

int MainControl::votesCountRegular(string state)
{
    int count = 0;
    for(int i = 0; i < this->_rvotes.size(); i++)
    {
        if(this->_rvotes[i]->vote_to == state)
            count++;
    }
    return count;
}
int MainControl::votesCountJudge(string state)
{
    int count = 0;
    for(int i = 0; i < this->_jvotes.size(); i++)
    {
        if(this->_jvotes[i]->vote_to == state)
            count++;
    }
    return count;
}


MainControl& MainControl::operator+=(_Vote vote)
{
    //to be continued...
    if(vote->voter.state() == vote->vote_to)
        return *this;
    else if(vote->voter.timesOfVotes() == this->_max_votes && vote->voter.voterType()== Regular)
        return *this;
    else if(vote->voter.timesOfVotes() == 1 && vote->voter.voterType() == Judge)
        return *this;
    //to be continued...
    ++vote;
    if(vote->voter.voterType() == Regular)
        this->_rvotes.push_back(vote);
    else if(vote->voter.voterType() == Judge)
        this->_jvotes.push_back(vote);

	//might remove this line
	delete vote;
	return *this;
}





