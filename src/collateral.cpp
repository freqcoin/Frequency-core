// Copyright (c) 2020 The Frequency developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>

/**
 * The number of blocks that both new and old MN collateral value will
 * be accepted, for smoother transition.
 */
const unsigned int COLLATERAL_TRANSITION_BLOCKS = 100;

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight)
{
    CAmount nCollateralRequired;
    
    if (nHeight >= 1 && nHeight <= 1000) {
        nCollateralRequired = 15000 * COIN;
    } else if (nHeight >= 1001 && nHeight <= 150000) {
        nCollateralRequired = 15000 * COIN;
    } else if (nHeight >= 150001 && nHeight <= 300000) {
        nCollateralRequired = 15000 * COIN;
    } else if (nHeight >= 300001 && nHeight <= 450000) {
        nCollateralRequired = 15000 * COIN;
    } else if (nHeight >= 450001 && nHeight <= 600000) {
        nCollateralRequired = 15000 * COIN;
    } else if (nHeight >= 600001 && nHeight <= 850000) {
        nCollateralRequired = 15000 * COIN;
    } else if (nHeight >= 850001) {
        nCollateralRequired = 15000 * COIN;
    } else {
       nCollateralRequired = 15000 * COIN; 
    }

    return nCollateralRequired;
}


/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators for the amount of 
 * COLLATERAL_TRANSITION_BLOCKS blocks during the collateral change.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight)
{
    return (
        nAmountToCheck == CollateralRequired(nHeight) || 
        nAmountToCheck == CollateralRequired(nHeight - floor(COLLATERAL_TRANSITION_BLOCKS / 2)) ||
        nAmountToCheck == CollateralRequired(nHeight + floor(COLLATERAL_TRANSITION_BLOCKS / 2))
        );
}
