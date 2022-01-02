/* header files */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "SLL.h"

using namespace std;

/* forward declaration of all classes */

// classes relevant to actors

class Actor;         // Actor data type
class ActorNode;     // node of ActorTree
class ActorTree;     // doubly linked list of ActorNode
class MoviesActedIn; // a list to store pointer of all movies in which a particular actor has acted in

// classes relevant to directors
class Director;       // Director data type
class DirectorNode;   // node of DirectorList
class DirectorList;   // doubly linked list of DirectorNode
class MoviesDirected; // a list to store pointer of all movies which is directed by a particular director

// classes relevant to movies
class Movie;     // Movie data type
class MovieNode; // node of MovieList, its data part is the Movie class
class MovieList; // doubly linked list of MovieNode
class ActorsInMovie;

/* class definitions */
class Actor
{
public:
    string name;
    unsigned short int fb_likes;
    MoviesActedIn *start;
};

class ActorNode
{
public:
    Actor data;
    ActorNode *right = NULL;
    ActorNode *left = NULL;
};

class ActorTree
{
public:
    ActorNode *root = NULL;
    ActorNode *ploc = NULL;
    ActorNode *loc = NULL;
    /* user-defined functions */
    // an insert function to insert new actor nodes
    bool isEmpty() { return root == NULL; }

    void Insert(string name, unsigned short int fb_likes)
    {
        ActorNode *newNode = new ActorNode();
        newNode->data.name = name;
        newNode->data.fb_likes = fb_likes;
        SearchActor(name);
        if (isEmpty())
            root = newNode;
        else if (ploc->data.name > name)
            ploc->left = newNode;
        else if (ploc->data.name < name)
            ploc->right = newNode;
        else
            cout << name << " is already in the tree. Duplication not possible!" << endl; //
    }
    // a search function to search actors by name
    ActorNode *SearchActor(string name)
    /* If the actor is found in the tree
    the function will return its address

    else
    the function will return address of its logical (by name)  pre-decessor */
    {
        if (!isEmpty())
        {
            loc = root;
            ploc = NULL;
            while (loc != NULL)
            {
                if (name != loc->data.name)
                {
                    ploc = loc;
                    if (name < loc->data.name)
                        loc = loc->left;
                    else if (name > loc->data.name)
                        loc = loc->right;
                    else if (name == loc->data.name)
                        return loc;
                }
                else
                    return ploc;
            }
        }
    }
};

class MoviesActedIn
{
public:
    Movie *data;
    MoviesActedIn *next;
};

class Director
{
public:
    string name;
    unsigned short int fb_likes;
    MoviesDirected *start;
};

class DirectorNode
{
public:
    Director data;
    DirectorNode *prev = NULL;
    DirectorNode *next = NULL;
};

class DirectorList
{
public:
    DirectorList *start = NULL;
    DirectorList *last = NULL;
    /* user-defined functions */
    // a search function to search directors by name
    // an insert function to insert new director nodes
};

class MoviesDirected
{
public:
    Movie *data;
    MoviesDirected *next;
};

class Movie
{
public:
    string title;

    string genre; // enum
    unsigned short int year;
    float imdb_score;

    DirectorNode *director;

    unsigned short int num_critic_for_views;
    unsigned short int duration;

    ActorsInMovie *actors;

    long gross;
    unsigned int num_voted_users;
    unsigned int cast_total_fb_likes;
    unsigned short int facenumber_in_poster;

    string keywords; //
    string imdb_link;
    unsigned short int num_user_reviews;
    string language; // enum
    string country;
    string content_rating; // enum
    long budget;
    float aspect_ratio;
    unsigned int movie_fb_likes;
    bool color; // bool
};

class MovieNode
{
public:
    Movie data;
    MovieNode *next;
    MovieNode *prev;
};

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
    void Parser();

    /* function that acts like insertAtEnd function of DLL
    it inserts the tempMovie at end of the list */
    void insertNode(MovieNode *tempMovie);
};

class ActorsInMovie
{
    Actor *data;
    ActorsInMovie *next;
};

bool MovieList::isEmpty() { return start == NULL; }
void MovieList::Parser()
{
    int count = 0;
    ifstream inputFile;
    inputFile.open(".//1.csv");
    string line = "";

    /* global list of actors and directors is made */
    ActorTree *globalListOfActors = new ActorTree();
    DirectorList *globalListOfDirectors = new DirectorList();

    // parsing of each row in data part of MovieNode i.e Movie
    while (getline(inputFile, line))
    {
        MovieNode *tempMovie = new MovieNode();
        stringstream inputString(line);
        string tempString, tempString2; // temporary string to convert string to numeric data types
        int tempInt;
        getline(inputString, tempMovie->data.title, ',');
        getline(inputString, tempMovie->data.genre, ',');

        // converting year to int
        getline(inputString, tempString, ',');
        tempMovie->data.year = atoi(tempString.c_str());

        // converting imdbscore to float
        getline(inputString, tempString, ',');
        tempMovie->data.imdb_score = atof(tempString.c_str());

        /* line 199 to line 201 will be edited using logic on line 202 */
        getline(inputString, tempString, ',');
        getline(inputString, tempString2, ',');
        tempInt = atoi(tempString2.c_str());
        /* search DirectorsList if name already exists
        point director pointer to that node
        also update MoviesDirected for that director

        else
        create a new node of DirectorNode type, insert it in MoviesList
        point director pointer to that node
        update name, fb_likes, MoviesDirected for that director*/

        // converting crtic for views to int
        getline(inputString, tempString, ',');
        tempMovie->data.num_critic_for_views = atoi(tempString.c_str());

        // converting duration to int
        getline(inputString, tempString, ',');
        tempMovie->data.duration = atoi(tempString.c_str());

        /* create a new ActorsInMovie list that contains list of actors of this movie
        parse name of actor1, and search it in global list of actors

        if found, insert pointer of his node to ActorsInMovie
        update moviesActedIn for that actor

        if not found, insert a new node of ActorNode type in global list of actors
        insert pointer of his node to ActorsInMovie
        update actor name, fb likes, moviesActedIn for that actor


        repeat the same process for next 2 actors
        to do so, update the next pointer of ActorsInMovie*/

        /* line 233 to line 250 will be edited using logic on line 219 */
        getline(inputString, tempString, ',');

        // converting actor 1 fb likes to int
        getline(inputString, tempString, ',');
        tempInt = atoi(tempString.c_str());

        getline(inputString, tempString, ',');

        // converting actor 2 fb likes to int
        getline(inputString, tempString, ',');
        tempInt = atoi(tempString.c_str());

        getline(inputString, tempString, ',');

        // converting actor 3 fb likes to int
        getline(inputString, tempString, ',');
        tempInt = atoi(tempString.c_str());

        // converting gross to long int
        getline(inputString, tempString, ',');
        tempMovie->data.gross = atol(tempString.c_str());

        // converting num voted users to int
        getline(inputString, tempString, ',');
        tempMovie->data.num_voted_users = atoi(tempString.c_str());

        // converting cast_total_fb_likes to int
        getline(inputString, tempString, ',');
        tempMovie->data.cast_total_fb_likes = atoi(tempString.c_str());

        // converting facenumber_in_poster to int
        getline(inputString, tempString, ',');
        tempMovie->data.facenumber_in_poster = atoi(tempString.c_str());

        getline(inputString, tempMovie->data.keywords, ',');
        getline(inputString, tempMovie->data.imdb_link, ',');

        // converting num_user_reviews to int
        getline(inputString, tempString, ',');
        tempMovie->data.num_user_reviews = atoi(tempString.c_str());

        getline(inputString, tempMovie->data.language, ',');
        getline(inputString, tempMovie->data.country, ',');
        getline(inputString, tempMovie->data.content_rating, ',');

        // converting budget to long int
        getline(inputString, tempString, ',');
        tempMovie->data.budget = atol(tempString.c_str());

        // converting aspect_ratio to float
        getline(inputString, tempString, ',');
        tempMovie->data.aspect_ratio = atof(tempString.c_str());

        // converting movie_fb_likes to int
        getline(inputString, tempString, ',');
        tempMovie->data.movie_fb_likes = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        tempMovie->data.color = (tempString == "Color") ? true : false;

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
    m.Parser();
    cout << "title: " << m.start->data.title << endl;
    cout << "title: " << m.last->data.title << endl;
}
