/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */
#include "main.h"

// @lc code=start
class Twitter {
    struct Node {
        unordered_set<int> followee;
        list<int> tweet;
    };
    int recentMax, time;
    unordered_map<int, int> tweetTime;
    unordered_map<int, Node> user;

    void init(int userId) {
        user[userId].followee.clear();
        user[userId].tweet.clear();
    }

  public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
        recentMax = 10;
        user.clear();
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (user.find(userId) == user.end())
            init(userId);
        if (user[userId].tweet.size() == recentMax)
            user[userId].tweet.pop_back();
        user[userId].tweet.push_front(tweetId);
        tweetTime[tweetId] = ++time;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
     * in the news feed must be posted by users who the user followed or by the
     * user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        ans.clear();
        for (auto it : user[userId].tweet)
            ans.push_back(it);
        for (int followId : user[userId].followee) {
            if (followId == userId)
                continue;
            vector<int> res;
            res.clear();
            auto it = user[followId].tweet.begin();
            int i = 0;
            while (i < ans.size() && it != user[followId].tweet.end()) {
                if (tweetTime[*it] > tweetTime[ans[i]]) {
                    res.push_back(*it);
                    ++it;
                } else {
                    res.push_back(ans[i]);
                    ++i;
                }
                if (res.size() == recentMax)
                    break;
            }
            for (; i < ans.size() && res.size() < recentMax; ++i)
                res.push_back(ans[i]);
            for (; it != user[followId].tweet.end() && res.size() < recentMax;
                 ++it)
                res.push_back(*it);
            ans.assign(res.begin(), res.end());
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a
     * no-op. */
    void follow(int followerId, int followeeId) {
        if (user.find(followerId) == user.end())
            init(followerId);
        if (user.find(followeeId) == user.end())
            init(followeeId);
        user[followerId].followee.insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be
     * a no-op. */
    void unfollow(int followerId, int followeeId) {
        user[followerId].followee.erase(followeeId);
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
// @lc code=end
