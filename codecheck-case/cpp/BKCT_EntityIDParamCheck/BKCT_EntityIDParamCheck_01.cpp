//
// Created by wadema on 24-10-9.
//
// define:bkcheck(EntityIDParamCheck)
void bad()
{
    uint32_t iEntityID = 5;
    // bad
    if (!IsSvrEntityIDValid(iEntityID))
    {
        //do xx
    }
    unsigned int iEntityID1 = 5;
    // bad
    if (!IsSvrEntityIDValid(iEntityID1))
    {
        //do xx
    }
    uint32 iEntityID2 = 5;
    // bad
    if (!IsSvrEntityIDValid(iEntityID2))
    {
        //do xx
    }
    unsigned iEntityID3 = 5;
    // bad
    if (!IsSvrEntityIDValid(iEntityID3))
    {
        //do xx
    }
}

void good()
{
    int32_t iEntityID = 5;
    // good
    if (!IsSvrEntityIDValid(iEntityID))
    {
        //do xx
    }
    int iEntityID1 = 5;
    // good
    if (!IsSvrEntityIDValid(iEntityID1))
    {
        //do xx
    }
    int32 iEntityID2 = 5;
    // good
    if (!IsSvrEntityIDValid(iEntityID2))
    {
        //do xx
    }
    signed iEntityID3 = 5;
    // good
    if (!IsSvrEntityIDValid(iEntityID3))
    {
        //do xx
    }
}
