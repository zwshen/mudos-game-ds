#include <ansi.h>
inherit ITEM;

string pows(int index);
string version_card(int ver);

void create()
{
        set_name("紙牌瀏覽機", ({ "card browse set", "set", "browse set" }));
        set("long", @LONG
這是一台不知道那邊來的機器, 你可以用 browsec 瀏覽你身上的紙牌.
LONG
        );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "台");
                set("value", 1450);
        }
        setup();
}

void init()
{
        add_action("do_browse", "browsec");
}

int do_browse(string arg)
{
        object me = this_player(), card, *objs = all_inventory(me);
        int i, *pow, cards=1; 
        string msg = "", pow_m;

/*
 牌數    卡 片  稱 號    能力點數    版  本   卡號  等級
‾‾‾  ‾‾‾‾‾‾‾  ‾￣￣￣￣  ﹊﹊﹊﹊  ﹊﹊  ‾‾
    1    神槍  李書文    １２３４   孟村傳奇   30    6
*/

//      if( arg != "card" ) return 0;

        if( !card=present("magic card", me) )
                return notify_fail("你身上沒有牌！\n");

        for(i=0;i<sizeof(objs);i++)
                if( pointerp(pow=objs[i]->query("pow")) )
                {
                        pow_m = pows(pow[0]) + pows(pow[1]) + pows(pow[2]) + pows(pow[3]);
                        if( cards == 1 )
                                msg += HIG" 牌數    "HIY"卡 片  稱 號    "HIM"能力點數    "HIC"版  本   "NOR+CYN"卡號  "YEL"等級\n"NOR+
                                        HIG"‾‾‾  "HIY"‾‾‾‾‾‾‾  "HIM"‾￣￣￣￣  "HIC"﹊﹊﹊﹊  "NOR+CYN"﹊﹊  "YEL"‾‾\n"NOR;
                        msg += sprintf(HIW"  %3d    %12s    %8s   %8s   %2d    %2d\n"NOR ,
                                cards++,
                                objs[i]->query("short"),
                                pow_m,
                                version_card(objs[i]->query("ver")),
                                objs[i]->query("num"),
                                objs[i]->query("lv"));
                }

        if( msg == "" ) return notify_fail("你身上沒有牌, 或者是牌的設定有誤. \n");
        me->start_more(msg+NOR);
        return 1;
}

string version_card(int ver)
{
        // 1α版 2孟村傳奇 3武神 4梅龍小鎮 5天城之戰 6群魔亂舞 7古代一版
        switch(ver)
        {
                case 1:
                        return "α\版";
                case 2:
                        return "孟村傳奇";
                case 3:
                        return "武神";
                case 4:
                        return "梅龍小鎮";
                case 5:
                        return "天城之戰";
                case 6:
                        return "群魔亂舞";
                case 7:
                        return "古代一版";
                default:
                        return "未定義";
        }
}

string pows(int index)
{
        string *match = ({"０","１","２","３","４","５","６","７","８","９"});
        if( index > sizeof(match) ) return "Ａ";
        return match[index];
}
