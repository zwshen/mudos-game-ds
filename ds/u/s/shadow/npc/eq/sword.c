/**
 *	Shadow's sword - 血浪
 *	以青岩劍為範本修改之.
 */
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIR"血浪"NOR, ({ "blood wave sword","sword" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {		
		set("unit", "柄");
		set("long",@LONG
    此劍名為「血浪」，大有血濺成浪之意，乃是一柄吹毛可斷
破敵甲如無物的絕世寶劍。劍長七尺，劍鞘刻有古代銘文、劍柄
處更以古篆鑄著「血浪」兩字。抽劍一看，只見晶光燦爛的特長
劍體上隱有棗紅血紋，並呈波浪之狀，不由得讓人讚嘆這柄寶劍
確為曠世傑作！
LONG
		);
		set("needaward", 40);
		set("value", 1);
		set_weight(8000);
		set("material", "blacksteel");
		set("no_drop", 1);
		set("can_give", 1);
		
		set("wield_msg", HIR"$N裝備上血浪，雙目瞬間閃過一抹殷紅殺氣！\n"NOR);
		set("unwield_msg", RED"$N卸下了血浪，怵目驚心的殺氣也隱然退去！\n"NOR);
		
		set("weapon_prop/con", 2);
		set("weapon_prop/hit", 30);
		set("weapon_prop/bar", 2);
		set("weapon_prop/wit", -1);
		init_sword(60);
	}
	    
	setup();
}

int query_autoload() { return 1; }
