#pragma once
#include <string>

namespace MPS_Resource {
	enum MPS_MODIFIER_TYPE {
		tASM,
		tPSM,
		tFSM,
		tEAM,
		tRM,
		
		tMPS_MODIFIER_TYPE_NUM
	};

	enum MPS_TASK_TYPE {
		tMPS_TASK_DAMAGE,
		tBUFF_SELF_OFF,
		tBUFF_FRIEND_OFF,
		tDEBUFF_PLAYER_DEF,
		tADD_FRIEND_RE,
		tDISPEL_PLAYER_HPBUFF,
		tRECOVER_SELF_HP,
		tBUFF_SELF_DEF,
		tDEBUFF_PLAYER_OFF,
		tRECOVER_FRIEND_HP,
		tBUFF_FRIEND_DEF,
		tDEC_PLAYER_RE,
		tSTOP_PLAYER_ACT,
		tADD_SELF_RE,
		tADD_FRIEND_NUM,
		tMPS_TASK_ESCAPE,

		tMPS_TASK_TYPE_NUM
	};


}