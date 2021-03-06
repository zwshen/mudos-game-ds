/**
 * Shadow's area [荒廢漁村 - 古道 - oldway2]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"古道"NOR);
	set("long",@LONG
沿著古道你走進了一片異常茂密的森林，高聳入雲的大樹完全遮
蓋住外界的光線，若沒有攜帶照明設備定會伸手不見五指。地上攀爬
著難以計數的藤蔓，想必是這不見天日的潮濕環境所影響，再仔細一
看赫然發現藤蔓所依附的竟是人死後留下的骸骨！循著藤蔓生長方向
望去，更發現居然有幾座偌大的墳墓。讓你不禁駭然失色！
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"oldway1",
		"north": __DIR__"graveyard1",
	]));
  
	setup();
}

int room_effect(object me)
{
	switch(random(9))
	{               
		case 4:
		case 3:
			message_vision("∼呼∼呼∼ 突然四周陰風陣陣。\n", me);
			return 1;
		case 2:
		case 1:
			message_vision("∼叩∼叩∼叩∼ $N突然聽到墳墓中傳來敲擊的聲響！。\n", me);
			return 1;
		case 0:
			message_vision("$N突然頭皮一陣發麻，不知該前進或是後退！\n",me);
			return 1;
		default:
			return 1;
	}
}
