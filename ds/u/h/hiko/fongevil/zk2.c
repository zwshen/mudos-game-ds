inherit ROOM;
void create()
{
        set("short", "山間小路");
        set("long",@LONG
這裡看起來十分陰森，雙測都是一些無主的孤墳，兼且山頂風聲十分凌
厲，令你聽而生畏，這裡四處望去都無他物，感覺極為冷清，使你往前探索
的意願也大為動搖，往西南方可看到一條小徑。
LONG
        );
  
set("exits", ([
  "northwest" : __DIR__"zk3",
  "southeast" : __DIR__"zk22",  
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

 


