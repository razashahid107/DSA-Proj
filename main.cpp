#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "SLL.h"

using namespace std;

class Movie
{
public:
    string title;

    /* to be converted in a linked list */
    string genre;
    int year;
    float imdb_score;
    string director_name;
    int director_fb_likes;
    int num_critic_for_views;
    int duration;
    
    /* to be converted in a linked list */
    string actor_1_name;
    int actor_1_fb_likes;
    string actor_2_name;
    int actor_2_fb_likes;
    string actor_3_name;
    int actor_3_fb_likes;


    long gross;
    int num_voted_users;
    int cast_total_fb_likes;
    int facenumber_in_poster;

    /* to be converted in a linked list */
    string keywords;
    string imdb_link;
    int num_user_reviews;
    string language;
    string country;
    string content_rating;
    long budget;
    float aspect_ratio;
    int movie_fb_likes;
    string color;
};

class MovieNode // node of a doubly linked list
{
public:
    Movie data;
    MovieNode *next;
    MovieNode *prev;
};

/* class of a doubly linked list to store movies */
class MovieList
{
public:
    MovieNode *start = NULL;
    MovieNode *last = NULL;
    // user-defined functions

    /* function that checks if MovieList is empty */
    bool isEmpty();

    /*function that reads 1 line of CSV,
    creates object of MovieNode,
    stores all entries in data part of MovieNode,
    calls insertNode function to insert tempMovie in DLL*/
    void ReadCSV();

    /* function that acts like insertAtEnd function of DLL
    it inserts the tempMovie at end of the list */
    void insertNode(MovieNode *tempMovie);
};

bool MovieList::isEmpty() { return start == NULL; }
void MovieList::ReadCSV()
{
    int count = 0;
    ifstream inputFile;
    inputFile.open(".//1.csv");
    string line = "";
        // tempMovie = NULL;


    // parsing of each row in data part of MovieNode i.e Movie
    while (getline(inputFile, line))
    {
        MovieNode *tempMovie = new MovieNode();
        stringstream inputString(line);
        /* temporary string that will be used to convert string to numeric data types */
        string converterString;
        getline(inputString, tempMovie->data.title, ',');
        getline(inputString, tempMovie->data.genre, ',');

        // converting year to int
        getline(inputString, converterString, ',');
        tempMovie->data.year = atoi(converterString.c_str());

        // converting imdbscore to float
        getline(inputString, converterString, ',');
        tempMovie->data.imdb_score = atof(converterString.c_str());

        getline(inputString, tempMovie->data.director_name, ',');

        // converting director fb likes to int
        getline(inputString, converterString, ',');
        tempMovie->data.director_fb_likes = atoi(converterString.c_str());

        // converting crtic for views to int
        getline(inputString, converterString, ',');
        tempMovie->data.num_critic_for_views = atoi(converterString.c_str());

        // converting duration to int
        getline(inputString, converterString, ',');
        tempMovie->data.duration = atoi(converterString.c_str());

        getline(inputString, tempMovie->data.actor_1_name, ',');

        // converting actor 1 fb likes to int
        getline(inputString, converterString, ',');
        tempMovie->data.actor_1_fb_likes = atoi(converterString.c_str());

        getline(inputString, tempMovie->data.actor_2_name, ',');

        // converting actor 2 fb likes to int
        getline(inputString, converterString, ',');
        tempMovie->data.actor_2_fb_likes = atoi(converterString.c_str());

        getline(inputString, tempMovie->data.actor_3_name, ',');

        // converting actor 3 fb likes to int
        getline(inputString, converterString, ',');
        tempMovie->data.actor_3_fb_likes = atoi(converterString.c_str());

        // converting gross to long int
        getline(inputString, converterString, ',');
        tempMovie->data.gross = atol(converterString.c_str());

        // converting num voted users to int
        getline(inputString, converterString, ',');
        tempMovie->data.num_voted_users = atoi(converterString.c_str());

        // converting cast_total_fb_likes to int
        getline(inputString, converterString, ',');
        tempMovie->data.cast_total_fb_likes = atoi(converterString.c_str());

        // converting facenumber_in_poster to int
        getline(inputString, converterString, ',');
        tempMovie->data.facenumber_in_poster = atoi(converterString.c_str());

        getline(inputString, tempMovie->data.keywords, ',');
        getline(inputString, tempMovie->data.imdb_link, ',');

        // converting num_user_reviews to int
        getline(inputString, converterString, ',');
        tempMovie->data.num_user_reviews = atoi(converterString.c_str());

        getline(inputString, tempMovie->data.language, ',');
        getline(inputString, tempMovie->data.country, ',');
        getline(inputString, tempMovie->data.content_rating, ',');

        // converting budget to long int
        getline(inputString, converterString, ',');
        tempMovie->data.budget = atol(converterString.c_str());

        // converting aspect_ratio to float
        getline(inputString, converterString, ',');
        tempMovie->data.aspect_ratio = atof(converterString.c_str());

        // converting movie_fb_likes to int
        getline(inputString, converterString, ',');
        tempMovie->data.movie_fb_likes = atoi(converterString.c_str());

        getline(inputString, tempMovie->data.color, ',');

        // cout << ++count << ". Title: " << tempMovie->data.title << " Genre: " << tempMovie->data.year << endl;

        insertNode(tempMovie);
    }
};

void MovieList::insertNode(MovieNode *tempMovie)
{
    /* if DLL is empty */
    if (isEmpty())
    {
        cout << "this executed" << endl;
        start = tempMovie;
        last = tempMovie;
    }
    /* if DLL contains only 1 node */
    else if (start == last)
    {
        // cout << "this executed 2" << endl;

        last = tempMovie;
        start->next = last;
        last->prev = start;
    }
    /* if DLL contains more than 1 node */
    else
    {
        last->next = tempMovie;
        tempMovie->prev = last;
        last = tempMovie;
    }
}
int main()
{
    MovieList m;
    m.ReadCSV();
    cout << "title: " << m.start->data.title << endl;
    cout << "title: " << m.last->data.title << endl;
}
