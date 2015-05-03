#ifndef BATTLESTATE_H
#define BATTLESTATE_H

class CBattleEventHandler;

#define BATTLESTATESTART(name) class State_##name{\
	public:\
		void Active();\
		void Update();\
		const char* GetStateName(){return #name;}\
		void SetContext(CBattleEventHandler* p){m_pEventHandler = p;}\
	private:\
		CBattleEventHandler* m_pEventHandler;\

#define BATTLESTATEEND() };



#endif
