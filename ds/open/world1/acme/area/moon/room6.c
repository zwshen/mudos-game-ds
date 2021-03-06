inherit ROOM;

void create()
{
	set("short","蒼月之間");
	set("long", @LONG
當你進入這一間房的時候，你發現到房間四面的牆壁刻有許多的
武功招式與各門的內功心法，這裡想必就是月族族人們鍛練自己武功
的地方了。正當你在端詳著牆上所刻畫的武功之時，突然有一股寒風
從你的身後吹過。你回頭一看，在你的四周出現了很多假人和沙包。
在數個假人之中，有一個右手握著月牙劍，身穿月之鎧的冰像從天而
降。你不住好奇的向冰像靠過去，想要把雕像看個仔細。

LONG
	);
	set("exits",([
  "north" : __DIR__"room7.c",
  "east" : __DIR__"room3.c",
]));
  set("objects",([
     "open/world1/npc/goldman" : 10,
//__DIR__"box1" :1,
]));
	set("item_desc",([
  "冰像":@ICE

在你眼前是一尊由千年寒冰所鑄成的雪晴雕像(KenwayStatue)。
他是本族中最傑出的戰士，年少時曾陪同族長四處闖蕩。因為他
在族內立功無數，族長特別封他為-新月旗-的旗主，並為他在此
建造一尊雕像。令在這�婼m功的族人，每次看到這尊雕像的時候
，勇氣便會油然而生。
                              
ICE
,
  "牆壁":@WALL
 
這�堥銴F很多派門的武功招式及內功心法包括

疾風門的---  索極劍法(sorgi_sword) 迷幻七步訣(fogseven) 殘月心法(moon_force)
八極門的---  大槍訣(da-fork)       八極拳法(bagi_fist)  八極紮馬(horse-steps)
神武教的---  神武劍訣(godsword)    仙源迷蹤步(mirage-steps)
凌雲寺的---  無塵杖法(wuchen-staff)  

WALL
,
]));

	set("light",1);
set("no_goto",1);
	setup();
        call_other( "/obj/board/moon_room6_b", "???" );
//	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
}

