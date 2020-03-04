//add moon box by manto 2006.06.09
inherit ROOM;

void create()
{
	set("short","月魂殿");
	set("long", @LONG
雖然你已經做好了心理準備，但在你步入月魂殿之時，仍不禁因
雙眼所見而張口結舌。不過並不是因為殿中的佈置富麗堂皇，反倒是
因為它的遼闊與簡單而使你感動莫名，你發現自己的眼眶竟然有點濕
潤。你繼續向前走到殿的中央，此處有一雪白晶瑩的巨大球體持續的
散發出溫和的白光，想必這就是月之石的本體吧！在這溫和的白光照
射之下，你感到自己就好像在母親的懷抱之中一樣。月魂殿乃是月族
族人集會之所，左右各有一條通道通往偏間。

LONG
	);
	set("exits",([
  "up" : "/open/world1/wilfred/club/dragon/online",
  "south" : __DIR__"room2.c",
  "east" : __DIR__"room4.c",
  "west" : __DIR__"room6.c",
		"down" : __DIR__"bank",
]));
      set("objects",([
__DIR__"item/moon_box" :1,
]));
	set("item_desc",([
  "浮刻":@DESC1

                              人
                              不
                              犯
                              我
                              
                              我
                              不
                              犯
                       燕     人
                       赤     
                       霞       
                              
DESC1
,
]));
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
	call_other( "/obj/board/moon_room3_b", "???" );
}

void init()
{
	this_player()->set_temp("come_from_moon", 1);
	this_player()->set_temp("come_from_sky", 0);
	this_player()->set_temp("come_from_dragon", 0);
}
// add by -alickyuen@ds-
