/* things to do at end */
// 10 part b
// make search functions non-case sensitive

/* HEADER FILES */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "SLL.h"

using namespace std;

// classes relevant to actors
/* GLOBAL FUNCTIONS PROTOTYPES */
string convertToLower(string line);
int countCharInAString(string line, char c);
string convertEnumToString(int eNumber);
int convertStringToEnum(string genre);

/* FORWARD DECLARATION OF ALL CLASSES */

class Actor;         // Actor data type
class ActorNode;     // node of ActorTree
class ActorTree;     // BST of ActorNode
class MoviesActedIn; // a list to store pointer of all movies in which a particular actor has acted in
class CoActorNode;   // a node of list of an actor's co actors, this list also contains a list of common movies

// classes relevant to directors
class Director;       // Director data type
class DirectorNode;   // node of DirectorTree
class DirectorTree;   // BST of DirectorNode
class MoviesDirected; // a list to store pointer of all movies which are directed by a particular director

// classes relevant to movies
class Movie;          // Movie data type
class MovieNode;      // node of MovieTree, its data part is the Movie class
class MovieTree;      // BST of MovieNode
class ActorsInMovie;  // a node of a list that stores pointer of all actors who have acted in a movie
class IndexedNode;    // node of the above class
class YearWiseList;   // a list to store movies in ascending order of year released
class RatingWiseList; // a list to store movies in ascending order of rating

// classes relevant to genre
class GenreNode;

// classes relevant to keywords
class KeyWordNode;

/* CLASS DEFINITIONS */

class Actor
{
public:
    string name;
    unsigned short int fb_likes;
    unsigned int countOfMovies = 0;
    MoviesActedIn *startOfList;
    MoviesActedIn *ploc = NULL;
    MoviesActedIn *loc = NULL;
    CoActorNode *startOfCoActorsList = NULL;
    /* Function that inserts movies in actor's movie list in alphabetical order */
    void insertActedMovies(Movie *ptrToMovie);
    /* 1. Function that prints details of an actor */
    void printActedMovies();
    /* 5. Check whether 2 actors are coActors */
    void checkCoActors(string actor2);
    /* insert Actors in list of Co Actors list */
    void insertCoActor(Actor *coActor, Movie *movie);
    /* 3. Prints unique co actors of an actor and all the movies they have acted in */
    void printUniqueCoActors();
    /* Prints only the names of all co actors of an actor */
    void printCoActorNameOnly(string dontPrint);
    /* 4. Prints co actors of co actors of an actor */
    void printCoActorsOfCoActors();
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

    /* function to check if tree is empty */
    bool isEmpty() { return root == NULL; }

    /* If Tree is empty or the director node is not found
    it will insert a newNode of DirectorNode type and return the node's address
    however if the directorNode was already found in search function,
    then it will only return the node's address */
    ActorNode *InsertActor(string name, unsigned short int fb_likes);

    /* If the actor is found in the tree
    the function will return true
    else the function will return false */
    bool SearchActor(string name);

    /* function that traverses through actor tree and prints name of actor whose name matches searchedName */
    void DeepSearchActor(ActorNode *ptr, string searchedName);
};
class MoviesActedIn
{
public:
    Movie *data;
    MoviesActedIn *next = NULL;
};
class CoActorNode
{
public:
    Actor *data;
    CoActorNode *next = NULL;
    MoviesActedIn *startOfListOfCommonMovies = NULL;
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
    /* function to check if a director has directed movie of a certain genre */
    bool checkGenreForDirector(string genre);
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
    else the function will return false */

    /* 7. Print directors who have directed movies of a certain genre */
    void printDirectorOfGenres(DirectorNode *ptr, string genre);
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
    GenreNode *startOfListOfGenres = NULL;
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
    KeyWordNode *startOfListOfKeywords;
    string imdb_link;
    unsigned short int num_user_reviews;
    string language; // enum
    string country;
    string content_rating; // enum
    long budget;
    float aspect_ratio;
    unsigned int movie_fb_likes;
    bool color;
    /* a function that inserts a genre in a movie */
    void insertGenreInMovie(int genreToBeInserted);
    /* a function that inserts a keyword in a movie */
    void insertKeywordInMovie(string keyWordToBeInserted);
    /* a function that inserts an actor in a movie */
    void insertActorInMovie(Actor *ptrToActor);

    bool checkGenreInMovie(string genre);
    bool checkKeywordInMovie(string keyword);
    void printActorsOfMovie();
    void printGenresOfMovie();
};
class MovieNode
{
public:
    Movie data;
    MovieNode *right;
    MovieNode *left;
};
class MovieTree
{
public:
    MovieNode *root = NULL;
    MovieNode *ploc = NULL;
    MovieNode *loc = NULL;
    // user-defined functions

    /* Function that checks if MovieTree is empty */
    bool isEmpty();

    /* Function that reads 1 line of CSV,
    creates object of MovieNode,
    stores all entries in data part of MovieNode,
    calls InsertMovie function to insert tempMovie in DLL */
    void Parser();

    /* If Tree is empty or the movie node is not found
    it will insert a newNode of MovieNode type and return the node's address
    however if the MovieNode was already found in search function,
    then it will only return the node's address */
    void InsertMovie(MovieNode *tempMovie);

    /* If the movie is found in the tree
    the function will return true and store the movie address in loc
    else the function will return false */
    bool SearchMovieName(string name);

    /* Function that prints title/details of all movies
    in alphabetical order of title */
    void PrintMovies(MovieNode *ptr);

    /* 8. Search a movie by name or keywords, (movie title not necessarily complete) */
    void DeepSearchMovie(MovieNode *ptr, string searchedWord);

    /* Print all details of a movie */
    void PrintMovieDetails(string movieTitle);
};
class ActorsInMovie
{
public:
    Actor *data;
    ActorsInMovie *next;
};
class YearWiseList
{
public:
    IndexedNode *start = NULL;
    IndexedNode *ploc = NULL;
    IndexedNode *loc = NULL;
    bool isEmpty();
    void searchNode(int year);
    /* inserts ptr to movie in the list in order of its release year */
    void insertSorted(Movie *newMovie);
    /* 10. a) Prints movie titles increasing year-wise */
    void printMoviesYearWise();
    /* 10. b) Prints movie titles decreasing year-wise */
    void printMoviesYearWiseDescending(IndexedNode *ptr);
    /* 9. Prints all movie titles released in the given year */
    void printFromYear(int year);
};
class IndexedNode
{
public:
    Movie *data;
    IndexedNode *next = NULL;
};
class RatingWiseList
{
public:
    IndexedNode *start = NULL;
    IndexedNode *ploc = NULL;
    IndexedNode *loc = NULL;
    bool isEmpty();

    void searchNode(float rating);
    /* inserts ptr to movie in the list in order of its rating */
    void insertSorted(Movie *newMovie);
    /* 12. Prints movies from highest to lowest rating .*/
    void printMoviesRatingWise();
    /* 13. Print movies of a certain genre Rating Wise */
    void printMoviesOfGenre(string genre);
};

class GenreNode
{
public:
    int genreEnum;
    GenreNode *next = NULL;
};

class KeyWordNode
{
public:
    string keyword;
    KeyWordNode *next;
};

/* ENUM */
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

/* GLOBAL VARIABLE LISTS */
ActorTree *globalListOfActors = new ActorTree();
DirectorTree *globalListOfDirectors = new DirectorTree();
YearWiseList *globalListOfYearWiseMovies = new YearWiseList();
RatingWiseList *globalListOfRatingWiseMovies = new RatingWiseList();

/* FUNCTION DEFINITIONS OF CLASS FUNCTIONS */

void Movie::insertGenreInMovie(int genreToBeInserted)
{
    GenreNode *loc;
    GenreNode *ploc;
    GenreNode *newGenre = new GenreNode();
    newGenre->genreEnum = genreToBeInserted;
    newGenre->next = NULL;
    if (startOfListOfGenres == NULL)
        startOfListOfGenres = newGenre;
    else
    {
        loc = startOfListOfGenres;
        while (loc != NULL)
        {
            ploc = loc;
            loc = loc->next;
        }
        ploc->next = newGenre;
    }
}
void Movie::insertKeywordInMovie(string keyWordToBeInserted)
{
    KeyWordNode *loc;
    KeyWordNode *ploc;
    KeyWordNode *newGenre = new KeyWordNode();
    newGenre->keyword = keyWordToBeInserted;
    newGenre->next = NULL;
    if (startOfListOfKeywords == NULL)
        startOfListOfKeywords = newGenre;
    else
    {
        loc = startOfListOfKeywords;
        while (loc != NULL)
        {
            ploc = loc;
            loc = loc->next;
        }
        ploc->next = newGenre;
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
bool Movie::checkGenreInMovie(string genre)
{
    GenreNode *loc = startOfListOfGenres;
    int genreNum = convertStringToEnum(genre);
    if (genreNum != -1)
    {
        while (loc != NULL)
        {
            if (genreNum == loc->genreEnum)
                return true;
            loc = loc->next;
        }
    }
    else
        cout << "Invalid genre type." << endl;
    return false;
}
bool Movie::checkKeywordInMovie(string keyword)
{
    KeyWordNode *loc = startOfListOfKeywords;
    while (loc != NULL)
    {
        if (loc->keyword.find(keyword) != string::npos)
            return true;
        loc = loc->next;
    }
    return false;
}
void Movie::printActorsOfMovie()
{
    ActorsInMovie *loc = startOfListOfActors;
    int count = 0;
    cout << "MAIN ACTORS: " << endl;
    while (loc != NULL)
    {
        cout << ++count << ". " << loc->data->name << endl;
        loc = loc->next;
    }
}
void Movie::printGenresOfMovie()
{
    GenreNode *loc = startOfListOfGenres;
    cout << "GENRES: ";
    while (loc != NULL)
    {
        cout << convertEnumToString(loc->genreEnum) << " ";
        loc = loc->next;
    }
    cout << endl;
}

bool MovieTree::isEmpty() { return root == NULL; }
void MovieTree::Parser()
{
    int count = 0;
    ifstream inputFile;
    inputFile.open(".//12 - Copy.csv");
    string line = "";

    /* global list of actors and directors is made */

    // parsing of each row in data part of MovieNode i.e Movie
    while (getline(inputFile, line))
    {
        if (count != 0)
        {
            MovieNode *tempMovie = new MovieNode();
            stringstream inputString(line);
            // temporary string to convert string to numeric data types
            string tempString, tempString2;
            int tempInt;
            getline(inputString, tempMovie->data.title, ',');

            /* START: Genres are parsed
            converted to their respective eNums
            and stored in a dynamic array of int */

            //  tempString is a string containing all genres
            getline(inputString, tempString, ',');

            /* we count '|' in tempString
            sizeOfGenre = count+1 */
            int countOfGenres = countCharInAString(tempString, '|') + 1;
            string tempGenre;

            // stringstream helps to separate genres using separator '|'
            stringstream genreString(tempString);

            // separation of genres, and storing them in eNums
            for (int i = 0; i < countOfGenres; i++)
            {
                if (i == countOfGenres - 1)
                    getline(genreString, tempString);
                else
                    getline(genreString, tempString, '|');
                // converting genre into its enum
                tempInt = convertStringToEnum(tempString);
                // storing each eNum in a linked list of int
                tempMovie->data.insertGenreInMovie(tempInt);
            }
            // number of genres are also stored in Movie
            /* END */

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
            update name, fb_likes, MoviesDirected for that director */

            DirectorNode *tempDirectorNode;
            /* inserting director in global list of directors without duplication */
            tempDirectorNode = globalListOfDirectors->InsertDirector(tempString, tempInt);
            // setting ptrToDir equal to its director
            tempMovie->data.ptrToDir = &tempDirectorNode->data;
            // adding movie nodes in director's directed movies
            tempMovie->data.ptrToDir->insertDirectedMovies(&tempMovie->data);

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
            Actor *tempActor[3];

            for (int i = 0; i < 3; i++)
            {
                getline(inputString, tempString, ',');

                // converting actor fb likes to int
                getline(inputString, tempString2, ',');
                tempInt = atoi(tempString2.c_str());

                /* create a new ActorsInMovie list that contains list of actors of this movie
                parse name of actor1, and search it in global list of actors
                if found, insert pointer of his node to ActorsInMovie
                update moviesActedIn for that actor

                if not found, insert a new node of Actor type in global list of actors
                insert pointer of his node to ActorsInMovie
                update actor name, fb likes, moviesActedIn for that actor */

                /*  inserting actor in global list of actor, and storing its address in tempActorNode[i] */
                tempActorNode = globalListOfActors->InsertActor(tempString, tempInt);

                /* inserting actor in actor list of movie */
                tempMovie->data.insertActorInMovie(&(tempActorNode->data));

                /* inserting movie in actor's acted movies */
                tempActorNode->data.insertActedMovies(&tempMovie->data);
                // array of pointer to all 3 actors
                tempActor[i] = &tempActorNode->data;
            }
            // inserting co actors of all 3 actors here
            for (int i = 0; i < 3; i++)
            {
                tempActor[i]->insertCoActor(tempActor[(i + 1) % 3], &tempMovie->data);
                tempActor[i]->insertCoActor(tempActor[(i + 2) % 3], &tempMovie->data);
            }

            /* END:  parsing of actor into ActorNode ends here */

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

            /* START: start of parsing of keywords */
            getline(inputString, tempString, ',');
            int countOfKeywords = countCharInAString(tempString, '|') + 1;
            stringstream KeywordString(tempString);

            for (int i = 0; i < countOfKeywords; i++)
            {
                if (i == countOfKeywords - 1)
                    getline(KeywordString, tempString);
                else
                    getline(KeywordString, tempString, '|');
                tempMovie->data.insertKeywordInMovie(tempString);
            }
            /* END: end of parsing of keywords */

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

            // inserting MovieNode in MovieTree
            InsertMovie(tempMovie);
            // inserting address of Movie in an Year Wise index
            globalListOfYearWiseMovies->insertSorted(&tempMovie->data);
            // inserting address of Movie in a Rating Wise index
            globalListOfRatingWiseMovies->insertSorted(&tempMovie->data);
        }
        else
            count++;
    }
}
void MovieTree::InsertMovie(MovieNode *tempMovie)
{

    /* if DLL is empty */
    MovieNode *newNode = new MovieNode();
    newNode = tempMovie;
    SearchMovieName(tempMovie->data.title);
    if (isEmpty())
    {
        root = newNode;
    }
    else
    {
        if (ploc->data.title > newNode->data.title)
            ploc->left = newNode;
        else if (ploc->data.title <= newNode->data.title)
            ploc->right = newNode;
    }
}
bool MovieTree::SearchMovieName(string name)
{
    if (!isEmpty())
    {
        loc = root;
        ploc = NULL;
        while (loc != NULL)
        {
            // cout << convertToLower(name) << endl;
            // cout << convertToLower(loc->data.title) << endl;
            if (convertToLower(name) != convertToLower(loc->data.title)) // keep traversing if node not found
            {
                ploc = loc;
                if (name < loc->data.title)
                    loc = loc->left;
                else if (name > loc->data.title)
                    loc = loc->right;
            }
            else // return if node found, loc contains address of node
                return true;
        }
    }
    return false;
}
void MovieTree::PrintMovies(MovieNode *ptr)
{
    if (ptr == root)
        cout << "The movies in our database are: \n\n";
    if (!isEmpty())
    {
        if (ptr != NULL)
        {
            PrintMovies(ptr->left);
            cout << ptr->data.title << endl;
            PrintMovies(ptr->right);
        }
    }
}
void MovieTree::DeepSearchMovie(MovieNode *ptr, string searchedWord)
{
    if (searchedWord.size() < 3)
    {
        cout << "You must enter at least 3 letters for the search to proceed. " << endl;
        return;
    }
    else
    {
        /* traverse through movies
        check if searchedWord exist in movie title,
        if yes, then print movie name
        else proceed
        also check if searchedWord == keyword of movie
        if yes then print movie name
        else proceed  */
        if (ptr == root)
            cout << "Movies relevant to the word " << searchedWord << " are:\n\n";
        if (ptr != NULL)
        {
            DeepSearchMovie(ptr->left, searchedWord);
            string tempTitle = convertToLower(ptr->data.title);
            if (tempTitle.find(convertToLower(searchedWord)) != string::npos || ptr->data.checkKeywordInMovie(searchedWord))
                cout << "Title: " << ptr->data.title << endl;
            DeepSearchMovie(ptr->right, searchedWord);
        }
    }
}
void MovieTree::PrintMovieDetails(string movieTitle)
{
    if (SearchMovieName(movieTitle))
    {
        cout << "Movie search successful! The movie details are:" << endl
             << endl;
        cout << "MOVIE TITLE: " << loc->data.title << endl;
        loc->data.printGenresOfMovie();
        cout << "RELEASED IN: " << loc->data.year << endl
             << "RATING: " << loc->data.imdb_score << endl
             << "DIRECTED BY: " << loc->data.ptrToDir->name << endl
             << "DURATION: " << loc->data.duration << " minutes" << endl;
        loc->data.printActorsOfMovie();
        cout << "GROSS: " << loc->data.gross << endl
             << "TOTAL VOTES: " << loc->data.num_voted_users << endl
             << "CAST TOTAL LIKES ON FACEBOOK: " << loc->data.cast_total_fb_likes << endl
             << "IMDB LINK: " << loc->data.imdb_link << endl
             << "REVIEWED BY " << loc->data.num_user_reviews << " users" << endl
             << "LANGUAGE: " << loc->data.language << endl
             << "COUNTRY: " << loc->data.country << endl
             << "CONTENT RATING: " << loc->data.content_rating << endl
             << "BUDGET: " << loc->data.budget << endl
             << "FACEBOOK LIKES: " << loc->data.movie_fb_likes << endl
             << "COLORS: " << (loc->data.color ? "Colored" : "Black and White") << endl
             << endl;
    }
    else
        cout << "No such movie exists. Make sure you have entered the complete title, or try deep search to see related movies." << endl;
}

void Actor::insertActedMovies(Movie *ptrToMovie)
{
    MoviesActedIn *newMovie = new MoviesActedIn();
    countOfMovies++;
    newMovie->data = ptrToMovie;
    newMovie->next = NULL;
    if (startOfList == NULL) // inserting movie in an empty list
        startOfList = newMovie;
    else
    {

        loc = startOfList;
        if (loc->data->title > newMovie->data->title)
        { // inserting movie at front
            newMovie->next = startOfList;
            startOfList = newMovie;
        }
        else
        { // inserting movie somewhere in middle or end
            while (loc->data->title <= newMovie->data->title)
            {
                ploc = loc;
                loc = loc->next;
                if (loc == NULL) // if loc becomes null then movie will be inserted at end
                    break;
            }
            ploc->next = newMovie;
            newMovie->next = loc;
        }
        // while (loc != NULL)
        // {
        //     ploc = loc;
        //     loc = loc->next;
        // }
    }
}
void Actor::printActedMovies()
{
    int count = 0;

    cout << "Actor Name: " << name << endl
         << "Facebook Likes: " << fb_likes << endl
         << "Movies shooted: " << countOfMovies << endl
         << endl;
    cout << name << " has acted in following movies." << endl;

    loc = startOfList;
    while (loc != NULL)
    {
        cout << ++count << ". " << loc->data->title << " (" << loc->data->year << ")" << endl;
        loc = loc->next;
    }
}
void Actor::insertCoActor(Actor *coActor, Movie *movie)
{
    // if list is empty startofco = actor, start of movie list = movie
    // else
    // check if coactor already exists in the list
    // if co actor exists then only insert movie
    // if co actor does not exist then insert co actor and movie
    MoviesActedIn *newMovieNode = new MoviesActedIn;
    newMovieNode->data = movie;
    if (startOfCoActorsList == NULL)
    {
        CoActorNode *newCoActorNode = new CoActorNode;
        newCoActorNode->data = coActor;
        startOfCoActorsList = newCoActorNode;
        // insert movie
        newCoActorNode->startOfListOfCommonMovies = newMovieNode;
    }
    else
    {
        CoActorNode *loc = startOfCoActorsList;
        CoActorNode *ploc = NULL;
        bool coActorExists = false;
        // traverse thru list
        while (loc != NULL)
        {
            if (loc->data == coActor) // coactor already exist
            {
                coActorExists = true;
                break;
            }
            ploc = loc;
            loc = loc->next;
        }
        if (coActorExists)
        {
            // insert movie
            {
                // always insert at front (to reduce time complexity) as order doesnot matter
                newMovieNode->next = loc->startOfListOfCommonMovies;
                loc->startOfListOfCommonMovies = newMovieNode;
            }
        }
        else
        { // co actor does not exist, ploc points to last co actor
          // insert movie and coactor
            CoActorNode *newCoActorNode = new CoActorNode;
            newCoActorNode->data = coActor;
            ploc->next = newCoActorNode;
            // insert movie
            // always insert at front (to reduce time complexity) as order doesnot matter
            newMovieNode->next = newCoActorNode->startOfListOfCommonMovies;
            newCoActorNode->startOfListOfCommonMovies = newMovieNode;
        }
    }
}
void Actor::printUniqueCoActors()
{ // simply prints the list of co actors of an actor and the list of movies they have acted together
    CoActorNode *loc = startOfCoActorsList;
    cout << "Co-Actors of " << name << " are:" << endl;
    while (loc != NULL)
    {
        cout << loc->data->name << " in ";
        MoviesActedIn *movieLoc = loc->startOfListOfCommonMovies;
        while (movieLoc != NULL)
        {
            if (movieLoc != loc->startOfListOfCommonMovies)
                cout << " | ";
            cout << movieLoc->data->title;
            movieLoc = movieLoc->next;
        }
        cout << endl;
        loc = loc->next;
    }
    cout << endl;
}
void Actor::checkCoActors(string actor2)
{
    bool isCoActor = false;
    CoActorNode *loc;
    for (loc = startOfCoActorsList; loc != NULL; loc = loc->next)
    {
        if (loc->data->name == actor2)
        {
            isCoActor = true;
            break;
        }
    }
    if (isCoActor)
    {
        cout << name << " and " << loc->data->name << " are Co Actors, they have acted together in:" << endl;
        for (MoviesActedIn *movieLoc = loc->startOfListOfCommonMovies; movieLoc != NULL; movieLoc = movieLoc->next)
        {
            cout << movieLoc->data->title << " (" << movieLoc->data->year << ")" << endl;
        }
    }
    else
        cout << name << " and " << actor2 << " are not Co Actors" << endl;
}
void Actor::printCoActorNameOnly(string dontPrint)
{
    CoActorNode *loc = startOfCoActorsList;
    while (loc != NULL)
    {
        // dont print original actor's name
        if (loc->data->name != dontPrint)
            cout << loc->data->name << endl;
        loc = loc->next;
    }
    cout << endl;
}
void Actor::printCoActorsOfCoActors()
{
    CoActorNode *loc = startOfCoActorsList;
    while (loc != NULL)
    {
        cout << "Co Co Actors of " << name << " via " << loc->data->name << ":" << endl;
        // print all co actors of co actors except the original actor
        loc->data->printCoActorNameOnly(name);
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
void ActorTree::DeepSearchActor(ActorNode *ptr, string searchedName)
{
    if (searchedName.size() < 2)
    {
        cout << "You must enter at least 2 letters for the search to proceed" << endl;
    }
    else
    {
        if (ptr == root)
            cout << "The following actors have been found.\n\n";
        if (ptr != NULL)
        {
            DeepSearchActor(ptr->left, searchedName);
            string tempName = convertToLower(ptr->data.name);
            if (tempName.find(convertToLower(searchedName)) != string::npos)
                cout << ptr->data.name << endl;
            DeepSearchActor(ptr->right, searchedName);
        }
    }
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
bool Director::checkGenreForDirector(string genre)
{
    MoviesDirected *tempPtr = startOfList;
    while (tempPtr != NULL)
    { /* traverse the linked list of movies directed by the director,
     and if any movie node contains the genre, then return true */
        if (tempPtr->data->checkGenreInMovie(genre))
            return true;
        tempPtr = tempPtr->next;
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
void DirectorTree::printDirectorOfGenres(DirectorNode *ptr, string genre)
{
    if (!isEmpty())
    {
        if (ptr != NULL)
        {
            printDirectorOfGenres(ptr->left, genre);
            // check if the
            if (ptr->data.checkGenreForDirector(genre))
                cout << ptr->data.name << " " << endl;
            printDirectorOfGenres(ptr->right, genre);
        }
    }
}

bool YearWiseList::isEmpty() { return start == NULL; }
void YearWiseList::insertSorted(Movie *newMovie)
{
    IndexedNode *newNode = new IndexedNode();
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
          if greater year is not found then ploc = last node */
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
void YearWiseList::printMoviesYearWiseDescending(IndexedNode *ptr)
{
    if (ptr == NULL)
        return;
    printMoviesYearWiseDescending(ptr->next);
    if (ptr->data->year == 0)
        cout << "Year: NOT IN RECORD Title: " << ptr->data->title << endl;
    else
        cout << "Year: " << ptr->data->year << " Title: " << ptr->data->title << endl;
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

void RatingWiseList::printMoviesOfGenre(string genre)
{
    loc = start;
    while (loc != NULL)
    {
        if (loc->data->checkGenreInMovie(genre))
            cout << "Genre: " << genre << "\tRating: " << loc->data->imdb_score << "\tMovie Title: " << loc->data->title << endl;
        loc = loc->next;
    }
}
bool RatingWiseList::isEmpty()
{
    return start == NULL;
}
void RatingWiseList::insertSorted(Movie *newMovie)
{
    IndexedNode *newNode = new IndexedNode();
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
          if greater year is not found then ploc = last node */
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
            cout << "Title: " << loc->data->title << " RATING: " << loc->data->imdb_score << endl;
        loc = loc->next;
    }
}

/* GLOBAL FUNCTIONS */

string convertEnumToString(int eNumber)
{
    switch (eNumber)
    {
    case Action:
        return "Action";
    case Adventure:
        return "Adventure";
    case Animation:
        return "Animation";
    case Biography:
        return "Biography";
    case Comedy:
        return "Comedy";
    case Crime:
        return "Crime";
    case Documentary:
        return "Documentary";
    case Drama:
        return "Drama";
    case Family:
        return "Family";
    case Fantasy:
        return "Fantasy";
    case FilmNoir:
        return "Film-Noir";
    case History:
        return "History";
    case Horror:
        return "Horror";
    case Music:
        return "Music";
    case Musical:
        return "Musical";
    case Mystery:
        return "Mystery";
    case Romance:
        return "Romance";
    case SciFi:
        return "Sci-Fi";
    case Short:
        return "Short";
    case Sport:
        return "Sport";
    case Superhero:
        return "Superhero";
    case Thriller:
        return "Thriller";
    case War:
        return "War";
    case Western:
        return "Western";
    default:
        return "Invalid Enum";
    }
}
int convertStringToEnum(string genre)
{
    if (genre == "Action")
        return 0;
    else if (genre == "Adventure")
        return 1;
    else if (genre == "Animation")
        return 2;
    else if (genre == "Biography")
        return 3;
    else if (genre == "Comedy")
        return 4;
    else if (genre == "Crime")
        return 5;
    else if (genre == "Documentary")
        return 6;
    else if (genre == "Drama")
        return 7;
    else if (genre == "Family")
        return 8;
    else if (genre == "Fantasy")
        return 9;
    else if (genre == "FilmNoir" || genre == "Film-Noir")
        return 10;
    else if (genre == "History")
        return 11;
    else if (genre == "Horror")
        return 12;
    else if (genre == "Music")
        return 13;
    else if (genre == "Musical")
        return 14;
    else if (genre == "Mystery")
        return 15;
    else if (genre == "Romance")
        return 16;
    else if (genre == "SciFi" || genre == "Sci-Fi")
        return 17;
    else if (genre == "Short")
        return 18;
    else if (genre == "Sport")
        return 19;
    else if (genre == "Superhero")
        return 20;
    else if (genre == "Thriller")
        return 21;
    else if (genre == "War")
        return 22;
    else if (genre == "Western")
        return 23;
    else
        return -1;
}
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

void PrintInstructions()
{
    cout << "WELCOME TO IMDB" << endl
         << endl
         << "Enter the a number to search the following " << endl
         << endl
         << "1. Search profile of an Actor." << endl
         << "2. Deep search an actor." << endl
         << "3. Search Co Actors of an Actor and the Movies in which both acted." << endl
         << "4. Print a list of all coactors of the coactors of an actor." << endl
         << "5. Check of two Actors are Co Actors." << endl
         << endl
         << "6. Search profile of a Director." << endl
         << "7. Search Directors of a specific Genre." << endl
         << endl
         << "8. Search a Movie." << endl
         << "9. Deep search a Movie." << endl
         << "10. Search Movies released in a specific year." << endl
         << "11. Search latest Movies." << endl
         << "12. Search oldest Movies." << endl
         << "13. Search all Movies of a specific Genre." << endl
         << "14. Search Top-Rated Movies." << endl
         << endl
         << "Enter 0 to exit." << endl
         << endl
         << "Your input: ";
}

int main()
{
    srand(time(0));
    time_t start = clock();
    MovieTree m;
    int command;
    string name1, name2;
    m.Parser();

    // cout << "Time Taken: " << (clock() - start) / (double)CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;

    PrintInstructions();
    cin >> command;
    system("cls");
    switch (command)
    {
    case 1:
    {
        cout << "Enter the name of actor you want to search: ";
        getchar();
        getline(cin, name1);
        /* 1. */ globalListOfActors->SearchActor(name1);
        globalListOfActors->loc->data.printActedMovies();
        cout << "Enter any key to proceed...   ";
        system("pause");
        break;
    }
    case 2:
    {
        cout << "Enter the name of actor you want to DEEP search: ";
        getchar();
        getline(cin, name1);
        globalListOfActors->DeepSearchActor(globalListOfActors->root, name1);
        cout << "Enter any key to proceed...   ";
        system("pause");
        break;
    }
    case 3:
    {
        cout << "Enter the name of Actor whose Co Actors you want to search: ";
        getchar();
        getline(cin, name1);
        /* 3. */ globalListOfActors->SearchActor(name1);
        globalListOfActors->loc->data.printUniqueCoActors();
        cout << "Enter any key to proceed...   ";
        system("pause");
        break;
    }
    case 4:
    {
        cout << "Enter the name of Actor whose Co-Co Actors you want to search: ";
        getchar();
        getline(cin, name1);
        /* 4. */ globalListOfActors->SearchActor(name1);
        globalListOfActors->loc->data.printCoActorsOfCoActors();
        cout << "Enter any key to proceed...   ";
        system("pause");
        break;
    }
    case 5:
    {
        cout << "Enter name of first actor: ";
        getline(cin, name1);

        cout << "Enter name of second actor: ";
        getline(cin, name2);
        /* 5. */ globalListOfActors->SearchActor(name1);
        globalListOfActors->loc->data.checkCoActors(name2);
        cout << "Enter any key to proceed...   ";
        system("pause");
        break;
    }
    case 6:
    {
        cout << "Enter the name of Director you want to search: ";
        getchar();
        getline(cin, name1);
        /* 6. */ if (globalListOfDirectors->SearchDirector(name1))
            globalListOfDirectors->loc->data.printDirectedMovies();
        else
            cout << "Director does not exist, try searching again.\n";
        system("pause");

        break;
    }
    case 7:
    {
        cout << "Enter a Genre: ";
        getchar();
        getline(cin, name1);
        if (convertStringToEnum(name1) == -1)
            cout << "Invalid genre, try again." << endl;
        else
            /* 7. */ globalListOfDirectors->printDirectorOfGenres(globalListOfDirectors->root, name1);
        system("pause");

        break;
    }
    case 8:
    {
        cout << "Enter movie name: ";
        getchar();
        getline(cin, name1);
        /* 8. Direct Search */
        m.PrintMovieDetails(name1);
        system("pause");
        break;
    }
    case 9:
    {
        cout << "Enter a keyword to deep search a movie: ";
        getchar();
        getline(cin, name1);
        /*  Deep Search */
        m.DeepSearchMovie(m.root, "flashdance");
        system("pause");
        break;
    }
    case 10:
    {
        /* 9. */ globalListOfYearWiseMovies->printFromYear(2013);

        break;
    }
    case 11:
    {
        /* 10. b) */ globalListOfYearWiseMovies->printMoviesYearWiseDescending(globalListOfYearWiseMovies->start);

        break;
    }
    case 12:
    {
        /* 10. a) */ globalListOfYearWiseMovies->printMoviesYearWise();
        break;
    }
    case 13:
    {
        // /* 13. */   globalListOfRatingWiseMovies->printMoviesOfGenre("Action");

        break;
    }
    case 14:
    {
        /* 12. */ globalListOfRatingWiseMovies->printMoviesRatingWise();
        break;
    }
    case 0:
    {
        // exit here
        break;
    }
    default:
        cout << "Enter a valid input" << endl;
        break;
    }
    system("cls");

    // /* Print only names of all movies (Alphabetical) */m.PrintMovies(m.root);
}
