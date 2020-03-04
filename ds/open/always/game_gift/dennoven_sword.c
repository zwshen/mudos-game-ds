//¥Ñ /std/item/game_gift.c ³Ð³y by -Acme-

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name( "[33m¶Àª÷[35m¤§Às[31m£»[36m¤Û[1;37m¼v[1;31m¦å[30m¼C[0m", ({ "dragon's sword","sword" }) );
	set_weight(7457);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","³o¬O¤@§â¥¿®ð¡B§¯®ð¦X¤@£x¼C¡A¨Ï¥ÎªÌ¥²¶·¥ç¥¿¥ç¨¸¡A§_«h±N·|¨ü¨ì³o§â¼Cªº±±¨î¦Ó¯«¸g¿ù¶Ã¡B¸g¯ßºÉ¸H¨­¤`¡C");
		set("unit", "§â");
		set("value",4886);
	}
	set("weaopn_prop/hit", 10 );
	set("weaopn_prop/dex", 1 );
	init_sword(60);
	setup();
}
int query_autoload() { return 1; }
