
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("冥紙",({"dead paper","paper","_DEAD_PAPER_"}) );
        set("long",@LONG
這是一張好兄弟在用的冥紙。你可以在上面書寫(write)想要換取的東西，
可書寫的種類為 art, pop, exp 及 money。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","張");
        }
        set("value", 1);
        setup();
}

void init()
{
    add_action("do_write","write");
}


int do_write(string arg) {
	string type, ctype;
    object me;
    me = this_player();
    
	if(arg=="art") {
		type = "art";
		ctype = "戰鬥藝術";
	} else if(arg=="pop") {
		type = "pop";
		ctype = "聲望";
	}  else if(arg=="exp") {
		type = "exp";
		ctype = "經驗值";
	} else if(arg=="money") {
		type = "money";
		ctype = "金錢";
	} else
		return notify_fail("可書寫的種類為 art, pop, exp 及 money。\n");

	message_vision("$N在$n上書寫上"+ctype+"的字樣。\n", me, this_object());	
	set("type", type);
	
	return 1;
}