inherit ROOM;

void create()
{
        set("short", "錟都城兵營門口");
        set("long", @LONG
你走過了喧鬧的街道，一步一步的走到了一棟大宅院的門口，在這裡
沒有啥小販和行人，地上出奇的乾淨，只有一些從大門旁兩顆梧桐樹上飄
下的落葉，和一些被風來的紙削。不過你卻聽到一些人的講話聲，在你的
好奇心驅使下，你從門縫向裡面看，看到一群彪形大漢，在裡面操演，看
他們的衣服，你知道他們就是錟都城的武夫，平時都待在裡面只有在有事
時才會出來，避免會擾民，而這裡當然就是錟都城兵營的門口了。

LONG
        );
        set("exits", ([                 
                "north" : __DIR__"city31",
                "west" : __DIR__"city35",
                "south" : __DIR__"city37",
                                        ]));

        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/citysoldier":3 ,
                                            ]));           

                
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

