inherit ROOM;
void create()
{
        set("short", "泊浪村鐵匠舖");        
set("long",@LONG
這裡是泊浪村的鐵匠舖，牆上掛的都是打鐵的器材，而也給人有點
悶熱感覺，仔細一看原來是打鐵的火爐正在熊熊燒著，而沉重的打鐵聲
也鏘∼鏘∼的迴盪著，也可以感覺出來師傅的力量很足，給人一種非常
專業的感覺。
LONG
        );
        set("exits", ([
  "north" : __DIR__"po8",
    "west" : __DIR__"po8s-w",
]));
set("objects", 
([__DIR__"npc/trainer" : 1,
        ]));
set("light",1);        
set("no_clean_up", 0);
        setup();
}






