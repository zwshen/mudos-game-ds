/*	File : "..\dodgeman.c" 
	Author : Alickyuen@ds
	Last modify : 2002年5月14日	*/

#include <ansi2.h>

inherit NPC;

void create()
{
        set_name(HIY"五頭六臂銅人"NOR, ({ "5 head 6 arms copper man", "man" }) );
        set("level", 35);
	set("long", @long
一尊六尺高的機關銅人，外形是照總舵主Opek的樣子翻模而成，全身
筋肉線條爆現，胸前雙龍環抱，背後還刻有天地會的標誌。銅人的六
個拳頭上都包上厚厚的棉絮，大大地降低了它的傷害力。銅人的肚臍
處有一投錢孔，旁邊的紙條上寫著"使用請投百枚古幣"、
Please "pay money"。
long);
	setup();
}

void init()
{
        add_action("do_enter", "pay");
}

int do_enter(string arg)
{
        object me, obj;

        me = this_player();
        obj = this_object();

        if( obj->query("attacking") ) 
                return notify_fail("現在已經在攻擊當中，請等完結後再入過錢。\n");

        if( !arg || arg != "money" )
                return notify_fail("每次收貴200 coin，使用時間為５分鍾。\n");

	me->add("bank/past", -100);
	me->force_me("deposit 100");

        obj->set("attacking", 1);
        COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"), 2);

        obj->delete("attacking");

        return 1;
}
