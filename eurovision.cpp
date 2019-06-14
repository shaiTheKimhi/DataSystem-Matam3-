#include<isotream>
#include<string>
#include<vector>
#include<stdlib>

using namespace std;

Participant::~Participant()
{

}
Participant::Participant(char* country_name, char* song_name, int time, char* singer_name)
{
    this->country_name = new string(country_name);
    this->song_name = new string(song_name);
    this->singer_name = new string(singer_name);
    this->song_length = song_length;
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