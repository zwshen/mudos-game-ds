// Room35.c

inherit ROOM;

void create()
{
        set("short","天地會大殿");
        set("long", @LONG
你眼前的正是天地會的中央大殿，一股肅穆之氣籠罩上心頭。周
圍佈置得一塵不染，兩側各排列了數張桌子和椅子，以供款客之用。
殿內極之寬敞，令你原本緊張的心理登時放鬆。在你心神放鬆的時候
，發覺大殿盡頭正中央的牆壁上，掛著兩把劍成交叉形掛在牆壁上，
在江湖上行走多年的你，直覺那兩把並不是普通的劍。往西可以到達
天罡堂，往東可以到達地剎堂，往北可以到達天地會會議室。

LONG
        );
        set("exits", ([
                "north": __DIR__"room25",
                "east": __DIR__"room36",
                "south": __DIR__"room45",
                "west": __DIR__"room34",
  "up" : "/open/world1/wilfred/club/dragon/online",
        ]));
        set("objects",([
        __DIR__"item/equip_box" :1, // 2006.5.30 add by whoami
        ]));

        set("light",1);
        set("no_kill",1);
set("no_goto",1);
        setup();
        set("stroom",1);
        call_other( "/obj/board/sky_room35_b", "???" );
}

void init()
{
  this_player()->set_temp("come_from_dragon",0);
  this_player()->set_temp("come_from_sky",1);
}

