// /u/f/frank/workroom.c
inherit ROOM;

void create()
{
        set("short", "FRANK工作室");
        set("long", @LONG
一個凌亂的房間,地上放滿了各種房子的模型,天花板上掛滿了各
式的燈,隨時在變換光彩。在房間角落有一個書桌,上面堆滿了許
多的計劃表，可見得主人是個十分敬業的人。這時你無意間看到
垃圾桶的紙條--上面寫著.....幹掉你 ！！！
LONG
        );
        set("exits", ([ 
  		"wiz" :"/d/wiz/hall1",
]));
   	set("no_clean_up", 0);
  	set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
	load_object("/obj/board/frank_b");

}
