#ifndef RP_SPORTS_BOW_NPC_MANAGER_H
#define RP_SPORTS_BOW_NPC_MANAGER_H
#include "types_RP.h"
#include "IRPSysHostIOSocket.h"
#include "RPBowNPC.h"

/**
 * @brief Stores and manages all 6 Bowling NPCs
 * @customname
 */
class RPBowNPCManager : public IRPSysHostIOSocket
{
public:
    /**
     * @brief Manages printing debugging information about all the NPCs
     * @address 803327fc
     */
    void PrintStateInfo();
    //! @address 80332854
    void UpdateNPCs();
    //! @address 80332a68
    void InitNPCs(UNKWORD, UNKWORD);
    //! @address 80332b34
    RPBowNPCManager();
    //! @address 803155d4
    virtual ~RPBowNPCManager();
    

private:
    //! @brief All 6 NPCs
    RPBowNPC *mNPCs[6]; // at 0x0
    UNKWORD WORD_0x18;  // at 0x18
    /**
     * @brief Determines if debugging information about all the NPCs
     * should be displayed
     */
    bool mPrintNPCStateInfo;  // at 0x1C
    bool WORD_0x1D;  // at 0x1D
    bool WORD_0x1E;  // at 0x1E
    bool WORD_0x1F;  // at 0x1F
};

#endif