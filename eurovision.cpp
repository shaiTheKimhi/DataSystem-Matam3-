#include<isotream>
#include<string>
#include<vector>
#include<stdlib>

using namespace std;

#define DEFAULT_MAX_PARTICIPANTS 26
#define DEFAULT_MAX_TIME 180    
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
    this->song_name = song;
    this->singer_name = singer;
    this->song_length = length;
}

string Participant::state()
{
    return this->(*country_name);
}
string Participant::song()
{
    return this->(*song_name);
}
int Participant::timeLength()
{
    return this->song_length;
}
string Participant::singer()
{
    return this->(*singer_name);
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
//ofstream operator for Main Control
std::ostream& operator<<(std::ostream& os, MainControl& eur)
{
    Participant *temp;
    os << eur._phase << endl;
    if(eur._phase == Registration)
    {
        for(int i = 0; i < eur._participants.size(); i++)
        {
            temp = eur._participants[i];
            os << "[" << temp->state() << "/" << temp->song() << "/"
            << temp->timeLength << "/" << temp->singer() << "]" << endl;
        }
    }
    else
    {
        //complete this to voting stage 
    }
    return os;
}
////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
//Vote struct functions:
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

////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
//MainControl class functions:
MainControl::MainControl()
{
    this->_phase = Registration;
    this->_max_participants = DEFAULT_MAX_PARTICIPANTS;
    this->_max_time = DEFAULT_MAX_TIME;
}
MainControl::~MainControl()
{
    for(int i = 0; i < this->_participants.size(); i++)
        delete this->_participants[i];
    for(int i = 0; i < this->_votes.size(); i++)
        delete this->_votes;
}
//checks if the state already exists in the participants vector
bool checkStateExists(vector<Participant*> participants, string state_name)
{
    for(int i = 0; i < participants.size(); i++)
    {
        if(participants[i]->state() == state_name)
            return true;
    }
    return false;
}
//return the index of the participant by the name of state, returns NULL if does not exist
int getStateIndexByName(vector<Participant*> participants, string state_name)
{
    for(int i = 0; i < participants.size(); i++)
    {
        if(participants[i]->state() == state_name)
            return i
    }
    return -1;
}


MainControl MainControl::operator+=(Participant& p)
{
     if(this->_phase != Registration)
        return *this;
    if(!this->leagalParticipant(p))
        return *this;
    if(checkStateExists(this->_participants, p.state()))
        return *this;
    this->_participants.insert(&p);
    p.updateRegistered(true);

    return *this;
}

MainControl MainControl::operator-=(Participant& p)
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










