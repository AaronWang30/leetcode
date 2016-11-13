class Twitter {
private:
    struct Tweet {
        int time;
        int id;
        Tweet(int _t, int _id) : time(_t), id(_id) {}
    };
    int cur_time;
public:
    /** Initialize your data structure here. */
    Twitter() {
        cur_time = 0; 
    }
    
    std::unordered_map<int, std::vector<Tweet>> tweets; 
    std::unordered_map<int, std::unordered_set<int>> following; 
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
         tweets[userId].emplace_back(cur_time++,tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */

    vector<int> getNewsFeed(int userId) {
        vector< pair<vector<Tweet>::iterator,vector<Tweet>::iterator>> temp;
        vector<int> r;
        r.reserve(10);
        for(auto& x:following[userId]) {
            if(tweets[x].size()>0){
                temp.emplace_back(make_pair(tweets[x].begin(),tweets[x].end()-1));
            }
        }
        if(tweets[userId].size())
            temp.emplace_back(make_pair(tweets[userId].begin(), tweets[userId].end()-1));

        auto comp = [](const pair<vector<Tweet>::iterator,vector<Tweet>::iterator> x, const pair<vector<Tweet>::iterator,vector<Tweet>::iterator> y) {
            return ((x.second))->time < ((y.second))->time;
        };
        std::make_heap(temp.begin(), temp.end(), comp);
        int i(0);
        while(!temp.empty()&&i++<10) {
            pop_heap(temp.begin(), temp.end(), comp);
            r.push_back(temp.back().second->id);
            if(temp.back().first==temp.back().second--) 
                temp.pop_back();
            else std::push_heap (temp.begin(),temp.end(),comp);
        }
        return r;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
         if (followerId != followeeId)
             following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
          following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */