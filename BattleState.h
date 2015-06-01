#ifndef BATTLESTATESTART_H
#define BATTLESTATESTART_H

class CBattleEventHandler;

class State_Base
{
public:
	virtual void Active() = 0; 
	virtual void Update(float t) = 0; 
	virtual void SetContext(CBattleEventHandler* p) = 0;
	virtual const char* GetStateName() = 0;

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
BATTLESTATEEND()

BATTLESTATESTART(PlayerTurnStart)
BATTLESTATEEND()

BATTLESTATESTART(WaitForClick)
BATTLESTATEEND()

BATTLESTATESTART(PawnClicked)
BATTLESTATEEND()

BATTLESTATESTART(PawnAttack)
BATTLESTATEEND()

BATTLESTATESTART(PawnHurt)
BATTLESTATEEND()

BATTLESTATESTART(PawnDie)
BATTLESTATEEND()

BATTLESTATESTART(PawnMove)
BATTLESTATEEND()

BATTLESTATESTART(PawnMoveEnd)
BATTLESTATEEND()

BATTLESTATESTART(PlayerTurnEnd)
BATTLESTATEEND()

BATTLESTATESTART(TurnEnd)
BATTLESTATEEND()



#endif
