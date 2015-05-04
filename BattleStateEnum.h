#ifndef BATTLESTATEENUM_H
#define BATTLESTATEENUM_H
enum EBattleState
{
	eBS_TurnStart,
	eBS_PlayerTurnStart,
	eBS_WaitForClick,
	eBS_PawnClicked,
	eBS_PawnAttack,
	eBS_PawnHurt,
	eBS_PawnDie,
	eBS_PawnMove,
	eBS_PawnMoveEnd,
	eBS_PlayerTurnEnd,
	eBS_TurnEnd,
	eBS_All
};

#endif
