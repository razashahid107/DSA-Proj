/* things to do at end */
// function that prints movies votes wise
// function that prints movies duration wise
// implement recursion where possible
// make search functions non-case sensitive

/* genre insertion */
/*  */
/* header files */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "SLL.h"

using namespace std;

/* FORWARD DECLARATION OF ALL CLASSES */

// classes relevant to actors

string convertToLower(string line);
int countCharInAString(string line, char c);

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
class Movie;          // Movie data type
class MovieNode;      // node of MovieList, its data part is the Movie class
class MovieList;      // doubly linked list of MovieNode
class ActorsInMovie;  // a node of a list that stores pointer of all actors who have acted in a movie
class YearWiseList;   // a list to store movies in ascending order of year released
class YearWiseNode;   // node of the above class
class RatingWiseList; // a list to store movies in ascending order of rating
class RatingWiseNode; // node of the above class

//classes relevant to genre
class Genre;

/* CLASS DEFINITIONS */

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

    /*  tempString contains all genres
    we count '|' in tempString
    sizeOfGenre = count+1
    string tempGenre
    dynamic string array of genres created (size is sizeofgenre)

    stringstream genreString(tempString);

    loop this logic sizeOfGenre times:
        getline(genreString, tempGenre, '|')
        if(i == sizeOfGenre)
            getline(genreString, arrayOfGenre[i], ',')

        arrayOfGenre[i] = convertStringToEnum(tempGenre)

    end of loop

    ptrToGenreList = &arrayOfGenre;
     */
    string genre; // will be converted to dynamic array of string

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

    string keywords; // will be converted to dynamic array of string
    string imdb_link;
    unsigned short int num_user_reviews;
    string language; // enum
    string country;
    string content_rating; // enum
    long budget;
    float aspect_ratio;
    unsigned int movie_fb_likes;
    bool color;

    void insertActorInMovie(Actor *ptrToActor);
    void printActorsOfMovie();
};

class Actor
{
public:
    string name;
    unsigned short int fb_likes;
    unsigned int countOfMovies = 0;
    MoviesActedIn *startOfList;
    MoviesActedIn *ploc = NULL;
    MoviesActedIn *loc = NULL;
    string tempCoActor1;
    string tempCoActor2;
    void insertActedMovies(Movie *ptrToMovie);
    /* 1. Function that prints details of an actor */
    void printActedMovies();
    /* Function that finds the co-Actors of an actor in a specific movie */
    void findCoActors(MoviesActedIn *loc);
    /* 2. Print Co Actors of an actor and the movie they acted in */
    void printCoActors();
    /* 5. Check whether 2 actors are coActors */
    void checkAandB(string actor2);
};

/* class definitions */

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

    /* function to check if tree is empty */
    bool isEmpty() { return root == NULL; }

    // an insert function to insert new actor nodes
    ActorNode *InsertActor(string name, unsigned short int fb_likes);
    /* If Tree is empty or the director node is not found
    it will insert a newNode of DirectorNode type and return the node's address
    however if the directorNode was already found in search function,
    then it will only return the node's address */

    bool SearchActor(string name);
    /* If the actor is found in the tree
    the function will return true
    else the function will return false*/
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
    void insertDirectedMovies(Movie *ptrToMovie);
    /* 6. Function that prints all the movies directed by a director */
    void printDirectedMovies();
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

    /* function to check if tree is empty */
    bool isEmpty() { return root == NULL; }

    DirectorNode *InsertDirector(string name, unsigned short int fb_likes);
    /* If Tree is empty or the director node is not found
    it will insert a newNode of DirectorNode type and return the node's address
    however if the directorNode was already found in search function,
    then it will only return the node's address */

    bool SearchDirector(string name);
    /* If the director is found in the tree
    the function will return true
    else the function will return false*/
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

class YearWiseList
{
public:
    YearWiseNode *start = NULL;
    YearWiseNode *ploc = NULL;
    YearWiseNode *loc = NULL;
    bool isEmpty();
    void searchNode(int year);
    void insertSorted(Movie *newMovie);
    /* 10. a) Prints movie titles increasing year-wise */
    void printMoviesYearWise();
    /* 9. Prints all movie titles released in the given year */
    void printFromYear(int year);
};

class YearWiseNode
{
public:
    Movie *data;
    YearWiseNode *next = NULL;
};

class RatingWiseList
{
public:
    RatingWiseNode *start = NULL;
    RatingWiseNode *ploc = NULL;
    RatingWiseNode *loc = NULL;
    bool isEmpty();
    void searchNode(float rating);
    void insertSorted(Movie *newMovie);
    /* 12. Prints movies from highest to lowest rating. */
    void printMoviesRatingWise();
};
class RatingWiseNode
{
public:
    Movie *data;
    RatingWiseNode *next = NULL;
};

class Genre
{
    public:
    enum genre
    {
        Action,
        Adventure,
        Animation,
        Biography,
        Comedy,
        Crime,
        Documentary,
        Drama,
        Family,
        Fantasy,
        FilmNoir,
        History,
        Horror,
        Music,
        Musical,
        Mystery,
        Romance,
        SciFi,
        Short,
        Sport,
        Superhero,
        Thriller,
        War,
        Western,
    };
    string convertEnumToString(int eNumber); 
    int convertStringToEnum(string genre);
};


/* GLOBAL VARIABLE LISTS */
ActorTree *globalListOfActors = new ActorTree();
DirectorTree *globalListOfDirectors = new DirectorTree();
YearWiseList *globalListOfYearWiseMovies = new YearWiseList();
RatingWiseList *globalListOfRatingWiseMovies = new RatingWiseList();



/* FUNCTION DEFINITIONS OF CLASS FUNCTIONS*/

bool MovieList::isEmpty() { return start == NULL; }
void MovieList::Parser()
{
    int count = 0;
    ifstream inputFile;
    inputFile.open(".//12.csv");
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

        // cout << "The director of " << tempMovie->data.ptrToDir->startOfList->data->title << " is " << tempMovie->data.ptrToDir->name << endl;
        /* END: parsing of director ends here */

        // converting crtic for views to int
        getline(inputString, tempString, ',');
        tempMovie->data.num_critic_for_views = atoi(tempString.c_str());

        // converting duration to int
        getline(inputString, tempString, ',');
        tempMovie->data.duration = atoi(tempString.c_str());

        /* START: parsing of actor into ActorNode starts here */
        ActorNode *tempActorNode;
        for (int i = 0; i < 3; i++)
        {
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

            tempActorNode = globalListOfActors->InsertActor(tempString, tempInt); // inserting actor in global list of actor

            tempMovie->data.insertActorInMovie(&(tempActorNode->data)); // inserting actor in actor list

            tempActorNode->data.insertActedMovies(&tempMovie->data);
        }
        /* END:  parsing of actor into ActorNode ends here */

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
        globalListOfYearWiseMovies->insertSorted(&tempMovie->data);
        globalListOfRatingWiseMovies->insertSorted(&tempMovie->data);
        tempString.clear();
        tempString2.clear();
    }
}

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

void Movie::insertActorInMovie(Actor *ptrToActor)
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
void Movie::printActorsOfMovie()
{
    ActorsInMovie *loc = startOfListOfActors;
    int count = 0;
    cout << "The actors of this movie are: " << endl;
    while (loc != NULL)
    {
        cout << ++count << ". " << loc->data->name << endl;
        loc = loc->next;
    }
}

void Actor::insertActedMovies(Movie *ptrToMovie)
{
    MoviesActedIn *newMovie = new MoviesActedIn();
    countOfMovies++;
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
void Actor::printActedMovies()
{
    int count = 0;

    cout << "Actor name: " << name << endl;
    cout << "Movies shooted: " << countOfMovies << endl
         << endl;
    cout << name << " has acted in following movies." << endl;

    loc = startOfList;
    while (loc != NULL)
    {
        cout << ++count << ". " << loc->data->title << " (" << loc->data->year << ")" << endl;
        loc = loc->next;
    }
}
void Actor::findCoActors(MoviesActedIn *loc)
{
    if (loc->data->startOfListOfActors->data->name == name)
    {
        tempCoActor1 = loc->data->startOfListOfActors->next->data->name;
        tempCoActor2 = loc->data->startOfListOfActors->next->next->data->name;
    }
    else if (loc->data->startOfListOfActors->next->data->name == name)
    {
        tempCoActor1 = loc->data->startOfListOfActors->data->name;
        tempCoActor2 = loc->data->startOfListOfActors->next->next->data->name;
    }
    else
    {
        tempCoActor1 = loc->data->startOfListOfActors->data->name;
        tempCoActor2 = loc->data->startOfListOfActors->next->data->name;
    }
}
void Actor::printCoActors()
{
    cout << name << " has acted in following movies with following actors." << endl
         << endl;
    loc = startOfList;

    while (loc != NULL)
    {
        findCoActors(loc);

        cout << "Movie name: " << loc->data->title << " (" << loc->data->year << ")" << endl
             << "Co-Actors: " << tempCoActor1 << " & " << tempCoActor2 << endl
             << endl;

        loc = loc->next;
    }
}
void Actor::checkAandB(string actor2)
{
    loc = startOfList;
    bool areCoActors = false;
    while (loc != NULL)
    {
        findCoActors(loc);
        if (actor2 == tempCoActor1 || actor2 == tempCoActor2)
        {
            areCoActors = true;
            cout << name << " & " << actor2 << " have acted together in " << loc->data->title << "." << endl;
        }
        loc = loc->next;
    }
    if (!areCoActors)
        cout << name << " & " << actor2 << " are not Co-Actors." << endl;
}

void Director::insertDirectedMovies(Movie *ptrToMovie)
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
void Director::printDirectedMovies()
{

    int count = 0;
    cout << name << " has directed the following movies." << endl;
    loc = startOfList;
    while (loc != NULL)
    {
        cout << ++count << ". " << loc->data->title << endl;
        loc = loc->next;
    }
}

ActorNode *ActorTree::InsertActor(string name, unsigned short int fb_likes)
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
bool ActorTree::SearchActor(string name)
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
                return true;
        }
    }
    return false;
}

DirectorNode *DirectorTree::InsertDirector(string name, unsigned short int fb_likes)
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
bool DirectorTree::SearchDirector(string name)
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
                return true;
        }
    }
    return false;
}

bool YearWiseList::isEmpty() { return start == NULL; }
void YearWiseList::insertSorted(Movie *newMovie)
{
    YearWiseNode *newNode = new YearWiseNode();
    newNode->data = newMovie;
    searchNode(newMovie->year);
    if (isEmpty())
    {
        start = newNode;
        newNode->next = NULL;
    }
    else
    {
        if (ploc == NULL) // case when newNode will be first node (list is not empty)
        {
            newNode->next = start;
            start = newNode;
        }
        else if (loc == NULL && ploc != NULL) // case when the newNode will be the last node
        {
            ploc->next = newNode;
            newNode->next = NULL;
        }
        else if (loc != NULL && ploc != NULL) // case when newNode will be inserted somewhere in middle
        {
            ploc->next = newNode;
            newNode->next = loc;
        }
    }
}
void YearWiseList::searchNode(int year)
{
    if (!isEmpty())
    {
        loc = start;
        ploc = NULL;

        while (loc->data->year <= year)
        { /* keep traversing until greater year is found
          if greater year is not found then ploc = last node*/
            ploc = loc;
            loc = loc->next;
            if (loc == NULL)
                break;
        }
        // now ploc is the predecessor of movie node
    }
}
void YearWiseList::printMoviesYearWise()
{
    loc = start;
    while (loc != NULL)
    {
        if (loc->data->year == 0)
            cout << "Year: NOT IN RECORD Title: " << loc->data->title << endl;
        else
            cout << "Year: " << loc->data->year << " Title: " << loc->data->title << endl;
        loc = loc->next;
    }
}
void YearWiseList::printFromYear(int year)
{
    loc = start;
    while (loc != NULL)
    {
        if (loc->data->year == year)
            cout << "Year: " << loc->data->year << " Title: " << loc->data->title << endl;
        if (loc->data->year > year)
            break;
        loc = loc->next;
    }
}

bool RatingWiseList::isEmpty() { return start == NULL; }
void RatingWiseList::insertSorted(Movie *newMovie)
{
    RatingWiseNode *newNode = new RatingWiseNode();
    newNode->data = newMovie;
    searchNode(newMovie->imdb_score);
    if (isEmpty())
    {
        start = newNode;
        newNode->next = NULL;
    }
    else
    {
        if (ploc == NULL) // case when newNode will be first node (list is not empty)
        {
            newNode->next = start;
            start = newNode;
        }
        else if (loc == NULL && ploc != NULL) // case when the newNode will be the last node
        {
            ploc->next = newNode;
            newNode->next = NULL;
        }
        else if (loc != NULL && ploc != NULL) // case when newNode will be inserted somewhere in middle
        {
            ploc->next = newNode;
            newNode->next = loc;
        }
    }
}
void RatingWiseList::searchNode(float rating)
{
    if (!isEmpty())
    {
        loc = start;
        ploc = NULL;

        while (loc->data->imdb_score >= rating)
        { /* keep traversing until greater year is found
          if greater year is not found then ploc = last node*/
            ploc = loc;
            loc = loc->next;
            if (loc == NULL)
                break;
        }
        // now ploc is the predecessor of movie node
    }
}

void RatingWiseList::printMoviesRatingWise()
{
    loc = start;
    while (loc != NULL)
    {
        if (loc->data->imdb_score == 0)
            cout << "Rating: NOT IN RECORD Title: " << loc->data->title << endl;
        else
            cout << "Title: " << loc->data->title << " Rating: " << loc->data->imdb_score << endl;
        loc = loc->next;
    }
}


/* GLOBAL FUNCTIONS */
string convertToLower(string line)
{
    string temp = line;
    for (int i = 0; temp[i] != '\0'; i++)
    {
        // convert temp[i] to lowercase
        temp[i] = tolower(temp[i]);
    }
    return temp;
}
int countCharInAString(string line, char c)
{
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == c)
            count++;
    }
    return count;
}
int main()
{
    MovieList m;
    m.Parser();

    globalListOfActors->SearchActor("Tom Cruise");
    globalListOfActors->loc->data.printCoActors();
}
