inherit MOBROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
 你現在來到一處樹木林立的地方, 一陣陣的風撲面
 而來, 樹上有一堆的蟬正在那嘰嘰的叫著, 好似歡迎你
 來到這裡, 此路往東方和北方分開, 你聽到不遠處有人
 砍樹的聲音。
 
LONG
 );
 
 set("exits",(["north":__DIR__"en5",
               "east":__DIR__"en4",
               "southwest":__DIR__"en2",
     ]));
 
        set("outdoors","land");
        set("chance",40);
        set("mob_amount",3);
        set("mob_object",({
                    __DIR__"npc/chan",
        }) );
        set("no_clean_up", 0);
        set("outdoors","land");
 setup();
}

