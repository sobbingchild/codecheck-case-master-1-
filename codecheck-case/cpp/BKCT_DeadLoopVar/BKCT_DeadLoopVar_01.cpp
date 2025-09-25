//
// Created by wadema on 24-8-6.
//
// define:bkcheck(DeadLoopVar)
void good()
{
    int iDeadLoop = 0;
    // good
    for (auto itr = vecRequests.begin(); vecRequests.end() != itr; ++itr)
    {
        DEADLOOP_CHECK_MAX(iDeadLoop, MAX_FRIEND_REQUEST_NUM);
        //do xxx
    }
}

void bad()
{
    // bad
    for (auto element : COLLECTION)
    {
    }
}
