#include <h1_SW35xx.h>
using namespace h1_SW35xx;

/**
 * @brief Convert fast charge type to string
 * 
 * @param fastChargeType The fast charge type
 * @return const char* The string representation of the fast charge type
 */
const char* fastChargeType2String(SW35xx::fastChargeType_t fastChargeType)
{
    switch (fastChargeType)
    {
    case SW35xx::NOT_FAST_CHARGE:
        return "Not fast charge";
    case SW35xx::QC2:
        return "QC2.0";
    case SW35xx::QC3:
        return "QC3.0";
    case SW35xx::FCP:
        return "FCP";
    case SW35xx::SCP:
        return "SCP";
    case SW35xx::PD_FIX:
        return "PD Fix";
    case SW35xx::PD_PPS:
        return "PD PPS";
    case SW35xx::MTKPE1:
        return "MTK PE1.1";
    case SW35xx::MTKPE2:
        return "MTK PE2.0";
    case SW35xx::LVDC:
        return "LVDC";
    case SW35xx::SFCP:
        return "SFCP";
    case SW35xx::AFC:
        return "AFC";
    default:
        return "unknown";
    }
}