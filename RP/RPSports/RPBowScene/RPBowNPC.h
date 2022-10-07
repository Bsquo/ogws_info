#ifndef RP_SPORTS_BOW_NPC_H
#define RP_SPORTS_BOW_NPC_H
#include "types_RP.h"
#include "IRPSysHostIOSocket.h"

/**
 * @brief A Bowling NPC
 * @customname
 */
class RPBowNPC : public IRPSysHostIOSocket
{
public:
    enum EBowNPCState
    {
        IDLE,                       //!< Idles
        WAIT_PREPARE_LINE,          //!< Idles in lane with the ball in hand
        PREPARE,                    //!< Moves the ball slightly, getting ready to throw
        RUN,                        //!< Runs towards the lane and throws the ball
        SEE,                        //!< Watches the ball as it goes through the lane
        BACK                        //!< Retreats back
    };

    /**
     * @brief Manages printing debugging information about the state of the NPC
     * @address 80331654
     */
    void PrintStateInfo();
    //! @address 80331750
    void CalcState();
    /**
     * @brief Prepares the NPC for going into the WAIT_PREPARE_LINE state
     * @address 80332540
     */
    void GoToLane();
    //! @address 803325c4
    bool IsIdle();
    //! @address 80332a68
    void Init(UNKTYPE *, UNKTYPE *, UNKTYPE *, s32 NPC_ID, UNKTYPE *, UNKTYPE *);
    /**
     * @brief The constructor appears to be inlined. It "starts" at 80332b74.
     */
    inline RPBowNPC();
    //! @address 80332bcc
    virtual ~RPBowNPC();

private:
    UNKWORD WORD_0x0;
    //! @brief Current state of NPC
    EBowNPCState mState;    // at 0x4
    //! @brief Time the NPC spends in mState in frames
    u32 mTimeInState;       // at 0x8
    bool BOOL_0xC;
    bool BOOL_0xD;
    /**
     * @brief Determines whether or not the NPC should throw the ball again.
     * This is set to true when a NPCs returns back after getting a strike or a spare.
     */
    bool mIsFinished;       // at 0xE
    bool BOOL_0xF;
    UNKTYPE *PTR_0x10;
    UNKTYPE *PTR_0x14;
    UNKTYPE *PTR_0x18;
    UNKTYPE *PTR_0x1C;
    UNKTYPE *PTR_0x20;
    //! @brief ID for the NPCs. This also determines what lane they should occupy.
    s32 mID;                // at 0x24
    UNKWORD WORD_0x28;
    s32 WORD_0x2C;
    s32 WORD_0x30;
    s32 WORD_0x34;
    s32 WORD_0x38;
    UNKWORD WORD_0x3C;
    UNKTYPE *PTR_0x40;
    bool BOOL_0x44;
    bool BOOL_0x45;
    bool BOOL_0x46;
    bool BOOL_0x47;
    UNKTYPE *PTR_0x48;
    UNKWORD WORD_0x4C;
    UNKTYPE *PTR_0x50;
};

#endif