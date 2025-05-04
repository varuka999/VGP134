#include <iostream>
#include "Hand.h"

int Hand::ReturnHandValue()
{
    int totalValue = 0;
    int aceCounter = 0;

    for (int i = 0; i < mHand.size(); ++i)
    {
        std::cout << mHand[i].get()->mRank << " of " << mHand[i].get()->mSuit << "\n";

        if (mHand[i].get()->mRank != 'A')
        {
            totalValue += mHand[i].get()->mValue;
        }
        else
        {
            aceCounter++;
        }

        for (int i = 0; i < aceCounter; ++i)
        {
            if (totalValue + 11 > 21)
            {
                totalValue += 1;
            }
            else
            {
                totalValue += 11;
            }
        }
    }

    return totalValue;
}

void Hand::DrawCard()
{
    mHand.push_back(BlackJackTable::Get()->ReturnTopCard());
}
