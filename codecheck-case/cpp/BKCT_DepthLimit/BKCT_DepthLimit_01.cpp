//
// Created by wadema on 24-8-6.
//
// define:bkcheck(DepthLimit)
void bad(int a, int b)
{
    while (a > 0)
    {
        a--;
        for (int i = 0; i < MAX; ++i)
        {
            if (b > 0)
            {
                b--;
                do
                {
                    int s = 1;
                }
                while (b != 0);
            }
            else
            {
                b++;
                if (b < 5)
                {
                    b++;
                    // bad
                    switch (a)
                    {
                    case 0:
                        break;
                    case 1:
                        break;
                    default:
                        break;
                    }
                }
                // bad
                else if (a > 5)
                {
                    break;
                }
            }
        }
    }
}
