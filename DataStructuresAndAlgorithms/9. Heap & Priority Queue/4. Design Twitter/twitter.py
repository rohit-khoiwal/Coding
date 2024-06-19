import heapq
class Twitter:

    def __init__(self):
        self.accounts = {}
        self.newFeed = []
        self.count = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        if not userId in self.accounts:
            self.accounts[userId] = set([userId])
        heapq.heappush(self.newFeed, (self.count, userId, tweetId))
        self.count += 1
        # print(self.accounts)
    def getNewsFeed(self, userId: int):
        i = 0
        recentTweets = heapq.nlargest(20, self.newFeed)
        # print(recentTweets)
        tweets = []
        for recentTweet in recentTweets:
            if i == 10:
                return tweets
            print(recentTweet)
            if recentTweet[1] in self.accounts[userId]:
                tweets.append(recentTweet[2])
                i += 1
        return tweets            
        

    def follow(self, followerId: int, followeeId: int) -> None:
        self.accounts[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.accounts[followerId].remove(followeeId)

if __name__ == '__main__':
    a = set()
    obj = Twitter()
    methods = ["postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
    arguments = [[1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
    for i, method in enumerate(methods):
        if method == "postTweet":
            print(obj.postTweet(*arguments[i]), end=' ')
        elif method == "getNewsFeed":
            print(obj.getNewsFeed(*arguments[i]), end=' ')
        elif method == "follow":
            print(obj.follow(*arguments[i]), end=' ')
        else:
            print(obj.unfollow(*arguments[i]), end=' ')