#include <ansi.h>
inherit SKILL;
mapping *action = ({
 ([      "action":               "$N½w½wªº¨«¦V$n¡A§Aªº¨­§Î©¿¥ª©¿¥k¡A¥O$n¬Ý¤£²M·,
                "dodge":                -50,
                "parry":                -30,
                "force":                100,
                "damage_type":  "·ï¶Ë",
        ]),
 ([      "action":               "$NÂùÁu¤@½÷¡A¨Ï¥X¤C¶Ë®±¤§"HIW"À@"RED"¤ß¨ë°©"NO,
                "dodge":                -50,
                "parry":                -50,
                "force":                100,
                "damage_type":  "·ï¶Ë",
        ]),
 ([      "action":               "$N¥kÁu¤@´§¡A´­µÃ¤@®±¥´¥X¡A¬I®i"HIC"µh"HIY"¤£",
                "dodge":                -50,
                "parry":                -50,
                "force":                100,
                "damage_type":  "·ï¶Ë",
        ]),
 ([      "action":               "$N°f¹B¯u®ð¦Ü¤â¤W¤Ö¶§¤TµJ¸g¡A­è±j¦Óª¥¼öªº¤º«lº,
                "dodge":                -50,
                "parry":                -50,
                "force":                120,
                "damage_type":  "¤º¶Ë",
        ]),
});
int valid_enable(string usage) { return usage=="unarmed"; }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

