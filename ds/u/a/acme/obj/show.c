#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("阿秀",({"ar show","show"}) );
        set("long","阿秀一號。\n");
        set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","坨");
                set("value",100);
        }
        setup();

}

void init()
{
        add_action("do_show","show");
    add_action("do_laugh","laugh");
}

int do_show()
{
        string msg="";
        msg += HIM"\n\t嫦娥幽幽歎道：\n\n"NOR;
        msg += HIG"\t\t十輪霜影轉庭梧，此夕羈人獨向隅。\n";
        msg += "\t\t未必素娥無悵恨，玉蟾清冷桂花孤。\n\n"NOR;
        msg+="\t(中秋節活動開始。)\n";
        message("system",msg,users());
        return 1;
}
int do_laugh()
{
    message("system", HIR"\n奇(Tmr)因違反  ☆11☆ 巫師與巫師無故發生戰鬥，將予以嚴重處分。 ，被流影(Acme)砍檔了。\n"NOR, users());
}

