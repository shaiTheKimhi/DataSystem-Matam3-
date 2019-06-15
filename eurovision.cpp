#include<isotream>
#include<string>
#include<vector>
#include<stdlib>

using namespace std;

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


std::ostream& operator<<(std::ostream& os, Participant p)
{
    os << "[" << p.state() << "/" << p.song() << "/"
    << p.timeLength << "/" << p.singer() << "]"; 
    return os;
}




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