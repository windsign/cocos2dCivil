#ifndef BATTLESTATESTART_H
#define BATTLESTATESTART_H

class CBattleEventHandler;

class State_Base
{
public:
	virtual void Active(); 
	virtual void Update(float t); 
};

#define BATTLESTATESTART(name) class State_##name : public State_Base{\
	public:\
		void Active();\
		void Update(float t);\
		const char* GetStateName(){return #name;}\
		void SetContext(CBattleEventHandler* p){m_pEventHandler = p;}\
	private:\
		CBattleEventHandler* m_pEventHandler;\

#define BATTLESTATEEND() };

BATTLESTATESTART(TurnStart)
BATTLESTATEEND(TurnStart)

BATTLESTATESTART(PlayerTurnStart)
BATTLESTATEEND(PlayerTurnStart)

BATTLESTATESTART(WaitForClick)
BATTLESTATEEND(WaitForClick)

BATTLESTATESTART(PawnClicked)
BATTLESTATEEND(PawnClicked)

BATTLESTATESTART(PawnAttack)
BATTLESTATEEND(PawnAttack)

BATTLESTATESTART(PawnHurt)
BATTLESTATEEND(PawnHurt)

BATTLESTATESTART(PawnDie)
BATTLESTATEEND(PawnDie)

BATTLESTATESTART(PawnMove)
BATTLESTATEEND(PawnMove)

BATTLESTATESTART(PawnMoveEnd)
BATTLESTATEEND(PawnMoveEnd)

BATTLESTATESTART(PlayerTurnEnd)
BATTLESTATEEND(PlayerTurnEnd)

BATTLESTATESTART(TurnEnd)
BATTLESTATEEND(TurnEnd)



#endif
