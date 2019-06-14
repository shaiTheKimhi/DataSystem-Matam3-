#include<isotream>
#include<String>
#include<vector>
using namespace std;

Participant::~Participant()
{

}
Participant::Participant(char* country_name, char* song_name, int time, char* singer_name)
{
    this->country_name = new String(country_name);
    this->song_name = new String(song_name);
    this->singer_name = new String(singer_name);
    this->song_length = song_length;
}
