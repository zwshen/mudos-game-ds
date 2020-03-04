inherit ROOM;
void create()
{
        set("short", "主墓室");
        set("long",@LONG
這裡是墓室中央的位置，比起其他地方寬敞多了。而最中央的位置
橫著一具頗為巨大的棺木，想必就是無名英雄長眠之處吧。抬頭望向天
花板，發現一幅巨大的壁畫。想著他生前的種種，心中不免充滿了保家
衛國的凜然正氣。只是奇怪的是，不知道這裡哪裡來的光線，竟然不用
照明的工具。
LONG
        );
        set("exits", ([
        "north" : __DIR__"grav1.c",
        "south" : __DIR__"grav4.c",
        ]));
	set("objects",([
	__DIR__"obj/coffin.c":1,
	]));
        set("item_desc",([
        "壁畫" : "一個人騎在戰馬上，宛若天神的姿態讓人由衷的敬畏。\n"
                 "不過壁畫裡的人身上的戰甲好像引引發著金光...。\n",
        ]));
        set("light", 1);
        setup();
}
