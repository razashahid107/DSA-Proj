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
class ActorTree;     // BST of ActorNode
class MoviesActedIn; // a list to store pointer of all movies in which a particular actor has acted in

// classes relevant to directors
class Director;       // Director data type
class DirectorNode;   // node of DirectorTree
class DirectorTree;   // BST of DirectorNode
class MoviesDirected; // a list to store pointer of all movies which are directed by a particular director

// classes relevant to movies
class Movie;         // Movie data type
class MovieNode;     // node of MovieList, its data part is the Movie class
class MovieList;     // doubly linked list of MovieNode
class ActorsInMovie; // a list to store pointer of all actors who have acted in a movie

class MoviesActedIn
{
public:
    Movie *data;
    MoviesActedIn *next;
};
class ActorsInMovie
{
public:
    Actor *data;
    ActorsInMovie *next;
};

class Movie
{
public:
    string title;

    string genre; // enum
    unsigned short int year;
    float imdb_score;

    Director *ptrToDir;

    unsigned short int num_critic_for_views;
    unsigned short int duration;

    ActorsInMovie *startOfListOfActors;

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

    void insertActor(Actor *ptrToActor)
    {
        ActorsInMovie *loc;
        ActorsInMovie *ploc;
        ActorsInMovie *newActor = new ActorsInMovie();
        newActor->data = ptrToActor;
        newActor->next = NULL;
        if (startOfListOfActors == NULL)
            startOfListOfActors = newActor;
        else
        {
            loc = startOfListOfActors;
            while (loc != NULL)
            {
                ploc = loc;
                loc = loc->next;
            }
            ploc->next = newActor;
        }
    }
};
/* class definitions */
class Actor
{
public:
    string name;
    unsigned short int fb_likes;
    MoviesActedIn *startOfList;
    MoviesActedIn *ploc = NULL;
    MoviesActedIn *loc = NULL;
    void insertActedMovies(Movie *ptrToMovie)
    {
        MoviesActedIn *newMovie = new MoviesActedIn();
        newMovie->data = ptrToMovie;
        newMovie->next = NULL;
        if (startOfList == NULL)
            startOfList = newMovie;
        else
        {
            loc = startOfList;
            while (loc != NULL)
            {
                ploc = loc;
                loc = loc->next;
            }
            ploc->next = newMovie;
        }
    }
    void printActedMovies()
    {
        int count = 0;
        cout << name << " has directed the following movies." << endl;
        loc = startOfList;
        while (loc != NULL)
        {
            cout << ++count << " " << loc->data->title << endl;
            loc = loc->next;
        }
    }
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
    bool isEmpty() { return root == NULL; }

    // an insert function to insert new actor nodes
    ActorNode *InsertActor(string name, unsigned short int fb_likes)
    {
        if (isEmpty()) // inserting in an empty tree
        {
            ActorNode *newNode = new ActorNode();
            newNode->data.name = name;
            newNode->data.fb_likes = fb_likes;
            root = newNode;
            return newNode;
        }
        else
        {
            SearchActor(name);
            if (loc != NULL) // Actor found, no need to insert
                return loc;
            // else a new node of the actor will be added to the list
            ActorNode *newNode = new ActorNode();
            newNode->data.name = name;
            newNode->data.fb_likes = fb_likes;
            if (ploc->data.name > name)
                ploc->left = newNode;
            else if (ploc->data.name < name)
                ploc->right = newNode;

            return newNode;
        }
    }
    // a search function to search actors by name
    /* If the actor is found in the tree
    the function will return its address

    else
    the function will return address of its logical (by name)  pre-decessor */
    void SearchActor(string name)
    {
        if (!isEmpty())
        {
            loc = root;
            ploc = NULL;
            while (loc != NULL)
            {
                if (name != loc->data.name) // keep traversing if node not found
                {
                    ploc = loc;
                    if (name < loc->data.name)
                        loc = loc->left;
                    else if (name > loc->data.name)
                        loc = loc->right;
                }
                else // return if node found, loc contains address of node
                    return;
            }
        }
    }
};

class MoviesDirected
{
public:
    Movie *data;
    MoviesDirected *next;
};

class Director
{
public:
    string name;
    unsigned short int fb_likes;
    MoviesDirected *startOfList = NULL;
    MoviesDirected *ploc = NULL;
    MoviesDirected *loc = NULL;
    void insertDirectedMovies(Movie *ptrToMovie)
    {
        MoviesDirected *newMovie = new MoviesDirected();
        newMovie->data = ptrToMovie;
        newMovie->next = NULL;
        if (startOfList == NULL)
            startOfList = newMovie;
        else
        {
            loc = startOfList;
            while (loc != NULL)
            {
                ploc = loc;
                loc = loc->next;
            }
            ploc->next = newMovie;
        }
    }
    void printDirectedMovies()
    {
        int count = 0;
        cout << name << " has directed the following movies." << endl;
        loc = startOfList;
        while (loc != NULL)
        {
            cout << ++count << " " << loc->data->title << endl;
            loc = loc->next;
        }
    }
};

class DirectorNode
{
public:
    Director data;
    DirectorNode *right = NULL;
    DirectorNode *left = NULL;
};

class DirectorTree
{
public:
    DirectorNode *root = NULL;
    DirectorNode *ploc = NULL;
    DirectorNode *loc = NULL;
    /* user-defined functions */
    bool isEmpty() { return root == NULL; }

    // an insert function to insert new director nodes and return their address
    DirectorNode *InsertDirector(string name, unsigned short int fb_likes)
    {
        if (isEmpty()) // inserting in an empty tree
        {
            DirectorNode *newNode = new DirectorNode();
            newNode->data.name = name;
            newNode->data.fb_likes = fb_likes;
            root = newNode;
            return newNode;
        }
        else
        {
            SearchDirector(name);
            if (loc != NULL) // Director found, no need to insert
                return loc;
            // else a new node of the director will be added to the list
            DirectorNode *newNode = new DirectorNode();
            newNode->data.name = name;
            newNode->data.fb_likes = fb_likes;
            if (ploc->data.name > name)
                ploc->left = newNode;
            else if (ploc->data.name < name)
                ploc->right = newNode;

            return newNode;
        }
    }

    // a search function to search directors by name
    /* If the director is found in the tree
    the function will return its address

    else
    the function will return address of its logical (by name)  pre-decessor */
    void SearchDirector(string name)
    {
        if (!isEmpty())
        {
            loc = root;
            ploc = NULL;
            while (loc != NULL)
            {
                if (name != loc->data.name) // keep traversing if node not found
                {
                    ploc = loc;
                    if (name < loc->data.name)
                        loc = loc->left;
                    else if (name > loc->data.name)
                        loc = loc->right;
                }
                else // return if node found, loc contains address of node
                    return;
            }
        }
    }
};
ActorTree *globalListOfActors = new ActorTree();
DirectorTree *globalListOfDirectors = new DirectorTree();

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

bool MovieList::isEmpty() { return start == NULL; }
void MovieList::Parser()
{
    int count = 0;
    ifstream inputFile;
    inputFile.open(".//1.csv");
    string line = "";

    /* global list of actors and directors is made */

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

        /* START: parsing of director into DirectorNode starts here */
        getline(inputString, tempString, ',');
        getline(inputString, tempString2, ',');
        tempInt = atoi(tempString2.c_str());
        /* search DirectorsList if name already exists
        point director pointer to that node
        also update MoviesDirected for that director

        else
        create a new node of DirectorNode type, insert it in DirectorTree
        point director pointer to that data part of that node
        update name, fb_likes, MoviesDirected for that director*/

        DirectorNode *tempDirectorNode;
        tempDirectorNode = globalListOfDirectors->InsertDirector(tempString, tempInt); // inserting director in global list of director

        tempMovie->data.ptrToDir = &tempDirectorNode->data; // setting ptrToDir equal to its director

        tempMovie->data.ptrToDir->insertDirectedMovies(&tempMovie->data); // adding movie nodes in director's directed movies

        cout << "The director of " << tempMovie->data.ptrToDir->startOfList->data->title << " is " << tempMovie->data.ptrToDir->name << endl;
        /* END: parsing of director ends here */

        // converting crtic for views to int
        getline(inputString, tempString, ',');
        tempMovie->data.num_critic_for_views = atoi(tempString.c_str());

        // converting duration to int
        getline(inputString, tempString, ',');
        tempMovie->data.duration = atoi(tempString.c_str());

        /* START: parsing of actor into ActorNode starts here */
        getline(inputString, tempString, ',');

        // converting actor 1 fb likes to int
        getline(inputString, tempString2, ',');
        tempInt = atoi(tempString.c_str());
        /* create a new ActorsInMovie list that contains list of actors of this movie
        parse name of actor1, and search it in global list of actors

        if found, insert pointer of his node to ActorsInMovie
        update moviesActedIn for that actor

        if not found, insert a new node of Actor type in global list of actors
        insert pointer of his node to ActorsInMovie
        update actor name, fb likes, moviesActedIn for that actor
        */

        ActorNode *tempActorNode;
        tempActorNode = globalListOfActors->InsertActor(tempString, tempInt); // inserting actor in global list of actor

        tempMovie->data.insertActor(&(tempActorNode->data)); // inserting actor in actor list

        tempActorNode->data.insertActedMovies(&tempMovie->data);

        cout << "The first actor of this movie is " << tempMovie->data.startOfListOfActors->data->name << endl
             << endl;

        /* repeat the same process for next 2 actors
       to do so, update the next pointer of ActorsInMovie*/

        /* line 233 to line 250 will be edited using logic on line 219 */

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

        count++;
        // cout << count << ". Title: " << tempMovie->data.title << " Genre: " << tempMovie->data.year << endl;

        insertNode(tempMovie);
    }
};

void MovieList::insertNode(MovieNode *tempMovie)
{
    /* if DLL is empty */
    if (isEmpty())
    {
        start = tempMovie;
        last = tempMovie;
    }
    /* if DLL contains only 1 node */
    else if (start == last)
    {
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

    globalListOfDirectors->SearchDirector("Bryan Singer");
    globalListOfDirectors->loc->data.printDirectedMovies();
}
