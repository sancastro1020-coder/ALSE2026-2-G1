#include <bits/stdc++.h>
using namespace std;

class Twitter
{
private:
    unordered_map<int, unordered_set<int>> siguiendo;

    unordered_map<int, vector<pair<int, int>>> tweets;

    int tiempo;

public:

    Twitter()
    {
        tiempo = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        tiempo++;

        tweets[userId].push_back({tiempo, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<pair<int, int>> todosLosTweets;

        // Tweets del propio usuario
        for (auto tweet : tweets[userId])
        {
            todosLosTweets.push_back(tweet);
        }

        // Tweets de los usuarios que sigue
        for (int usuario : siguiendo[userId])
        {
            for (auto tweet : tweets[usuario])
            {
                todosLosTweets.push_back(tweet);
            }
        }

        // Ordenar del más reciente al menos reciente
        sort(todosLosTweets.begin(), todosLosTweets.end(),
             [](pair<int, int> a, pair<int, int> b)
             {
                 return a.first > b.first;
             });

        vector<int> resultado;

        // Máximo 10 tweets
        for (int i = 0; i < todosLosTweets.size() && i < 10; i++)
        {
            resultado.push_back(todosLosTweets[i].second);
        }

        return resultado;
    }

    void follow(int followerId, int followeeId)
    {
        siguiendo[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        siguiendo[followerId].erase(followeeId);
    }
};


int main()
{
    Twitter twitter;

    // Usuario 1 publica el tweet 5
    twitter.postTweet(1, 5);

    vector<int> resultado1 = twitter.getNewsFeed(1);

    cout << "Feed 1: ";

    for (int tweet : resultado1)
    {
        cout << tweet << " ";
    }

    cout << endl;


    // Usuario 1 sigue al usuario 2
    twitter.follow(1, 2);

    // Usuario 2 publica el tweet 6
    twitter.postTweet(2, 6);

    vector<int> resultado2 = twitter.getNewsFeed(1);

    cout << "Feed 2: ";

    for (int tweet : resultado2)
    {
        cout << tweet << " ";
    }

    cout << endl;


    // Usuario 1 deja de seguir al usuario 2
    twitter.unfollow(1, 2);

    vector<int> resultado3 = twitter.getNewsFeed(1);

    cout << "Feed 3: ";

    for (int tweet : resultado3)
    {
        cout << tweet << " ";
    }

    cout << endl;

    return 0;
}
