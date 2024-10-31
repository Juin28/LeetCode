class Twitter {
private:
    int timer;
    unordered_map<int, vector< pair<int, int> > > tweetList;  // first = timer, second = tweetId
    unordered_map<int, vector<int> > followerList;
    unordered_map<int, vector<int> > followingList;

    void getNewsFeed(int userId, vector< pair<int, int> >& allNewsFeed) {
        vector< pair<int, int> > tweets = tweetList[userId];
        int numOfTweets = tweets.size();
        for (int i = 0; i < numOfTweets; ++i) {
            allNewsFeed.push_back(tweets[i]);
        }
    }
    
public:
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if (tweetList.find(userId) == tweetList.end()) {
            tweetList[userId] = {{timer, tweetId}};
        } else {
            tweetList[userId].push_back({timer, tweetId});
        }

        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector< pair<int, int> > allNewsFeed;

        getNewsFeed(userId, allNewsFeed);

        vector<int>& following = followingList[userId];
        int numFollowing = following.size();
        for (int i = 0; i < numFollowing; ++i) {
            getNewsFeed(following[i], allNewsFeed);
        }

        sort(allNewsFeed.begin(), allNewsFeed.end());

        vector<int> newsFeed;
        int numsOfNewsFeed = allNewsFeed.size();
        int tweetsCount = 0;
        for (int i = 0; i < numsOfNewsFeed; ++i) {
            if (tweetsCount == 10) {
                break;
            }
            
            newsFeed.push_back(allNewsFeed[numsOfNewsFeed - 1 - i].second);
            tweetsCount++;
        }

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }

        if (followerList.find(followeeId) == followerList.end()) {
            followerList[followeeId] = {followerId};
        } else {
            vector<int>& followers = followerList[followeeId];
            auto followerIt = find(followers.begin(), followers.end(), followerId);
            if (followerIt == followers.end()) {
                followerList[followeeId].push_back(followerId);
            }
        }

        if (followingList.find(followerId) == followingList.end()) {
            followingList[followerId] = {followeeId};
        } else {
            vector<int>& following = followingList[followerId];
            auto followingIt = find(following.begin(), following.end(), followeeId);
            if (followingIt == following.end()) {
                followingList[followerId].push_back(followeeId);
            }
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        
        if (followerList.find(followeeId) == followerList.end()) {
            // do nothing
        } else {
            vector<int>& followers = followerList[followeeId];
            auto followerIt = find(followers.begin(), followers.end(), followerId);
            if (followerIt != followers.end()) {
                followers.erase(followerIt);
            }
        }

        if (followingList.find(followerId) == followingList.end()) {
            // do nothing
        } else {
            vector<int>& following = followingList[followerId];
            auto followingIt = find(following.begin(), following.end(), followeeId);
            if (followingIt != following.end()) {
                following.erase(followingIt);
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
